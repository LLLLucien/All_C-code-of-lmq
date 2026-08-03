// httpServer
#include <arpa/inet.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sendfile.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

char *handle_get(char buf[]);

int main(void)
{
    // 1.创建套接字
    int s_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (s_fd < 0)
    {
        perror("socket error\n");
        return EXIT_FAILURE;
    }
    printf("socket succeed\n");
    // 2.端口复用
    int opt = 1;
    setsockopt(s_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    // 3.初始化地址结构体
    struct sockaddr_in s_addr;
    s_addr.sin_family = AF_INET;
    s_addr.sin_port = htons(9000);
    s_addr.sin_addr.s_addr = INADDR_ANY;

    // 4.绑定
    int ret = bind(s_fd, (struct sockaddr *)&s_addr, sizeof(s_addr));
    if (ret < 0)
    {
        perror("bind error\n");
        close(s_fd);
        return EXIT_FAILURE;
    }
    printf("bind succeed\n");
    // 5.监听
    if (listen(s_fd, 5) < 0)
    {
        perror("listen error\n");
        close(s_fd);
        return EXIT_FAILURE;
    }
    printf("listen succeed\n");

    // 6.接收
    while (1)
    {
        // 6.1 创建客户端结构体
        struct sockaddr_in c_addr;
        // 初始化客户端结构体
        memset(&c_addr, 0, sizeof(c_addr));
        socklen_t len = sizeof(c_addr);

        // 6.2 接收数据
        printf("wait accept.....\n");
        int c_fd = accept(s_fd, (struct sockaddr *)&c_addr, &len);
        if (c_fd < 0)
        {
            perror("accept error\n");
            break;
        }
        printf("===接收succeed===\n");
        // 获取ip地址
        char ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &c_addr.sin_addr, ip, sizeof(ip));
        // 获取端口
        int c_port = ntohs(c_addr.sin_port);
        printf("客户端的ip:%s,端口号:%d\n", ip, c_port);
        char buf[2048] = {0};
        long recv_total = 0;

        // 7.处理请求
        while (1)
        {
            int n = recv(c_fd, buf + recv_total, sizeof(buf), 0);
            if (n <= 0)
            {
                printf("===客户端已退出===\n");
                break;
            }
            recv_total += n;
            buf[recv_total] = '\0';
            if (strstr(buf, "\r\n\r\n") != NULL)
                break;
        }
        printf("%s\n", buf);
        printf("===总共接收%ld字节数据===", recv_total);

        // 获取需要文件
        char *file_path = handle_get(buf);
        printf("======%s=====", file_path);

        FILE *f_fd = fopen(file_path, "rb");
        if (f_fd == NULL)
        {
            perror("fopen error\n");
            char sendMSG_404[] = "HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\n\r\n";
            write(c_fd, sendMSG_404, sizeof(sendMSG_404));
            strcpy(file_path, "404.html\0");
        }

        // 8.发送响应

        int file_fd = open(file_path, O_RDONLY);
        // 发送的响应信息
        if (strcmp(file_path, "404.html\0") != 0)
        {
            char sendMSG[] = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";

            write(c_fd, sendMSG, sizeof(sendMSG));
        }
        // 9.发送文件
        struct stat st;
        fstat(file_fd, &st);
        long total_size = st.st_size;
        // 偏移量
        off_t offset = 0;
        // 要发送大小
        ssize_t send_len;
        // 已发送大小
        long sent = 0;

        // 然后 sendfile 发文件内容
        while (sent < total_size)
        {
            send_len = sendfile(c_fd, file_fd, &offset, 4096);
            if (send_len <= 0)
            {
                perror("sendfile");
                break;
            }
            sent += send_len;
        }

        close(c_fd);
    }
    // 关闭fd
    close(s_fd);
    return 0;
}
/*
HTTP/1.1 304 Not Modified
Server: nginx/1.24.0 (Ubuntu)
Date: Sun, 02 Aug 2026 08:23:04 GMT
Last-Modified: Sun, 02 Aug 2026 06:17:07 GMT
Connection: keep-alive
ETag: "6a6ee0e3-575"
*/

/*
  GET /index.html HTTP/1.1
  Host: 192.168.197.129:9000
  */

char *handle_get(char buf[])
{
    char method[16], path[256];
    sscanf(buf, "%15s %255s", method, path);
    // method 拿到了但不处理，只看 path
    return strdup(path + 1); // 去掉 '/'
}