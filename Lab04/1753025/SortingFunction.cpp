#include "SortingFunction.h"
#include "DataGenerate.h"

//Array Size
#define size_1   1000
#define size_3   3000
#define size_10  10000
#define size_30  30000
#define size_100 100000

//Support Functions
void printArr(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}
void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
void printSortingTime(int duration, int n, string sort) {

	if (n == 1000 || n == 3000) {
		cout << "CASE " << n << "   Time of " << sort << " : " << duration << " milisecs" << endl;
	}

	if (n == 10000 || n == 30000) {
		cout << "CASE " << n << "  Time of " << sort << " : " << duration << " milisecs" << endl;
	}

	if (n == 100000) {
		cout << "CASE " << n << " Time of " << sort << " : " << duration << " milisecs" << endl;
	}
}
void printDataType(int data_type) {
	switch (data_type) {
	case 0:
		cout << ">> DATA TYPE: RANDOM DATA" << endl << endl;
		break;
	case 1:
		cout << endl << ">> DATA TYPE: SORTED DATA" << endl << endl;
		break;
	case 2:
		cout << endl << ">> DATA TYPE: REVERSE DATA" << endl << endl;
		break;
	case 3:
		cout << endl << ">> DATA TYPE: NEARLY SORTED DATA" << endl << endl;
		break;
	default:
		cout << ">> DATA TYPE: UNKNOWN DATA";
		return;
	}
}
void sortingMenu() {
	int n;

	cout << "What kind of sorting do you want to test ?" << endl;
	cout << "01. Selection sort" << endl;
	cout << "02. Insertion sort" << endl;
	cout << "03. Bubble sort" << endl;
	cout << "04. Quick sort" << endl;
	cout << "05. Merge sort" << endl;
	cout << "06. Heap sort" << endl;
	cout << "07. Radix sort" << endl;
	cout << "08. Counting sort" << endl;
	cout << "09. Shell sort" << endl;
	cout << "10. Shaker sort" << endl;
	cout << "11. Flash sort" << endl;
	cout << "12. Binary insertion sort" << endl;
	cout << "00. Exit" << endl;

	cout << endl << "Your choice: "; cin >> n;
	cout << endl;

	switch (n) {
		case 0: 
			exit(1);
		case 1:
		{
			showSelectionSort(0);
			showSelectionSort(1);
			showSelectionSort(2);
			showSelectionSort(3);

			string ans;
			cout << endl << "Continue testing? (yes/no): ";
			cin >> ans;

			if (ans == "yes" || ans == "Yes" || ans == "y" || ans == "Y" || ans == "YES")
			{
				cout << endl;
				sortingMenu();
			}
			else
			{
				cout << endl << "Finish testing" << endl;
				exit(1);
			}
		}	
		case 2:
		{
			showInsertionSort(0);
			showInsertionSort(1);
			showInsertionSort(2);
			showInsertionSort(3);

			string ans;
			cout << endl << "Continue testing? (yes/no): ";
			cin >> ans;

			if (ans == "yes" || ans == "Yes" || ans == "y" || ans == "Y" || ans == "YES")
			{
				cout << endl;
				sortingMenu();
			}
			else
			{
				cout << endl << "Finish testing" << endl;
				exit(1);
			}
		}
		case 3:
		{
			showBubbleSort(0);
			showBubbleSort(1);
			showBubbleSort(2);
			showBubbleSort(3);

			string ans;
			cout << endl << "Continue testing? (yes/no): ";
			cin >> ans;

			if (ans == "yes" || ans == "Yes" || ans == "y" || ans == "Y" || ans == "YES")
			{
				cout << endl;
				sortingMenu();
			}
			else
			{
				cout << endl << "Finish testing" << endl;
				exit(1);
			}
		}
		case 4:
		{
			showQuickSort(0);
			showQuickSort(1);
			showQuickSort(2);
			showQuickSort(3);

			string ans;
			cout << endl << "Continue testing? (yes/no): ";
			cin >> ans;

			if (ans == "yes" || ans == "Yes" || ans == "y" || ans == "Y" || ans == "YES")
			{
				cout << endl;
				sortingMenu();
			}
			else
			{
				cout << endl << "Finish testing" << endl;
				exit(1);
			}
		}
		case 5:
		{
			showMergeSort(0);
			showMergeSort(1);
			showMergeSort(2);
			showMergeSort(3);

			string ans;
			cout << endl << "Continue testing? (yes/no): ";
			cin >> ans;

			if (ans == "yes" || ans == "Yes" || ans == "y" || ans == "Y" || ans == "YES")
			{
				cout << endl;
				sortingMenu();
			}
			else
			{
				cout << endl << "Finish testing" << endl;
				exit(1);
			}
		}
		case 6:
		{
			showHeapSort(0);
			showHeapSort(1);
			showHeapSort(2);
			showHeapSort(3);

			string ans;
			cout << endl << "Continue testing? (yes/no): ";
			cin >> ans;

			if (ans == "yes" || ans == "Yes" || ans == "y" || ans == "Y" || ans == "YES")
			{
				cout << endl;
				sortingMenu();
			}
			else
			{
				cout << endl << "Finish testing" << endl;
				exit(1);
			}
		}
		case 7:
		{
			showRadixSort(0);
			showRadixSort(1);
			showRadixSort(2);
			showRadixSort(3);

			string ans;
			cout << endl << "Continue testing? (yes/no): ";
			cin >> ans;

			if (ans == "yes" || ans == "Yes" || ans == "y" || ans == "Y" || ans == "YES")
			{
				cout << endl;
				sortingMenu();
			}
			else
			{
				cout << endl << "Finish testing" << endl;
				exit(1);
			}
		}
		case 8: 
			break;
		case 9: 
			break;
		case 10: 
			break;
		case 11: 
			break;
		case 12: 
			break;
		case 13: 
			break;
		default: break;
	}

}

