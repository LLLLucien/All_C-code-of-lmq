// send.c
#include "my.h"
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>

int main()
{
    // SOCK_DGRAM为UDP相关的数据包套接字
    int fd = socket(AF_INET, SOCK_DGRAM, 0);

    // 发送
    char msg[1024];

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    // inet_pton 把ip地址转换为网络字节序
    // inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr); // 接收方ip
    inet_pton(AF_INET, "122.51.242.187", &addr.sin_addr); // 接收方ip
    addr.sin_port = htons(9527);                          // 接收方port

    while (1)
    {
        memset(msg, 0, sizeof(msg));
        printf("请输入要发送的信息：");
        fgets(msg, sizeof(msg), stdin);
        msg[strcspn(msg, "\n")] = '\0';
        // 发送数据，参数：套接字描述符，数据，数据长度，发送标志默认0，目标地址，目标地址长度
        ssize_t len = sendto(fd, msg, strlen(msg), 0, (struct sockaddr *)&addr, sizeof(addr));
        printf("send: %s, len=%ld\n", msg, len);
        if (strcmp(msg, "exit") == 0)
        {
            memset(msg, 0, sizeof(msg));
            strcpy(msg, "lmq退出了客户端\n");
            ssize_t len = sendto(fd, msg, strlen(msg), 0, (struct sockaddr *)&addr, sizeof(addr));
            printf("---已退出---\n");
            break;
        }
    }
    // 关闭套接字
    close(fd);
    return 0;
}