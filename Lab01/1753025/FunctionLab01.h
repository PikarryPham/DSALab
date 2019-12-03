#pragma once

#include <iostream>
#include <cmath>

using namespace std;

/*
	DYNAMIC ARRAY WITH POINTER
*/

void InputArray(int* &a, int &n);

// 2. Remove array
void DellocateArray(int* &a);

// 3. Output all elements of the array:
void PrintArray(int* a, int n);

// 4. Find the smallest value from the array:
int FindMin(int* a, int n);

// 5. Find the greatest absolute value from the array:
int FindMaxModulus(int* a, int n);

// 6. Check if the array is ascending :
bool IsAscending(int* a, int n);

// 7. Find the total value of all elements of the array:
int SumOfArray(int* a, int n);

// 8. Count the number of prime numbers in the array:
int CountPrime(int* a, int n);

// 9. Create a new dynamic array which is the reverse of the given array:
int ReverseArray(int* &a, int* b, int n);

// 10. Sequential Search :
int LinearSearch(int* a, int n, int key);

// 11. Sequential Search(using flag) :
int SentinelLinearSearch(int* a, int n, int key);

// 12. Binary Search :
int BinarySearch(int* a, int n, int key);

// 13. Binary Search(using recursion) :
int RecursiveBinarySearch(int* a, int left, int right, int key);

/*
	RECURSION
*/

int SumOfSquares(int n);
int GCD(int a, int b);
int FIB(int n);


/*
	LINKED LIST
*/

struct NODE {
	int key;
	NODE* p_next;
};

struct List {
	NODE* p_head;
	NODE* p_tail;
};

NODE* CreateNode(int data);
List* CreateList(NODE* p_node);
bool AddHead(List* L, int data);
bool AddTail(List* L, int data);
void RemoveHead(List* L);
void RemoveTail(List* L);
void RemoveAll(List* &L);
void PrintList(List* L);
int CountElements(List* L);
List* ReverseList(List* L);
void RemoveDuplicate(List* &L);
bool RemoveElement(List* &L, int key);


//Support Function
bool isPrime(int n);