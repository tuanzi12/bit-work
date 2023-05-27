#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int main()
{
	for (int i = 0; i <= 100000; i++)
	{
		int mid = i,sum=0,count=1;
		while (mid / 10)
		{
			count++;
			mid /= 10;
		}
		mid = i;
		while (mid)
		{
			sum += pow(mid % 10, count);
			mid /= 10;
		}
		if (sum == i)
			printf("%d是水仙花数\n", sum);
	}
	return;
}