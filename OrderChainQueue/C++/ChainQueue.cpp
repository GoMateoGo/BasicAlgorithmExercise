#include "ChainQueue.h"
ChainQueue::ChainQueue()
{
    m_queue.front = m_queue.rear = nullptr;
}

bool ChainQueue::Push(int nValue)
{
    nodePtr pNew = new Node; //创建新节点
    if (pNew == nullptr) { //如果内存分配失败，返回false
        return false;
    }
    pNew->data = nValue; //新节点的数据赋值
    pNew->next = nullptr; //新节点的 next 指针置空
    if (m_queue.rear == nullptr) { //如果队列为空，新节点同时是头部和尾部
        m_queue.front = m_queue.rear = pNew;
    }
    else { //如果队列不为空，新节点只是尾部
        m_queue.rear->next = pNew;
        m_queue.rear = pNew;
    }
    return true;
}

bool ChainQueue::Pop(int* nValue)
{
    if (m_queue.front == nullptr) { //如果队列为空，返回false
        return false;
    }
    nodePtr pDel = m_queue.front; //创建要删除的节点指针
    *nValue = pDel->data; //写入返回值
    m_queue.front = pDel->next; //把当前队列头部的指针指向下一个节点
    if (m_queue.front == nullptr) { //如果队列为空，更新m_queue.rear
        m_queue.rear = nullptr;
    }
    delete pDel; //删除要删除的节点
    return true;
}

void ChainQueue::Clear()
{
	
	nodePtr pDel,pTmp; //创建要删除的节点指针和临时节点指针
	m_queue.rear = m_queue.front; //把当前队列头部指针指向尾部
    pTmp = m_queue.front->next; //把当前队列头部指针赋值给新节点指针
    m_queue.front->next = nullptr; //把当前队列头部指针的next指针置空;
	while(pTmp)
	{
        pDel = pTmp;
        pTmp = pTmp->next;
		delete pDel;
	}
}
