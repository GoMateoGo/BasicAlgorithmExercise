#include "OrderQueue.h"

OrderQueue::OrderQueue()
{
	m_queue.front = 0;
	m_queue.rear = 0;
}

bool OrderQueue::Push(int nValue)
{
	if ((m_queue.rear + 1)% QUEUE_SIZE == m_queue.front) // 队列已满
		return false;

	m_queue.data[m_queue.rear] = nValue;
	m_queue.rear = (m_queue.rear + 1) % QUEUE_SIZE;
	return true;
}

bool OrderQueue::Pop(int* nValue)
{
	if (m_queue.rear == m_queue.front) // 队列为空
		return false;

	*nValue = m_queue.data[m_queue.front];
	m_queue.front = (m_queue.front + 1) % QUEUE_SIZE;
	return true;
}

void OrderQueue::Clear()
{
	m_queue.rear = 0;
	m_queue.front = 0;
}

