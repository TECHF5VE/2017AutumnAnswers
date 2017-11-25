ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* list=new ListNode(0);
    ListNode* p1=l1->next;
    ListNode* p2=l2->next;
    ListNode* p3=list->next;
    int num1,num2,add=0;
    while(p1!=NULL||p2!=NULL)
    {
        if(!p1->next)
        {
            num1=p1->val;
            p1=p1->next;
        }
        else num1=0;

        if(!p2->next)
        {
            num2=p2->val;
            p2=p2->next;
        }
        else num2=0;

        p3=new ListNode(num1+num2+add);
        if(p3->val>=10)
        {
            p3->val-=10;
            add=1;
        }
        p3=p3->next;
    }
    return list;
}
