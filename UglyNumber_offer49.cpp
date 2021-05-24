#include "hpp.hpp"
#include <sstream>
using namespace std;

/*
剑指 Offer 49. 丑数
我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。
示例:

输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
说明:  

1 是丑数。
n 不超过1690。
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


int nthUglyNumber(int n) 
{
	int dp[n+1];
	dp[1]=1;//从1开始
	int p2=1,p3=1,p5=1;
	for(int i=2;i<=n;i++)
	{
		int num2=dp[p2]*2,num3=dp[p3]*3,num5=dp[p5]*5;
		dp[i]=min(num2,min(num3,num5));
		if(num2==dp[i])
			p2++;
		if(num3==dp[i])
			p3++;
		if(num5==dp[i])
			p5++;
	}
	return dp[n];
}


int main()
{

	int a=0;
	cin>>a;
	int res=nthUglyNumber(a);
	cout<<res<<endl;
	cout << "it is end1" << endl;
	return 0;
}

