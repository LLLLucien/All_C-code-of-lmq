// c.c
// client
// socket->connect->read/write->close

#include <arpa/inet.h>  //大小端转换
#include <netinet/in.h> //ip地址
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h> //用到了读写

int main()
{
    // 创建套接字,参数：协议族TCP/IP，套接字类型：流TCP，协议：默认
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1)
    {
        perror("套接字创建失败");
        return EXIT_FAILURE;
    }

    // 连接服务器

    // 服务器的地址
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9000); // 端口号转换为网络字节序
    // 主机字节序到网络字节序的转换
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);

    // 连接服务器，返回值0表示成功，只需连接一次
    if (connect(fd, (struct sockaddr *)&addr, sizeof(addr)) == -1)
    {
        perror("connect失败");
        close(fd);
        return EXIT_FAILURE;
    }

    char buf[1024];
    while (1)
    {
        memset(buf, 0, sizeof(buf));
        printf("请输入要发送的信息：");
        // 从标准输入读取一行，存入buf中
        if (fgets(buf, sizeof(buf), stdin) == NULL)
            break; // Ctrl+D 或读取错误时退出

        // 去掉 fgets 读入的换行符（便于比较）
        buf[strcspn(buf, "\n")] = '\0';

        // 输入 exit 时退出循环
        if (strcmp(buf, "exit") == 0)
            break;

        // 发送字符串（不含 '\0'）
        if (write(fd, buf, strlen(buf)) == -1)
        {
            perror("write 失败");
            break;
        }

        // 接收服务器的响应
        memset(buf, 0, sizeof(buf));
        size_t rlen = read(fd, buf, sizeof(buf) - 1);
        if (rlen <= 0)
        {
            perror("read 失败或服务器断开");
            break;
        }
        printf("服务器的响应：%s\n", buf);
    }
    close(fd);
    return 0;
}