#pragma once
#pragma once
#include<iostream>
using namespace std;
//底层 插值法
//void shell_sort(int arr[], int n) {
//	for (int gap = n / 2; gap > 0; gap /= 2) {
//		for (int j = gap; j < n; j++) {
//			int tmp = arr[j];
//			int i = 0;
//			for (i = j - gap; i >=0; i-=gap) { //思想是比较上一张牌和当前牌
//				if (arr[i] > tmp) {
//					//swap(arr[i], arr[i + 1]);或者直接赋值
//					arr[i + gap] = arr[i];
//				}
//				else
//					break;
//			}
//			arr[i + gap] = tmp;
//		}
//	}
//}

//底层 ，冒泡
//问题: if (flag == 0)  是break; 传统的冒泡 说明已完成，使用return
void shell_sort(int arr[], int n) {
	for (int gap = n / 2; gap > 0; gap /= 2) {
		int flag = 1;
		for (int i = 0; i < n; i++) {
			flag = 0;
			for (int j = 0; j < n - gap - i; j += gap) {//间隔为gap的子序列元素个数
				if (arr[j] > arr[j + gap]) {
					swap(arr[j], arr[j + gap]);
					flag = 1;
				}
			}
			if (flag == 0)  break;
		}
	}
}