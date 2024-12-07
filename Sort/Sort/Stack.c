#include "Stack.h"

// ��ʼ��ջ 
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;

}
// ��ջ 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		int newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->_a, sizeof(STDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		ps->_a = tmp;
		ps->_capacity = newcapacity;
	}
	ps->_a[ps->_top] = data;
	ps->_top++;

}
// ��ջ 
void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->_top > 0);
	--ps->_top;

}
// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->_top > 0);
	return (ps->_a[ps->_top - 1]);

}
// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0;

}
// ����ջ 
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = 0;
	ps->_capacity = ps->_top = 0;

}

void StackPrint(Stack* ps)
{
	assert(ps);
	while (!StackEmpty(ps))
	{
		printf("%d ", StackTop(ps));
		StackPop(ps);
	}

}