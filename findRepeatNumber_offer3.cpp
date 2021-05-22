#include "hpp.hpp"
using namespace std;

/*
找出数组中重复的数字。
在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

示例 1：
输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

void print_v(const vector<int> &vec)
{
	for (int j = 0; j < vec.size(); ++j)
		cout << vec[j] << " ";
	cout << endl;
}

int findRepeatNumber(vector<int> &nums)
{
	int n=nums.size();
	int a[100001]={0};
	for(int i=0;i<n;++i)
	{
		++a[nums[i]];
		if(	a[nums[i]]>1)
			return nums[i];
	}
	return 0;

}


int findRepeatNumber_1(vector<int> &nums)
{
	int n=nums.size();
	sort(nums.begin(),nums.end());
	for(int i=0;i<n-1;++i)
	{
		if(nums[i]==nums[i+1])
			return nums[i];
	}
	return 0;
}

int main()
{
	vector<int> vec;
	int a;
	while (cin >> a)
	{
		vec.push_back(a);
		if (cin.get() == '\n')
			break;
	}

	print_v(vec);
	cout<<"it is begin"<<endl;
	int ret=findRepeatNumber_1(vec);
	cout<<ret<<endl;
	cout << "it is end1" << endl;
	return 0;
}
