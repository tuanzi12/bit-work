#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqLIst.h"
void test()
{
	SeqList s1;
	SeqListInit(&s1);
	SeqListPushFront(&s1,1);
	SeqListPushBack(&s1,2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	SeqListPrint(&s1);
	
	SeqListInsert(&s1, 1, 6);
	SeqListPrint(&s1);
	SeqListErase(&s1,1);
	SeqListPrint(&s1);

}
int main()
{
	test();
	return 0;
}