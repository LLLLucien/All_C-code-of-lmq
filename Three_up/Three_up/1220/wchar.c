// 宽字符
// wchar.c
#include <stdio.h>
#include <wchar.h>
// i18n  Internationalization 国际化
// l10n  Localization 本地化
#include <locale.h> //本地化
int main()
{
    // 语言_地区.编码方式
    // CN指的是中国大陆，可以是zh_HK
    setlocale(LC_ALL, "zh_CN.UTF-8");
    // wide 宽字符：多字节字符
    wchar_t ch = L'王';
    wchar_t ch = L'😀';
    // 用#，自动加一个0x
    wprintf(L"字符=%lc,编码值=%#x\n", ch, ch);
    return 0;
}