#include <stdio.h>
int main()
{
	int i, j,sum;
	for (i = 1; i < 10; i++)
	{
		for (j = 1; j<=i; j++)
		{
			sum = i * j;
			printf("%d*%d=%d ", i, j, sum);
		}
		printf("\n");
	}
	return 0;
}