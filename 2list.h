/*
	������������ ������ 4
	�������� ������� ��� �������� ���������������� ������. ���������� �������
	��� ���������� �������� ���������� ������ �������� ����� � ����� ���������,
	�������� ��������� �������� � �������� ������ �� ���������.
*/

#include <iostream>
using namespace std;

struct t2node {
	int info;
	t2node *next;
	t2node *prev;
};
typedef t2node* p2node;

// �������� ���������������� ������
void formList(p2node *head, p2node*tail);

// ����� ������ � ������ �������
void printStraight(p2node head);

// ����� � �������� �������
void printReverse(p2node tail);

// �������� ��������
// ���������� 1 - �����, ��� 0 - �������
int deleteNode(p2node* head, p2node* tail, int info);

// �������� �������� ����� ��������
// ���������� 1 - �����, ��� 0 - �������
int insertBefore(p2node* head, int info, int new_info);

// �������� �������� ����� ���������
// ���������� 1 - �����, ��� 0 - �������
int insertAfter(p2node *head, p2node* tail, int info, int new_info);

// �������� ������ �� ���������
// ���������� TRUE ��� FALSE
bool symmetry(p2node head, p2node tail);
