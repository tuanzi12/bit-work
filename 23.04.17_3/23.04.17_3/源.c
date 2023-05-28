#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int outcome;
	int i = 0, j = 0;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= i; j++)
		{
			outcome = i * j;
			printf("%d*%d=%d ", i, j, outcome);
		}
		printf("\n");
	}
	return;
}
