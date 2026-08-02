// io.c
//  系统调用

// POSIX（Portable Operating System Interface）可移植操作系统接口
#include <fcntl.h>
// File Control Operations
#include <stdio.h>
#include <string.h>
#include <unistd.h>
int main(int argc, char *argv[])
{

    // 文件描述符：0 1 2
    //  0 标准输入stdin
    //  1 标准输出stdout
    //  2 标准错误输出stderr
    //  3 新打开的文件描述符一般从3开始
    /*
    char buf[16] = "hello POSIX";
    if (write(1, buf, strlen(buf)) != strlen(buf))
    {
        write(2, "write error\n", 11);
    }
    write(2, "\n", 1);
    char buf2[16];
    memset(buf2, 0, sizeof(buf2));
    int n = read(0, buf2, sizeof(buf2));

    write(1, buf2, n);
    */

    // 打开文件时，如果文件不存在，则创建文件
    // 给予权限
    // 0660 表示0是八进制，6是给用户读写权限，6是给组读写权限，0是给其他用户读写权限
    int fd = open("test4.txt", O_WRONLY | O_CREAT, 0660);
    printf("fd=%d\n", fd);

    char buf[] = "hello POSIX";
    int len = write(fd, buf, sizeof(buf));
    printf("len=%d\n", len);
    close(fd);

    return 0;
}
