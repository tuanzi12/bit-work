#include "List.h"
void testlist1()
{
	ListNode* plist = ListNodeInit();
	ListPushBack(plist , 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPrint(plist);
	printf("\n");
	ListPopBack(plist);
	ListPrint(plist);
}

void testlist2()
{
	ListNode* plist = ListNodeInit();
	ListPushFront(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPrint(plist);
	printf("\n");
	ListPopFront(plist);
	ListPrint(plist);
}
int main()
{
	testlist2();
	return 0;
}