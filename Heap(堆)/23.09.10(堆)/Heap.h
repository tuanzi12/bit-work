#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

void HeapInit(Heap* hp);
// �ѵ�����
void HeapDestory(Heap* hp);
// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x);
// �ѵ�ɾ��
void HeapPop(Heap* hp);
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp);
// �ѵ����ݸ���
int HeapSize(Heap* hp);
// �ѵ��п�
bool HeapEmpty(Heap* hp);
//���µ���
void AdjustDown(HPDataType* a, int n, int parent);
//���ϵ���
void AdjustUp(HPDataType* a, int child);

void HeapPrint(Heap* hp);

void swap(HPDataType* p1, HPDataType* p2);

void HeapSort(int* a, int n);