#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int a;
	scanf("%d", &a);
	int mid = a,sum=a;
	for (int i = 0; i < 4; i++)
	{
		mid = mid * 10 + a;
		sum += mid;
	}
	printf("%d", sum);
	return;
}
