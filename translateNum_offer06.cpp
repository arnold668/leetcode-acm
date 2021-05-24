#include "hpp.hpp"
#include <sstream>
using namespace std;

/*
剑指 Offer 46. 把数字翻译成字符串
给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

示例 1:
输入: 12258
输出: 5
解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
*/

//解题思路，使用动态规划，丑数特点是2、3、5的倍数，对三个值加倍数变量，此外还要考虑到相同情况

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

//建立数字与字母的联系、整数分割分别判断？
//0的情况
// int translateNum(int num)
// {
// 	vector<int> vec;
// 	while(num!=0)
// 	{
// 		vec.push_back(num%10);
// 		num/=10;
// 	}
// 	reverse(vec.begin(),vec.end());
// 	int size=vec.size();
// 	print_v(vec);
// 	vector<int> dp;
// 	dp.resize(size);
// 	dp[0]=1;
// 	if((vec[0]*10+vec[1])>25)	
// 		dp[1]=1;
// 	else
// 		dp[1]=2;
// 	for(int i=2;i<size;i++)
// 	{
// 		if((vec[i-1]*10+vec[i])>25&&vec[i-1]!=0)
// 			dp[i]=dp[i-1];
// 		else
// 			dp[i]=dp[i-1]+dp[i-2];
// 	}
// 	return dp[size-1];

// }
//学习
int translateNum(int num) {
	string s=to_string(num);
	int n=s.size();
	vector<int> dp(n+1);
	dp[0]=1;
	for(int i=1;i<=n;++i)
	{
		dp[i]=dp[i-1];
		if(i>1)
		{
			int subNum=(s[i-2]-'0')*10+s[i-1]-'0';
			if(subNum>=10&&subNum<=25)
				dp[i]+=dp[i-2];
		}

	}
	return dp[n];
}
int main()
{

	int a=0;
	cin>>a;
	int res=translateNum(a);
	cout<<res<<endl;
	cout << "it is end1" << endl;
	return 0;
}

