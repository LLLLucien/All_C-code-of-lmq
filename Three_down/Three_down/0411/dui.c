// 大顶堆
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
void dui(int arr[], int size);
void exchange(int *a, int *b);
void printTree(int arr[], int size);
void Sortdui(int arr[], int size);
int main(int argc, char const *argv[])
{
    // 下标为0的是根节点
    int arr[] = {9, 32, 7, 21, 13, 42, 5, 1, 81, 4, 77, 2, 55};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("原数组:{");
    for (int i = 0; i < size; i++)
    {
        printf("%d,", arr[i]);
    }
    printf("\b}\n");
    printf("大顶堆数组:{");
    dui(arr, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d,", arr[i]);
    }
    printf("\b}\n");
    printf("堆排序后数组:{");
    Sortdui(arr, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d,", arr[i]);
    }
    printf("\b}\n");

    printTree(arr, size);
    printf("\b \n");
    return 0;
}

void dui(int arr[], int size)
{
    // int count = 0;
    int i, l, r;
    i = size / 2 - 1; // 最后一个分支结点
    while (i >= 0)
    {
        int cur = i;
        while (1)
        {
            l = 2 * cur + 1;
            r = 2 * cur + 2;
            int max = cur;
            if (l < size && arr[max] < arr[l])
            {
                max = l;
            }
            if (r < size && arr[max] < arr[r])
            {
                max = r;
            }
            if (max == cur)
            {
                break;
            }
            exchange(&arr[max], &arr[cur]);
            cur = max;
        }
        i--;
    }
}
void exchange(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void Sortdui(int arr[], int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        exchange(&arr[0], &arr[i]);
        dui(arr, i); // 缩小范围，不包括最后一个，把剩下的视作另一个堆
    }
}

void printTree(int arr[], int size)
{
    if (size == 0)
        return;

    // 1. 计算树的高度（层数）
    int height = 0;
    while ((1 << height) - 1 < size)
    {
        height++;
    }

    int level = 0; // 当前层数（从0开始）
    int start = 0; // 当前层第一个元素的下标
    int count = 1; // 当前层最多有几个元素

    printf("完美三角形堆结构：\n\n");

    // 2. 逐层打印
    while (start < size)
    {
        // 计算当前层的前置空格数（让这一层居中）
        int frontSpaces = (1 << (height - level)) - 1;

        // 计算当前层元素之间的空格数
        int betweenSpaces = (1 << (height - level + 1)) - 1;

        // 打印前置空格
        for (int i = 0; i < frontSpaces; i++)
        {
            printf(" ");
        }

        // 打印当前层的元素
        for (int i = 0; i < count && start + i < size; i++)
        {
            printf("%d", arr[start + i]);

            // 打印元素之间的空格（最后一个元素不打）
            if (i != count - 1)
            {
                for (int j = 0; j < betweenSpaces; j++)
                {
                    printf(" ");
                }
            }
        }

        printf("\n\n"); // 每层之间空一行，更美观

        // 准备下一层
        start += count;
        count *= 2;
        level++;
    }
}