/*
	Лабораторная работа 4
	Написать функцию для создания двунаправленного списка. Обеспечить функции
	для выполнения операций добавления нового элемента перед и после заданного,
	удаления заданного элемента и проверки списка на симметрию.
*/

#include <iostream>
using namespace std;

struct t2node {
	int info;
	t2node *next;
	t2node *prev;
};
typedef t2node* p2node;

// Создание двунаправленного списка
void formList(p2node *head, p2node*tail);

// Вывод списка в прямом порядке
void printStraight(p2node head);

// Вывод в обратном порядке
void printReverse(p2node tail);

// Удаление элемента
// Возвращает 1 - успех, или 0 - неудача
int deleteNode(p2node* head, p2node* tail, int info);

// Удаление элемента перед заданным
// Возвращает 1 - успех, или 0 - неудача
int insertBefore(p2node* head, int info, int new_info);

// Удаление элемента после заданного
// Возвращает 1 - успех, или 0 - неудача
int insertAfter(p2node *head, p2node* tail, int info, int new_info);

// Проверка списка на симметрию
// Возвращает TRUE или FALSE
bool symmetry(p2node head, p2node tail);
