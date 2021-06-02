#include"hpp.h"
using namespace std;


struct ListNode
{
	int data;
	ListNode*next;
	ListNode():next(NULL){}
};

ListNode* createList (vector<int > arr)
{
	ListNode *head = new  ListNode;
	ListNode*p = head;
	head->data = arr[0];
	//head->next = NULL;
	for ( int i = 1; i <arr.size(); i++ )
	{
		ListNode*tmp = new ListNode;
		tmp->data = arr[i];
		p->next = tmp;
		p = tmp;
	}
	return head;
}

ListNode* reverseList (ListNode*head)
{
	ListNode*p = head, *prear = NULL, *pnow = head;
	
	while( pnow!= NULL )
	{
		p = p->next;
		pnow->next = prear;
		prear = pnow;
		pnow = p;
	}
	return prear;
	
}

int main ()
{
	int a [] = { 9,8,7,6,5,4,3,2,1 };
	vector<int > vec = { 9,8,7,6,5,4,3,2,1 };
	ListNode*head = createList ( vec );
	ListNode*revode = reverseList ( head );
	while ( revode )
	{
		cout << revode->data << endl;
		revode = revode->next;
	}
	system ( "pause" );
}


/*
1.struct �ṹ���÷���ListNode�ڵ�Ѵ���
2.����ʽcin��������
3.ѭ��t�������� ��
*/