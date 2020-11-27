#include "sortedList.h"

int main()
{
	int choose = 1, info, newInfo;
	pnode top;
	cout << "Enter list elements: " << endl;
	top = sorted_list();
	while (choose)
	{
		cout << endl << "0. Exit" << endl;
		cout << "1. Insert element: " << endl;
		cout << "2. Delete element: " << endl;
		cout << "3. Show list" << endl << endl;

		cout << "Enter command num: ";
		cin >> choose;
		switch (choose)
		{
		case 0:
			cout << "Goodbye!" << endl;
			system("pause");
			return 0;

		case 1:
			cout << "What elemet do you want to insert? : ";
			cin >> info;
			insertElement_Rec(&top, info);
			cout << "Done!" << endl;
			break;

		case 2:
			cout << "What elemet do you want to delete? : ";
			cin >> info;
			if (deleteNode(&top, info)) cout << "Done!" << endl;
			else cout << "Error. Try again" << endl;
			break;

		case 3:
			cout << endl;
			output(top);
			cout << endl;
			break;

		default:
			cout << "No such command. Try again" << endl;
			break;
		}
	}
}