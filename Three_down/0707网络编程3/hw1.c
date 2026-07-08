// hw1.c
#include "my.h"
#include <pthread.h>
#include <stdio.h>
#include <time.h>

typedef struct arg_t
{
    int fd;
    int send_port; // 要发送的端的端口

} ARG_T;

void *send_msg(void *arg)
{

    int fd = ((ARG_T *)arg)->fd;
    int send_port = ((ARG_T *)arg)->send_port;
    // 要发送的端的地址
    struct sockaddr_in send_addr;
    memset(&send_addr, 0, sizeof(send_addr));
    inet_pton(AF_INET, "127.0.0.1", &send_addr.sin_addr);
    // 要发送的端的端口
    send_addr.sin_port = htons(send_port);

    socklen_t len = sizeof(send_addr);
    char msg[1024];
    while (1)
    {
        memset(msg, 0, sizeof(msg));
        printf("请输入要发送的信息：");
        fgets(msg, sizeof(msg), stdin);
        msg[strcspn(msg, "\n")] = '\0';
        // 发送数据，参数：套接字描述符，数据，数据长度，发送标志默认0，目标地址，目标地址长度
        ssize_t len = sendto(fd, msg, strlen(msg), 0, (struct sockaddr *)&send_addr, sizeof(send_addr));
        printf("-----发送成功-----\n");
        if (strcmp(msg, "exit") == 0)
        {
            memset(msg, 0, sizeof(msg));
            strcpy(msg, "lmq退出了客户端\n");
            sendto(fd, msg, strlen(msg), 0, (struct sockaddr *)&send_addr, sizeof(send_addr));
            printf("---已退出---\n");
            break;
        }
    }
    close(fd);
    return NULL;
}
void *recv_msg(void *arg)
{

    int fd = ((ARG_T *)arg)->fd;

    // 缓冲区
    char buf[1500 - 28];
    memset(buf, 0, sizeof(buf));

    // 创建接收端地址
    struct sockaddr_in client_addr;
    memset(&client_addr, 0, sizeof(client_addr));

    socklen_t len = sizeof(client_addr);
    // 接收到的端口

    while (1)
    {
        ssize_t t = recvfrom(fd, buf, sizeof(buf), 0, (struct sockaddr *)&client_addr, &len);
        if (t == -1)
        {
            perror("recvfrom 失败\n");
            close(fd);
            return NULL;
        }
        int port = ntohs(client_addr.sin_port);
        char ip[INET_ADDRSTRLEN];
        // ip地址，从网络字节序转换为主机字节序
        inet_ntop(AF_INET, &client_addr.sin_addr, ip, sizeof(ip));
        printf("\n\t\t\t----由%s:%d发送的数据:%s,len=%ld\n", ip, port, buf, t);

        memset(buf, 0, sizeof(buf));
    }
    return NULL;
}

int main()
{

    pthread_t t1, t2;

    // 创建套接字
    int fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd == -1)
    {
        perror("socket 失败");
        return EXIT_FAILURE;
    }
    int opt = 1;
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    // 自身地址
    printf("输入本机端口号:");
    int DIY_port;
    scanf("%d", &DIY_port);
    printf("输入要发送的端口号:");
    int send_port;
    scanf("%d", &send_port);
    while ((getchar() != '\n'))
        ;
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(DIY_port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    // 绑定
    int ret = bind(fd, (struct sockaddr *)&addr, sizeof(addr));
    if (ret == -1)
    {
        perror("bind 失败");
        close(fd);
        return EXIT_FAILURE;
    }
    ARG_T arg;
    arg.fd = fd;
    arg.send_port = send_port;
    // 地址复用

    pthread_create(&t1, NULL, (void *)&send_msg, &arg);
    pthread_create(&t2, NULL, (void *)&recv_msg, &arg);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    close(fd);

    return 0;
}