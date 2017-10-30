#include<iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x):val(x),next(NULL) {};
};
 
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode*p = l1->next;
    ListNode*q = l2->next;
    int jinwei = 0;
	for(int n = 0;n<3;n++){
		if(jinwei == 1){cout<<(p->val+q->val)+1;jinwei = 0;}
		else
		{
			if((p->val+q->val)>=10){
			jinwei = 1;
			cout<<(p->val+q->val-10);
		 } else{
		 cout<<(p->val+q->val);
	}
		cout<<" ";
		
		p = p->next;
		q = q->next;
	}
}}


int main() {
	// test codes example
	ListNode* listA = new ListNode(0);
	ListNode* listB = new ListNode(0);
	int a[] = {1, 3, 3};
	int b[] = {5, 9, 2};
	ListNode* p = listA; 
	for(int n = 0;n<3;n++){
		p->next = new ListNode(a[n]);
		p = p->next;
	}
	ListNode* q = listB; 
	for(int n = 0;n<3;n++){
		q->next = new ListNode(b[n]);
		q = q->next;
	}
	
	addTwoNumbers(listA, listB);
}
