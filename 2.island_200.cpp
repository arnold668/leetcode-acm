#include "hpp.hpp"
using namespace std;

void print_v(const vector<vector<char>> &vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		for (int j = 0; j < vec[0].size(); ++j)
			cout << vec[i][j] << " ";
		cout << endl;
	}
}

void dfs(vector<vector<char>> &grid, int i, int j)
{
	int nr = grid.size();
	int nc = grid[0].size();
	grid[i][j] = '0';
	//i + 1 < nr 最高下标为nr-1s
	if (i - 1 >= 0 && grid[i - 1][j] == '1')
		dfs(grid, i - 1, j);
	if (i + 1 < nr && grid[i + 1][j] == '1')
		dfs(grid, i + 1, j);
	if (j - 1 >= 0 && grid[i][j - 1] == '1')
		dfs(grid, i, j - 1);
	if (j + 1 <nc && grid[i][j + 1] == '1')
		dfs(grid, i, j + 1);
}
int numIslands(vector<vector<char>> &grid)
{
	int nr = grid.size();
	int nc = grid[0].size();
	int islandNum=0;;
	for (int i = 0; i < nr; ++i)
	{
		for (int j = 0; j < nc; ++j)
		{
			if (grid[i][j] == '1')
			{

				dfs(grid, i, j);
				++islandNum;
			}
		}
	}
	return islandNum;
}

int main()
{
	// 2-D vector fuzhi
	// 1. for 循环。push
	// 2. 初始化 {{1,2},{3,4}};
	// vector<vector<char>> grid = {{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
	vector<vector<char>> grid;
	int row=0,col=0;
	char c;
	cin>>row>>col;
	cin.get();
	for (int i = 0; i < row; ++i)
	{
		vector<char> vec;
		while(cin>>c)
		{
			vec.push_back(c);
			if(cin.get()=='\n')
				break;
		}
		grid.push_back(vec);
	}

	print_v(grid);
	int num=numIslands(grid);
	cout<<num<<endl;
	cout<<"it is end1"<<endl;
	return 0;
}
