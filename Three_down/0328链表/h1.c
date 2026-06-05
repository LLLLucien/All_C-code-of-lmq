// 二路归并
#include <stdio.h>
#include <stdlib.h>
int *TowSort(int a[], int len_a, int b[], int len_b, int *index);
int main()
{
    int a1[] = {2, 23, 24, 25};
    int b1[] = {2, 4, 5};
    int index = 0;
    int *n = TowSort(a1, 4, b1, 3, &index);
    // printf("--%d\n", index);
    for (int i = 0; i < index; i++)
    {
        printf("%d,", n[i]);
    }

    return 0;
}
int *TowSort(int a[], int len_a, int b[], int len_b, int *index)
{
    // int len_a = sizeof(a) / sizeof(a[0]);
    // int len_b = sizeof(b) / sizeof(b[0]);
    int *new = malloc(sizeof(int) * (len_a + len_b));

    int i = 0;
    int j = 0;
    int k = 0;
    // 直到都到达边界
    while (i < len_a || j < len_b)
    {
        // 如果a到达边界，则直接将2剩余内容存入b
        if (i == len_a)
        {
            // printf("1\n");
            new[k] = b[j];
            j++;
            k++;
            // 直接跳过，不需要判断
            continue;
        }
        // 如果b到底，同理a
        if (j == len_b)
        {
            // printf("2\n");
            new[k] = a[i];
            i++;
            k++;
            continue;
        }
        // b为小的，则存入b，j后移
        if (a[i] > b[j])
        {
            // printf("3\n");
            new[k] = b[j];
            j++;
        }
        // 相等都存入，i，j都后移
        else if (a[i] == b[j])
        {
            //  printf("4\n");
            new[k] = a[i];
            k++;
            new[k] = b[j];
            i++;
            j++;
        }
        else if (a[i] < b[j])
        {
            // printf("5\n");
            new[k] = a[i];
            i++;
        }
        // 最后增加k
        k++;
    }

    *index = k;
    return new;
}