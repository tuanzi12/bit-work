#include "Stack.h"
#include "Queue.h"
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
void Queuetest1()
{
	Queue qt;
	QueueInit(&qt);
	QueuePush(&qt, 2);
	QueuePrint(&qt);
	QueueDestroy(&qt);
}

int main()
{
	Stacktest1();
	Queuetest1();
	return 0;

}