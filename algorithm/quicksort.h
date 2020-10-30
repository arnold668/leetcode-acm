#pragma once
#include<iostream>
#include<vector>
#include"print.h"
using namespace std;
//错误点1. 分离函数代码的for循环的范围出错，应该在low和high内
//2.vector做函数参数要改变，需要使用传引用方式
//错误循环  for (int i = 0; i < data.size() - 1; i++) {
//主要思想，快慢双指针法，快指针查找小于基准数，则慢指针所指下一个对象与快指针所指对象swap
//void print_sort(vector<int> data);
int partition(vector<int> &data, int low, int high) {
	int tmp = data[high];  //定当前区间最后一位为基准
	int curr = low - 1;  //慢指针从low-1开始
	for (int i = low; i < high; i++) { //范围为[low,high-1],取不到high
		if (data[i] <= tmp) {  //排序为小于等于
			curr++;
			swap(data[i], data[curr]);
		}
	}
	swap(data[curr + 1], data[high]);
	return curr + 1;
}
void quick_sort(vector<int> &data, int low, int high) {
	//cout << "low:" << low << "  high:" << high << endl;
	if (low < high) {
		int position = partition(data, low, high);
		//cout << "position:" << position << endl;
		//print_sort(data);
		quick_sort(data, low, position - 1);
		quick_sort(data, position +1, high);//position +1大于high
	}
	else
		return;
}


//2.传指针模式，注意变更， (*data)[high]
//int partition(vector<int> *data, int low, int high) {
//	int tmp = (*data)[high];  //定当前区间最后一位为基准
//	int curr = low - 1;  //慢指针从low-1开始
//	for (int i = low; i < high; i++) { //范围为[low,high-1],取不到high
//		if ((*data)[i] <= tmp) {  //排序为小于等于
//			curr++;
//			swap((*data)[i], (*data)[curr]);
//		}
//	}
//	swap((*data)[curr + 1], (*data)[high]);
//	return curr + 1;
//}
//void quick_sort(vector<int> *data, int low, int high) {
//	//cout << "low:" << low << "  high:" << high << endl;
//	if (low < high) {
//		int position = partition(data, low, high);
//		//cout << "position:" << position << endl;
//		//print_sort(data);
//		quick_sort(data, low, position - 1);
//		quick_sort(data, position + 1, high);//position +1大于high
//	}
//	else
//		return;
//}

//3.自身递归
//错误点1，左边比较应该是<=
//void quicksort ( vector<int>&a,int left, int right )
//{
//	int i, j, t, temp;
//	if ( left > right )
//		return;
//
//	temp = a[left]; //temp中存的就是基准数
//	i = left;
//	j = right;
//	while ( i != j )
//	{
//		//顺序很重要，要先从右边开始找
//		while ( a[j] >= temp && i < j )
//			j--;
//		//再找右边的
//		cout << "j=" << j << "   ";
//		while ( a[i] <= temp && i < j )
//			i++;
//		cout<< "i=" << i<<endl;
//		//交换两个数在数组中的位置
//		if ( i < j )
//		{
//			t = a[i];
//			a[i] = a[j];
//			a[j] = t;
//		}
//		print_sort ( a );
//	}
//	//最终将基准数归位
//	a[left] = a[i];
//	a[i] = temp;
//
//	quicksort ( a,left, i - 1 );//继续处理左边的，这里是一个递归的过程
//	quicksort ( a, i + 1, right );//继续处理右边的 ，这里是一个递归的过程
//}
