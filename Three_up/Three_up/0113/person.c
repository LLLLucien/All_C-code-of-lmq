#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_SIZE 16
typedef struct
{
    int year;
    int month;
    int day;
} Date;

typedef struct Person
{
    char name[NAME_SIZE];
    int age;
    Date birthday;
    struct Person *lover; // 可以一开始不分配
} Person;

int main()
{
    Person p2 = {"bob"};
    Person p1 = {"alice", 21, {2004, 1, 13}, &p2};
    p2.lover = &p1;
    printf("%s,%d,%d-%d-%d\n",
           p1.name, p1.age,
           p1.birthday.year, p1.birthday.month, p1.birthday.day);
    return 0;
}