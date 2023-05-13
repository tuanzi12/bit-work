#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int is_leap_year(int i)
{
    return  ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0));
}
int main()
{
    int i,year = 0;
    printf("请输入要判断是否为闰年的年份");
    scanf("%d", &year);
    if (is_leap_year(year) == 1)
        printf("%d是闰年 ", year);
    else
        printf("%d不是闰年", year);
return 0;
}