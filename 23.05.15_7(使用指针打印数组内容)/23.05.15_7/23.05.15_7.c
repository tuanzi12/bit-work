#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int* listarr(int* arr)
{
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", *arr);
		++arr;
	}
	return 0;
}
int main()
{
	int arr[5] = {10,11,12,13,14,};
	int *p=arr;
	listarr(p);
	return 0;
}