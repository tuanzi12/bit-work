#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int i = 2;
	float tmp=1.00;
	for (; i <= 100; i++)
	{
		if (i % 2 == 0)
			tmp -= (float)1 / i;
		else
			tmp += (float)1 / i;
	}
	printf("%2f", tmp);
	return;
}
