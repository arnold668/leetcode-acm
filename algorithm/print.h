#pragma once
#include<iostream>
#include<vector>
using namespace std;
void print_cur ( int  arr [], int n )
{
	cout << "��ǰ����Ϊ" << endl;
	//cout << sizeof arr << endl;���鴫��ʱֻ�ᴫ��������׵�ַ�������ں�����Ҫ�õ�����Ԫ��ʱ�ٸ����׵�ַ���±�ȥ��
	for ( int i = 0; i < n; i++ )
	{//�������
		cout << arr[i] << "\t";
	}
	cout << endl;
}
 void print_sort(vector<int> data) {
	cout << "������Ϊ" << endl;
	for (int i = 0; i < data.size(); i++) {//�������
		cout << data[i] << "\t";
	}
	cout << endl;
}

 void print_sort(int  arr[], int n) {
	cout << "������Ϊ" << endl;
	//cout << sizeof arr << endl;���鴫��ʱֻ�ᴫ��������׵�ַ�������ں�����Ҫ�õ�����Ԫ��ʱ�ٸ����׵�ַ���±�ȥ��
	for (int i = 0; i < n; i++) {//�������
		cout << arr[i] << "\t";
	}
	cout << endl;
}