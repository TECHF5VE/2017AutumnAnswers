#include <iostream>
#include <string>
using namespace std;
struct ListNode {//定义节点
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void addTwoNumbers(ListNode* l1, ListNode* l2,int len) {
	ListNode *q1=l1,*q2=l2;int i=0;
	do
	{
	q1->val+=q2->val;
	if (q1->val>=10)
    	if (q1->next!=NULL)
		{
			q1->next->val++;
			q1->val-=10;
		}
		else
		{
			q1->next=new ListNode(1);
			q1->val-=10;
		}
	q1=q1->next;q2=q2->next;i++;
	} 
	while(i<len); 
}
void print(ListNode* l1)//输出
{
	while(l1->next!=NULL)
	{
		cout<<l1->val;
		l1=l1->next;
	}
	cout<<l1->val<<endl;
}
void main() {
	// test codes example
	int i,lena,lenb,max;
	ListNode *heada,*headb;
    int a[] = {1, 3, 3};
	int b[] = {5, 9, 2};
	lena=sizeof(a)/sizeof(a[0]);lenb=sizeof(b)/sizeof(b[0]);
	max=lena;if(lena<lenb) max=lenb;
	ListNode* listA = new ListNode(a[0]);heada=listA;
    ListNode* listB = new ListNode(b[0]);headb=listB;	
	for(i=1;i<lena;i++)
	{
		listA->next=new ListNode(a[i]);
		listA=listA->next;
	}
	for(i=1;i<lenb;i++)
	{
        listB->next=new ListNode(b[i]);
    	listB=listB->next;
	}
    if (max=lena) {addTwoNumbers(heada,headb,max);print(heada);}
	else {addTwoNumbers(headb,heada,max);print(headb);}
}