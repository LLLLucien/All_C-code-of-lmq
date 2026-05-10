#include <stdio.h>
int main()
{
    // 闰年
    //  1）被4整除且不能被100整除
    //  2）被400整除
    int year;
    printf("输入年份：");
    scanf("%d", &year);
    if ((0 == year % 4 && 0 != year % 100) || 0 == year % 400)
    {
        printf("%04d是闰年\n", year);
    }
    else
    {
        printf("%04d不是闰年\n", year);
    }

    // 成绩判断
    /*
    int score;
    printf("输入成绩：");
    scanf("%d", &score);
    //     s >=90 ->A
    // 90> s >=80 ->C
    // 80> s >=70 ->B
    // 70> s >=60 ->D
    // 60> s      ->E
    char g;
    if (score >= 90)
    {
        g = 'A';
    }
    else if (score >= 80) // 常见错误就是
                          // 还写了 score >= 80 && score <90
    {
        g = 'B';
    }
    else if (score >= 70)
    {
        g = 'C';
    }
    else if (score >= 60)
    {
        g = 'D';
    }
    else
    {
        g = 'E';
    }
    printf("分数：%d，等级：%c\n", score, g);
    */
    // 运用&&验证短路情况
    /*
    int a = 1;
    int b = 2;
    if (a < b && b++ >2)
    {

    }
    printf("%d\n",b);
    */
    //--------------------
    /*
    int age;
    printf("输入年龄：");
    scanf("%d", &age);

    if (age >= 18 && age < 70)
    {
        printf("OK!\n");
    }
    else
    {
        printf("No!\n");
    }
        */
    return 0;
}