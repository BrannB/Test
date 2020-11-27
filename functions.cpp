#include "sortedList.h"

int insertElement_Rec(pnode *top, int info)
{
	pnode cur;
	if (!(*top))
	{
		*top = new tnode;
		(*top)->info = info;
		(*top)->next = NULL;
		return 1;
	}
	if ((*top)->info >= info)
	{
		cur = new tnode;
		cur->info = info;
		cur->next = *top;
		*top = cur;
		return 1;
	}
	else
		return insertElement_Rec(&(*top)->next, info);
}

pnode sorted_list()
{
	int info;
	pnode cur, top = NULL, prev;
	cin >> info;

	if (info)
	{
		top = new tnode;
		top->info = info;
		top->next = NULL;
	}
	else return NULL;

	cin >> info;
	while (info)
	{
		insertElement_Rec(&top, info);
		cin >> info;
	}

	return top;
}

int deleteNode(pnode * top, int info)
{
	pnode cur, prev;
	if (!(*top)) return 0;
	if ((*top)->info == info)
	{
		cur = *top;
		*top = (*top)->next;
		delete cur;
		return 1;
	}
	else
	{
		prev = *top;
		cur = prev->next;
		while (cur)
		{
			if (cur->info == info)
			{
				prev->next = cur->next;
				delete cur;
				return 1;
			}
			else
			{
				prev = cur;
				cur = cur->next;
			}
		}
	}
	return 0;
}

void output(pnode top)
{
	if (!(top)) cout << "List is empty";
	else
	{
		while (top)
		{
			cout << top->info << " ";
			top = top->next;
		}
		cout << endl;
	}
}