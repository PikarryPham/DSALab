#include "FunctionLab01.h"

// 1. POINTER - DYNAMIC ARRAY
void InputArray(int* &a, int &n){
	cout << "Size of array: "; cin >> n;
	a = new int[n];

	for (int i = 0; i < n; i++) {
		cout << "Element " << i + 1 << ": ";
		cin >> a[i];
	}
}
void DellocateArray(int* &a) {
	delete[]a;
}
void PrintArray(int* a, int n){
	if (a == NULL) cout << "Empty\n";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
int FindMin(int* a, int n){
	int min;

	if (a == NULL) return -1;
	else
		min = a[0];

	for (int i = 1; i < n; i++) {
		if (a[i] < min)
			min = a[i];
	}

	return min;
}
int FindMaxModulus(int* a, int n){
	int max;

	if (a == NULL) return -1;
	else
		max = abs(a[0]);

	for (int i = 1; i < n; i++) {
		if (abs(a[i]) > max)
			max = abs(a[i]);
	}

	return max;
}
bool IsAscending(int* a, int n){
	if (a == NULL) return false;

	for (int i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1])
			return false;
	}

	return true;
}
int SumOfArray(int* a, int n){
	if (a == NULL) return 0;
	int sum = 0;

	for (int i = 0; i < n; i++) {
		sum += a[i];
	}

	return sum;
}
int CountPrime(int* a, int n){
	if (a == NULL) return 0;

	int count = 0;

	for (int i = 0; i < n; i++) {
		if (isPrime(a[i]))
			count++;
	}

	return count;
}
int ReverseArray(int* &a, int* b, int n){
	if (a == NULL) return 0;

	b = new int[n];
	int j = 0;

	for (int i = n - 1; i >= 0; i--, j++) {
		b[j] = a[i];
	}

	delete[]a;
	a = new int[n];
	a = b;
	
	return 1;
}
int LinearSearch(int* a, int n, int key) { 
	if (a == NULL) return -1;

	for (int i = 0; i < n; i++) {
		if (a[i] == key)
			return (i + 1);
	}
	return -1; 
}
int SentinelLinearSearch(int* a, int n, int key) {
	if (a == NULL) return -1;

	int flag = a[n - 1];
	a[n - 1] = key;
	int i = 0;

	while (a[i] != key) {
		i++;
	}

	a[n - 1] = flag;

	if (i < n - 1 || key == flag)
		return i + 1;
	else
		return -1;
}
int BinarySearch(int* a, int n, int key) { 
	if (a == NULL) return -1;

	int l = 0 , r = n - 1;

	if (IsAscending(a, n)) {
		while (l <= r) {
			int m = l + (r - l) / 2;

			if (a[m] == key)
				return m + 1;

			if (a[m] < key)
				l = m + 1;
			else
				r = m - 1;
		}
	}
	else {
		while(l <= r) {
			int m = l + (r - l) / 2;

			if (a[m] == key)
				return m + 1;

			if (a[m] > key)
				l = m + 1;
			else
				r = m - 1;
		}
	}
	
	
	return -1; 
}
int RecursiveBinarySearch(int* a, int left, int right, int key) { 
	if (a == NULL) return -1;

	if (IsAscending(a, right + 1)) {
		if (left <= right) {
			int m = left + (right - left) / 2;

			if (a[m] == key)
				return m + 1;

			if (a[m] < key)
				return RecursiveBinarySearch(a, m + 1, right, key);
			else
				return RecursiveBinarySearch(a, left, m - 1, key);
		}
	}
	else {
		if (left <= right) {
			int m = left + (right - left) / 2;

			if (a[m] == key)
				return m + 1;

			if (a[m] > key)
				return RecursiveBinarySearch(a, m + 1, right, key);
			else
				return RecursiveBinarySearch(a, left, m - 1, key);
		}
	}
	
	
	return -1; 
}

// 2. RECURSIVE
int SumOfSquares(int n) {
	if (n == 1) return 1;

	return n * n + SumOfSquares(n-1);
}
int GCD(int a, int b) { 
	if (b == 0) return a;

	return GCD(b, a%b);
}
int FIB(int n) {
	if (n == 1 || n == 0) return n;
	else
		return FIB(n - 1) + FIB(n - 2);
}

