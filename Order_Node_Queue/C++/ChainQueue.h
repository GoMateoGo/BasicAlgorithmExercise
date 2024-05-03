#pragma once

#define QUEUE_SIZE 10

class ChainQueue
{
public:
	ChainQueue();
	typedef struct Node
	{
		struct Node* next;
		int data; //���Դ���������
	}Node, *nodePtr;
	typedef struct 
	{
		nodePtr front, rear;
	}nQueue;
	nQueue m_queue;
	bool Push(int nValue);
	bool Pop(int *nValue);
	void Clear();
};
