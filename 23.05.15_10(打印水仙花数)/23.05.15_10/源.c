#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int main()
{
	int count, tmp, sum;
	for (int i = 0; i < 100000; i++)
	{
		count = 1;
		tmp = i;
		sum = 0;
		while (tmp / 10)
		{
			count++;
			tmp = tmp / 10;
		}
		tmp = i;
		while (tmp)
		{
			sum += pow(tmp % 10, count);
			tmp = tmp / 10;
		}
		if (sum==i)
		{
			printf("%d\n",i);
		}
	}
	return 0;
}