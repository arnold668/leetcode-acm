#pragma once
#include<iostream>
#include<vector>
using namespace std;
void bubble_sort(int arr[], int n) {
	int flag = 1;
	for (int i = 0; i < n; i++) {
		flag = 0;
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j+1]) {
				swap(arr[j], arr[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0) return;
	}
}
