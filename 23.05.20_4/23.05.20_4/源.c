#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void ret(int arr[5],int size)
{
	int left = 0,i=0;
	int right = size - 1;
	while (left < right)
	{
		while (arr[left] % 2 == 1)
			left++;
		while (arr[right] % 2 == 0)
			right--;
		if (left < right)
		{
			int tmp = arr[right];
			arr[right] = arr[left];
			arr[left] = tmp;
		}
	}
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
}
int main()
{
	int arr[5];
	int i = 0;
	int size = sizeof(arr)/sizeof(arr[0]);
	for(i=0;i<size;i++)
	 scanf("%d", &arr[i]);
	ret(&arr,size);
	
	return 0;
}
