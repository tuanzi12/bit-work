#include "List.h"

// 创建返回链表的头结点.
ListNode* ListCreate(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (node == NULL)
	{
		perror("node malloc fail");
		exit(-1);
	}

	node->_data = x;
	node->_next = NULL;
	node->_prev = NULL;
	return node;
}

ListNode* ListNodeInit()
{
	ListNode* phead = ListCreate(0);
	phead->_next = phead;
	phead->_prev = phead;
	return phead;
}
// 双向链表销毁
void ListDestory(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		ListNode* next = cur->_next;
		cur = cur->_next;
		free(cur);
	}
	free(pHead);
}
// 双向链表打印
void ListPrint(ListNode* pHead)
{
	assert(pHead);
	printf("pHead<==>");
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		printf("%d<==>", cur->_data);
		cur = cur->_next;
	}
}
// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	//ListNode* tail = pHead->_prev;//定义尾节点
	//ListNode* NewNode = ListCreate(x);//添加新节点

	//NewNode->_prev = tail;//新节点前驱指向尾
	//pHead->_prev = NewNode;//哨兵位前驱指向新节点
	//NewNode->_next = pHead;//新节点后继指向哨兵位
	//tail->_next = NewNode;//尾结点后继指向新节点

	ListInsert(pHead, x);//复用当前位置之前插入
	//向哨兵位之前，也就是尾结点之后插入

}
// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	assert(pHead->_next != pHead);//判断不为空链表

	//ListNode* tail = pHead->_prev;
	//ListNode* tailprev = tail->_prev;
	//free(tail);

	//pHead->_prev = tailprev;//哨兵位前驱结点指向新的尾节点
	//tailprev->_next = pHead;//新的尾节点的next指向哨兵位

	ListErase(pHead->_prev);
}
// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);

	//ListNode* NewNode = ListCreate(x);
	//ListNode* first = pHead->_next;

	//pHead->_next = NewNode;//哨兵位后继指向新节点
	//NewNode->_prev = pHead;//新节点前驱指向哨兵位
	//NewNode->_next = first;//新节点后继指向第一个节点
	//first->_prev = NewNode;//第一个节点前驱指向新节点
	
	ListInsert(pHead->_next,x);//复用当前位置插入
	//在哨兵位后插入
}
// 双向链表头删
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	assert(pHead->_next != pHead);

	//ListNode* first = pHead->_next;
	//ListNode* second = first->_next;
	//free(first);
	//pHead->_next = second;//哨兵位后继指向第二个节点
	//second->_prev = pHead;//第二个节点前驱指向哨兵位
	
	ListErase(pHead->_next);

}
// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		if (cur->_data == x)
			return cur;
		cur = cur->_next;
	}
	return NULL;
}
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);

	ListNode* posprev = pos->_prev;//定义当前位置前一个节点
	ListNode* NewNode = ListCreate(x);

	posprev->_next = NewNode;
	NewNode->_prev = posprev;
	NewNode->_next = pos;
	pos->_prev = NewNode;
}
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	assert(pos);

	ListNode* posprev = pos->_prev;
	ListNode* posnext = pos->_next;
	free(pos);
	posprev->_next = posnext;
	posnext->_prev = posprev;



}