int partition(int arr[], int p, int r) {
	int pivot = arr[r];
	int i = p - 1;

	for (int j = p; j < r; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[r]);
	
	return (i + 1);
}
void HeapRebuild(int arr[], int n, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if ((left < n) && (arr[left] > arr[largest]))
		largest = left;
	if ((right < n) && (arr[right] > arr[largest]))
		largest = right;
	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);
		HeapRebuild(arr, n, largest);
	}
}
int middlePartition(int arr[], int left, int right) {
	int pivot = arr[(left + right) / 2];
	int temp;
	int i(left), j(right);

	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;

		if (i <= j) {
			swap(&arr[i], &arr[j]);
			i++;
			j--;
		}
	}
	return i;
}
void Merge(int arr[], int left, int m, int right) {
	int i, j, k;
	int nr = m - left + 1;
	int nl = right - m;

	int *l, *r;
	l = new int[nr];
	r = new int[nl];

	for (i = 0; i < nr; i++) {
		l[nr] = arr[left + i];
	}

	for (j = 0; j < nl; j++) {
		r[nl] = arr[m + 1 + j];
	}

	i = 0;
	j = 0;
	k = left;

	while (i < nr && j < nl) {
		if (l[i] <= r[j]) {
			arr[k] = l[i];
			i++;
		}
		else {
			arr[k] = r[j];
			j++;
		}
		k++;
	}

	while (i < nr) {
		arr[k] = l[i];
		i++;
		k++;
	}

	while (j < nl) {
		arr[k] = r[j];
		j++;
		k++;
	}
}
//Implement Sorting Algorithms
void selectionSort(int arr[], int n) {
	std::clock_t start;
	double duration;
	start = std::clock();
	string sort = "Selection Sort";

	int i, j, min_pos;

	for (i = 0; i < n - 1; i++) {
		min_pos = i;

		for (j = i + 1; j < n; j++) {
			if (arr[j] < arr[min_pos]) {
				min_pos = j;
			}
		}

		swap(&arr[min_pos], &arr[i]);
	}

	duration = ((std::clock() - start) / (double)CLOCKS_PER_SEC)*1000;
	
	printSortingTime(duration, n, sort);
}
void insertionSort(int arr[], int n){
	std::clock_t start;
	double duration;
	start = std::clock();
	string sort = "Insertion Sort";

	int j, key;

	for (int i = 0; i < n; i++) {
		key = arr[i];
		j = i - 1;

		while ((j >= 0) && (arr[j] > key)) {
			arr[j + 1] = arr[j];
			j -= 1;
		}
		arr[j + 1] = key;
	}

	duration = ((std::clock() - start) / (double)CLOCKS_PER_SEC) * 1000;

	printSortingTime(duration, n, sort);
}
void bubbleSort(int arr[], int n){
	std::clock_t start;
	double duration;
	start = std::clock();
	string sort = "Bubble Sort";

	bool isSwap = false;

	for (int i = 0; i < n - 1; i++) {
		isSwap = false;

		for (int j = i; j < n-1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
				isSwap = true;
			}
		}
		if (isSwap == false)
			break;
	}

	duration = ((std::clock() - start) / (double)CLOCKS_PER_SEC) * 1000;

	printSortingTime(duration, n, sort);
}

