#include <stdio.h>
#include <string.h>
struct Date
{
    int year;
    int month;
    int day;
};

struct Student
{
    // 姓名
    char *name;
    // 成绩
    int score;
    // 性别
    char sex;
    // 生日
    struct Date birthday; // 嵌套
};

void Pstruct(struct Student *s)
{
    printf("%s\t%c\t%d\t%04d-%02d-%02d\n", s->name, s->sex, s->score,
           s->birthday.year,
           s->birthday.month,
           s->birthday.day);
}

void update_score(struct Student *s, int n)
{
    s->score = n;
    // 等价
    (*s).score = n;
}
void update_name(struct Student *s, char *n)
{
    s->name = n;
}
void update_sex(struct Student *s, char n)
{
    s->sex = n;
}

int main()
{
    struct Student s1 = {"bob", 89, 'M', {2000, 7, 30}};
    // 可以缺失，但是得按顺序
    struct Student s2 = {"alice", 89};
    // 也可指定,指定不需要顺序
    struct Student s3 = {.sex = 'F', .score = 100, .name = "jack", .birthday = {2000, 4, 13}};

    struct Student s4;
    s2.sex = 'F';
    s4.score = 99;
    s4.sex = 'M';
    // 名字是字符数组，不能直接赋值
    // 需要这样
    s4.name = "tom";
    s4.birthday.year = 2005;
    s4.birthday.month = 2;
    s4.birthday.day = 25;
    // strcpy(s4.name, "tom");
    Pstruct(&s1);
    update_name(&s1, "AAA");
    update_score(&s1, 100);
    Pstruct(&s1);
    Pstruct(&s2);
    Pstruct(&s3);
    Pstruct(&s4);

    // Pstruct(s2);
    // Pstruct(s3);
    // Pstruct(s4);

    return 0;
}