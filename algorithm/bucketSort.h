#pragma once
#include<iostream>
#include<vector>
using namespace std;
void count_sort ( int  data [], int n )
{
	int l = 0, h = n - 1;
	//int size = h - l + 1;
	vector<float> b(n);//��size�����ݣ��ͷ���size��Ͱ
	for ( int i = l; i <= h; i++ )
	{
		int bi = size * A[i];//Ԫ��A[i]��Ͱ���
		b[bi].push_back ( A[i] );//��Ԫ��A[i]ѹ��Ͱ��
	}
	for ( int i = 0; i < size; i++ )
		sort ( b[i].begin (), b[i].end () );//Ͱ������
	int idx = l;//ָ������A���±�
	for ( int i = 0; i < size; i++ )
	{//����Ͱ
		for ( int j = 0; j < b[i].size (); j++ )
		{//����Ͱ��Ԫ��
			A[idx++] = b[i][j];
		}
	}
	}
