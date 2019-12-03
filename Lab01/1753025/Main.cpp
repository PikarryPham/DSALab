#include "FunctionLab01.h"

int main() {
	/*
		True -> Test Pointer and Recursion
		False -> Test Linked List
	*/
	bool flag = false;

	if (flag) {
		int *a;

		int n;

		InputArray(a, n);
		PrintArray(a, n);
		IsAscending(a, n) ? cout << "Ascending" << endl : cout << "Not Ascending\n";
		cout << "Min: " << FindMin(a, n) << endl;
		cout << "Max Module: " << FindMaxModulus(a, n) << endl;
		cout << "Sum: " << SumOfArray(a, n);
		cout << "Count Prime: " << CountPrime(a, n) << endl;
		int *b = new int[n];
		//cout << "Reverse: " << ReverseArray(a, b, n) << endl;
		cout << "Print ";  PrintArray(a, n);

		int k = LinearSearch(a, n, 12);
		k == -1 ? cout << "Not Found\n" : cout << "Found at " << k << endl;

		int k2 = SentinelLinearSearch(a, n, 12);
		k2 == -1 ? cout << "Not Found\n" : cout << "Found at " << k2 << endl;

		int k3 = BinarySearch(a, n, 12);
		k3 == -1 ? cout << "Not Found\n" : cout << "Found at " << k3 << endl;

		int k4 = RecursiveBinarySearch(a, 0, n - 1, 12);
		k4 == -1 ? cout << "Not Found\n" : cout << "Found at " << k4 << endl;

		DellocateArray(a);
		//cout << "Print ";  PrintArray(a, n);

		cout << "Sum of squares: " << SumOfSquares(3) << endl;
		cout << "FIB: " << FIB(4) << endl;
		cout << "GCD: " << GCD(36, 18) << endl;
	}
	else {
		List* t;
		NODE* a = CreateNode(15);
		t = CreateList(a);

		for (int i = 0; i < 10; i++) {
			bool a = AddHead(t, 9);
			bool c = AddHead(t, i);
			//bool ac = AddHead(t, 9);
			
		}
		AddHead(t, 8);
		PrintList(t); cout << endl;
		/*RemoveHead(t);
		RemoveHead(t);
		RemoveTail(t);*/
		//RemoveTail(t);
		PrintList(t); cout << endl;
		cout << "Print lan 2" << endl;
		cout << t->p_tail->key << " HEAD " << t->p_head->key;

		List* tmp = ReverseList(t);
		cout << endl;
		PrintList(tmp); 

		//bool lim = RemoveElement(t, 2);
		cout << " Xoa: " << endl;
		PrintList(t);

		RemoveDuplicate(t);
		cout << "Remove duplicate " << endl;
		PrintList(t);
	}
	
	system("pause");
	return 0;
}