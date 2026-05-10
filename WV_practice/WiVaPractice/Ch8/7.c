/*写程序读取一个5×5的整数数组，然后显示出每行的和与每列
的和*/
#include <stdio.h>
#define count 5
int main()
{
    int Rsum = 0;
    int Csum = 0;
    int R[count][count] = {0};
    for (int i = 0; i < count; i++)
    {
        printf("Enter row %d:", i + 1);
        for (int j = 0; j < count; j++)
        {
            scanf("%d", &R[i][j]);
        }
    }
    printf("Row sum:\t");
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            Rsum += R[i][j];
        }
        printf("%d ", Rsum);
        Rsum = 0;
    }
    printf("\n");
    printf("Column sum:\t");
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            Csum += R[j][i];
        }
        printf("%d ", Csum);
        Csum = 0;
    }
    printf("\n");

    return 0;
}