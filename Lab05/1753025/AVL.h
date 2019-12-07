#pragma once

#include <iostream>
#include <ctime>
#include <cmath>
#include <queue>
#include <string>

using namespace std;

struct NODE {
	int key;
	NODE* left;
	NODE* right;
	int height;
};

class AVL {
public:
	NODE* root;

	AVL();
	~AVL();
	NODE * CreateNode(int data);
	void Insert(NODE* &p_root, int x);
	void Remove(NODE* &p_root, int x);
	void NLR(NODE* p_root);
	void LNR(NODE* p_root);
	void LNRHeight(NODE* p_root);
	void LRN(NODE* p_root);
	void LevelOrder(NODE* p_root);
	bool IsAVL(NODE* p_root);
	

	//Support Function
	int getBalanceOfNode(NODE* root);
	int Height(NODE* root);
	int Max(int a, int b);

	void LeftRotation(NODE* &p_root);
	void RightRotation(NODE* &p_root);
	NODE* getMinNode(NODE* p_root);
	int getHeight(NODE* p_root);

	//Option Menu
	void Menu();
	void Option01();
};