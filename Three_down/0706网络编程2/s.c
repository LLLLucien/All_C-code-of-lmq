// s.c
// server
// 基本步骤：socket->bind->listen->accpet->read/write->close

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main()
{

    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1)
    {
        perror("套接字创建失败");
        return EXIT_FAILURE;
    }
    // 地址复用,放在bind前
    int opt = 1;
    // 参数：套接字描述符，协议族，选项名启用地址重用，选项值，选项值长度
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));

    addr.sin_family = AF_INET;
    addr.sin_port = htons(9000);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(fd, (struct sockaddr *)&addr, sizeof(addr)) == -1)
    {
        perror("bind 绑定失败");
        close(fd);
    }
    listen(fd, 3);
    printf("监听成功\n");
    while (1)
    {
        printf("等待连接\n");
        struct sockaddr_in client_addr;
        memset(&client_addr, 0, sizeof(client_addr));
        socklen_t len = sizeof(client_addr);

        int c_fd = accept(fd, (struct sockaddr *)&client_addr, &len);
        if (c_fd == -1)
        {
            perror("accept 失败");
            close(fd);
            return EXIT_FAILURE;
        }
        printf("客户端连接成功\n");
        // 用port 记录端口号
        int port = ntohs(client_addr.sin_port);
        // INET_ADDRSTRLEN 是ipv4的长度，就是16
        char ip[INET_ADDRSTRLEN];
        // 把网络字节序转换为主机字节序
        inet_ntop(AF_INET, &client_addr.sin_addr, ip, sizeof(ip));
        printf("客户端的ip:%s,端口号:%d\n", ip, port);
        char buf[1024];
        while (1)
        {
            memset(buf, 0, sizeof(buf));
            // 读
            size_t len = read(c_fd, buf, sizeof(buf));
            if (strcmp(buf, "exit") == 0 || len == 0)
            {
                printf("%s客户端退出\n", ip);
                break;
            }
            printf("%s客户端发送的信息：%s\n", ip, buf);
            memset(buf, 0, sizeof(buf));
            // 写
            strcpy(buf, "---服务器收到信息---");
            write(c_fd, buf, strlen(buf));
        }
        printf("关闭:%s:%d\n", ip, port);
        close(c_fd);
    }

    close(fd);
    return 0;
}