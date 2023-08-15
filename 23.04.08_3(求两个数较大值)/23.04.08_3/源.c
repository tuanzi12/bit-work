#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int average(int num1,int num2)
{
	if (num1 > num2)
		return num1;
	else
		return num2;

}
int main()
{
	int num1, num2,big;
	scanf("%d %d", &num1, &num2);
	big=average(num1, num2);
	printf("%d", big);
	return 0;
}