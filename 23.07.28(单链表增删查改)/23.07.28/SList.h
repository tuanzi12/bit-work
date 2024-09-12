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
//动态申请节点
SListNode* BuySListNode(SLTDateType x);
//单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x);
//单链表头插
void SListPushFront(SListNode** pplist, SLTDateType x);
//单链表尾删
void SListPopBack(SListNode** pplist);
//单链表头删
void SListPopFront(SListNode** pplist);
//打印
void SListPrint(SListNode* plist);
// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x);