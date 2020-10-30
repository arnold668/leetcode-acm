#pragma once
//计数排序，这个数组 的值范围为10，则创建临时数组大小为11，存放0-11个数，分析判断如果是+1
#include<iostream>
using namespace std;


//计数排序
void count_sort ( int  data[] , int n )
{
	int i, k, idx = 0;
	int max = data[0], min = data[0];
	for ( i = 0; i < n; i++ )
	{//找出最值
		if ( data[i] > max )
			max = data[i];
		else if ( data[i] < min )
			min = data[i];
	}
	cout << max << "\t" << min << endl;
	k = max - min + 1;
	int *b = new int[k]();//加()指定初始化
	for ( i = 0; i < k; i++ )
	{
		//b[i] = 0;
		cout << b[i];
	}
	for ( i = 0; i < n; i++ )
	{
		b[data[i] - min]++;

	}

	for ( i = 0; i < k; i++ )
	{
		while ( (b[i]--) > 0 )
		{
			data[idx] = i + min;
			idx++;
		}
	}
	delete []b;
}