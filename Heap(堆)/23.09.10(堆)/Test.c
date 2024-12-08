#include "Heap.h"
void CreateNDate()
{
	// дьЪ§Он
	int n = 10000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}

	for (size_t i = 0; i < n; ++i)
	{
		int x = rand() % 1000000;
		fprintf(fin, "%d\n", x);
	}

	fclose(fin);
}

void PrintTopK(const char* filename,int k)
{
	FILE* fout = fopen(filename, "r");
	if (fout == NULL)
	{
		perror("fopen fail");
		exit(-1);
	}
	int* minHeap = (int*)malloc(sizeof(int) * k);
	if (minHeap == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &minHeap[i]);
	}

	for (int i = (k - 2) / 2; i >= 0; i--)
	{
		AdjustDown(minHeap, k, i);
	}
	int x = 0;
	while (fscanf(fout, "%d", &x) != EOF)
	{
		if (x > minHeap[0])
		{
			minHeap[0] = x;
			AdjustDown(minHeap, k, 0);
		}
	}
	HeapSort(minHeap, k);
	for (int i = 0; i < k; i++)
	{
		printf("%d ", minHeap[i]);
	}
	printf("\n");
	free(minHeap);
	fclose(fout);

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
		swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}
int main()
{
	//CreateNDate();
	int a[] = { 2,3,5,7,4,6,8 };
	/*HeapSort(a, sizeof(a) / sizeof(int));

	PrintTopK("data.txt", 5);*/
	Heap hp;
	HeapInit(&hp);
	for (int i = 0; i < sizeof(a)/sizeof(int); i++)
	{
		HeapPush(&hp, a[i]);
	}
		HeapPrint(&hp);
	return 0;
}