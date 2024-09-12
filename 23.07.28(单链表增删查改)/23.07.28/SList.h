#pragma once

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;
//��̬����ڵ�
SListNode* BuySListNode(SLTDateType x);
//������β��
void SListPushBack(SListNode** pplist, SLTDateType x);
//������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x);
//������βɾ
void SListPopBack(SListNode** pplist);
//������ͷɾ
void SListPopFront(SListNode** pplist);
//��ӡ
void SListPrint(SListNode* plist);
// ���������
SListNode* SListFind(SListNode* plist, SLTDateType x);