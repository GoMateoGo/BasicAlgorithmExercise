#pragma once
#define QUEUE_SIZE  100

class OrderQueue
{
public:
	OrderQueue();
	typedef struct
	{
		int front;
		int rear;
		int data[QUEUE_SIZE];
	}Queue;

	Queue m_queue;

	bool Push(int nValue);
	bool Pop(int *nValue);
	void Clear();
};
