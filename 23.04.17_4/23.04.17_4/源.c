#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int evaluation_max(int a[10])
{
	int i = 0,max=0;
	for (i = 0; i < 9; i++)
		max = a[++i] >  max ? a[i] : max;
	return max;
}
int main()
{
	int a[10] = { 0 }, max = 0;
	printf("请输入十个整数：");
	for (int i = 0; i < 10; i++)
		scanf("%d", &a[i]);
	max=evaluation_max(a);
	printf("最大值为:%d", max);
	return;
}
