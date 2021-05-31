#include "hpp.hpp"
#include <sstream>
#include<unordered_map>
#include<algorithm>
#include<limits.h>
#include<cstdio> 
#include <cstring>
using namespace std;
/*
136. 只出现一次的数字
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

*/

/*
1.for循环遍历
2.hash map
3.异或 
任何数和 00 做异或运算，结果仍然是原来的数，即 a⊕0=a。
任何数和其自身做异或运算，结果是 00，即 a⊕a=0。
异或运算满足交换律和结合律，即 a⊕b⊕a=b⊕a⊕a=b⊕(a⊕a)=b⊕0=b。
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


// int singleNumber(vector<int>& nums) {
// 	// if(nums.size()==0) return ;
// 	unordered_map<int,bool> mp;
// 	int len=nums.size();
// 	for(int i=0;i<len;++i)
// 	{
// 		if(mp.find(nums[i])!=mp.end())
// 			mp[nums[i]]=false;
// 		else
// 			mp[nums[i]]=true;
// 	}
// 		for(int i=0;i<len;++i)
// 		{
// 			if(mp[nums[i]]==true)
// 				return nums[i];
// 		}
// 		return -1;
// 	}
// }

// int singleNumber(vector<int>& nums) {
// 	int len=nums.size();
// 	for(int i=0;i<len;++i)
// 	{
// 		int temp=nums[i];
// 		int flag=1;
// 		for(int j=0;j<len;++j)
// 		{
// 			if(nums[j]==temp&&j!=i)
// 			{
// 				flag=0;
// 				break;
// 			}
// 		}
// 		if(flag==1)
// 		{
// 			return temp;
// 		}
// 	}
// 	return -1;
// }

int singleNumber(vector<int>& nums) {
	int len=nums.size();
	int res=0;
	for(int i=0;i<len;++i)
	{
		res^=nums[i];
	}
	return res;
}

int main()
{
	vector<int> vec={4,1,2,1,2};
	int num=singleNumber(vec);
	cout<<num<<endl;
	cout << "it is end1" << endl;
	return 0;
}

