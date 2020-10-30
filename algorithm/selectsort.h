#pragma once
#include<iostream>
#include"print.h"
using namespace std;
//选择排序：每次选最大的，保存下标，最后swap
//问题：最后一个数随机数,越界，发现问题是max的取值，max=n-1-i
//升序
void select_sort(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		int max = n - i-1;//最大下标为n-1
		for (int j = 0; j < n-1-i; j++) {
			if (arr[j] > arr[max]) {
				max = j;
			}
		}
		if (max != n - i-1) {
			swap(arr[max], arr[n - i-1]);
		}
		//print_sort ( arr, n ); 
	}
}
//降序
//void select_sort(int arr[], int n) {
//	for (int i = 0; i < n; i++) {
//		int max = i;//最大下标为i
//		for (int j = i+1; j < n ; j++) {
//			if (arr[j] > arr[max]) {
//				max = j;
//			}
//		}
//		if (max != i) {
//			swap(arr[max], arr[ i]);
//		}
//	}
//}
