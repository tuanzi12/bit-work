#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int m = 0;
	int n = 0;
	scanf("%d %d", &m, &n);
	int k = 0;
	while (k = m % n)
	{
		m = n;
		n = k;
	}
	printf("%d", n);
}
