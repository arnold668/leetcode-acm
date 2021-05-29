#include "hpp.hpp"
#include <sstream>
#include<unordered_map>
#include<algorithm>
#include<limits.h>
#include<cstdio> 
using namespace std;
/*
实现atoi函数：字符串转成int
越过空格
遇上数字或正负号才开始做转换，而再遇到非数字或字符串时（'\0'）才结束转化，
并将结果返回（返回转换后的整型数）。

*/

/*
分析：
1.不满足条件返回0：字符串空、首字母字母a返回0
2.首部情况 ：遇到空格，遇到正负号，遇到0
3.结束条件：非数字或字符串时（'\0'）
4.考虑返回值大小超出int范围

流程：
1.处理首部0
2.处理size=0；
3.处理正负号
4.处理shi
 isdight(str)  #include<cstdio> 
 INT_MAX #include<limits.h>
 res>INT_MAX/10||(res=INT_MAX/10&&str[i]-'0'>7)
 先判断是否溢出，以下四个条件满足任一个则溢出：
1.res>INT_MAX/10;
2.res=INT_MAX/10但是最后一位（即pop）大于7（即INT_MAX%10）；
3.rex<INT_MIN/10；
4.res=INT_MIN/10但是最后一位（即pop）小于-8（即INT_MIN%10）；

*/

int stoi_my(string str)
{
	int i=0;
	int res=0;
	int flag=1;
	while(str[i]==' ')
	{
		i++;
	}
	if(str.size()==0)
		return res;
	if(str[i]=='-') flag=-1;
	if(str[i]=='-'||str[i]=='+') i++;
	while(i<str.size()&&(str[i]>='0')&&(str[i]<='9'))
	{
		int num=str[i]-'0';
		if(res>INT_MAX/10&&(res==INT_MAX/10&&num>7))  
			return flag>0?INT_MAX:INT_MIN;
		res=res*10+num;
		i++;
	}
	return flag>0? res:-res;
}

int main()
{
	string str;
	cin>>str;
	int num=stoi_my(str);
	cout<<num<<endl;
	cout << "it is end1" << endl;
	return 0;
}

