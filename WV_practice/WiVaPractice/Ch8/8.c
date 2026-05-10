/*改编程题7，使其提示用户输入每个学生5门测验的成绩，一
共有5个学生。然后计算每个学生 的总分和平均分，以及每门测验
的平均分、高分和低分*/

#include <stdio.h>
#define count 5

int main()
{
    double sum = 0;
    int max = 0;
    int min = 0;
    int R[count][count] = {0};
    for (int i = 0; i < count; i++)
    {
        printf("输入第%d位学生的五门成绩:", i + 1);
        for (int j = 0; j < count; j++)
        {
            scanf("%d", &R[i][j]);
        }
    }

    for (int i = 0; i < count; i++)
    {
        max = R[i][0];
        min = R[i][0];
        for (int j = 0; j < count; j++)
        {
            max = max > R[i][j] ? max : R[i][j];
            min = min > R[i][j] ? min : R[i][j];
            sum += R[i][j];
        }

        printf("第%d位学生的总分:%.2f,平均分:%.2f\n", i + 1, sum, sum / 5.0);
        sum = 0;
    }
    for (int i = 0; i < count; i++)
    {
        max = R[0][i];
        min = R[0][i];
        for (int j = 0; j < count; j++)
        {
            max = max > R[j][i] ? max : R[j][i];
            min = min < R[j][i] ? min : R[j][i];
            sum += R[j][i];
        }
        printf("第%d门的平均分:%.2f,最高分:%d,最低分:%d\n", i + 1, sum / 5.0, max, min);
        sum = 0;
    }
    printf("\n");
    return 0;
}
