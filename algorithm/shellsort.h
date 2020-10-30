#pragma once
#pragma once
#include<iostream>
using namespace std;
//�ײ� ��ֵ��
//void shell_sort(int arr[], int n) {
//	for (int gap = n / 2; gap > 0; gap /= 2) {
//		for (int j = gap; j < n; j++) {
//			int tmp = arr[j];
//			int i = 0;
//			for (i = j - gap; i >=0; i-=gap) { //˼���ǱȽ���һ���ƺ͵�ǰ��
//				if (arr[i] > tmp) {
//					//swap(arr[i], arr[i + 1]);����ֱ�Ӹ�ֵ
//					arr[i + gap] = arr[i];
//				}
//				else
//					break;
//			}
//			arr[i + gap] = tmp;
//		}
//	}
//}

//�ײ� ��ð��
//����: if (flag == 0)  ��break; ��ͳ��ð�� ˵������ɣ�ʹ��return
void shell_sort(int arr[], int n) {
	for (int gap = n / 2; gap > 0; gap /= 2) {
		int flag = 1;
		for (int i = 0; i < n; i++) {
			flag = 0;
			for (int j = 0; j < n - gap - i; j += gap) {//���Ϊgap��������Ԫ�ظ���
				if (arr[j] > arr[j + gap]) {
					swap(arr[j], arr[j + gap]);
					flag = 1;
				}
			}
			if (flag == 0)  break;
		}
	}
}