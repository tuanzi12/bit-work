#include "SList.h"
void TestList()
{
	SListNode* phead = NULL;
	SListPushBack(&phead,2);
	SListPrint(phead);
	SListPushFront(&phead, 1);
	SListPrint(phead);
	
	
}

int main()
{
	TestList();
	return 0;
}