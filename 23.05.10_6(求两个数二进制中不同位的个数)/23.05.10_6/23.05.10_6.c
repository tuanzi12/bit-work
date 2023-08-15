#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int num1, num2,count=0;
	scanf("%d %d", &num1, &num2);
	for (int i = 0; i < 32; i++) 
	{
		if (((num1 >> i) & 1) != ((num2 >> i) & 1))
			count++;
	}
	printf("%d", count);
	return 0;
}