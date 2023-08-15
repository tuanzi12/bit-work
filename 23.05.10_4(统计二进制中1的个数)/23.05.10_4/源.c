#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int i,num=-1,count=0;
	scanf("%d", &num);
	while (num)
	{
		count++;
		num = num & (num - 1);
	}
	printf("%d", count);
	return 0;
}
