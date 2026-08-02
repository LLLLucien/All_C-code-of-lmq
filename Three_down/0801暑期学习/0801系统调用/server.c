// server
#include <arpa/inet.h> //ip地址转换
#include <fcntl.h>
#include <netinet/in.h> //地址结构和
#include <stdio.h>
#include <string.h>
#include <sys/socket.h> //套接字
#include <sys/types.h>
#include <unistd.h>
typedef struct
{
    int name_len;
    long file_size;
} FileHeader;

int main(int argc, char *argv[])
{
    // 创建套接字
    int sockfd;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("socket error\n");
        return 1;
    }
    printf("socket success\n");

    int opt = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // 绑定套接字
    struct sockaddr_in s_addr;
    s_addr.sin_family = AF_INET;
    s_addr.sin_port = htons(9000);
    s_addr.sin_addr.s_addr = INADDR_ANY;

    int ret = bind(sockfd, (struct sockaddr *)&s_addr, sizeof(s_addr));
    if (ret < 0)
    {
        printf("bind error\n");
        return 1;
    }
    printf("bind success\n");
    // 监听套接字
    listen(sockfd, 5);
    printf("listen success\n");

    while (1)
    {
        struct sockaddr_in c_addr;
        socklen_t c_addr_len = sizeof(c_addr);
        int connfd = accept(sockfd, (struct sockaddr *)&c_addr, &c_addr_len);
        if (connfd < 0)
        {
            printf("accept error\n");
            return 1;
        }
        printf("accept success\n");
        printf("客户端接入: %s:%d\n", inet_ntoa(c_addr.sin_addr), ntohs(c_addr.sin_port));

        // 接收文件头
        FileHeader header;
        recv(connfd, &header, sizeof(header), 0);

        char file_name[1024] = {0};
        recv(connfd, file_name, header.name_len, 0);

        printf("将要接收文件: %s，大小:%ld bytes\n", file_name, header.file_size);

        strcat(file_name, "_2");

        // 创建文件写入

        int in_fd = open(file_name, O_CREAT | O_WRONLY, 0666);
        if (in_fd < 0)
        {
            printf("open error\n");
            return 1;
        }
        printf("open success\n");

        long recv_total = 0;
        ssize_t n;
        while (header.file_size > recv_total)
        {
            char buf[1024] = {0};
            n = recv(connfd, buf, sizeof(buf), 0);
            write(in_fd, buf, n);
            recv_total += n;
        }
        printf("\n文件 %s 接收完成\n", file_name);
        close(in_fd);
        // shutdown
        close(connfd);
    }
}