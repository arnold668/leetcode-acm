#pragma once
#include<iostream>
using namespace std;
//���㣬1.��֮ǰ�ƶ�������ģ�2.�ӵڶ����ƿ�ʼ��Ĭ������һ��3.��ǰ�������һ�ſ�ʼ�Ա�
void insert_sort(int arr[], int n) {
	for (int j = 1; j < n; j++) {
		int tmp =arr[j];
		int i = 0;
		for ( i = j-1; i >=0; i--) {
			if (arr[i] > tmp) {
				//swap(arr[i], arr[i + 1]);����ֱ�Ӹ�ֵ
				arr[i + 1] = arr[i];
			}
			else
				break;
		}
		arr[i + 1] = tmp;
	}
}
