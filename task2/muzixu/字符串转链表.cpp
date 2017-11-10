#include <iostream>
#include <string>
using namespace std;
struct ListNode {//定义节点
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
typedef ListNode LI;//别名
void addTwoNumbers(ListNode* l1, ListNode* l2,int len) {//两链表相加
	LI *q1=l1,*q2=l2;int i=0;
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
			q1->next=new LI(1);
			q1->val-=10;
		}
	q1=q1->next;q2=q2->next;i++;
	} 
	while(i<len); 
}
void print(LI* l1)//输出
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
	int i,lena,lenb,x;
	LI *heada,*headb;
	string a,b,ch;
	cin>>a;cin>>b;
	lena=a.length();lenb=b.length();
	if (lena<lenb) {ch=a;a=b;b=ch;x=lena;lena=lenb;lenb=x;}
	ListNode* listA = new ListNode(a[0]-'0');heada=listA;
    ListNode* listB = new ListNode(b[0]-'0');headb=listB;
      for (i=1;i<lena;i++)
	  {
          listA->next=new ListNode(a[i]-'0');
	      listA=listA->next;
	  }
	  for (i=1;i<lenb;i++)
	  {
		  listB->next=new ListNode(b[i]-'0');
		  listB=listB->next;
	  }
    addTwoNumbers(heada,headb,lenb);
	print(heada);
}