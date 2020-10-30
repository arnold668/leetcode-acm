#pragma once
#include<iostream>
#include<vector>
using namespace std;
void print_cur ( int  arr [], int n )
{
	cout << "当前数组为" << endl;
	//cout << sizeof arr << endl;数组传递时只会传递数组的首地址，函数在后面需要用到数组元素时再根据首地址和下标去找
	for ( int i = 0; i < n; i++ )
	{//结果遍历
		cout << arr[i] << "\t";
	}
	cout << endl;
}
 void print_sort(vector<int> data) {
	cout << "排序结果为" << endl;
	for (int i = 0; i < data.size(); i++) {//结果遍历
		cout << data[i] << "\t";
	}
	cout << endl;
}

 void print_sort(int  arr[], int n) {
	cout << "排序结果为" << endl;
	//cout << sizeof arr << endl;数组传递时只会传递数组的首地址，函数在后面需要用到数组元素时再根据首地址和下标去找
	for (int i = 0; i < n; i++) {//结果遍历
		cout << arr[i] << "\t";
	}
	cout << endl;
}