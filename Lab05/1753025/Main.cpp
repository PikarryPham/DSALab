/*
	Binary Search Tree Header 
	AVL Tree Header here
	If you want to use, uncomment one.
	Because I use the same name of Struct so we cannot use 2 header file 
	in the same time.
*/

//#include "BinarySearchTree.h"
#include "AVL.h"

int main() {

	/*BST b;
	while (true) {
		b.Menu();
		string ans;
		cout << endl << "Continue ? (yes/no) -> ";
		cin >> ans;

		if (ans == "Y" || ans == "y" || ans == "yes" || ans == "Yes" ||
			ans == "yEs" || ans == "yES" || ans == "YES" || ans == "YeS")
		{
			continue;
		}
		else break;
	}*/

	AVL a;
	while (true) {
		a.Menu();

		string ans;
		cout << endl << "Continue ? (yes/no) -> ";
		cin >> ans;

		if (ans == "Y" || ans == "y" || ans == "yes" || ans == "Yes" ||
			ans == "yEs" || ans == "yES" || ans == "YES" || ans == "YeS")
		{
			continue;
		}
		else break;
	}


	/*
		CHECK isBinaryTree and isAVL

		NEED: a Tree to test.
	*/

	//bool avl = a.IsAVL(a.root);
	//bool bst = b.isBST(b.root);

	system("pause");
	return 0;
}