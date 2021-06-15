#include "hpp.hpp"
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <limits.h>
#include <cstdio>
#include <cstring>
using namespace std;
/*
剑指 Offer 55 - I. 二叉树的深度
输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。

例如：
给定二叉树 [3,9,20,null,null,15,7]，
*/

/*

*/

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode *root)
{
	if (root == nullptr)
		return 0;
	int n = maxDepth(root->left)+1;
	int m = maxDepth(root->right)+1;
	return max(n, m);
}

int main()
{
	// // vector<int> vec={4,1,2,1,2};
	// vector<vector<int>> vec;
	int target = 0;
	cin >> target;
	cout << "it is end1" << endl;
	return 0;
}
