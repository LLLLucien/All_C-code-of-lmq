#include "ShortURL.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// 初始化存放短链接的数组
void Init_ShortURL(ShortURL *url)
{
    if (url == NULL)
    {
        fprintf(stderr, "错误：传入的url指针为空！\n");
        exit(1); // 用不同错误码区分“空指针”和“内存分配失败”
    }

    long num = URL_NUMBER; // 默认放30个链接
    url->Unum = num;
    url->Uarr = (char **)malloc(url->Unum * sizeof(char *));
    if (url->Uarr == NULL)
    {
        perror("初始Uarr内存分配失败");
        exit(1);
    }
}
// 给数组动态分配链接容量
void Init_ShortURLsize(ShortURL *url)
{
    if (url == NULL)
    {
        fprintf(stderr, "错误:url指针为空!\n");
        exit(1); // 空指针失败
    }
    if (url->Unum <= 0)
    {
        fprintf(stderr, "错误:Unum必须大于0!\n");
        exit(1); // 参数非法失败
    }
    if (url->Uarr == NULL)
    {
        fprintf(stderr, "错误:Uarr未初始化!\n");
        exit(1); // 参数非法失败
    }

    // 分配30个空间来存放大小
    url->Usize = (long *)malloc(url->Unum * sizeof(long));
    if (url->Usize == NULL)
    {
        perror("Usize内存分配失败");
        exit(1);
    }
    // 遍历每个链接地址，为其分配字符空间
    for (long i = 0; i < url->Unum; i++)
    {
        // 对应的数组来存取其大小的标志
        url->Usize[i] = URL_SIZE;
        // 给第i个链接分配140字节的字符空间（存139个可见字符+'\0'）
        url->Uarr[i] = (char *)malloc(url->Usize[i] * sizeof(char));
        // 初始化字符空间为0，避免脏数据
        if (url->Uarr[i] == NULL)
        {
            perror("初始内存分配失败");
            // 释放已分配的Uarr[i]和Usize，避免内存泄漏
            for (long j = 0; j < i; j++)
            {
                free(url->Uarr[j]);
            }
            // 释放Uarr指针数组的内存
            free(url->Uarr);
            // 释放Usize容量数组的内存
            free(url->Usize);
            // 置空指针，避免后续访问野指针
            url->Uarr = NULL;
            url->Usize = NULL;
            exit(1);
        }

        memset(url->Uarr[i], 0, url->Usize[i]);
    }
}
// 初始化存放原来 链接的数组
void Init_LongURL(LongURL *url)
{
    if (url == NULL)
    {
        fprintf(stderr, "错误：传入的url指针为空！\n");
        exit(1); // 用不同错误码区分“空指针”和“内存分配失败”
    }

    long num = URL_NUMBER; // 默认放30个链接
    url->Unum = num;
    url->Uarr = (char **)malloc(url->Unum * sizeof(char *));
    if (url->Uarr == NULL)
    {
        perror("初始Uarr内存分配失败");
        exit(1);
    }
}
// 给数组动态分配链接容量
void Init_LongURLsize(LongURL *url)
{
    if (url == NULL)
    {
        fprintf(stderr, "错误:url指针为空!\n");
        exit(1); // 空指针失败
    }
    if (url->Unum <= 0)
    {
        fprintf(stderr, "错误:Unum必须大于0!\n");
        exit(1); // 参数非法失败
    }
    if (url->Uarr == NULL)
    {
        fprintf(stderr, "错误:Uarr未初始化!\n");
        exit(1); // 参数非法失败
    }

    // 分配30个空间来存放大小
    url->Usize = (long *)malloc(url->Unum * sizeof(long));
    if (url->Usize == NULL)
    {
        perror("Usize内存分配失败");
        exit(1);
    }
    // 遍历每个链接地址，为其分配字符空间
    for (long i = 0; i < url->Unum; i++)
    {
        // 对应的数组来存取其大小的标志
        url->Usize[i] = URL_SIZE;
        // 给第i个链接分配140字节的字符空间（存139个可见字符+'\0'）
        url->Uarr[i] = (char *)malloc(url->Usize[i] * sizeof(char));
        // 初始化字符空间为0，避免脏数据
        if (url->Uarr[i] == NULL)
        {
            perror("初始内存分配失败");
            // 释放已分配的Uarr[i]和Usize，避免内存泄漏
            for (long j = 0; j < i; j++)
            {
                free(url->Uarr[j]);
            }
            // 释放Uarr指针数组的内存
            free(url->Uarr);
            // 释放Usize容量数组的内存
            free(url->Usize);
            // 置空指针，避免后续访问野指针
            url->Uarr = NULL;
            url->Usize = NULL;
            exit(1);
        }

        memset(url->Uarr[i], 0, url->Usize[i]);
    }
}

void show_main_menu()
{
    // 进入菜单先清屏
    CLEAR_SCREEN();

    // 主菜单UI排版（纯printf实现，对齐+分隔线增强可读性）
    printf("=============================================\n");
    printf("              短链接管理系统 v1.0            \n");
    printf("=============================================\n");
    printf("               【功能菜单】                    \n");
    printf("---------------------------------------------\n");
    printf("  1. 生成短链接      \n");
    printf("  2. 解析短链接                 \n");
    printf("  3. 访问短链接              \n");
    printf("  4. 查看短链接数据记录       \n");
    // printf("  5. 模拟访问短链接（累计访问次数）       \n");
    printf("  0. 退出系统                                \n");
    printf("---------------------------------------------\n");
    printf("  提示:选择功能后按回车，自动清理屏幕       \n");
    printf("=============================================\n");
    printf("请输入功能编号（0-4）:");
}

