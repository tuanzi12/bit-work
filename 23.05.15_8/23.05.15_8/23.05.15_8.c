#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int reverse(char *arr)
{
	char* left = arr;
	char* right = arr+strlen(arr) - 1;
	char mid;
	while (left<right)
	{
		mid = *left;
		*left = *right;
		*right = mid;
		left++;
		right--;
	}
}
int main()
{
	char arr[] = "Hello world";
	reverse(arr);
	printf("%s", arr);
	return 0;
}