#include "ChainQueue.h"
ChainQueue::ChainQueue()
{
    m_queue.front = m_queue.rear = nullptr;
}

bool ChainQueue::Push(int nValue)
{
    nodePtr pNew = new Node; //�����½ڵ�
    if (pNew == nullptr) { //����ڴ����ʧ�ܣ�����false
        return false;
    }
    pNew->data = nValue; //�½ڵ�����ݸ�ֵ
    pNew->next = nullptr; //�½ڵ�� next ָ���ÿ�
    if (m_queue.rear == nullptr) { //�������Ϊ�գ��½ڵ�ͬʱ��ͷ����β��
        m_queue.front = m_queue.rear = pNew;
    }
    else { //������в�Ϊ�գ��½ڵ�ֻ��β��
        m_queue.rear->next = pNew;
        m_queue.rear = pNew;
    }
    return true;
}

bool ChainQueue::Pop(int* nValue)
{
    if (m_queue.front == nullptr) { //�������Ϊ�գ�����false
        return false;
    }
    nodePtr pDel = m_queue.front; //����Ҫɾ���Ľڵ�ָ��
    *nValue = pDel->data; //д�뷵��ֵ
    m_queue.front = pDel->next; //�ѵ�ǰ����ͷ����ָ��ָ����һ���ڵ�
    if (m_queue.front == nullptr) { //�������Ϊ�գ�����m_queue.rear
        m_queue.rear = nullptr;
    }
    delete pDel; //ɾ��Ҫɾ���Ľڵ�
    return true;
}

void ChainQueue::Clear()
{
	
	nodePtr pDel,pTmp; //����Ҫɾ���Ľڵ�ָ�����ʱ�ڵ�ָ��
	m_queue.rear = m_queue.front; //�ѵ�ǰ����ͷ��ָ��ָ��β��
    pTmp = m_queue.front->next; //�ѵ�ǰ����ͷ��ָ�븳ֵ���½ڵ�ָ��
    m_queue.front->next = nullptr; //�ѵ�ǰ����ͷ��ָ���nextָ���ÿ�;
	while(pTmp)
	{
        pDel = pTmp;
        pTmp = pTmp->next;
		delete pDel;
	}
}
