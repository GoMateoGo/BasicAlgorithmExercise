package main

import "fmt"

const MaxSize = 10

func main() {
	// 顺序队列
	queue := CreateOrderQueue()
	fmt.Println("data length:", len(queue.data))
	for i := 0; i < MaxSize-1; i++ {
		if queue.Push(i) {
			fmt.Println("push:", i)
		} else {
			fmt.Println("push fail")
		}
	}

	var nValue int
	for i := 0; i < MaxSize-1; i++ {
		if queue.Pop(&nValue) {
			fmt.Println("pop:", nValue)
		} else {
			fmt.Println("pop fail")
		}
	}

	for i := 0; i < MaxSize-1; i++ {
		if queue.Push(i) {
			fmt.Println("push:", i)
		} else {
			fmt.Println("push fail")
		}
	}
}
