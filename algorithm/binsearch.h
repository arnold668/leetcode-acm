#pragma once
#include<iostream>
#include<vector>
using namespace std;
//二分查找：前提是有序数组，分外面查找，内部查找
//二分查找法,数组arr（从小到大），个数n，值key，函数返回key在数组位置
//错误原因：mid需在while循环里设定，mid是随着二分上下限改变后不断变化的
int bin_search(int arr[], int key, int n) {
	//int mid = n / 2;第一次二分，mid的变的
	int mid;
	int low = 0, high = n - 1;
	while (low < high) {
		mid = low + (high - low) / 2;//防溢出，错误改正
		if (arr[mid] == key) {
			return mid;
		}
		else if (arr[mid] < key) {
			low = mid + 1;
		}
		else if (arr[mid] > key) {
			high = mid - 1;
		}
	}
	return -1;
}