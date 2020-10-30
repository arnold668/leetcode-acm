// algorithm.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include <iostream>
//#include"vld.h"
#include<vector>
#include"print.h"//输出函数头
#include"sort.h" //排序
#include"binsearch.h"
#include"countSort.h"
using namespace std;

int main()
{

	int arr[] = { 2,10,5,14,4,1,6,11,12,13 };
	//vector<int> data = { 23,6,44,32,78,2,33 ,66,11 };
	//int arr [] = { 23,6,44,32,78,2,33 ,66,111 };
	vector<int> data = {2,10,5,14,4,1,6,11,12,13 };
	int n = data.size();
	print_cur ( arr, n );
	//int n = sizeof (arr)/ sizeof(arr[0]);  
	//1.快排
	//quick_sort(&data, 0, n);//传指针
	//quick_sort(data, 0, n-1);  //传引用
	//quicksort ( data, 0, n - 1 );
	//2.冒泡
	//bubble_sort(arr, n);
	//3.插入
	//insert_sort(arr, n);
	//4.希尔
	//shell_sort(arr, n);
	//5.选择排序
	//select_sort(arr, n);
	//6.堆
	//heap_sort(arr, n);
	//7.计数排序
	 count_sort ( arr, n );
	//8.基数排序

	//9. 归并排序


	cout << "最终" << endl;
	//print_sort ( data );
	print_sort ( arr, n );
	//int key = 23;
	//1. 二分查找
	//int seq=bin_search(arr, key, n);
	//cout << seq;
	system("pause");
	return 0;
 }

