#include "hpp.hpp"
#include <sstream>
#include<unordered_map>
#include<algorithm>
#include<limits.h>
#include<cstdio> 
using namespace std;
/*
344. 反转字符串
编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。

不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。

你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

/*


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



void revser_str(string &str)
{
	int len=str.size();
	for(int i=0;i<len/2;i++)
	{
		swap(str[i],str[len-1-i]);
	}
}

int main()
{
	string str;
	cin>>str;
	cout<<str<<endl;
	revser_str(str);
	cout<<str<<endl;
	cout << "it is end1" << endl;
	return 0;
}

