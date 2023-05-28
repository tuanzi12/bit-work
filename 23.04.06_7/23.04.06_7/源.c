#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int num;
	scanf("%d", &num);
	if (num % 5 == 0)
		printf("YES");
	else
		printf("NO");
	return 0;
}