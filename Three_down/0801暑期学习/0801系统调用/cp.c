// cp.c
// 实现文件复制，使用系统调用
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("参数不足\n");
        return EXIT_FAILURE;
    }

    int fd_in;
    int fd_out;

    // 只读模式，要读取的文件
    fd_in = open(argv[1], O_RDONLY);
    if (fd_in == -1)
    {
        perror("open error1");
    }
    // 读写模式没有则创建，要写入的文件
    fd_out = open(argv[2], O_WRONLY | O_CREAT, 0666);
    if (fd_out == -1)
    {
        perror("open error2");
    }
    struct stat st;
    fstat(fd_in, &st);
    printf("%ld,%ld\n", st.st_size, st.st_blksize);

    // 读写1024字节
    char buf[1024];
    // 读取的字节数
    int n;
    // 读取到0字节，说明读取完毕
    while ((n = read(fd_in, buf, sizeof(buf))) > 0)
    {
        write(fd_out, buf, n);
    }
    printf("copy success");
    close(fd_in);
    close(fd_out);
    return 0;
}