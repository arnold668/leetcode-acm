#pragma once
#include<iostream>
#include<vector>
#include"print.h"
using namespace std;
//�����1. ���뺯�������forѭ���ķ�Χ����Ӧ����low��high��
//2.vector����������Ҫ�ı䣬��Ҫʹ�ô����÷�ʽ
//����ѭ��  for (int i = 0; i < data.size() - 1; i++) {
//��Ҫ˼�룬����˫ָ�뷨����ָ�����С�ڻ�׼��������ָ����ָ��һ���������ָ����ָ����swap
//void print_sort(vector<int> data);
int partition(vector<int> &data, int low, int high) {
	int tmp = data[high];  //����ǰ�������һλΪ��׼
	int curr = low - 1;  //��ָ���low-1��ʼ
	for (int i = low; i < high; i++) { //��ΧΪ[low,high-1],ȡ����high
		if (data[i] <= tmp) {  //����ΪС�ڵ���
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
		quick_sort(data, position +1, high);//position +1����high
	}
	else
		return;
}


//2.��ָ��ģʽ��ע������ (*data)[high]
//int partition(vector<int> *data, int low, int high) {
//	int tmp = (*data)[high];  //����ǰ�������һλΪ��׼
//	int curr = low - 1;  //��ָ���low-1��ʼ
//	for (int i = low; i < high; i++) { //��ΧΪ[low,high-1],ȡ����high
//		if ((*data)[i] <= tmp) {  //����ΪС�ڵ���
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
//		quick_sort(data, position + 1, high);//position +1����high
//	}
//	else
//		return;
//}

//3.����ݹ�
//�����1����߱Ƚ�Ӧ����<=
//void quicksort ( vector<int>&a,int left, int right )
//{
//	int i, j, t, temp;
//	if ( left > right )
//		return;
//
//	temp = a[left]; //temp�д�ľ��ǻ�׼��
//	i = left;
//	j = right;
//	while ( i != j )
//	{
//		//˳�����Ҫ��Ҫ�ȴ��ұ߿�ʼ��
//		while ( a[j] >= temp && i < j )
//			j--;
//		//�����ұߵ�
//		cout << "j=" << j << "   ";
//		while ( a[i] <= temp && i < j )
//			i++;
//		cout<< "i=" << i<<endl;
//		//�����������������е�λ��
//		if ( i < j )
//		{
//			t = a[i];
//			a[i] = a[j];
//			a[j] = t;
//		}
//		print_sort ( a );
//	}
//	//���ս���׼����λ
//	a[left] = a[i];
//	a[i] = temp;
//
//	quicksort ( a,left, i - 1 );//����������ߵģ�������һ���ݹ�Ĺ���
//	quicksort ( a, i + 1, right );//���������ұߵ� ��������һ���ݹ�Ĺ���
//}
