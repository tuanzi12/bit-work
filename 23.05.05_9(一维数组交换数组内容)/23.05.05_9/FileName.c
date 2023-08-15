#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int i;
	int a[5];
	int b[5];
	printf("请输入a数组的5个值\n");
	for (i = 0; i < 5; i++)
		scanf("%d", &a[i]);
	printf("请输入b数组的5个值\n");
	for (i = 0; i < 5; i++)
		scanf("%d", &b[i]);
	for (i = 0; i < 5; i++)
	{
		int mid=a[i];
		a[i] = b[i];
		b[i] = mid;
	}
	printf("交换之后数组为：\n");
	for (i = 0; i < 5; i++)
		printf("%d", a[i]);
	printf("\n");
	for (i = 0; i < 5; i++)
		printf("%d", b[i]);
	return 0;
}