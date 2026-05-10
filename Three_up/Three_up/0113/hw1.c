// 品牌
// - 名称 - 创建时间 - 产品列表
// 产品
// - 名称 - 价格 - 品牌（结构体、指针？）

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Date // 创建时间
{
    int year;
    int month;
    int day;
} Date;
typedef struct Product // 产品
{
    char name[16];
    int price;
    struct Brand *brand; // 使用指针
} Product;
typedef struct Brand // 品牌
{
    char name[16];
    Date biuld_time;
    Product *product;
} Brand;

int main()
{

    Brand XiaoMi = {"小米", {2000, 1, 1}};

    XiaoMi.product = malloc(sizeof(Product) * 3);
    if (XiaoMi.product == NULL)
    {
        perror("内存分配失败");
        return EXIT_FAILURE;
    }

    strcpy(XiaoMi.product[0].name, "平板");
    XiaoMi.product[0].price = 2799;
    XiaoMi.product[0].brand = &XiaoMi;
    strcpy(XiaoMi.product[1].name, "手机");
    XiaoMi.product[1].price = 8888;
    XiaoMi.product[1].brand = &XiaoMi;
    strcpy(XiaoMi.product[2].name, "洗衣机");
    XiaoMi.product[2].price = 799;
    XiaoMi.product[2].brand = &XiaoMi;

    printf("品牌名称：%s\n", XiaoMi.name);
    printf("创建时间：%d-%d-%d\n", XiaoMi.biuld_time.year,
           XiaoMi.biuld_time.month,
           XiaoMi.biuld_time.day);

    printf("\n拥有的产品:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%s\t价格：%d\t品牌：%s\n", XiaoMi.product[i].name,
               XiaoMi.product[i].price,
               XiaoMi.product[i].brand->name);
    }
    free(XiaoMi.product);
    return 0;
}