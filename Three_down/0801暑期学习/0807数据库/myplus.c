// myplus.c
// MYSQL C API — 预编译 INSERT 防注入
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
    // 1.初始化
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

    // 3.预编译 INSERT（防注入）
    MYSQL_STMT *stmt = mysql_stmt_init(conn);
    char *sql = "INSERT INTO dept VALUES(NULL, ?, ?)";

    // 用户输入（即使含恶意 SQL 也是纯数据）
    char *name = "test";
    char *city = "aaa";

    if (mysql_stmt_prepare(stmt, sql, strlen(sql)))
    {
        fprintf(stderr, "prepare失败: %s\n", mysql_stmt_error(stmt));
        goto cleanup;
    }

    MYSQL_BIND bind[2];
    memset(bind, 0, sizeof(bind));
    bind[0].buffer_type = MYSQL_TYPE_STRING;
    bind[0].buffer = name;
    bind[0].buffer_length = strlen(name);
    bind[1].buffer_type = MYSQL_TYPE_STRING;
    bind[1].buffer = city;
    bind[1].buffer_length = strlen(city);

    if (mysql_stmt_bind_param(stmt, bind))
    {
        fprintf(stderr, "bind失败: %s\n", mysql_stmt_error(stmt));
        goto cleanup;
    }
    if (mysql_stmt_execute(stmt))
    {
        fprintf(stderr, "执行失败: %s\n", mysql_stmt_error(stmt));
        goto cleanup;
    }
    printf("INSERT成功，影响行数: %lu\n", mysql_stmt_affected_rows(stmt));

cleanup:
    mysql_stmt_close(stmt);
    mysql_close(conn);
    return 0;
}
