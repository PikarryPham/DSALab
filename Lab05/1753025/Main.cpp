//#include "BinarySearchTree.h"
#include "AVL.h"

int main() {

	/*BST b;
	while (true) {
		b.Menu();	
	}*/
	
	AVL a;
	
	/*srand((unsigned int)time(0));
	for (int i = 0; i < 15; i++) {
		int check = rand() % 15;
		cout << check << " ";
		a.Insert(a.root, check);
	}*/
	a.Insert(a.root, 8);
	a.Insert(a.root, 0);
	a.Insert(a.root, 0);
	a.Insert(a.root, 12);
	a.Insert(a.root, 12);
	a.Insert(a.root, 9);
	a.Insert(a.root, 14);
	a.Insert(a.root, 1);
	a.Insert(a.root, 5);
	a.Insert(a.root, 12);
	a.Insert(a.root, 7);
	a.Insert(a.root, 4);
	a.Insert(a.root, 5);
	a.Insert(a.root, 4);
	a.Insert(a.root, 13);

	cout << endl << "LNR   : ";
	a.LNR(a.root);
	//cout << endl;
	cout << endl << "Height: ";
	a.LNRHeight(a.root);

	cout << "\n After Remove Node \n";
	a.Remove(a.root, 14);
	cout << endl << "LNR   : ";
	a.LNR(a.root);
	//cout << endl;
	cout << endl << "Height: ";
	a.LNRHeight(a.root);

	cout << "\n LevelOrder: ";
	a.LevelOrder(a.root);

	bool check = a.IsAVL(a.root);
	if (check)
		cout << "\n IS AVL \n";
	else
		cout << "\n NOT AVL\n";
	system("pause");
	return 0;
}