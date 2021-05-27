#include "hpp.hpp"
#include <sstream>
#include<unordered_map>
#include<algorithm>
using namespace std;

/*
排序算法
*/

void print_v(const vector<int> &vec)
{
	for (int j = 0; j < vec.size(); ++j)
		cout << vec[j] << " ";
	cout << endl;
}

void print_v(const vector<vector<int>> &vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		for (int j = 0; j < vec[i].size(); ++j)
			cout << vec[i][j] << " ";
		cout << endl;
	}
}


void bubble_sort(int a[],int n)
{
	int flag=1;
	for(int i=0;i<n;i++)
	{
		flag=0;
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				swap(a[j],a[j+1]);
				flag=1;
			}
		}
		if(flag==0) return;
	}
}

//
int part(vector<int>&data,int low,int high)
{
	int tmp=data[high];
	int curr=low-1;
	for(int i=low;i<high,++i)
	{
		if(tmp<=data[i])
		{
			curr++;
			swap(data[i],data[curr]);
		}

	}
	swap(data[curr+1],data[high]);
	return curr+1;
}
void quick_sort(vector<int>&data,int low,int high)
{
	if(low>high)
		return ;
	int position=part(data,low,high);
	quick_sort(data,low,position-1);
	quick_sort(data,position+1,high);

}
//插入  第二循环j额外定义,插入从第一张牌开始，所以i=1

void insert_sort(int a[],int len)
{
	for(int i=1;i<len;i++)
	{
		int tmp=a[i];
		int j=0;
		for(j=i-1;j>=0;j--)
		{
			if(a[j]>tmp)
				swap(a[j],a[j+1]);
			else
				break;
		}
		a[j+1]=tmp;
	}
}
//shell sort
void shell_sort(int a[],int len)
{
	for(int gap=len/2;gap>0;gap/=2)
	{
		for(int i=gap;i<len;i++)
		{
			int tmp=a[i];
			int j=0;
			for(j=i-gap;j>=0;j-=gap)
			{
				if(a[j]>tmp)
					swap(a[j],a[j+1]);
				else
					break;
		}
		a[j+gap]=tmp;
		}
	}
}
void choose_sort(int a[],int len)
{
	for(int i=0;i<len;i++)
	{
		int max=len-i-1;
		for(int j=0;j<len-i-1;j++)
		{
			if(a[max]<a[j])
				max=j;
		}
		if(max!=n-i-1)
			swap(a[max],a[len-i-1]);
	}
}

int bin_search(int a[],int len, int key)
{
	int mid;
	int low=0,high=len-1;
	while(low<high)
	{
		mid=low+(high-low)/2;
		if(a[mid]==key)
		{
			return mid
		}
		else if(a[mid]>key)
		{
			low=mid+1;
		}
		else
		{
			high=mid-1;
		}

	}
	return -1;
}
int main()
{
	vector<int> vec;
	int len=0,a=0;
	cin>>len;
	for(int i=0;i<len;++i)
	{
		cin>>a;
		vec.push_back(a);
	}
	int res=pass_bridge(vec);
	cout<<res<<endl;
	cout << "it is end1" << endl;
	return 0;
}

