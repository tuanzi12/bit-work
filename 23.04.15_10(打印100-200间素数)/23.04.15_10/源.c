#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int main()
{
	
	for (int i = 101; i <= 200; i+=2)
	{
		int j = 0;
		for(j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				break;
			}
		}
		if (j > sqrt(i))
			printf("%d ", i);
	}
	return 0;
}