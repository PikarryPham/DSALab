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
