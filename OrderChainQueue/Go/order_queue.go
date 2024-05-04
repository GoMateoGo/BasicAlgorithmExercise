package main

//顺序队列
type OrderQueue struct {
	front int
	rear  int
	data  [MaxSize]int
}

func CreateOrderQueue() *OrderQueue {
	Q := &OrderQueue{
		front: 0,
		rear:  0,
	}
	return Q
}

// 入队
func (this *OrderQueue) Push(nValue int) bool {
	// 队列已满
	/*
	* 取模:
	* 1. 小于 目标值, 结果为本身
	* 2. 等于 目标值, 结果为0
	* 3. 大于 目标值, 结果为余数
	 */
	if (this.rear+1)%len(this.data) == this.front {
		return false
	}
	//入队
	this.data[this.rear] = nValue
	// 尾指针后移,小于长度取自身+1
	this.rear = (this.rear + 1) % len(this.data)
	return true
}

// 出队
func (this *OrderQueue) Pop(nValue *int) bool {
	//队列为空
	if this.rear == this.front {
		return false
	}
	*nValue = this.data[this.front]
	// 头指针后移
	this.front = (this.front + 1) % len(this.data)
	return true
}

// 清空队列
func (this *OrderQueue) Clear() {
	//
	this.front = 0
	this.rear = 0
}
