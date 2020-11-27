using namespace std;
#include<iostream>

struct tnode
{
	int info;
	tnode * next;
};
typedef tnode * pnode;


pnode sorted_list();

int insertElement_Rec(pnode *top, int info);

int deleteNode(pnode * top, int info);

void output(pnode top);