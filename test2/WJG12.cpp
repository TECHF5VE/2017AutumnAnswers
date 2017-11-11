#include<iostream>
struct ListNode{
	int val;
	ListNode *next;
	ListNode (int x):val(x),next（NULL）{} 
};//链表结点定义 
ListNode* addTwoNumbers(ListNode* l1,ListNode* l2)//()参数表 
{
	ListNode* listC=new ListNode（0）；
	ListNode *p,*q,*1;
	l=listC,p=l1,q=l2;
	
	if(l1==NULL)
	return l2;  
	if(l2==NULL) 
	return l1;//当其中有一个链表为空时
	
	int sum,step;
	for(p=l1,q=l2;p!=NULL&&q!=NULL;p=p->next,q=q->next)
	{
		sum=(p->val)+(q->val)+step;
		if(sum>=10)
		{
			sum=sum%10;
			step=1;
		}
		else
		step=0;
	}
	
	}	
    int main ()
{
	  ListNode* ListA =new ListNode(0);
  	ListNode* ListB =new ListNode(0);
  	int a[]={1,3,3};
  	int b[]={5,9,2};
  	//initilise listA and listB
  	int i,j;
  	ListNode*p,*q;
  	p=ListA;
  	q=ListB;
  	for（int i=0;i<sizeof(a)/sizeof(int);i++）
    { 
  	p=new ListNode(a[i]);
  	p=p->next; 
  	}
    for (int j=0;j<sizeof(b)/sizeof(int);j++ )
    {
    q->next=add ListNode(b[j]);
	  }

  	for(l=listC;l->next!=NULL;l=l->next)
  	cout<<l->val<<endl; 
  addTwoNumbers(ListA,ListB);
  returm 0; 
  }
}
