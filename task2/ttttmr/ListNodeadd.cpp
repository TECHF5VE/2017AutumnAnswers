ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* list=new ListNode(0)
    ListNode* p1=l1->next,
              p2=l2->next,
              p3=list->next;
    int num1,num2,//l1和l2的数值
        add=0;//进位标志，初始0
    while(p1!=NULL||p2!=NULL)//均为空时退出
    {
        if(!p1->next)//判断是否为空
        {
            num1=p1->val;//赋值
            p1=p1->next;//下一个
        }
        else num1=0;//为空则置0

        if(!p2->next)//同上
        {
            num2=p2->val;
            p2=p2->next;
        }
        else num2=0;

        p3->val=new ListNode(num1+num2+add);//相加并赋值
        if(p3->val>=10)//判断是否要进位
        {
            p3->val-=10;
            add=1;
        }
        p3=p3->next;
    }
    return list;
}