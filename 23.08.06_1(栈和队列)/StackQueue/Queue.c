#include "Queue.h"

// ��ʼ������ 
void QueueInit(Queue* q)
{
	assert(q);
	q->_front = q->_rear = NULL;
	q->_size = 0;
}
// ��β����� 
void QueuePush(Queue* q, QDataType data)
{

}
// ��ͷ������ 
void QueuePop(Queue* q);
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q);
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q);
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q);
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q);
// ���ٶ��� 
void QueueDestroy(Queue* q)
{
	assert(q);

}