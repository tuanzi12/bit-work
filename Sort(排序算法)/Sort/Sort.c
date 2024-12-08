#include "Sort.h"
#include "Stack.h"
// 打印
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

// 交换
void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;

}
// 插入排序
void InsertSort(int* a, int n)
{
	for (size_t i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
			}
			else
			{
				break;
			}
			--end;
		}
		a[end + 1] = tmp;
	}
}

// 希尔排序
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
			for (int i = 0; i < n - gap; ++i)
			{
				int end = i;
				int tmp = a[end + gap];
				while (end >= 0)
				{
					if (tmp < a[end])
					{
						a[end + gap] = a[end];
						end -= gap;
					}
					else
					{
						break;
					}
				}
				
				a[end + gap] = tmp;
			}
	}
}

// 选择排序
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int min = begin, max = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (a[i] > a[max])
			{
				max = i;
			}
			if (a[i] < a[min])
			{
				min = i;
			}
		}
		Swap(&a[begin], &a[min]);
		if (max == begin)
		{
			max = min;
		}
		Swap(&a[end], &a[max]);
		++begin;
		--end;
	}
}
// 堆排序
void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
			++child;
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}
// 冒泡排序
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		int flag = 0;
		for (int j = 1; j < n-i; j++)
		{
			if (a[j - 1] > a[j])
			{
				Swap(&a[j - 1], &a[j]);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}

//三数取中
int GetMid(int* a, int left, int right)
{
	int mid = (left + right) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
			return mid;
		else if (a[left] > a[right])
			return left;
		else return right;
	}
	else
	{
		if (a[mid] > a[right])
			return mid;
		else if (a[left] < a[right])
			return left;
		else return right;
	}
}
// 快速排序递归实现
// 快速排序hoare版本
int PartSort1(int* a, int left, int right)
{
	int mid = GetMid(a, left, right);
	Swap(&a[mid], &a[left]);
		int key = left;
		while (left < right)
		{	
			//找小
			while (left < right && a[right] >= a[key])
			{
				--right;
			}
			while (left < right && a[left] <= a[key])
			{
				++left;
			}
			Swap(&a[left], &a[right]);
		}
		Swap(&a[key], &a[left]);
		return left;
}
// 快速排序挖坑法
int PartSort2(int* a, int left, int right)
{
	int mid = GetMid(a, left, right);
	Swap(&a[mid], &a[left]);
	int key = a[left];
	int hole = left;
	while (left < right)
	{
		//找小
		while (left < right && a[right] >= key)
		{
			--right;
		}
		a[hole] = a[right];
		hole = right;
		while (left < right && a[left] <= key)
		{
			++left;
		}
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;
	return hole;
}

// 快速排序前后指针法
int PartSort3(int* a, int left, int right)
{
	int mid = GetMid(a, left, right);
	Swap(&a[mid], &a[left]);

	int key = left;
	int prev = left, cur = prev + 1;
	while (cur <= right)
	{
		if (a[cur] < a[key] && cur != ++prev)
			Swap(&a[cur], &a[prev]);
		++cur;
	}
	Swap(&a[prev], &a[key]);
	return prev;
}
void QuickSort(int* a, int left, int right)
{

	if (left >= right)
		return;
	int key = PartSort3(a, left, right);
	QuickSort(a, left, key - 1);
	QuickSort(a, key + 1, right);
}

void QuickSortNonR(int* a, int left, int right)
{
	Stack st;
	StackInit(&st);
	StackPush(&st, right);
	StackPush(&st, left);
	while (!StackEmpty)
	{
		int left = StackTop(&st);
		StackPop(&st);

		int right = StackTop(&st);
		StackPop(&st);

		int key = PartSort2(a, left, right);
		if (key + 1 < right)
		{
			StackPush(&st, right);
			StackPush(&st, key + 1);
		}
		if (key - 1 > left)
		{
			StackPush(&st, key - 1);
			StackPush(&st, left);
		}
	}
	StackDestroy(&st);
}
void _MergeSort(int* a, int* tmp, int begin, int end)
{
	if (end <= begin)
		return;
	int mid = (end + begin) / 2;
	_MergeSort(a, tmp, begin, mid);
	_MergeSort(a, tmp, mid + 1, end);
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int index = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else 
		{ 
			tmp[index++] = a[begin2++]; 
		}
	}
	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}
	memcpy(a + begin, tmp + begin, (end - begin + 1) * sizeof(int));
}
// 归并排序递归实现
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}
	_MergeSort(a, tmp, 0, n - 1);
	free(tmp);
}

void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += gap * 2)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i+2*gap-1;
			if (begin2 >= n)
			{
				break;
			}
			if (end2 >= n)
			{
				end2 = n - 1;
			}
			int index = i;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[index++] = a[begin1++];
				}
				else
				{
					tmp[index++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[index++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[index++] = a[begin2++];
			}
			memcpy(a + i, tmp + i, (end2 - i + 1) * sizeof(int));
		}
		printf("\n");
		gap *= 2;
	}
	free(tmp);
}

void CountSort(int* a, int n)
{
	int min = a[0], max = a[0];
	for (size_t i = 0; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];

		if (a[i] > max)
			max = a[i];
	}

	int range = max - min + 1;
	int* count = (int*)malloc(sizeof(int) * range);
	printf("range:%d\n", range);
	if (count == NULL)
	{
		perror("malloc fail");
		return;
	}
	memset(count, 0, sizeof(int) * range);

	// 统计数据出现次数
	for (int i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}

	// 排序
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (count[i]--)
		{
			a[j++] = i + min;
		}
	}
}