#pragma once
#include<iostream>
#include<vector>
using namespace std;
//���ֲ��ң�ǰ�����������飬��������ң��ڲ�����
//���ֲ��ҷ�,����arr����С���󣩣�����n��ֵkey����������key������λ��
//����ԭ��mid����whileѭ�����趨��mid�����Ŷ��������޸ı�󲻶ϱ仯��
int bin_search(int arr[], int key, int n) {
	//int mid = n / 2;��һ�ζ��֣�mid�ı��
	int mid;
	int low = 0, high = n - 1;
	while (low < high) {
		mid = low + (high - low) / 2;//��������������
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