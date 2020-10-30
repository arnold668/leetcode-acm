#pragma once
#include<iostream>
#include"print.h"
using namespace std;
/*
1. keep_head���ѵ����ڽڵ�Ƚ��꣬��Ҫ�ݹ����½��жѵ�����ÿ���ӽ���븸��㽻����
�轫���ӽ��Ϊ������ȫ����������Ϊ�󶥶ѣ�

2. build_head���ڽ��ѵĿ�ʼ���Ǵ����һ���ж��ӵĽڵ㣬heap_size/2-1����2��ȡ���ڵ㣬���˲����һ��Ϊ���

3. sort��������ɾ��˼�룬�Ƚ����ѣ�����֤��arr[0]�����Ԫ�أ���
Ȼ����Ԫ����βԪ��swap�����Ŷ�size-1���������ֵ���������ֶ�����
*/

void keepHeap(int arr[],int i,int heap_size) {//iΪ��ǰ�ڵ�
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
		//print_sort ( arr, 10 );�����鿴�ѱ仯
		keepHeap(arr, max, heap_size);//�ѵ㣬������ڵ㣬��ʹ�䱣�ֺ���ڵ�Ķѹ�ϵ
	}
}
//����
void buildHeap(int arr[],int heap_size) { //�����һ���ж��ӵĽڵ㿪ʼ���ѣ�Ȼ����ǰ
	int k = heap_size / 2 - 1;
	//int k = (heap_size - 1) / 2;
	for (int i = k; i >= 0; i--) {
		cout << endl;
		cout << "k��Ϊ��" << i << endl;
		keepHeap(arr, i, heap_size);
		print_sort ( arr, 10 );
	}
	
}

void heap_sort(int arr[],int heap_size) {//��ǰһ������󻥻���Ȼ��ѭ������-1
	buildHeap(arr, heap_size);
	//print_sort ( arr, 10 );
	for (int i = heap_size - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		keepHeap(arr, 0, i);
		//���ƶ�Ԫ��ɾ����heapsize=heapsize-1��keepHeap(arr, 0, heapsize);  
	}
}