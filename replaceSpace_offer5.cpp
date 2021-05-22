#include "hpp.hpp"
#include <sstream>
using namespace std;

/*
剑指 Offer 05. 替换空格
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

 

示例 1：

输入：s = "We are happy."
输出："We%20are%20happy."
*/




string replaceSpace(string s) 
{
	int n=s.size();
	int num_space=0;
	for(int i=0;i<s.size();++i)
	{
		if(s[i]==' ')
			++num_space;
	}
	int len=num_space*2+n;
	s.resize(len);
	len--;
	for(int i=n-1;i>=0;--i)
	{
		if(s[i]==' ')
		{
			s[len--]='0';
			s[len--]='2';
			s[len--]='%';

		}
		else
			s[len--]=s[i];
	}
	return s;
}


int main()
{
	//care that input include space,choose getline
	vector<vector<int>> grid;
	string s;
	getline(cin,s);
	cout<<"it is begin"<<endl;
	string ret=replaceSpace(s);
	cout<<ret<<endl;
	cout << "it is end1" << endl;
	return 0;
}

