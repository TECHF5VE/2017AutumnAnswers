//Definition for singly-linked list.
#include<iostream>
using namespace std;
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {};
  };
 
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode* listC=new ListNode(0);
	  ListNode *p,*q,*l;
	  l=listC;
	  int n,i=0;
	  
	  for(p=l1,q=l2;((p->next!=NULL)&&(q->next!=NULL));q=q->next,p=p->next)
	  {
		  n=(p->next->val)+(q->next->val)+i;
			  if(n>=10){
				  n=n%10;i=1;
			  }
			  else i=0;
			  l->next=new ListNode(n);
		  l=l->next;
	  }
	  for(;p->next!=NULL;p=p->next)
	  {
		  l->next=new ListNode(p->next->val+i);
		  l=l->next;
		  i=0;
	  }
	  for(;q->next!=NULL;q=q->next)
	    {
		  l->next=new ListNode(q->next->val+i);
		  l=l->next;
		  i=0;
	  }
	  return listC;
}


int main() {
	// test codes example
	ListNode* listA = new ListNode(0);
	ListNode* listB = new ListNode(0);
	int a[] = {1, 2,3,4};
	int b[] = {5, 6};
	ListNode *p=listA;
	ListNode *q=listB;
	for(int i=0;i<sizeof(a)/sizeof(int);i++) {
		p->next=new ListNode(a[i]);
		p=p->next;
		// initilise listA 
	}
	for(int i=0;i<sizeof(b)/sizeof(int);i++)
	{
		q->next=new ListNode(b[i]);
		q=q->next;
		// initilise listB
	}
	addTwoNumbers(listA, listB);
	return 0;
}