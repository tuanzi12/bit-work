#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	printf("请输入两个数进行两个变量的交换");
	int num1, num2;
	scanf("%d %d", &num1, &num2);
	num1 = num1 ^ num2;
	num2 = num1 ^ num2;
	num1 = num1 ^ num2;
	printf("%d %d", num1, num2);
}