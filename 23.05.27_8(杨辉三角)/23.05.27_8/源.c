#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define max 10
int main()
{
	int i,j;
	int a[max][max];
	for (i = 0; i < max; i++)
	{
		a[i][0] = 1;
		a[i][i] = 1;
	}
	for (i = 2; i < max; i++)
	{
		for (j = 1; j < i; j++)
			a[i][j] = a[i - 1][j-1] + a[i-1][j];
	}
	for (i = 0; i < max; i++)
	{
		for (j = 0; j <= i; j++)
			printf(" %d ", a[i][j]);
		printf("\n");
	}
	return 0;
}
