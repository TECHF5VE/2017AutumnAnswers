/*
ID：6 MinoYu
For Task2 
*/ 

ListNode *addtwonumbers(ListNode *list1,ListNode *list2)
{
     ListNode *list3=new ListNode(0);
     ListNode *p,*q,*l;
     l=list3;
     int n,i=0;

  for(p=list1,q=list2;((p->next!=NULL)&&(q->next!=NULL));p=p->next,q=q->next)
   { n=(p->next->val)+(q->next->val)+i;
       if(n>=10)  
      {
          i=n/10;
          n=n%10;
      }else  i=0;
     
	 l->next=new ListNode(n);
     l=l->next ;
   }

  for(;(p->next==NULL)&&(q->next!=NULL);q=q->next)
  {
     n=q->next->val;
     l->next=new ListNode(n);
     l=l->next;
  }
 for(;(p->next!=NULL)&&(q->next==NULL);p=p->next)
 {
     n=p->next->val;
     l->next=new ListNode(n);
     l=l->next;
  }
   return list3;
}
 void showList(ListNode *list)
 {
 	ListNode *p = list->next;
 	while (p != NULL)
 	{
		cout << p->val << ' ';
 		p = p->next;
 	}
 }

int main()
{
   ListNode *list1=new ListNode(0);
   ListNode *list2=new ListNode(0);

   int a[]={2,4,3};
   int b[]={5,6,4};

   ListNode *p=list1;
   ListNode *q=list2;

    for(int r=0;r<sizeof(a)/sizeof(int);++r)
  {
      p->next=new ListNode(a[r]);
      p=p->next;
  }

 for(int t=0;t<sizeof(b)/sizeof(int);++t)
  {
  q->next=new ListNode(b[t]);
  q=q->next;
  }
 ListNode *res=addtwonumbers(list1,list2);
 showList(res);
 return 0;
}