// 3. LINKED LIST

NODE* CreateNode(int data) {
	NODE* tmp = new NODE;
	tmp->key = data;
	tmp->p_next = NULL;

	return tmp;
}
List* CreateList(NODE* p_node){
	List* t = new List;
	 t->p_tail =  t->p_head = p_node;

	 return t;
}
bool AddHead(List* L, int data){
	NODE* p = CreateNode(data);
	p->p_next = L->p_head;
	L->p_head = p;

	return true;
}
bool AddTail(List* L, int data){
	NODE* p = CreateNode(data);

	if (L->p_head == NULL && L->p_tail == NULL)
		L->p_head = L->p_tail = p;
	else {
		L->p_tail->p_next = p;
		L->p_tail = p;
	}

	return true;
}
void RemoveHead(List* L){
	if (L->p_head == NULL) return;

	L->p_head = L->p_head->p_next;
}
void RemoveTail(List* L){
	if (L->p_head == NULL) return;
	if (L->p_head->p_next == NULL)
	{
		delete L->p_head;
		return;
	}

	NODE* tmp = L->p_head;

	while (tmp->p_next->p_next != NULL) {
		tmp = tmp->p_next;
	}

	delete tmp->p_next;
	tmp->p_next = NULL;
	L->p_tail = tmp;
}
void RemoveAll(List* &L){
	NODE* next;

	while (L->p_head != NULL) {
		next = L->p_head->p_next;
		delete L->p_head;
		L->p_head = next;
	}
}
void PrintList(List* L){
	if (L == NULL) return;
	NODE* tmp = L->p_head;

	while (tmp != NULL) {
		cout << tmp->key << " ";
		tmp = tmp->p_next;
	}
}
int CountElements(List* L) { 
	NODE* tmp = L->p_head;
	int count = 0;
	while (tmp != NULL) {
		count++;
		tmp = tmp->p_next;
	}
	return count;
}
List* ReverseList(List* L){
	NODE* a = NULL;
	List* t = CreateList(a);
	
	for (NODE* tmp = L->p_head; tmp != NULL; tmp = tmp->p_next) {
		bool c = AddHead(t, tmp->key);
	}

	return t;
}
void RemoveDuplicate(List* &L){
	bool check = false;
	int value = L->p_head->key;
	NODE* prev = L->p_head;
	NODE* current = L->p_head->p_next;

	while (current->p_next!= NULL) {
		check = false;
		NODE* tmp = current;
		NODE* prevTmp = prev;

		while(tmp != NULL) {

			if (value == tmp->key) {

				if (tmp == L->p_tail)
				{
					RemoveTail(L);
					break;
				}
				else {
					check = true;
					prevTmp->p_next = tmp->p_next;
					if (current == tmp) {
						delete tmp;
						tmp = prevTmp->p_next;
						current = tmp;
					}
					else {
						delete tmp;
						tmp = prevTmp->p_next;
					}
					
				}
			}
			tmp = tmp->p_next;
			prevTmp = prevTmp->p_next;
		}

		if (!check) {
			prev = prev->p_next;
			current = current->p_next;
			value = prev->key;
		}
	}





}
bool RemoveElement(List* &L, int key) {
	
	bool isDel = false;

	NODE* prev = L->p_head;
	NODE* current = L->p_head->p_next;

	while (current->p_next != NULL) {
		if (current->key == key)
		{
			prev->p_next = current->p_next;
			delete current;
			current = prev->p_next;
			isDel = true;
		}
		else {
			current = current->p_next;
			prev = prev->p_next;
		}
	}
		
	if (L->p_head->key == key) {
		NODE* current = L->p_head;
		L->p_head = L->p_head->p_next;
		delete current;
		isDel = true;
	}

	if (L->p_tail->key == key) {
		RemoveTail(L);
		isDel = true;
	}
	return isDel;
}

//Support Function
bool isPrime(int n)
{
	if (n <= 1)
		return false;

	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return false;

	return true;
}