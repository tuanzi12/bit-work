#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int i, num;
	scanf("%d", &num);
	for (i = 31; i >0; i -= 2)
	{
		printf("%d", (num >> i) & 1);
	}
	printf("\n");
	for (i = 32; i > 1; i -= 2)
	{
		printf("%d", (num >> i) & 1);
	}
	return 0;
}