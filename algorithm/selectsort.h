#pragma once
#include<iostream>
#include"print.h"
using namespace std;
//ѡ������ÿ��ѡ���ģ������±꣬���swap
//���⣺���һ���������,Խ�磬����������max��ȡֵ��max=n-1-i
//����
void select_sort(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		int max = n - i-1;//����±�Ϊn-1
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
//����
//void select_sort(int arr[], int n) {
//	for (int i = 0; i < n; i++) {
//		int max = i;//����±�Ϊi
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
