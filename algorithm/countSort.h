#pragma once
//��������������� ��ֵ��ΧΪ10���򴴽���ʱ�����СΪ11�����0-11�����������ж������+1
#include<iostream>
using namespace std;


//��������
void count_sort ( int  data[] , int n )
{
	int i, k, idx = 0;
	int max = data[0], min = data[0];
	for ( i = 0; i < n; i++ )
	{//�ҳ���ֵ
		if ( data[i] > max )
			max = data[i];
		else if ( data[i] < min )
			min = data[i];
	}
	cout << max << "\t" << min << endl;
	k = max - min + 1;
	int *b = new int[k]();//��()ָ����ʼ��
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