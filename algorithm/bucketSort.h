#pragma once
#include<iostream>
#include<vector>
using namespace std;
void count_sort ( int  data [], int n )
{
	int l = 0, h = n - 1;
	//int size = h - l + 1;
	vector<float> b(n);//有size个数据，就分配size个桶
	for ( int i = l; i <= h; i++ )
	{
		int bi = size * A[i];//元素A[i]的桶编号
		b[bi].push_back ( A[i] );//将元素A[i]压入桶中
	}
	for ( int i = 0; i < size; i++ )
		sort ( b[i].begin (), b[i].end () );//桶内排序
	int idx = l;//指向数组A的下标
	for ( int i = 0; i < size; i++ )
	{//遍历桶
		for ( int j = 0; j < b[i].size (); j++ )
		{//遍历桶内元素
			A[idx++] = b[i][j];
		}
	}
	}
