#include <stdio.h>

typedef struct ListNode {
     int val;
     struct ListNode *next;
 } ListNode;
 
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
        int jw=0;
        ListNode *r = 0;
        ListNode *head = 0;
        while(l1||l2||jw)
        {
        	if(r)
        	{
        	r->next=malloc(sizeof(ListNode));
        		r->next->val=0;
        		r->next->next=0;
        	r=r->next;
        	}
        	else
        	head=r=malloc(sizeof(ListNode));
        	r->val=(l1?l1->val:0)+
        	(l2?l2->val:0)+jw;
        	jw=r->val/10;
        	r->val%=10;
        	l1=l1?l1->next:0;
        	l2=l2?l2->next:0;
        }
        return head;
}

int main() 
{
	ListNode *listA;
	ListNode *listB;
	ListNode *t;
	int a[] = {1, 3, 3};
	int b[] = {5, 9, 2};
	int i;
	listA=malloc(sizeof(ListNode));
	listB=malloc(sizeof(ListNode));
	t=listA;
	t->next=0;
	t->val=0;
	for(i=0;i<sizeof(a)/sizeof(int);i++) 
	{
		t->val=a[i];
		t->next=malloc(sizeof(ListNode));
		t->next->next=0;
		t=t->next;
	}
	t=listB;
	t->next=0;
	for(i=0;i<sizeof(b)/sizeof(int);i++) 
	{
		t->val=b[i];
		t->next=malloc(sizeof(ListNode));
		t->next->next=0;
		t=t->next;
	}
	listA=addTwoNumbers(listA, listB);
	while(listA){
		printf("%d\n",listA->val);
		listA=listA->next;
	}
	return 0;
}
