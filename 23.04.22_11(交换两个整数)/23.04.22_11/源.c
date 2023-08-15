#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void change(int* x, int* y)
{
	int mid=*y;
	*y = *x;
	*x = mid;
}
int main()
{
	int num1, num2;
	printf("请输入两个数进行交换\n");
	scanf("%d %d", &num1, &num2);
	change(&num1, &num2);
	printf("交换之后的两个数为\n");
	printf("%d %d", num1, num2);
	return 0;
}