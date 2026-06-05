#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

typedef struct AllCount {
    int file_count;
    int dir_count;
    int line_count;
} AllCount;

void countLines(char *path, AllCount *ac);
void init(AllCount *ac);
void getAllCount(const char *path, AllCount *ac);

int main(int argc, char *argv[])
{
    // if (argc != 2)
    // {
    //     printf("请输入要统计的目录\n");
    //     return EXIT_FAILURE;
    // }

    AllCount ac;
    init(&ac);
    // getAllCount(argv[1], &ac);
    getAllCount("/home/lmq20233547/linux-7.0.10", &ac);

    printf("文件数：%d\n", ac.file_count);
    printf("目录数：%d\n", ac.dir_count);
    printf("所有文件的总行数：%d\n", ac.line_count);
    return 0;
}

void getAllCount(const char *dir_path, AllCount *ac)
{
    DIR *dir = opendir(dir_path);
    if (dir == NULL)
    {
        perror("无法打开目录");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
    {
        // 跳过 . 和 ..
        if (entry->d_name[0] == '.')
        {
            continue;
        }

        // 拼接完整路径
        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path,
                 entry->d_name);

        if (entry->d_type == DT_DIR)
        {
            ac->dir_count++;
            getAllCount(full_path, ac); // 递归处理子目录
        } else if (entry->d_type == DT_REG)
        {
            ac->file_count++;
            countLines(full_path, ac); // 统计文件行数
        }
    }
    closedir(dir);
}

void init(AllCount *ac)
{
    ac->file_count = 0;
    ac->dir_count = 0;
    ac->line_count = 0;
}

// 统计文件行数
void countLines(char *path, AllCount *ac)
{
    FILE *fp = fopen(path, "r");
    if (!fp)
    {
        perror("文件无法打开");
        return;
    }

    char buf[1024];
    int line_count = 0;
    while (fgets(buf, sizeof(buf), fp) != NULL)
    {
        line_count++;
    }
    ac->line_count += line_count;
    fclose(fp);
}
