#pragma once
#include<iostream>
#include"print.h"
using namespace std;
/*
1. keep_head的难点在于节点比较完，需要递归向下进行堆调整（每次子结点与父结点交换后，
需将以子结点为根的完全二叉树调整为大顶堆）

2. build_head在于建堆的开始点是从最后一个有儿子的节点，heap_size/2-1，除2是取父节点，个人猜想减一后为序号

3. sort在于理解堆删除思想，先建最大堆，（保证了arr[0]是最大元素），
然后首元素与尾元素swap，接着堆size-1（隐藏最大值）继续保持堆特性
*/

void keepHeap(int arr[],int i,int heap_size) {//i为当前节点
	int left = 2*i + 1;
	int right = 2 * i + 2;
	int max = i;
	int flag = 0;
	if (arr[left] > arr[max] && left < heap_size) {
		max = left;
		flag = 1;
	}
	if (arr[right] > arr[max] && right < heap_size) {
		max = right;
		flag = 1;
	}
	//if(max!=i){
	if (flag == 1) {
		swap(arr[i], arr[max]);
		//print_sort ( arr, 10 );用来查看堆变化
		keepHeap(arr, max, heap_size);//难点，检查后面节点，并使其保持后面节点的堆关系
	}
}
//建堆
void buildHeap(int arr[],int heap_size) { //从最后一个有儿子的节点开始建堆，然后向前
	int k = heap_size / 2 - 1;
	//int k = (heap_size - 1) / 2;
	for (int i = k; i >= 0; i--) {
		cout << endl;
		cout << "k次为：" << i << endl;
		keepHeap(arr, i, heap_size);
		print_sort ( arr, 10 );
	}
	
}

void heap_sort(int arr[],int heap_size) {//最前一个和最后互换，然后循环长度-1
	buildHeap(arr, heap_size);
	//print_sort ( arr, 10 );
	for (int i = heap_size - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		keepHeap(arr, 0, i);
		//类似堆元素删除，heapsize=heapsize-1；keepHeap(arr, 0, heapsize);  
	}
}