// 输入函数(传入数组与对应的序号)
void InputURL(LongURL *lurl, long i)
{
    int ch;                 // 接收getchar
    long input_Usize = 0;   // 链接大小的标志
    int has_valid_char = 0; // 有效内容的标志
    // safe_clear_buffer();
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        if (ch == ' ')
            continue; // 识别到空格就跳过
        has_valid_char = 1;
        if (input_Usize >= lurl->Usize[i] - 1)
        {
            long new_size = lurl->Usize[i] * 2;
            char *new_lurl = realloc(lurl->Uarr[i], new_size * sizeof(char));
            if (new_lurl == NULL)
            {
                perror("内存扩容失败");
                free(lurl->Uarr[i]);
                exit(1);
            }
            else
            {
                lurl->Uarr[i] = new_lurl;
                lurl->Usize[i] = new_size;
            }
        }
        lurl->Uarr[i][input_Usize++] = (char)ch;
    }
    if (!has_valid_char || input_Usize == 0)
    {
        CLEAR_SCREEN();
        printf("❌ 错误：长链接不能为空！请重新输入\n");
        printf("---------------------------------------------\n");
        // 递归调用，要求用户重新输入（直到输入有效内容）
        InputURL(lurl, i);
        return; // 递归后直接返回，避免重复处理
    }
    lurl->Uarr[i][input_Usize] = '\0';
}

// 62进制字符表（0-9, a-z, A-Z）
const char base62_chars[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

// 哈希函数
unsigned long Turn_to_hash(const char *str)
{
    unsigned long hash = 0;
    // 遍历字符串每个字符，直到结束符'\0'
    while (*str)
    {
        // 核心哈希公式：乘质数131 + 当前字符的无符号ASCII码
        hash = hash * 131 + (unsigned char)*str++;
    }
    return hash;
}
// 长链接变短链接
void hash_to_base62(unsigned long num, char *result)
{
    int i = 0;
    char temp[32]; // 临时存储逆序的62进制字符

    // 处理哈希值为0的特殊情况（空字符串的哈希值）
    if (num == 0)
    {
        result[0] = base62_chars[0];
        result[1] = '\0'; // 字符串结束符
        return;
    }

    // 核心：取余法转62进制（结果先逆序存在temp里）
    while (num > 0)
    {
        temp[i++] = base62_chars[num % BASE]; // 余数对应62进制字符
        num = num / BASE;                     // 商继续参与循环
    }
    temp[i] = '\0'; // 临时数组加结束符

    // 逆序temp数组，得到正确的62进制字符串
    int len = strlen(temp);
    for (int j = 0; j < len; j++)
    {
        result[j] = temp[len - 1 - j];
    }
    result[len] = '\0'; // 最终结果加结束符
}
// 选择链接时长
int Chose_URL_State()
{

    printf("🔍 请选择短链接有效期：\n");
    printf("\t1. 1天\t\n\t2. 7天\t\n\t3. 365天\t\n\t4. 自定义\t\n\t5. 永久\t\n");
    printf("---------------------------------------------\n");
    int url_state = 0;
    printf("请输入序号:\n");
    // 检查scanf的返回值，判断是否读取到有效数字

    int scan_result = scanf("%d", &url_state);
    safe_clear_buffer();
    if (scan_result != 1)
    { // 读取失败（输入非数字）
        // 清空缓冲区里的错误输入（比如dasd）

        CLEAR_SCREEN();
        printf("输入的不是数字！请重新输入\n");
        return Chose_URL_State(); // 重新调用
    }
    switch (url_state)
    {
    case 1:
        return 1;
        break;
    case 2:
        return 7;
        break;
    case 3:
        return 365;
        break;
    case 4:
        CLEAR_SCREEN();
        printf("请输入定义天数:\n");
        int temp_day = 0;
        // 同样检查自定义天数的输入是否有效

        scan_result = scanf("%d", &temp_day);
        safe_clear_buffer();
        if (scan_result != 1 || temp_day <= 0)
        { // 非数字或负数都不行
            CLEAR_SCREEN();
            printf("天数必须是正整数！请重新输入\n");
            return Chose_URL_State();
        }
        return temp_day;
        break;
    case 5:
        return 0;
        break;

    // case -1:
    //     return -1;
    //     break;
    default:
        CLEAR_SCREEN();
        printf("请输入正确的序号!\n");

        return Chose_URL_State();
        break;
    }
}
// 清除缓冲区
void safe_clear_buffer()
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
        ;
}

// 解析短链接，返回对应长链接的下标（-1表示未找到）
long parse_short_url(ShortURL *surl, long url_count, const char *input_short_url)
{
    // 遍历所有已生成的短链接
    for (long i = 0; i < url_count; i++)
    {
        // 字符串匹配（注意：strcmp返回0表示相等）
        if (strcmp(surl->Uarr[i], input_short_url) == 0)
        {
            return i; // 返回匹配的下标
        }
    }
    return -1; // 未找到
}
