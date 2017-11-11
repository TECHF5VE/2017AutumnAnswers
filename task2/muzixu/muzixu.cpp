#include <iostream>
#include <string>
using namespace std;
struct ListNode {//定义节点
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode *c=new ListNode(l1->val+l2->val);
	ListNode *head=c;
	do{
		if (c->val>=10){
			c->next=new ListNode(1);c->val-=10;
		}
		else c->next=new ListNode(0);
		c=c->next;
		if (l1->next!=NULL) l1=l1->next; else l1->val=0;
		if (l2->next!=NULL) l2=l2->next; else l2->val=0;
		if (l1->next!=NULL||l1->val>0) c->val+=l1->val;
		if (l2->next!=NULL||l2->val>0) c->val+=l2->val;
	}
	while(l1->next!=NULL||l2->next!=NULL);
	return head;
}
	void print(ListNode* l1) {//输出
	while(l1->next!=NULL)	{
		cout<<l1->val;
		l1=l1->next;
	}
	cout<<l1->val<<endl;
}
void main() {
	// test codes example
	int i,lena,lenb;
	ListNode *heada,*headb;
    int a[] = {5,4,6,3};
	int b[] = {9,8,6,3,2,3,5,7,3};
	lena=sizeof(a)/sizeof(a[0]);lenb=sizeof(b)/sizeof(b[0]);
	ListNode* listA = new ListNode(a[0]);heada=listA;
    ListNode* listB = new ListNode(b[0]);headb=listB;	
	for(i=1;i<lena;i++)	{
		listA->next=new ListNode(a[i]);
		listA=listA->next;
	}
	for(i=1;i<lenb;i++)	{
        listB->next=new ListNode(b[i]);
    	listB=listB->next;
	}
	print(addTwoNumbers(heada,headb));
}