#include "BinarySearchTree.h"

BST::BST():root(NULL){}
BST::~BST(){
	delete root;
}

//Main Functions
NODE* BST::CreateNode(int data) {
	NODE* node = new NODE;
	node->key = data;
	node->left = nullptr;
	node->right = nullptr;

	return node;
}
void BST::NLR(NODE* root){
	if (root == NULL) return;

	cout << root->key << " ";
	NLR(root->left);
	NLR(root->right);
}
void BST::LNR(NODE* root) {
	if (root == NULL) return;
	
	LNR(root->left);
	cout << root->key << " ";
	LNR(root->right);
}
void BST::LRN(NODE* root) {
	if (root == NULL) return;

	LRN(root->left);
	LRN(root->right);
	cout << root->key << " ";
}

void BST::LevelOrder(NODE* root) {
	if (root == NULL) return;
	int height = Height(root);

	for (int i = 1; i < (height + 1); i++) {
		printLevelOrder(root, i);
	}
}
void BST::printLevelOrder(NODE* root, int height) {
	if (root == NULL) return;

	if (height == 1)
		cout << root->key << " ";
	else if (height > 1)
	{
		printLevelOrder(root->left, height - 1);
		printLevelOrder(root->right, height - 1);
	}
}
NODE* BST::Search(NODE* root, int x){
	if (root == NULL || root->key == x) 
		return root;
	
	if (root->key < x)
		return Search(root->right, x);
	
	return Search(root->left, x);
}
void BST::Insert(NODE* &root, int x){
	if (root == NULL) {
		root = CreateNode(x);
	}
	if (root->key < x)
		Insert(root->right, x);
	else if (root->key > x)
		Insert(root->left, x);
}

void BST::Remove(NODE* &root, int x){
	if (root == NULL) return;
	NODE* tmp = new NODE;
	tmp = getChildWhenRemoveNode(root, x);

	if (tmp == NULL) cout << "Nothing to remove" << endl;
	else
	{
		root = tmp;
		cout << "Removed" << endl;
	}
}
NODE* BST::getChildWhenRemoveNode(NODE* root, int x) {

	if (root == NULL) return root;

	if (root->key > x)
		root->left = getChildWhenRemoveNode(root->left, x);
	else if (root->key < x)
		root->right = getChildWhenRemoveNode(root->right, x);
	else {
		if (root->left == NULL) {
			//Khong co con trai
			cout << "Ko con trai" << endl;
			NODE* tmp = root->right;
			delete root;
			return tmp;
		}
		else if (root->right == NULL) {
			//Khong co con phai
			cout << "Ko co con phai" << endl;
			NODE* tmp = root->left;
			delete root;
			return tmp;
		}
		else {
			// Co hai con
			cout << "Co ca hai con" << endl;
			int min = minValue(root->right);
			root->key = min;
			root->right = getChildWhenRemoveNode(root->right, min);
		}
	}
	
	return root;
}

int BST::Height(NODE* root) {
	if (root == NULL)
		return 0; 

	int leftSub = Height(root->left);
	int rightSub = Height(root->right);

	if (leftSub > rightSub)
		return leftSub + 1;
	else
		return rightSub + 1;
}
int BST::CountNode(NODE* root) { 
	if (root == NULL)
		return 0;

	int leftNode = CountNode(root->left);
	int rightNode = CountNode(root->right);

	return (leftNode + rightNode + 1);
}

int BST::Level(NODE* root, NODE* p) { 
	if(root == NULL)
		return 0;

	return GetLevelOfNode(root, p->key, 1);
}
int BST::GetLevelOfNode(NODE* root, int key, int level) {
	if (root == NULL) return 0;

	if (root->key == key)
		return level;

	int goDown = GetLevelOfNode(root->left, key, level + 1);

	if (goDown != 0)
		return goDown;

	goDown = GetLevelOfNode(root->right, key, level + 1);

	return goDown;
}

int BST::CountLeaf(NODE* root) { 
	if (root == NULL)
		return 0;
	
	int l_leaf = CountLeaf(root->left);
	int r_leaf = CountLeaf(root->right);
	
	if (root->left == NULL && root->right == NULL)
		return (l_leaf + r_leaf + 1);
	else
		return l_leaf + r_leaf;
}
int BST::CountLess(NODE* root, int x) { 
	if (root == NULL)
		return 0; 

	int c_left = CountLess(root->left, x);
	int c_right = CountLess(root->right, x);

	if (root->key < x) {
		return (c_left + c_right + 1);
	}
	else {
		return (c_left + c_right);
	}
}
int BST::CountGreater(NODE* root, int x) { 
	if (root == NULL)
		return 0;

	int c_left = CountGreater(root->left, x);
	int c_right = CountGreater(root->right, x);

	if (root->key > x) {
		return (c_left + c_right + 1);
	}
	else {
		return (c_left + c_right);
	}
}

bool BST::isBST(NODE* root) { 
	if (root == NULL)
		return false;

	if (root->left != NULL && maxValue(root->left) > root->key)
		return false;
	if (root->right != NULL && minValue(root->right) < root->key)
		return false;
	if (!isBST(root->left) || !isBST(root->right))
		return false;
	
	return true;
}

