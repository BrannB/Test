#include "2list.h"

int main()
{
	p2node first = NULL, lst;
	int info, new_info, res, choose = 1;

	formList(&first, &lst);

	while (choose)
	{
		cout << "What do you want to do?" << endl << " 1 - Delete element" << endl << " 2 - Insert before" << endl 
			<< " 3 - Insert after" << endl << " 4 - Check on symmetry" << endl << " 5 - Print straight" << endl 
			<< " 6 - Print reverse" << endl << " 0 - Exit" << endl;
		cin >> choose;
		switch (choose)
		{
		case 1:
			cout << "Enter element which you want to delete: ";
			cin >> info;
			res = deleteNode(&first, &lst, info);
			break;
		case 2:
			cout << "Enter element before which you want to add: ";
			cin >> info;
			cout << "Enter element which you want to add: ";
			cin >> new_info;
			insertBefore(&first, info, new_info);
			break;
		case 3:
			cout << "Enter element after which you want to add: ";
			cin >> info;
			cout << "Enter element which you want to add: ";
			cin >> new_info;
			insertAfter(&first, &lst, info, new_info);
			break;
		case 4:
			if (symmetry(first, lst))
				cout << "This list is symmetry" << endl;
			else 
				cout << "This list is not symmetry" << endl;
			break;
		case 5:
			printStraight(first);
			break;
		case 6:
			printReverse(lst);
			break;
		case 0:
			system("pause");
			return 0;
		}
	}
}
