#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int i,count=0;
	for (i = 0; i <= 100; i++)
	{
		if (i / 10 == 9)
			count++;
		if (i % 10 == 9)
			count++;
	}
	printf("100以内9的个数是：%d", count);
	return;
}