#include <arpa/inet.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sendfile.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <unistd.h>
typedef struct
{
    int name_len;
    long file_size;
    // char md[32];
} FileHeader;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s upload_file_path\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    const char *file_path = argv[1];
    // 创建套接字
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // 初始化地址
    struct sockaddr_in c_addr;
    c_addr.sin_family = AF_INET;
    c_addr.sin_port = htons(9000);
    inet_pton(AF_INET, "127.0.0.1", &c_addr.sin_addr);

    socklen_t len = sizeof(c_addr);
    // 连接服务器
    int ret = connect(sockfd, (struct sockaddr *)&c_addr, len);
    if (ret < 0)
    {
        perror("connect");
        close(sockfd);
        exit(1);
    }
    // 打开要读取的文件
    int file_fd = open(file_path, O_RDONLY);
    if (file_fd < 0)
    {
        perror("open file");
        close(sockfd);
        exit(1);
    }
    // 获取文件大小
    struct stat st;
    fstat(file_fd, &st);
    long total_size = st.st_size;

    char file_name[256] = {0};
    char *p = strrchr(file_path, '/');
    if (p)
        strcpy(file_name, p + 1);
    else
        strcpy(file_name, file_path);

    int name_len = strlen(file_name);
    // 发送文件头部信息
    FileHeader header = {.name_len = name_len, .file_size = total_size};

    // 发送结构体
    send(sockfd, &header, sizeof(header), 0);
    // 发送文件名
    send(sockfd, file_name, name_len, 0);

    // 偏移量
    off_t offset = 0;
    // 要发送大小
    ssize_t send_len;
    // 已发送大小
    long sent = 0;

    while (sent < total_size)
    {
        send_len = sendfile(sockfd, file_fd, &offset, 4096);
        if (send_len <= 0)
        {
            perror("sendfile");
            break;
        }
        sent += send_len;
    }

    close(file_fd);
    close(sockfd);
    return 0;
}