//---StackOverflow with Sorted Data, Reverse Data, Nearly Sorted Data
void quickSort(int arr[], int n) {
	std::clock_t start;
	double duration;
	start = std::clock();
	string sort = "Quick Sort";

	//implementQuickSort(arr, 0, n - 1);
	middleQuickSort(arr, 0, n - 1);

	duration = ((std::clock() - start) / (double)CLOCKS_PER_SEC) * 1000;
	printSortingTime(duration, n, sort);
}
void lastQuickSort(int arr[], int p, int r) {
	if (p < r) {
		int q = partition(arr, p, r);
		lastQuickSort(arr, p, q - 1);
		lastQuickSort(arr, q + 1, r);
	}
}
void middleQuickSort(int arr[], int left, int right) {
	int p = middlePartition(arr, left, right);
	if (left < p - 1)
		middleQuickSort(arr, left, p - 1);
	if (right > p)
		middleQuickSort(arr, p, right);
}
//---------------------------------------------------------------

void mergeSort(int arr[], int n){
	std::clock_t start;
	double duration;
	start = std::clock();
	string sort = "Merge Sort";

	doMergeSort(arr, 0, n - 1);

	duration = ((std::clock() - start) / (double)CLOCKS_PER_SEC) * 1000;
	printSortingTime(duration, n, sort);
}
void doMergeSort(int  arr[], int left, int right) {
	if (left < right) {
		int m = left + (right - 1) / 2;

		doMergeSort(arr, left, m);
		doMergeSort(arr, m + 1, right);
		Merge(arr, left, m, right);
	}
}
void heapSort(int arr[], int n){
	std::clock_t start;
	double duration;
	start = std::clock();
	string sort = "Heap Sort";

	for (int i = n / 2; i >= 0; i--)
		HeapRebuild(arr, n, i);

	for (int i = n - 1; i >= 0; i--) {
		swap(&arr[0], &arr[i]);
		HeapRebuild(arr, i, 0);
	}

	duration = ((std::clock() - start) / (double)CLOCKS_PER_SEC) * 1000;
	printSortingTime(duration, n, sort);
}
void radixSort(int arr[], int n){}

void countingSort(int ar[], int n){}
void shellSort(int arr[], int n){}
void shakerSort(int arr[], int n){}
void flashSort(int arr[], int n){}
void binaryInsertionSort(int arr[], int n){}

