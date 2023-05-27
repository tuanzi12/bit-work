#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int row=0;
	scanf("%d", &row);
	int i,j;
	for (i = 1; i <= row+1; i++)
	{
		for (j = 1; j <= row+1 - i; j++)
		printf(" ");
		for (j = 1; j <= 2 * i - 1; j++)
			printf("*");
		printf("\n");
	}
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= i; j++)
			printf(" ");
		for (j = 1; j <= (row * 2 + 1) - 2 * i; j++)
		printf("*");
		printf("\n");
	}
		return;
}