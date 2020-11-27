#include "2list.h"

void formList(p2node *head, p2node*tail) //Формирование списка
{
	p2node cur;
	int info;
	cout << "Enter elements of list:" << endl;
	cin >> info;
	if (info)
	{
		*head = new t2node;    //создаем голову списка
		(*head)->info = info;
		(*head)->prev = NULL;
	}
	else return;
	cin >> info;
	cur = *head;
	while (info)
	{
		cur->next = new t2node;
		cur->next->prev = cur;
		cur = cur->next;
		cur->info = info;
		cin >> info;
	}
	cur->next = NULL;
	*tail = cur;
}

void printStraight(p2node head) //Вывод в прямом порядке
{ 
	p2node cur;
	cur = head;
	while (cur)
	{
		cout << cur->info << " ";
		cur = cur->next;
	}
	cout << endl;
}

void printReverse(p2node tail)  //Вывод в обратном порядке
{
	p2node cur;
	cur = tail;
	while (cur)
	{
		cout << cur->info << " ";
		cur = cur->prev;
	}
	cout << endl << endl;
}

int deleteNode(p2node* head, p2node* tail, int info)  //Удаление элемента
{
	p2node cur;

	if (*head == NULL) return 0;  //Проверка списка на пустоту

	if ((*head)->info == info)  //Если нужно удалить голову
	{
		cur = *head;
		*head = (*head)->next;
		//(*head)->next = cur->next->next;
		(*head)->prev = NULL;
		delete cur;
		return 1;
	}

	cur = (*head)->next;

	while (cur)
	{
		if (cur->info == info)
		{
			if (cur->next != NULL)
			{
				cur->prev->next = cur->next;
				cur->next->prev = cur->prev;
				delete cur;
				return 1;
			}
			else		//Если нужно будет изменить хвост
			{
				(*tail) = cur->prev;
				(*tail)->next = NULL;
				delete cur;
				return 1;
			}
		}
		else cur = cur->next;
	}
	return 0;
}

int insertBefore(p2node* head, int info, int new_info) // Вставка перед
{
	p2node cur, previos, newNode;
	if (head == NULL) return 0;

	if ((*head)->info == info)   // Если нужно вставить перед первым и изменить голову
	{
		cur = new t2node;
		cur->prev = NULL;
		cur->info = new_info;
		cur->next = *head;
		(*head)->prev = cur;
		*head = cur;
		return 1;
	}
	cur = (*head)->next;
	while (cur)
	{
		if (cur->info == info) 
		{
			previos = cur->prev;
			newNode = new t2node;
			previos->next = newNode;
			newNode->prev = previos;
			newNode->info = new_info;
			newNode->next = cur;
			cur->prev = newNode;
			return 1;
		}
		else cur = cur->next;
	}
	return 0;
}

int insertAfter(p2node *head, p2node* tail, int info, int new_info) // Вставка после
{
	p2node cur, newNode, next_el;
	if (head == NULL) return 0;
	cur = *head;
	while (cur)
	{
		if (cur->info == info)
		{
			if (cur->next)
			{
				next_el = cur->next;
				newNode = new t2node;
				cur->next = newNode;
				newNode->prev = cur;
				newNode->info = new_info;
				newNode->next = next_el;
				next_el->prev = newNode;
				return 1;
			}
			else	//если нужно вставить после хвоста		
			{
				newNode = new t2node;
				cur->next = newNode;
				newNode->prev = cur;
				newNode->info = new_info;
				newNode->next = NULL;
				*tail = newNode;
				return 1;
			}
		}
		else cur = cur->next;
	}
	return 0;
}


bool symmetry(p2node head, p2node tail) // Проверка списка на симметричность
{
	while (head != tail)
	{
		if (head->info != tail->info)
		{
			return false;
		}
		else if (head->next == tail && head->info != tail->info) {
			return false;
		}
		else {
			head = head->next;
			tail = tail->prev;
		}
	}
	return true;
}