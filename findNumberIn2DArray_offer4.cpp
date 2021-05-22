#include "hpp.hpp"
#include <sstream>
using namespace std;

/*
在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
示例:

现有矩阵 matrix 如下：
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
给定 target = 5，返回 true。
给定 target = 20，返回 false。
*/

//error
//1.边界 [] [[]]:当vec=[]时，vec[0].size()报错

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
		for (int j = 0; j < vec[0].size(); ++j)
			cout << vec[i][j] << " ";
		cout << endl;
	}
}
bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) 
{
	// int row=matrix.size()-1;
	// int col=matrix[0].size()-1;
	// if(row<0||col<0) return false;
	int row=matrix.size()-1;
	if(row<0) return false;
	int col=matrix[0].size()-1;
	int i=row,j=0;
	while (i>=0&&j<=col)
	{
		if(matrix[i][j]>target)
		{
			--i;
		}
		else if(matrix[i][j]<target)
		{
			++j;
		}
		else
		{
			return true;
		}
	}
	return false;
	
}
int main()
{
	//不定行，列输出
	vector<vector<int>> grid;
	string s;
	while(getline(cin,s))
	{
		if(s.size()==0) break;
		stringstream st(s);
		vector<int> vec;
		while(getline(st,s,','))
		{
			vec.push_back(stoi(s));
		}
		grid.push_back(vec);
	}
	print_v(grid);
	cout<<"it is begin"<<endl;
	bool ret=findNumberIn2DArray(grid,5);
	cout<<ret<<endl;
	cout << "it is end1" << endl;
	return 0;
}