//Show All Cases of Sorting Algorithms
void showSelectionSort(int data_type) {

	switch (data_type) {
	case 0: 
		cout << "DATA TYPE: RANDOM DATA" << endl << endl;
		break;
	case 1:
		cout << "DATA TYPE: SORTED DATA" << endl << endl;
		break;
	case 2:
		cout << "DATA TYPE: REVERSE DATA" << endl << endl;
		break;
	case 3:
		cout << "DATA TYPE: NEARLY SORTED DATA" << endl << endl;
		break;
	default:
		cout << "DATA TYPE: UNKNOWN DATA";
		return;
	}
	int a[size_1];
	GenerateData(a, size_1, data_type);
	selectionSort(a, size_1);

	int b[size_3];
	GenerateData(b, size_3, data_type);
	selectionSort(b, size_3);

	int c[size_10];
	GenerateData(c, size_10, data_type);
	selectionSort(c, size_10);

	int d[size_30];
	GenerateData(d, size_30, data_type);
	selectionSort(d, size_30);

	int e[size_100];
	GenerateData(e, size_100, data_type);
	selectionSort(e, size_100);
}
void showInsertionSort(int data_type){
	switch (data_type) {
	case 0:
		cout << "DATA TYPE: RANDOM DATA" << endl << endl;
		break;
	case 1:
		cout << "DATA TYPE: SORTED DATA" << endl << endl;
		break;
	case 2:
		cout << "DATA TYPE: REVERSE DATA" << endl << endl;
		break;
	case 3:
		cout << "DATA TYPE: NEARLY SORTED DATA" << endl << endl;
		break;
	default:
		cout << "DATA TYPE: UNKNOWN DATA";
		return;
	}
	int a[size_1];
	GenerateData(a, size_1, data_type);
	insertionSort(a, size_1);

	int b[size_3];
	GenerateData(b, size_3, data_type);
	insertionSort(b, size_3);
	
	int c[size_10];
	GenerateData(c, size_10, data_type);
	insertionSort(c, size_10);
	
	int d[size_30];
	GenerateData(d, size_30, data_type);
	insertionSort(d, size_30);

	int e[size_100];
	GenerateData(e, size_100, data_type);
	insertionSort(e, size_100);
}
void showBubbleSort(int data_type){
	printDataType(data_type);

	int a[size_1];
	GenerateData(a, size_1, data_type);
	bubbleSort(a, size_1);

	int b[size_3];
	GenerateData(b, size_3, data_type);
	bubbleSort(b, size_3);

	int c[size_10];
	GenerateData(c, size_10, data_type);
	bubbleSort(c, size_10);

	int d[size_30];
	GenerateData(d, size_30, data_type);
	bubbleSort(d, size_30);

	int e[size_100];
	GenerateData(e, size_100, data_type);
	bubbleSort(e, size_100);
}
void showQuickSort(int data_type) {
	printDataType(data_type);

	int a[size_1];
	GenerateData(a, size_1, data_type);
	quickSort(a, size_1);
	
	int b[size_3];
	GenerateData(b, size_3, data_type);
	quickSort(b, size_3);

	int c[size_10];
	GenerateData(c, size_10, data_type);
	quickSort(c, size_10);

	int d[size_30];
	GenerateData(d, size_30, data_type);
	quickSort(d, size_30);

	int e[size_100];
	GenerateData(e, size_100, data_type);
	quickSort(e, size_100);
}
void showMergeSort(int data_type){
	printDataType(data_type);

	int a[size_1];
	GenerateData(a, size_1, data_type);
	mergeSort(a, size_1);

	int b[size_3];
	GenerateData(b, size_3, data_type);
	mergeSort(b, size_3);

	int c[size_10];
	GenerateData(c, size_10, data_type);
	mergeSort(c, size_10);

	int d[size_30];
	GenerateData(d, size_30, data_type);
	mergeSort(d, size_30);

	int e[size_100];
	GenerateData(e, size_100, data_type);
	mergeSort(e, size_100);
}
void showHeapSort(int data_type){
	printDataType(data_type);

	int a[size_1];
	GenerateData(a, size_1, data_type);
	heapSort(a, size_1);

	int b[size_3];
	GenerateData(b, size_3, data_type);
	heapSort(b, size_3);

	int c[size_10];
	GenerateData(c, size_10, data_type);
	heapSort(c, size_10);

	int d[size_30];
	GenerateData(d, size_30, data_type);
	heapSort(d, size_30);

	int e[size_100];
	GenerateData(e, size_100, data_type);
	heapSort(e, size_100);
}
void showRadixSort(int data_type){
	printDataType(data_type);

	int a[size_1];
	GenerateData(a, size_1, data_type);
	radixSort(a, size_1);

	int b[size_3];
	GenerateData(b, size_3, data_type);
	radixSort(b, size_3);

	int c[size_10];
	GenerateData(c, size_10, data_type);
	radixSort(c, size_10);

	int d[size_30];
	GenerateData(d, size_30, data_type);
	radixSort(d, size_30);

	int e[size_100];
	GenerateData(e, size_100, data_type);
	radixSort(e, size_100);
}

void showCountingSort(int data_type){}
void showShellSort(int data_type){}
void showShakerSort(int data_type){}
void showFlashSort(int data_type){}
void showBinaryInsertionSort(int data_type){}