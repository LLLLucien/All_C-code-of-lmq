#ifndef SHORTURL_H
#define SHORTURL_H

#define CLEAR_SCREEN() system("clear")
#define URL_NUMBER 100
#define URL_SIZE 140
#define BASE 62
typedef struct ShortURL
{
    char **Uarr; // 指向字符指针的指针,存放链接的数组
    long Unum;   // 存放的数量
    long *Usize; // 每一个数组的容量
} ShortURL;
typedef struct LongURL
{
    char **Uarr; // 指向字符指针的指针,存放链接的数组
    long Unum;   // 存放的数量
    long *Usize; // 数组的容量
} LongURL;
void Init_ShortURL(ShortURL *url);     // 初始化短链接数组
void Init_ShortURLsize(ShortURL *url); // 给数组动态分配链接容量
void Init_LongURL(LongURL *url);       // 初始化原来链接数组
void Init_LongURLsize(LongURL *url);   // 给数组动态分配链接容量

void InputURL(LongURL *lurl, long i);                 // 输入函数(传入数组与对应的序号)
void show_main_menu();                                // 菜单
unsigned long Turn_to_hash(const char *str);          // 哈希函数
void hash_to_base62(unsigned long num, char *result); // 长链接变短链接
int Chose_URL_State();                                // 选择链接时效
void safe_clear_buffer();                             // 清空缓冲区

// 查询对应原链接
long parse_short_url(ShortURL *surl, long url_count, const char *input_short_url);
#endif