//Suppport Functions
void BST::viewBST(NODE* root) {
	printBST(root, 0);
}
void BST::printBST(NODE* root, int space) {
	if (root == NULL)
		return;

	space += INS;

	printBST(root->right, space);

	cout << endl;

	int i = INS;
	for (i; i < space; i++)
		cout << " ";
	
	cout << root->key << endl;

	printBST(root->left, space);

}
int BST::minValue(NODE* root) {
	if (root->left == NULL)
		return root->key;
	else
		return minValue(root->left);
}
int BST::maxValue(NODE* root) {
	if (root->right == NULL) return root->key;

	return maxValue(root->right);
}

//Option Menu
void BST::Menu() {
	int num;
	cout << endl << "----Binary Search Tree----\n" << endl;

	cout << "01. Create Binary Search Tree" << endl;
	cout << "02. Pre-Order Traversal" << endl;
	cout << "03. InOrder Traversal" << endl;
	cout << "04. Post-Order Traversal" << endl;
	cout << "05. Level Order Traversal" << endl;
	cout << "06. Insert One Node" << endl;
	cout << "07. Remove One Node" << endl;
	cout << "08. Height Of Tree" << endl;
	cout << "09. Number Of Nodes" << endl;
	cout << "10. Number Of Leafs" << endl;
	cout << "11. Number Of Nodes Greater Than X" << endl;
	cout << "12. Number Of Nodes Smaller Than X" << endl;
	cout << "13. Level Of One Node" << endl;
	cout << "14. Search One Node" << endl;
	cout << "15. Check Any Tree Is BST" << endl;
	cout << "00. Exit" << endl;
	cout << endl << "Your choice: "; cin >> num;
	
	switch (num) {
	case 0: exit(1);
	case 1: {
		this->Option01();
		this->viewBST(this->root);
		break;
	}
	case 2: {
		cout << "Pre-Order Traversal: ";
		this->NLR(this->root);
		cout << endl;
		break;
	}
	case 3: {
		cout << "In-Order Traversal: ";
		this->LNR(this->root);
		cout << endl;
		break;
	}
	case 4: {
		cout << "Post-Order Traversal: ";
		this->LRN(this->root);
		cout << endl;
		break;
	}
	case 5: {
		cout << "Level Order Traversal: ";
		this->LevelOrder(this->root);
		cout << endl;
		break;
	}
	case 6:{
		int x;
		cout << "Insert: "; cin >> x;
		this->Insert(this->root, x);
		break;
	}
		
	case 7: {
		int x;
		cout << "Remove: "; cin >> x;
		this->Remove(this->root, x);
		break;
	}
	case 8: {
		cout << "Height Of Tree: ";
		cout << this->Height(this->root);
		cout << endl;
		break;
	}
	case 9: {
		cout << "Number Of Nodes ";
		cout << this->CountNode(this->root);
		cout << endl;
		break;
	}
	case 10: {
		cout << "Number Of Leafs: ";
		cout << this->CountLeaf(this->root);
		cout << endl;
		break;
	}
	case 11: {
		int x;
		cout << "Input X: "; cin >> x;
		cout << "Number Of Nodes Greater Than " << x << ": ";
		cout << this->CountGreater(this->root, x);
		cout << endl;
		break;
	}
	case 12: {
		int x;
		cout << "Input X: "; cin >> x;
		cout << "Number Of Nodes Smaller Than " << x << ": ";
		cout << this->CountLess(this->root, x);
		cout << endl;
		break;
	}
	case 13: {
		int x;
		cout << "Input Node: "; cin >> x;
		cout << "Level Of Node " << x << ": ";
		cout << this->Level(this->root, this->CreateNode(x));
		cout << endl;
		break;
	}
	case 14: {
		int x;
		cout << "Input Node to Search: "; cin >> x;
		cout << "Found -> ";
		NODE* tmp = this->Search(this->root, x);

		if (tmp == NULL) cout << "Not Found" << endl;
		else 
			cout << tmp->key;
		cout << endl;
		break;
	}
	case 15: break;
	default: break;
	}
}

void BST::Option01() {
	int choice;
	this->root;

	cout << "You have 2 ways to create BST" << endl;
	cout << "1. Generate Automatically" << endl;
	cout << "2. Generate Manually" << endl;

	cout << endl << "Your choice: "; cin >> choice;

	switch (choice) {
	case 1: {
		unsigned int n;
		cout << endl << "Random size: "; cin >> n;
		srand((unsigned int)time(0));

		cout << endl << "List of Numbers: ";
		for (int i = 0; i < n; i++) {
			int check = rand() % n;
			cout << check << " ";
			this->Insert(this->root, check);
		}
		break;
	}

	case 2: {

		int n;

		cout << endl << "Type a negative number if you want to exit" << endl;
		do {
			cout << "Insert: "; cin >> n;
			if (n < 0) break;
			else
				this->Insert(this->root, n);
		} while (true);
		break;
	}

	default: break;
	}
}