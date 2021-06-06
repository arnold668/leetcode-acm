#include "hpp.hpp"
#include <sstream>
#include<unordered_map>
#include<algorithm>
#include<limits.h>
#include<cstdio> 
#include <cstring>
using namespace std;
/*
剑指 Offer 57 - II. 和为s的连续正数序列
输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。
*/

/*
1.连续序列相等，选滑动窗口（理解错误，大于三个组成的target，如何分辨，两个可以查询hashmap）
2.超过target/2无论怎么滑动总和必大于target
3.分支判断，如果=target，将当前i减去，并++i
<则sum+=j，>则sum-=i
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

vector<vector<int>> findContinuousSequence(int target) {
	vector<vector<int>> vec;
	int i=1,j=1,sum=0;
	while(i<=target/2)
	{
		if(sum<target)
		{
			sum+=j;
			j++;
		}
		else if(sum>target)
		{
			sum-=i;
			i++;
		}
		else{
			vector<int> res;
			for(int k=i;k<j;k++)
			{
				res.push_back(k);
			}
			vec.push_back(res);
			sum-=i;
			i++;
		}
	}
	return vec;
}

int main()
{
	// vector<int> vec={4,1,2,1,2};
	vector<vector<int>> vec;
	int target=0;
	cin>>target;
	vec=findContinuousSequence(target);
	// cout<<num<<endl;
	print_v(vec);
	cout << "it is end1" << endl;
	return 0;
}

