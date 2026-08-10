// my.c
// MYSQL C API
#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HOST "127.0.0.1"
#define USER "tom"
#define PASSWD "123456"
#define DB "hr"
#define PORT 3306

int main(void)
{
    // 1.创建结构体,初始化
    MYSQL *conn = mysql_init(NULL);
    if (conn == NULL)
    {
        perror("mysql_init error\n");
        return EXIT_FAILURE;
    }
    printf("初始化成功\n");

    // 2.连接数据库
    if (!mysql_real_connect(conn, HOST, USER, PASSWD, DB, PORT, NULL, 0))
    {
        fprintf(stderr, "连接失败：%d ,%s\n", mysql_errno(conn), mysql_error(conn));
        mysql_close(conn);
        return EXIT_FAILURE;
    }
    printf("连接成功\n");

    // ========== 预编译 INSERT（防注入）==========
    {
        fprintf(stderr, "执行失败：%d ,%s\n", mysql_errno(conn), mysql_error(conn));
        mysql_close(conn);
        return EXIT_FAILURE;
    }
    printf("执行成功\n");

    // 4.获取结果集
    MYSQL_RES *res = mysql_store_result(conn);
    if (res == NULL)
    {
        fprintf(stderr, "获取结果集失败：%d ,%s\n", mysql_errno(conn), mysql_error(conn));
        mysql_close(conn);
        return EXIT_FAILURE;
    }
    printf("获取结果集成功\n");
    printf("行数:%ld,列数:%d\n", res->row_count, res->field_count);

    // 5.遍历结果集

    MYSQL_FIELD *field;
    // 5.1 获取列字段信息
    // 遍历字段
    while ((field = mysql_fetch_field(res)) != NULL)
    {
        printf("%s\t", field->name);
    }
    printf("\n");

    /*=======================================================================
     * 获得所有字段构成的数组 带s
     *  field = mysql_fetch_fields(res);
     *  for (int i = 0; i < res->field_count; i++)
     *  {
     *      printf("%s\t", field[i].name);
     *  }
     *=======================================================================
     */

    // 5.2 获取列数
    // MYSQL_ROW 本质上是链表的一个节点，存储一行数据
    MYSQL_ROW row;

    // 5.3 获取行数
    int cols = res->field_count;

    // 5.4 当行不为空时，获取行数据
    while ((row = mysql_fetch_row(res)) != NULL)
    {
        for (int i = 0; i < cols; i++)
        {
            printf("%s\t", row[i]);
        }
        printf("\n");
    }
    mysql_free_result(res);
    return 0;
}