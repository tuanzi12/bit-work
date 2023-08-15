#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void print(int arr[], int sz)
	{
		int i = 0;
		for (i = 0; i < sz; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
void reverse(int arr[], int sz)
	{
		int left = 0;
		int right = sz - 1;
		while (left < right)
		{
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
			left++;
			right--;
		}
	}
	void init(int arr[], int sz)
	{
		int i = 0;
		for (i = 0; i < sz; i++)
		{
			arr[i] = 0;
		}
	}
	int main()
	{
		int i = 0;
		int arr[10];
		printf("请输入十个数完成逆置");
		for (i = 0; i < 10; i++)
			scanf("%d", &arr[i]);
		int sz = sizeof(arr) / sizeof(arr[0]);
		print(arr, sz);
		reverse(arr, sz);
		print(arr, sz);
		init(arr, sz);
		print(arr, sz);
		return 0;
	}
