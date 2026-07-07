// recv.c
#include "my.h"
#include <asm-generic/socket.h>
#include <stdio.h>
#include <sys/socket.h>

int main()
{
    // 创建套接字
    int fd = socket(AF_INET, SOCK_DGRAM, 0);

    // 地址复用
    int opt = 1;
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    // bind绑定
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9527);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    int ret = bind(fd, (struct sockaddr *)&addr, sizeof(addr));
    if (ret == -1)
    {
        perror("bind 失败");
        close(fd);
        return EXIT_FAILURE;
    }
    // 接收数据
    // UDP 包头中「长度」字段是 16 位，所以理论上一个 UDP 数据报最大是 2¹⁶ - 1 = 65535 字节
    // IP MTU(MAX TRANSMISSION UNIT最大传输单元)
    // 1500 是以太网的最大长度，28 是以太网的头部长度，
    char buf[1500 - 28];
    memset(buf, 0, sizeof(buf));

    struct sockaddr_in client_addr;
    memset(&client_addr, 0, sizeof(client_addr));
    socklen_t len = sizeof(client_addr);

    while (1)
    {
        ssize_t t = recvfrom(fd, buf, sizeof(buf), 0, (struct sockaddr *)&client_addr, &len);
        if (t == -1)
        {
            perror("recvfrom 失败");
            close(fd);
            return EXIT_FAILURE;
        }
        // 192.168.30.133
        //  获得端口
        int port = ntohs(client_addr.sin_port);
        char ip[INET_ADDRSTRLEN];
        // ip地址，从网络字节序转换为主机字节序
        inet_ntop(AF_INET, &client_addr.sin_addr, ip, sizeof(ip));
        printf("由%s:%d发送的数据:%s,len=%ld\n", ip, port, buf, t);
        // if (strcmp(buf, "exit") == 0)
        // {
        //     printf("客户端退出\n");
        //     break;
        // }
        memset(buf, 0, sizeof(buf));
    }
    close(fd);
    return 0;
}