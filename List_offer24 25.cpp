#include"hpp.hpp"
using namespace std;


struct ListNode
{
	int data;
	ListNode*next;
	ListNode(int x):data(x),next(NULL){}
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

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode*head=new ListNode(0);
	ListNode*tmp=head;
	while(l1!=NULL&&l2!=NULL)
	{
		if(l1->data<l2->data)
		{
			head->next=l1;
			l1=l1->next;
		}
		else
		{
			head->next=l2;
			l2=l2->next;
		}
		//对head进行next
		head=head->next;
	}
	if(l2==NULL)
	{
		head->next=l1;
	}
	else 
	{
		head->next=l2;
	}
	return tmp->next;
}

int main ()
{
	vector<int > vec = {1,2,3,4,5,6,7,8,9 };
	ListNode*head = createList ( vec );
	//1.reverse
	// ListNode*revode = reverseList ( head );
	// while ( revode )
	// {
	// 	cout << revode->data << endl;
	// 	revode = revode->next;
	// }


	//2.test list合并
	vector<int > vec2 = { 1,3,5,7,9};
	ListNode*head2 = createList ( vec2 );
	ListNode*merge=mergeTwoLists(head,head2);
	while ( merge )
	{
		cout << merge->data << endl;
		merge = merge->next;
	}
	system ( "pause" );
}


/*
1.struct �ṹ���÷���ListNode�ڵ�Ѵ���
2.����ʽcin��������
3.ѭ��t�������� ��
*/