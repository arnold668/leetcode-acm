#include "hpp.hpp"
#include <sstream>
#include<unordered_map>
using namespace std;

/*
剑指 Offer 50. 第一个只出现一次的字符
在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。

示例:

s = "abaccdeff"
返回 "b"

s = "" 
返回 " "
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

int pass_bridge(vector<int> &vec)
{
	int len=vec.size();
	if(len<=2)
	{
		return vec[len-1];
	}
	else if(len==3)
	{
		return vec[0]+vec[1]+vec[2];
	}
	else{
		int a=vec[0];
		int b=vec[1];
		int d=vec[len-1];
		int c=vec[len-2];
		int totalTime=0;
		//两种情况，需要选最小的方式
		//1.小的送大的过去a+d->d,a->a  即d+2a+c
		//2.两个小的先过桥a+b->b,a->a,c+d->d,b->b;即b+a+d+b;
		//人数>4 d+2a+c>2b+a+d  =>a+c>2b
		if(a+c>2*b)
		{
			vec.erase(vec.end()-1);
			vec.erase(vec.end()-1);
			totalTime+=2*b+a+d+pass_bridge(vec);
		}
		else
		{
			vec.erase(vec.end()-1);
			vec.erase(vec.end()-1);
			totalTime+=d+a+a+c+pass_bridge(vec);
		}
		return totalTime;
	}
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

