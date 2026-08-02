// d.c
#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>

char getType(int d_type)
{
    char t = ' ';
    switch (d_type)
    {
        case DT_DIR:
            t = 'd';
            break;
        case DT_REG:
            t = '-';
            break;
        case DT_LNK:
            t = 'l';
            break;

        default:
            t = 'x';
            break;
    }
    return t;
}
int main()
{
    DIR *dir =
        opendir("/home/lmq20233547/All_C-code-of-lmq/Three_down/0524io目录");
    if (dir == NULL)
    {
        perror("无法打开目录");
        return 1;
    }
    // readdir函数返回的是一个结构体指针，指向目录中的一个文件或目录
    // 结构体中包含了文件或目录的名称、类型、大小、修改时间等信息
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
    {
        // 跳过.和..
        //.表示当前目录，..表示上一级目录
        if (entry->d_name[0] == '.')
        {
            continue;
        }
        printf("%c %ld ", getType(entry->d_type), entry->d_ino);
        printf("%s ", entry->d_name);

        printf("\n");
    }
    // 关闭目录
    closedir(dir);
    return 0;
}