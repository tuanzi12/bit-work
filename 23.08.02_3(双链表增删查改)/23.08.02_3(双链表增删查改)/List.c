#include "List.h"

// �������������ͷ���.
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
// ˫����������
void ListDestory(ListNode* pHead)
{

}
// ˫�������ӡ
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
// ˫������β��
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* tail = pHead->_prev;//����β�ڵ�
	ListNode* NewNode = ListCreate(x);//����½ڵ�

	NewNode->_prev = tail;//�½ڵ�ǰ��ָ��β
	pHead->_prev = NewNode;//�ڱ�λǰ��ָ���½ڵ�
	NewNode->_next = pHead;//�½ڵ���ָ���ڱ�λ
	tail->_next = NewNode;//β�����ָ���½ڵ�
}
// ˫������βɾ
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	assert(pHead->_next != pHead);//�жϲ�Ϊ������

	ListNode* tail = pHead->_prev;
	ListNode* tailprev = tail->_prev;
	free(tail);

	pHead->_prev = tailprev;//�ڱ�λǰ�����ָ���µ�β�ڵ�
	tailprev->_next = pHead;//�µ�β�ڵ��nextָ���ڱ�λ

}
// ˫������ͷ��
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);

	ListNode* NewNode = ListCreate(x);
	ListNode* first = pHead->_next;

	pHead->_next = NewNode;//�ڱ�λ���ָ���½ڵ�
	NewNode->_prev = pHead;//�½ڵ�ǰ��ָ���ڱ�λ
	NewNode->_next = first;//�½ڵ���ָ���һ���ڵ�
	first->_prev = NewNode;//��һ���ڵ�ǰ��ָ���½ڵ�
}
// ˫������ͷɾ
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	assert(pHead->_next != pHead);

	ListNode* first = pHead->_next;
	ListNode* second = first->_next;
	free(first);
	pHead->_next = second;//�ڱ�λ���ָ��ڶ����ڵ�
	second->_prev = pHead;//�ڶ����ڵ�ǰ��ָ���ڱ�λ
	

}
// ˫���������
ListNode* ListFind(ListNode* pHead, LTDataType x)
{

}
// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x)
{

}
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{

}