#include "AVL.h"

AVL::AVL():root(NULL) {};
AVL::~AVL() {
	delete this->root;
}

NODE* AVL::CreateNode(int data) {
	NODE* tmp = new NODE;
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->key = data;
	tmp->height = 1;
	return tmp;
}

void AVL::Insert(NODE* &p_root, int x) {
	
	if (p_root == NULL){
		p_root = CreateNode(x);
		return;
	}

	if (x > p_root->key)
		Insert(p_root->right, x);
	else if (x < p_root->key)
		Insert(p_root->left, x);
	else
		return;

	p_root->height = 1 + Max(Height(p_root->left), Height(p_root->right));
	

	int bal = getBalanceOfNode(p_root);
	
	if (bal > 1) {
		//Left left case
		if (x < p_root->left->key)
			RightRotation(p_root);

		//left right case
		if (x > p_root->left->key) {
			LeftRotation(p_root->left);
			RightRotation(p_root);
		}
	}

	if (bal < -1) {
		//right right case
		if (x > p_root->right->key)
			LeftRotation(p_root);

		//right left case
		if (x < p_root->right->key) {
			RightRotation(p_root->right);
			LeftRotation(p_root);
		}
	}
}

void AVL::Remove(NODE* &p_root, int x) {
	if (p_root == NULL) return;

	if (x > p_root->key)
		Remove(p_root->right, x);
	else if (x < p_root->key)
		Remove(p_root->left, x);
	else {
		//Node has no child
		if (p_root->left == NULL && p_root->right == NULL) {
			NODE* tmp = p_root;
			p_root = NULL;
			delete tmp;
			return;
		}

		//Node has 1 child
		if (p_root->left == NULL) {
			NODE* tmp = p_root->right;
			*p_root = *tmp;
			delete tmp;
			//return;
		}
		else if (p_root->right == NULL) {
			NODE* tmp = p_root->left;
			*p_root = *tmp;
			delete tmp;
		}
		else {
			//Node has 2 childs
			NODE* tmp = getMinNode(p_root->right);
			p_root->key = tmp->key;
			Remove(p_root->right, tmp->key);
		}
	}

	//if tree has only one node - return after detele this node
	if (p_root == NULL) return;
	
	p_root->height = Max(Height(p_root->left), Height(p_root->right)) + 1;

	int bal = getBalanceOfNode(p_root);

	if (bal > 1) {
		//Left left case
		if (x < p_root->left->key)
			RightRotation(p_root);

		//left right case
		if (x > p_root->left->key) {
			LeftRotation(p_root->left);
			RightRotation(p_root);
		}
	}

	if (bal < -1) {
		//right right case
		if (x > p_root->right->key)
			LeftRotation(p_root);

		//right left case
		if (x < p_root->right->key) {
			RightRotation(p_root->right);
			LeftRotation(p_root);
		}
	}
}
void AVL::NLR(NODE* p_root){
	if (p_root == NULL) return;

	cout << p_root->key << " ";
	NLR(p_root->left);
	NLR(p_root->right);
}
void AVL::LNR(NODE* p_root){
	if (p_root == NULL) return;

	LNR(p_root->left);
	cout << p_root->key <<" ";
	LNR(p_root->right);
}
void AVL::LNRHeight(NODE* p_root) {
	if (p_root == NULL) return;

	LNRHeight(p_root->left);
	cout << p_root->height<< " ";
	LNRHeight(p_root->right);
}
void AVL::LRN(NODE* p_root){
	if (p_root == NULL) return;

	LRN(p_root->left);
	LRN(p_root->right);
	cout << p_root->key << " ";
}
void AVL::LevelOrder(NODE* p_root){
	if (p_root == NULL) return;

	queue<NODE*> q;
	q.push(p_root);

	while (!q.empty()) {
		NODE* tmp = q.front();
		cout << tmp->key << " ";
		q.pop();

		if (tmp->left != NULL)
			q.push(tmp->left);

		if (tmp->right != NULL)
			q.push(tmp->right);
	}
}
bool AVL::IsAVL(NODE* p_root) { 
	if (p_root == NULL)
		return true;

	int left = getHeight(p_root->left);
	int right = getHeight(p_root->right);

	/*
		If this Node is Balanced, go deeper to Left and Right 
		to check all of Node is balanced

		If not return false -> It is not an AVL tree
	*/
	if (abs(left - right) < 2) {
		if (IsAVL(p_root->left) && IsAVL(p_root->right))
			return true;
	}
		
	return false;
}

/*
	SUPPORT FUNCTON AREA
*/
int AVL::getBalanceOfNode(NODE* root) {
	if (root == NULL)
		return 0;

	return (Height(root->left) - Height(root->right));
}

int AVL::Height(NODE* root) {
	if (root == NULL) return 0;
	return root->height;
}

int AVL::Max(int a, int b) {
	return (a > b) ? a : b;
}

void AVL::LeftRotation(NODE* &p_root) {
	NODE* p = p_root->right;
	p_root->right = p->left;
	p->left = p_root;

	//Update the Height in left side
	p->left->height = Max(Height(p->left->left), Height(p->left->right)) + 1;
	
	//Update the Height of p
	p->height = Max(Height(p->left), Height(p->right)) + 1;
	
	p_root = p;
}

void AVL::RightRotation(NODE* &p_root) {
	NODE* p = p_root->left;
	p_root->left = p->right;
	p->right = p_root;

	//Update the Height in right side after rotation
	p->right->height = Max(Height(p->right->left), Height(p->right->right)) + 1;
	
	//Update the Height of p
	p->height = Max(Height(p->left), Height(p->right)) + 1;

	p_root = p;
}

NODE* AVL::getMinNode(NODE* p_root) {
	if (p_root == NULL) return NULL;
	NODE* tmp = p_root;

	while (tmp->left != NULL) {
		tmp = tmp->left;
	}

	return tmp;
}

int AVL::getHeight(NODE* p_root) {
	if (p_root == NULL) return 0;

	return 1 + Max(getHeight(p_root->left), getHeight(p_root->right));
}


//Option Menu
void AVL::Menu() {
	int num;
	cout << endl << "----AVL Tree----\n" << endl;

	cout << "1. Create Binary Search Tree" << endl;
	cout << "2. Pre-Order Traversal" << endl;
	cout << "3. InOrder Traversal" << endl;
	cout << "4. Post-Order Traversal" << endl;
	cout << "5. Level Order Traversal" << endl;
	cout << "6. Insert One Node" << endl;
	cout << "7. Remove One Node" << endl;
	cout << "0. Exit" << endl;
	cout << endl << "Your choice: "; cin >> num;

	switch (num) {
	case 0: exit(1);
	case 1: {
		this->Option01();
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
	case 6: {
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
	
	
	default: break;
	}
}

void AVL::Option01() {
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
