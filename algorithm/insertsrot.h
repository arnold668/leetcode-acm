#pragma once
#include<iostream>
using namespace std;
//两点，1.插之前牌都是有序的，2.从第二张牌开始，默认已有一张3.从前面牌最后一张开始对比
void insert_sort(int arr[], int n) {
	for (int j = 1; j < n; j++) {
		int tmp =arr[j];
		int i = 0;
		for ( i = j-1; i >=0; i--) {
			if (arr[i] > tmp) {
				//swap(arr[i], arr[i + 1]);或者直接赋值
				arr[i + 1] = arr[i];
			}
			else
				break;
		}
		arr[i + 1] = tmp;
	}
}
