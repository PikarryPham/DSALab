#pragma once

#include <iostream>
#include <ctime>
#include <cmath>
#include <string>

using namespace std;

#define INS 5;

struct NODE {
	int key;
	NODE* left;
	NODE* right;
};

class BST {
public:
	NODE* root;

	BST();
	~BST();
	NODE* CreateNode(int data);
	void NLR(NODE* root);
	void LNR(NODE* root);
	void LRN(NODE* root);
	void LevelOrder(NODE* root);
	NODE* Search(NODE* root, int x);
	void Insert(NODE* &root, int x);
	void Remove(NODE* &root, int x);
	int Height(NODE* root);
	int CountNode(NODE* root);
	int Level(NODE* root, NODE* p);
	int CountLeaf(NODE* root);
	int CountLess(NODE* root, int x);
	int CountGreater(NODE* root, int x);
	bool isBST(NODE* root);

	//Support Function
	void viewBST(NODE* root);
	void printBST(NODE* root, int space);
	void printLevelOrder(NODE* root, int height);
	NODE* getChildWhenRemoveNode(NODE* root, int x);
	int GetLevelOfNode(NODE* root, int key, int level);
	int minValue(NODE* root);
	int maxValue(NODE* root);

	//Option Menu
	void Menu();
	void Option01();
};