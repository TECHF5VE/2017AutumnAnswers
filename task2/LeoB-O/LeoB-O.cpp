ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
{
	ListNode *result = new ListNode();
	ListNode *p = result;
	int next_val = 0;
	int current_val;
	ListNode *pa = l1->next, *pb = l2->next;
	
	//两链表对应位均存在时相加
	while (pa != nullptr && pb != nullptr)
	{
		current_val = pa->val + pb->val + next_val;
		next_val = current_val / 10;
		current_val %= 10;
		p->next = new ListNode(current_val);
		p = p->next;
		pa = pa->next;
		pb = pb->next;
	}

	//较长链表剩余位进位赋值
	while (pa != nullptr)
	{
		current_val = pa->val + next_val;
		next_val = current_val / 10;
		current_val %= 10;
		p->next = new ListNode(current_val);
		p = p->next;
		pa = pa->next;
	}
	while (pb != nullptr)
	{
		current_val = pb->val + next_val;
		next_val = current_val / 10;
		current_val %= 10;
		p->next = new ListNode(current_val);
		p = p->next;
		pb = pb->next;
	}
	if (next_val != 0)
	{
		p->next = new ListNode(next_val);
	}

	return result;
}