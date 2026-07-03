// server.c
// TCP 服务端
#include <complex.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
// in.h 是网络通信的一些内容,定义了网络通信的地址
#include <netinet/in.h>
// un.h 是有本地通信的一些内容，定义了本地通信的地址
#include <string.h>
#include <sys/un.h>
#include <unistd.h>

int main()
{
    // 创建服务端套接字
    // 参数1：地址族 AF_UNIX 表示使用本地地址族
    // 参数2：SOCK_STREAM 表示使用 TCP 协议
    // 参数3：0 表示使用默认协议
    // 返回值：套接字描述符，-1 表示失败
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1)
    {
        perror("socket 创建失败");
        exit(EXIT_FAILURE);
    }

    // 绑定地址
    // sockaddr           (通用的)
    // sockaddr_un
    // sockaddr_in
    // sockaddr_in6

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    // 定义地址的协议族:TCP/IP IPV4
    addr.sin_family = AF_INET;
    // IP:无符号32位整数,htonl 是将主机字节序转换为网络字节序
    // INADDR_ANY 表示任意地址0.0.0.0
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    // 端口号是2字节，用htons 将主机字节序转换为网络字节序
    addr.sin_port = htons(9000);

    // 绑定地址
    if (bind(fd, (struct sockaddr *)&addr, sizeof(addr)) == -1)
    {
        perror("bind 绑定失败");
        close(fd);
        exit(EXIT_FAILURE);
    }

    listen(fd, 10);
    printf("监听成功\n");

    int flag = 1;
    while (flag)
    {
        printf("等待连接\n");
        // 用来记录客户端地址
        struct sockaddr_in c_addr;
        memset(&c_addr, 0, sizeof(c_addr));

        int len = sizeof(c_addr);
        // 接受连接
        int c_fd = accept(fd, (struct sockaddr *)&c_addr, &len);
        // 读写数据：在新的线程中处理

        char buf[1024];
        memset(buf, 0, 1024);
        // 读取数据
        int size = read(c_fd, buf, sizeof(buf));
        printf("收到:%s\n", buf);

        char msg[] = "TCP Server\n";
        write(c_fd, msg, strlen(msg));

        close(c_fd);
    }

    close(fd);
    return 0;
}