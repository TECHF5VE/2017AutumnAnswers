

/**
 * Definition for singly-linked list.*/
struct ListNode {
     int val;
     ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int jw=0;
        ListNode* r = 0;
        ListNode* head = 0;
        while(l1||l2||jw){
        	if(r){
        		r->next=new ListNode();
        	r=r->next;
        	}
        	else
        	head=r=new ListNode();
        	r->val=(l1?l1->val:0)+
        	(l2?l2->val:0)+jw;
        	jw=r->val/10;
        	r->val%=10;
        	l1=l1?l1->next:0;
        	l2=l2?l2->next:0;
        }
        return head;
}


int main() {
	// test codes example
	ListNode* listA = new ListNode();
	ListNode* listB = new ListNode();
	int a[] = {1, 3, 3,0};
	int b[] = {5, 9, 2,0};
	int i;
	t=listA;
	for(i=0;i<sizeof(a);i++) {
		// initilise listA
		ListNode *t;
		t->val=a[i];
		t->next=new ListNode();
		t=t->next;
	}
	t=listB;
	for(i=0;i<sizeof(b);i++) {
		// initilise listA
		ListNode *t;
		t->val=b[i];
		t->next=new ListNode();
		t=t->next;
	}
	listA=addTwoNumbers(listA, listB);
	while(listA){
		printf("%d\n",listA->val);
		listA=listA->next;
	}
}
