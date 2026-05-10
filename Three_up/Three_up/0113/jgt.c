#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NAME_SIZE 16

typedef struct
{
    char name[NAME_SIZE];
    int age;
} Student;

int main()
{
    int t;
    printf("请输入学生的数量：");
    scanf("%d", &t);
    // 长度可变的数组
    Student *ptr = (Student *)malloc(t * sizeof(Student));
    if (ptr == NULL)
    {
        printf("空间分配失败");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < t; i++)
    {
        printf("\n请输入姓名与年龄:");
        // 不能用ptr++，因为ptr不可改变
        scanf("%s %d", (ptr + i)->name, &(ptr + i)->age);
    }
    for (int i = 0; i < t; i++)
    {
        printf("%s\t%d\n", (ptr + i)->name, (ptr + i)->age);
    }

    free(ptr);
    ptr = NULL;
    /*
    Student a[4] = {{"吕布", 21}, {"赵子龙", 19}, {.age = 23, .name = "貂蝉"}};
    strcpy(a[3].name, "曹操");
    // 或strncpy(a[3].name, "曹操", sizeof(a[3].name) - 1); 更安全
    a[3].age = 34;

    Student *p = a;
    for (int i = 0; i < (sizeof(a) / sizeof(a[0])); i++)
    {
        // printf("%s\t%d\n", a[i].name, a[i].age); //数组下标
        // printf("%s\t%d\n", (*p).name, (*p).age); //指针
        printf("%s\t%d\n", p->name, p->age); // 指针->
        p++;
    }
    */
    return EXIT_SUCCESS;
}