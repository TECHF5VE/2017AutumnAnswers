#include <iostream>
using namespace std;

//链表节点定义
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x = 0, ListNode* next = nullptr) :val(x), next(next)
	{}
};

//两数相加
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

//打印链表
void showList(ListNode* list)
{
	ListNode *p = list->next;
	while (p != nullptr)
	{
		cout << p->val << ' ';
		p = p->next;
	}
}

//用数组初始化链表
void initList(ListNode * list, int *data, int length)
{
	ListNode *p = list;
	for (int i = 0; i < length; i++)
	{
		p->next = new ListNode(data[i]);
		p = p->next;
	}
}


template <class T>
int getArrayLen(T& array)
{
	return (sizeof(array) / sizeof(array[0]));
}


int main()
{
	ListNode *listA = new ListNode();
	ListNode *listB = new ListNode();
	int a[] = { 1, 2, 3, 4 };
	int b[] = { 5, 6 };
	initList(listA, a, getArrayLen(a));
	initList(listB, b, getArrayLen(b));

	ListNode *result = addTwoNumbers(listA, listB);
	showList(result);

	system("pause");
	return 0;
}


