#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ShortURL.h"
/*- 生成短地址
  - 有效期：1、n、永久
- 查看所以短地址/原始地址
- 查询短地址
- 加入统计：查询次数、短地址访问次数*/
int main()
{
    ShortURL surl;
    LongURL lurl;
    Init_ShortURL(&surl);
    Init_ShortURLsize(&surl);
    Init_LongURL(&lurl);
    Init_LongURLsize(&lurl);
    int url_state[URL_NUMBER] = {0};
    int choice;
    long url_count = 0;

    int parse_count[URL_NUMBER] = {0};            // 解析次数（初始0）
    int visit_count[URL_NUMBER] = {0};            // 访问次数（初始0）
    char create_time[URL_NUMBER][URL_SIZE] = {0}; // 短链接的创建时间

    while (1)
    {
        // 调用主菜单函数
        show_main_menu();
        // 读取用户选择
        scanf("%d", &choice);
        safe_clear_buffer();
        CLEAR_SCREEN();

        // 功能分支
        switch (choice)
        {
        case 1:
            printf("\n=============================================\n");
            printf("                 生成短链接                    \n");
            printf("=============================================\n");
            // 选择链接时效
            url_state[url_count] = Chose_URL_State();
            CLEAR_SCREEN();
            if (url_state[url_count] == 0)
            {
                printf("---------------------------------------------\n");
                printf("           已选择短链接时效为：永久              \n");
                printf("---------------------------------------------\n");
            }
            else
            {
                printf("---------------------------------------------\n");
                printf("           已选择短链接时效为:%d天              \n",
                       url_state[url_count]);
                printf("---------------------------------------------\n");
            }
            printf("请输入一个网页链接:\n");
            // 输入链接的函数
            InputURL(&lurl, url_count);
            // 使用哈希函数转化
            unsigned long hashNum = Turn_to_hash(lurl.Uarr[url_count]);
            // 使用62进制转化
            hash_to_base62(hashNum, surl.Uarr[url_count]);

            time_t now = time(NULL);
            // 转换为本地时间结构体
            struct tm *local_tm = localtime(&now);
            // 格式化为字符串
            strftime(create_time[url_count], URL_SIZE, "%Y-%m-%d %H:%M:%S", local_tm);
            printf("---------------------------------------------\n");
            printf("✅ 短链接生成成功！\n");
            printf("├─ 原始长链接：%s\n", lurl.Uarr[url_count]);
            printf("├─ 生成短链接：%s\n", surl.Uarr[url_count]);
            if (url_state[url_count] == 0)
                printf("├─ 有效期    ：永久\n");
            else
                printf("├─ 有效期    ：%d天\n", url_state[url_count]);
            printf("└─ 创建时间 ：%s\n", create_time[url_count]);
            printf("=============================================\n");
            url_count++;
            break;
        case 2:
            if (url_count == 0)
            {
                printf("=============================================\n");
                printf("               暂无已生成的短链接！             \n");
                printf("=============================================\n");
                break;
            }
            printf("\n\n=============================================\n");
            printf("                 解析短链接             \n");
            printf("=============================================\n");
            // printf("               请选择查询模式：\n");
            // printf("---------------------------------------------\n");
            // printf("1. 查看所有短链接\n");
            // printf("2. 查询指定短链接\n");
            // printf("---------------------------------------------\n");
            // printf("请输入选项（1/2）：");

            // int check_choice;
            // int check_scan_res = scanf("%d", &check_choice);
            // safe_clear_buffer();
            // if (check_scan_res != 1 || (check_choice != 1 && check_choice != 2))
            // {
            //     printf("输入错误！返回主菜单。\n");
            //     break;
            // }
            // if (check_choice == 1)
            // {
            // CLEAR_SCREEN();
            // printf("\n=============================================\n");
            // printf("                 所有短链接列表             \n");
            // printf("=============================================\n");
            // for (int i = 0; i < url_count; i++)
            // {
            //     if (i > 0)
            //         printf("---------------------------------------------\n");
            //     printf("原链接：%s\n", lurl.Uarr[i]);
            //     printf("对应短链接：%s\n", surl.Uarr[i]);
            // }
            // printf("┌─────────┬────────────────────────┬──────────┬─────────────────────┐\n");
            // printf("│ 序号    │ 短链接                 │ 有效期   │ 创建时间            │\n");
            // printf("├─────────┼────────────────────────┼──────────┼─────────────────────┤\n");

            // 列表内容（循环输出）
            // for (long i = 0; i < url_count; i++)
            // {
            //     // 用 %-*s 左对齐，固定宽度，避免错位
            //     printf("│ %-7ld │ %-22s │",
            //            i + 1,
            //            surl.Uarr[i]); // 只取时间的前8位，或调整宽度
            //     if (url_state[i] == 0)
            //         printf(" 永久     │");
            //     else
            //         printf(" %-8d │", url_state[i]);
            //     printf(" %-8s │\n", create_time[i]);
            // }
            // printf("└─────────┴────────────────────────┴──────────┴─────────────────────┘\n");
            // printf("总计：共生成 %ld 条短链接\n", url_count);
            //     printf("=============================================\n");
            // }
            // else if (check_choice == 2)
            // {
            // CLEAR_SCREEN();
            // printf("\n=============================================\n");
            // printf("                 查询指定短链接             \n");
            // printf("=============================================\n");
            char query_short[URL_SIZE] = {0};
            printf("请输入要解析的短链接：");
            fgets(query_short, URL_SIZE, stdin);
            query_short[strcspn(query_short, "\n")] = '\0';

            long query_idx = parse_short_url(&surl, url_count, query_short);
            if (query_idx == -1)
            {
                printf("---------------------------------------------\n");
                printf("未找到该短链接的数据，请检查是否已创建！\n");
                printf("=========================================\n");
            }
            else
            {
                CLEAR_SCREEN();
                printf("\n=============================================\n");
                printf("                 解析短链接             \n");
                printf("=============================================\n");

                printf("                 解析成功！\n");
                printf("---------------------------------------------\n");
                printf("短链接【%s】\n", surl.Uarr[query_idx]);

                printf("原始链接：%s\n", lurl.Uarr[query_idx]);
                parse_count[query_idx]++;
                printf("=========================================\n");
            }

            break;
        case 3:
            printf("\n=============================================\n");
            printf("                 访问短链接                 \n");
            printf("=============================================\n");
            if (url_count == 0)
            {
                printf("           暂无已生成的短链接,无法访问！         \n");
                printf("=============================================\n");
                break;
            }

            char input_short[URL_SIZE] = {0};
            printf("请输入要访问的短链接：");
            // 读取输入的短链接（复用你的缓冲区清理逻辑）

            fgets(input_short, URL_SIZE, stdin);
            // 去掉fgets读取的换行符
            input_short[strcspn(input_short, "\n")] = '\0';

            // 调用查询函数
            long match_index = parse_short_url(&surl, url_count, input_short);
            if (match_index == -1)
            {
                printf("---------------------------------------------\n");
                printf("❌ 访问失败：未找到该短链接！\n");
                printf("=============================================\n");
            }
            else
            {
                printf("---------------------------------------------\n");
                printf("✅ 访问成功！\n");
                printf("成功转到原始链接 ：%s\n", lurl.Uarr[match_index]);
                visit_count[match_index]++;
                printf("=============================================\n");
            }
            break;
        case 4:
            printf("\n=============================================\n");
            printf("                   统计总览             \n");
            printf("=============================================\n");

            if (url_count == 0)
            {
                printf("         暂无已生成的短链接，无统计数据！\n");
                printf("=============================================\n");
                break;
            }
            // 子菜单：选择查看全部/单条统计
            printf("请选择统计模式：\n");
            printf("---------------------------------------------\n");
            printf("1. 查看所有短链接的统计数据\n");
            printf("2. 查询指定短链接的统计数据\n");
            printf("---------------------------------------------\n");
            printf("请输入选项（1/2）：");

            int sub_choice;
            int scan_res = scanf("%d", &sub_choice);
            safe_clear_buffer();
            if (scan_res != 1 || (sub_choice != 1 && sub_choice != 2))
            {
                printf("输入错误！返回主菜单。\n");
                break;
            }

            // 模式1：查看所有统计
            if (sub_choice == 1)
            {
                CLEAR_SCREEN();
                printf("\n=============================================\n");
                printf("                 所有短链接数据             \n");
                printf("=============================================\n");
                // for (int i = 0; i < url_count; i++)
                // {
                //     printf("原链接：%s\t", lurl.Uarr[i]);
                //     printf("短链接：%s\t有效期：%d天\n", surl.Uarr[i], url_state[i]);
                // }
                printf("┌─────────┬────────────────────────┬──────────┬─────────┬──────────┬─────────────────────┐\n");
                printf("│ 序号    │ 短链接                 │ 有效期   │ 查询次数│ 访问次数 │ 创建时间            │\n");
                printf("├─────────┼────────────────────────┼──────────┼─────────┼──────────┼─────────────────────┤\n");

                // 列表内容（循环输出）
                for (long i = 0; i < url_count; i++)
                {
                    // 用 %-*s 左对齐，固定宽度，避免错位
                    printf("│ %-7ld │ %-22s │",
                           i + 1,
                           surl.Uarr[i]); // 只取时间的前8位，或调整宽度
                    if (url_state[i] == 0)
                        printf(" 永久     │");
                    else
                        printf(" %-8d │", url_state[i]);

                    printf(" %-8d│ %-8d │",
                           parse_count[i],
                           visit_count[i]);
                    printf(" %-8s │\n", create_time[i]);
                }
                printf("└─────────┴────────────────────────┴──────────┴─────────┴──────────┴─────────────────────┘\n");
                printf("总计：共生成 %ld 条短链接\n", url_count);
                printf("=============================================\n");

                // printf("=========================================\n");
                // printf("短链接\t\t查询次数\t访问次数\t有效期\n");
                // printf("=========================================\n");
                // for (long i = 0; i < url_count; i++)
                // {
                //     // 格式化输出，对齐展示
                //     printf("创建时间：%s\n", create_time[i]);
                //     printf("%s\t\t%d\t\t%d\t\t%d\n",
                //            surl.Uarr[i],
                //            parse_count[i],
                //            visit_count[i],
                //            url_state[i]);
                // }
                // printf("=========================================\n");
            }
            // 模式2：查询指定短链接统计
            else if (sub_choice == 2)
            {
                CLEAR_SCREEN();
                printf("\n=============================================\n");
                printf("                 查询指定短链接数据             \n");
                printf("=============================================\n");
                char query_short[URL_SIZE] = {0};
                printf("请输入要查询的短链接：");
                fgets(query_short, URL_SIZE, stdin);
                query_short[strcspn(query_short, "\n")] = '\0';

                long query_idx = parse_short_url(&surl, url_count, query_short);
                if (query_idx == -1)
                {
                    printf("未找到该短链接的统计数据！\n");
                }
                else
                {
                    printf("=========================================\n");
                    printf("短链接【%s】的统计数据\n", surl.Uarr[query_idx]);
                    printf("---------------------------------------------\n");
                    // printf("对应长链接：%s\n", lurl.Uarr[query_idx]);
                    // printf("有效期：%d天（0=永久）\n", url_state[query_idx]);
                    printf("累计查询次数：%d次\n", parse_count[query_idx]);
                    printf("累计访问次数：%d次\n", visit_count[query_idx]);
                    printf("=========================================\n");
                }
            }
            break;
        // case 5:
        //     printf("【模拟访问短链接】\n");
        //     if (url_count == 0)
        //     {
        //         printf("暂无已生成的短链接！\n");
        //         break;
        //     }
        //     char visit_short[URL_SIZE] = {0};
        //     printf("请输入要访问的短链接：");
        //     fgets(visit_short, URL_SIZE, stdin);
        //     visit_short[strcspn(visit_short, "\n")] = '\0';

        //     long visit_idx = parse_short_url(&surl, url_count, visit_short);
        //     if (visit_idx == -1)
        //     {
        //         printf("未找到该短链接！\n");
        //     }
        //     else
        //     {
        //         visit_count[visit_idx]++;
        //         printf("访问成功！\n");
        //         printf("短链接：%s\n", surl.Uarr[visit_idx]);
        //         printf("当前累计访问次数：%d次\n", visit_count[visit_idx]);
        //     }
        //     break;
        case 0:
            printf("=============================================\n");
            printf("              短链接管理系统 v1.0            \n");
            printf("=============================================\n");
            printf("             感谢使用,系统退出!\n");
            printf("=============================================\n");
            for (long i = 0; i < surl.Unum; i++)
            {
                if (surl.Uarr[i] != NULL)
                { // 判空避免野指针
                    free(surl.Uarr[i]);
                    surl.Uarr[i] = NULL; // 置空防止野指针
                }
            }
            // 2. 释放 Uarr 本身（容器）
            if (surl.Uarr != NULL)
            {
                free(surl.Uarr);
                surl.Uarr = NULL;
            }
            // 3. 释放 Usize（动态分配的数组）
            if (surl.Usize != NULL)
            {
                free(surl.Usize);
                surl.Usize = NULL;
            }
            // ❌ 绝对不要 free(surl.Unum) —— Unum 是普通long变量

            // ========== 第二步：释放 LongURL 的内存（同ShortURL） ==========
            for (long i = 0; i < lurl.Unum; i++)
            {
                if (lurl.Uarr[i] != NULL)
                {
                    free(lurl.Uarr[i]);
                    lurl.Uarr[i] = NULL;
                }
            }
            if (lurl.Uarr != NULL)
            {
                free(lurl.Uarr);
                lurl.Uarr = NULL;
            }
            if (lurl.Usize != NULL)
            {
                free(lurl.Usize);
                lurl.Usize = NULL;
            }
            return 0;
        default:
            printf("输入错误,请选择0-4的功能编号!\n");
        }

        // 功能执行后暂停,按回车返回主菜单
        printf("\n按回车键返回主菜单...");
        // 清空输入缓冲区,避免回车残留导致异常
        safe_clear_buffer();
    }

    // show_main_menu();
    // printf("=========主菜单========\n");

    // InputURL(&lurl, 0);

    // hash_to_base62(Turn_to_hash(lurl.Uarr[0]), lurl.Uarr[0]);
    // //  TurnLongURL(surl.Uarr[0], surl.Usize);
    // printf("输出链接：%s\n", lurl.Uarr[0]);
    // // https://www.baidu.com/s?wd=C%E8%AF%AD%E8%A8%80%E9%95%BF%E7%BD%91%E5%9D%80%E8%BD%AC%E7%9F%AD%E7%BD%91%E5%9D%80&rsv_spt=1
    return 0;
}