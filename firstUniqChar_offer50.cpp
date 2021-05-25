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

char firstUniqChar(string s) {
	if(s.size()==0) return ' ';
	unordered_map<char,bool> mp;
	for(int i=0;i<s.size();++i)
	{
		if(mp.find(s[i])!=mp.end())
			mp[s[i]]=false;
		else
			mp[s[i]]=true;
	}
	for(int i=0;i<s.size();++i)
	{
		if(mp[s[i]]==true)
			return s[i];
	}
	return ' ';
}

int main()
{

	string  s;
	cin>>s;
	char res=firstUniqChar(s);
	cout<<res<<endl;
	cout << "it is end1" << endl;
	return 0;
}

