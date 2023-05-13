#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void change(int *i, int *j)
{
	int mid;
	mid = *i;
	*i = j;
	*j = mid;
	return 0;
}
int main()
{
	int i, j;
	scanf("%d", &i);
	scanf("%d", &j);
	change(&i, &j);
	printf("%d%d", i, j);
	return 0;
}