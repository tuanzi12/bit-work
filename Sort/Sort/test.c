#include"Sort.h"
void TestInsertSort()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5 };
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
void TestShellSort()
{
	int a[] = {9,1,2,5,7,4,8,6,3,5};
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
void TestHeapSort()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5 };
	HeapSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
//
void TestBubbleSort()
{
	int a[] = { 9,1,2,5,7,4,8,6,3};
	BubbleSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
//
//void TestHeapSort()
//{
//	int a[] = { 9,1,2,5,7,4,8,6,3,5,1,2,3,5,1,8,3 };
//	HeapSort(a, sizeof(a) / sizeof(int));
//	PrintArray(a, sizeof(a) / sizeof(int));
//}
//
void TestSelectSort()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5};
	SelectSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
//
void TestQuickSort()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5 };
	QuickSort(a, 0, sizeof(a) / sizeof(int) - 1);
	PrintArray(a, sizeof(a) / sizeof(int));
}
void TestMergeSort()
{
	int a[] = { 9,1,2,5,7,4,8,6,3 ,5,1};
	MergeSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
void TestCountSort()
{
	int a[] = { 9,1,2,5,7,4,8,6,3 ,5,1 };
	CountSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

int main()
{
	/*TestOP();*/
	/*TestInsertSort();
	TestShellSort();
	TestBubbleSort();*/
	//TestHeapSort();
	//TestSelectSort();
	//TestHeapSort();
	/*TestQuickSort();*/
	TestMergeSort();
	TestCountSort();
	return 0;
}