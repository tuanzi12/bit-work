#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define Max 100
int main()
{
	int i = 0;
	for (i = 0; i < Max; i++)
	{
		if (i % 3 == 0)
			printf(" %d ", i);
	}
	return 0;
}
