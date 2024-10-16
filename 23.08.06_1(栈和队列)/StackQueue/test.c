#include "Stack.h"
void Stacktest1()
{
	Stack st;
	
	StackInit(&st);
	StackPush(&st,1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPrint(&st);
	printf("\n");
	StackDestroy(&st);

}
int main()
{
	Stacktest1();
	return 0;

}