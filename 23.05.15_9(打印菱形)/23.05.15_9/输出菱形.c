#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int line;
	int i=0;
	scanf("%d", &line);
	for (; i < line; i++)
	{
		int j = 0;
		for (j = 0; j < line-i; j++)
		{
			printf(" ");
			
		}
		printf("*\n");
	}
	return 0;
}