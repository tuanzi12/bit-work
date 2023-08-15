#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
/*int main()//主函数实现
{
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int k,flag=0;
	int row=0, col=2;
	printf("请输入要查找的数字");
	scanf("%d", &k);
	while (row <= 2 && col <= 2)
	{
		if (k > arr[row][col])
			row++;
		else if (k < arr[row][col])
			col--;
		else
			printf("找到了，下标是：%d %d\n", row, col);
		flag = 1;
		break;
	}
	if (flag==0)
		printf("未找到\n");
	return 0;
}
*/
void search(int arr[3][3],int k, int *x, int *y)
{
	int row = 0;
	int col = *y-1;
	while (row <= *x-1 && *y>=0)
	{
		if (k > arr[row][col])
			row++;
		else if (k < arr[row][col])
			col--;
		else
		{
			*x = row;
			*y = col;
			return;
		}
	}
	*x = -1;
	*y = -1;
}
int main()
{
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int k;
	int row = 3, col = 3;
	printf("请输入要查找的数字");
	scanf("%d", &k);
	search(arr, k, &row, &col);
	if (row == -1 && col == -1)
		printf("未找到");
	else
		printf("找到了，下标是：%d %d\n", row, col);
	return 0;
}