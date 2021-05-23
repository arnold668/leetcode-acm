#include "hpp.hpp"
#include <sstream>
using namespace std;

/*
剑指 Offer 07. 重建二叉树
输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
		for (int j = 0; j < vec[0].size(); ++j)
			cout << vec[i][j] << " ";
		cout << endl;
	}
}

// struct Node{
// 	int val;
// 	Node*left;
// 	Node*right;
// 	/* data */
// };
struct TreeNode{
	int val;
	TreeNode*left;
	TreeNode*right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
	/* data */
};

//先序、中序构造二叉树，需要四个参数。中序以根元素划分，主要前序的左子树最后一个元素为pr_l+leftlen_subTree
TreeNode*rebuildTree(vector<int>& preorder, vector<int>& inorder,int pr_l,int pr_r,int in_l,int in_r)
{
	if(pr_l>pr_r) return NULL;
	TreeNode*root=new TreeNode(preorder[pr_l]);
	cout<<root->val<<" ";
	int i=0;
	for(i=in_l;i<in_r;i++)
	{
		if(inorder[i]==preorder[pr_l])
			break;
	}
	//左子树大小由中序确定 i-左边界
	int leftlen_subTree=i-in_l;
	root->left=rebuildTree(preorder,inorder,pr_l+1,pr_l+leftlen_subTree,in_l,i-1);
	root->right=rebuildTree(preorder,inorder,pr_l+leftlen_subTree+1,pr_r,i+1,in_r);
	return root;

}
//后序。中序构造二叉树，需要三个参数，中序以根元素划分，pr_r减去右子树大小为左子树最后一个元素，即左子树根元素
TreeNode*rebuildTree(vector<int>& postorder, vector<int>& inorder,int pr_r,int in_l,int in_r)
{
	if(in_l>in_r) return NULL;
	TreeNode*root=new TreeNode(postorder[pr_r]);
	cout<<root->val<<" ";
	int i=0;
	for(i=in_l;i<in_r;i++)
	{
		if(inorder[i]==postorder[pr_r])
			break;
	}
	//左子树大小由中序确定 i-左边界，pr_r减去右子树大小为左子树最后一个元素，即左子树根元素
	// 
	root->left=rebuildTree(postorder,inorder,pr_r-1-in_r+i,in_l,i-1);
	root->right=rebuildTree(postorder,inorder,pr_r-1,i+1,in_r);
	return root;

}


void preorder(TreeNode*node,vector<int> &vec)
{
	if(node==NULL)
		return;
	cout<<node->val<<" ";
	//vec.push_back(node->val);
	preorder(node->left,vec);
	preorder(node->right,vec);
}


void inorder(TreeNode*node,vector<int> &vec)
{
	if(node==NULL)
		return;
	inorder(node->left,vec);
	cout<<node->val<<" ";
	inorder(node->right,vec);
}

void postorder(TreeNode*node,vector<int> &vec)
{
	if(node==NULL)
		return;
	postorder(node->left,vec);
	postorder(node->right,vec);
	cout<<node->val<<" ";
}


vector<vector<int>> levelOrder(TreeNode* root) 
{
	vector<vector<int>> vec;
	if(!root) return vec;
	queue<TreeNode*> que;
	que.push(root);
	while(!que.empty())
	{
		vector<int> res;
		int size=que.size();
		for(int i=0;i<size;++i)
		{
			TreeNode*temp=que.front();
			res.push_back(temp->val);
			que.pop();
			if(temp->left!=NULL) que.push(temp->left);
			if(temp->right!=NULL) que.push(temp->right);
		}
		if(!res.empty()) 
			vec.push_back(res);

	}
	return vec;
}
int main()
{
	//不定行，列输出
	vector<vector<int>> grid;
	vector<int> pre={3,9,20,15,7};
	vector<int> in={9,3,15,20,7};
	vector<int> post={9,15,7,20,3};

	cout<<"it is begin"<<endl;
	TreeNode* head=rebuildTree(pre,in,0,4,0,4);
	cout<<endl;
	TreeNode* head1=rebuildTree(post,in,4,0,4);
	cout<<endl;
	vector<int> vec;
	grid=levelOrder(head);
	// postorder(head1,vec);
	// inorder(head,vec);
	print_v(grid);
	cout << "it is end1" << endl;
	return 0;
}

