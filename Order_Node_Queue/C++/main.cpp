#include <iostream>
#include "OrderQueue.h"
#include "ChainQueue.h"

int main()
{
	int p = 0;
	ChainQueue queue;

	for (int i = 0; i < 20; i++)
	{
		bool pushOk = queue.Push(i);
		if (!pushOk) std::cout << "Push " << i << " !ok" << std::endl;
	}
	queue.Clear();
	//for (int i = 0; i < 20; i++)
	//{
	//	bool popOk = queue.Pop(&p);
	//	if (!popOk)
	//		std::cout << "Pop " << i << " !ok" << std::endl;
	//	else
	//		std::cout << p << std::endl;
	//}

	//q.Push(300);//����
	//q.Clear();
	//q.Push(100);//���Բ���
	return 0;
}