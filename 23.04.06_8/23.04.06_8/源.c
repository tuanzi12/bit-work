#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int x;
	scanf("%d", &x);
	x < 0 ? printf("1") : (x == 0 ? printf("0") : printf("-1"));
	return 0;
}