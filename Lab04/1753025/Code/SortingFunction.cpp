#include "SortingFunction.h"
#include "DataGenerate.h"


/*
	DATA TYPE      |      ARRAY SIZE
	(4 types)      |      (5 sizes)
	Random         |       1000
	Sorted         |       3000
	Reverse        |       10000
	Nearly Sorted  |       30000
	               |       100000
*/

//Support Functions
void SortingAlgorithm::printArr(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}
void SortingAlgorithm::swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
void SortingAlgorithm::printSortingTime(int duration, int n, string sort) {

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
void SortingAlgorithm::printDataType(int data_type) {
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
void SortingAlgorithm::isContinue() {
	string ans;
	cout << endl << "Do you want to Continue ? (yes/no): ";
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
void SortingAlgorithm::sortingMenu() {
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
			int i = 0;
			while (i < 4) {
				showCasesSelectionSort(i++);
			}

			isContinue();
		}	
		case 2:
		{
			int i = 0;
			while (i < 4) {
				showCasesInsertionSort(i++);
			}

			isContinue();
		}
		case 3:
		{
			int i = 0;
			while (i < 4) {
				showCasesBubbleSort(i++);
			}
			
			isContinue();
		}
		case 4:
		{
			int i = 0;
			while (i < 4) {
				showCasesQuickSort(i++);
			}

			isContinue();
		}
		case 5:
		{
			int i = 0;
			while (i < 4) {
				showCasesMergeSort(i++);
			}			

			isContinue();
		}
		case 6:
		{
			int i = 0;
			while (i < 4) {
				showCasesHeapSort(i++);
			}
			

			isContinue();
		}
		case 7:
		{
			int i = 0;
			while (i < 4) {
				showCasesRadixSort(i++);
			}
			
			isContinue();
		}
		case 8: 
		{
			int i = 0;
			while (i < 4) {
				showCasesCountingSort(i++);
			}
			

			isContinue();
		}
		case 9: 
		{
			int i = 0;
			while (i < 4) {
				showCasesShellSort(i++);
			}
			

			isContinue();
		}
		case 10: 
		{
			int i = 0;
			while (i < 4) {
				showCasesShakerSort(i++);
			}
			
			isContinue();
		}
		case 11: 
		{
			int i = 0;
			while (i < 4) {
				showCasesFlashSort(i++);
			}

			isContinue();
		}
		case 12: 
		{
			int i = 0;
			while (i < 4) {
				showCasesBinaryInsertionSort(i++);
			}

			isContinue();
		}
		case 13: 
			break;
		default: break;
	}

}
int SortingAlgorithm::findMax(int arr[], int n){
	int max = arr[0];

	for (int i = 1; i < n; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}

	return max;

}

int SortingAlgorithm::partition(int arr[], int p, int r) {
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
void SortingAlgorithm::HeapRebuild(int arr[], int n, int i) {
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
int SortingAlgorithm::middlePartition(int arr[], int left, int right) {
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
void SortingAlgorithm::Merge(int arr[], int left, int m, int right) {
	int i, j, k;
	int nr = m - left + 1;
	int nl = right - m;

	int *l, *r;
	l = new int[nr];
	r = new int[nl];

	for (i = 0; i < nr; i++) {
		l[i] = arr[left + i];
	}

	for (j = 0; j < nl; j++) {
		r[j] = arr[m + 1 + j];
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
int SortingAlgorithm::binarySearch(int arr[], int select, int left, int right) {
	while (left <= right) {
		int m = left + (right - left) / 2;
		if (select == arr[m])
			return m + 1;
		if (select < arr[m])
			right = m - 1;
		else
			left = m + 1;
	}

	//return left;
	/*if (right <= left)
		return (select > arr[left]) ? (left + 1) : left;
	int mid = left + (right - left) / 2;
	if (select == arr[mid])
		return mid + 1;
	if (select > arr[mid])
		return binarySearch(arr, select, mid + 1, right);*/
}



//Implement Sorting Algorithms
void SortingAlgorithm::selectionSort(int arr[], int n) {
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
void SortingAlgorithm::insertionSort(int arr[], int n){
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
void SortingAlgorithm::bubbleSort(int arr[], int n){
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
void SortingAlgorithm::quickSort(int arr[], int n) {
	std::clock_t start;
	double duration;
	start = std::clock();
	string sort = "Quick Sort";

	//implementQuickSort(arr, 0, n - 1);
	middleQuickSort(arr, 0, n - 1);

	duration = ((std::clock() - start) / (double)CLOCKS_PER_SEC) * 1000;
	printSortingTime(duration, n, sort);
}
void SortingAlgorithm::lastQuickSort(int arr[], int p, int r) {
	if (p < r) {
		int q = partition(arr, p, r);
		lastQuickSort(arr, p, q - 1);
		lastQuickSort(arr, q + 1, r);
	}
}
void SortingAlgorithm::middleQuickSort(int arr[], int left, int right) {
	int p = middlePartition(arr, left, right);
	if (left < p - 1)
		middleQuickSort(arr, left, p - 1);
	if (right > p)
		middleQuickSort(arr, p, right);
}
//---------------------------------------------------------------

void SortingAlgorithm::mergeSort(int arr[], int n){
	std::clock_t start;
	double duration;
	start = std::clock();
	string sort = "Merge Sort";

	doMergeSort(arr, 0, n - 1);

	duration = ((std::clock() - start) / (double)CLOCKS_PER_SEC) * 1000;
	printSortingTime(duration, n, sort);
}
void SortingAlgorithm::doMergeSort(int  arr[], int left, int right) {
	if (left < right) {
		//Finding middle - avoid overflow when left and right are too big.
		int m = left + (right - left) / 2; 

		doMergeSort(arr, left, m);
		doMergeSort(arr, m + 1, right);
		Merge(arr, left, m, right);
	}
}
void SortingAlgorithm::heapSort(int arr[], int n){
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

void SortingAlgorithm::radixSort(int arr[], int n){
	std::clock_t start;
	double duration;
	start = std::clock();
	string sort = "Radix Sort";

	int max = findMax(arr, n);

	for (int div = 1; (max / div) > 0; div *= 10) {
		subCountSort(arr, n, div);
	}

	duration = ((std::clock() - start) / (double)CLOCKS_PER_SEC) * 1000;
	printSortingTime(duration, n, sort);
}
void SortingAlgorithm::subCountSort(int arr[], int n, int div) {
	int i;
	int count[10] = { 0 };
	int *out;
	out = new int[n];

	for (i = 0; i < n; i++) {
		count[(arr[i] / div) % 10]++;
	}

	for (i = 1; i < 10; i++) {
		count[i] += count[i - 1];
	}

	for (i = n - 1; i >= 0; i--) {
		out[count[(arr[i] / div) % 10] - 1] = arr[i];
		count[(arr[i] / div) % 10]--;
	}

	for (i = 0; i < n; i++) {
		arr[i] = out[i];
	}
}

void SortingAlgorithm::countingSort(int arr[], int n){
	std::clock_t start;
	double duration;
	start = std::clock();
	string sort = "Counting Sort";

	int *tmp = new int[n];

	int max(arr[0]), min(arr[0]);

	for (int i = 1; i < n; i++) {
		if (arr[i] > max)
			max = arr[i];
		else if (arr[i] < min)
			min = arr[i];
	}

	int size = max - min + 1;

	int *count = new int[size]();

	for (int i = 0; i < size; i++)
		count[arr[i] - min]++;

	for (int i = 1; i < size; i++) {
		count[i] += count[i - 1];
	}

	for (int i = 0; i < n; i++) {
		tmp[count[arr[i] - min] - 1] = arr[i];
		count[arr[i] - min]--;
	}

	for (int i = 0; i < n; i++) {
		arr[i] = tmp[i];
	}


	duration = ((std::clock() - start) / (double)CLOCKS_PER_SEC) * 1000;
	printSortingTime(duration, n, sort);
}
void SortingAlgorithm::shellSort(int arr[], int n){
	std::clock_t start;
	double duration;
	start = std::clock();
	string sort = "Shell Sort";

	for (int mid = n / 2; mid > 0; mid /= 2) {
		for (int i = mid; i < n; i++) {
			int tmp = arr[i];

			int j = i;
			while (j >= mid && arr[j - mid] > arr[j]) {
				arr[j] = arr[j - mid];
				j -= mid;
			}
			arr[j] = tmp;
		}
	}

	duration = ((std::clock() - start) / (double)CLOCKS_PER_SEC) * 1000;
	printSortingTime(duration, n, sort);
}
void SortingAlgorithm::shakerSort(int arr[], int n){
	std::clock_t start;
	double duration;
	start = std::clock();
	string sort = "Shaker Sort";

	int left(0), right(n - 1);
	int k = 0;
	int i;
	while (left < right) {
		for (i = left; i < right; i++)
		{
			if (arr[i] > arr[i + 1]) {
				swap(&arr[i], &arr[i + 1]);
				k = i;
			}
		}
		right = k;

		for (i = right; i > left; i--) {
			if (arr[i] < arr[i - 1]) {
				swap(&arr[i], &arr[i - 1]);
				k = i;
			}
		}
		left = k;
	}

	duration = ((std::clock() - start) / (double)CLOCKS_PER_SEC) * 1000;
	printSortingTime(duration, n, sort);
}
void SortingAlgorithm::flashSort(int arr[], int n){
	std::clock_t start;
	double duration;
	start = std::clock();
	string sort = "Flash Sort";

	doFlashSort(arr, n);

	duration = ((std::clock() - start) / (double)CLOCKS_PER_SEC) * 1000;
	printSortingTime(duration, n, sort);
}

//**I USE THIS CODE FOR RREFERENCE AND LEARNING...
//The flashsort algorithm is attributed to Karl-Dietrich Neubert
//The translation to C++ is provided by Clint Jed Casper
//
//sorts an array in place in O(n) time using 20% of the
//memory used by the array for storing intermediate,
//temporary computations
void SortingAlgorithm::doFlashSort(int arr[], int n) {
	if (n == 0) return;
	//20% of the number of elements or 0.2n classes will
	//be used to distribute the input data set into
	//there must be at least 2 classes (hence the addition)
	int m = (int)((0.2 * n) + 2);

	//-------CLASS FORMATION-------

	//O(n)
	//compute the max and min values of the input data
	int min, max, maxIndex;
	min = max = arr[0];
	maxIndex = 0;

	for (int i = 1; i < n - 1; i += 2)
	{
		int small;
		int big;
		int bigIndex;


		if (arr[i] < arr[i + 1])
		{
			small = arr[i];
			big = arr[i + 1];
			bigIndex = i + 1;
		}
		else
		{
			big = arr[i];
			bigIndex = i;
			small = arr[i + 1];
		}

		if (big > max)
		{
			max = big;
			maxIndex = bigIndex;
		}

		if (small < min)
		{
			min = small;
		}
	}

	//do the last element
	if (arr[n - 1] < min)
	{
		min = arr[n - 1];
	}
	else if (arr[n - 1] > max)
	{
		max = arr[n - 1];
		maxIndex = n - 1;
	}

	if (max == min)
	{
		//all the elements are the same
		return;
	}

	//dynamically allocate the storage for L
	//note that L is in the range 1...m (hence
	//the extra 1)
	int* L = new int[m + 1]();

	//O(n)
	//use the function K(A(i)) = 1 + INT((m-1)(A(i)-Amin)/(Amax-Amin))
	//to classify each A(i) into a number from 1...m
	//(note that this is mainly just a percentage calculation)
	//and then store a count of each distinct class K in L(K)
	//For instance, if there are 22 A(i) values that fall into class
	//K == 5 then the count in L(5) would be 22

	//IMPORTANT: note that the class K == m only has elements equal to Amax

	//precomputed constant
	double c = (m - 1.0) / (max - min);
	int K;
	for (int h = 0; h < n; h++)
	{
		//classify the A(i) value
		K = ((int)((arr[h] - min) * c)) + 1;

		//assert: K is in the range 1...m

		//add one to the count for this class
		L[K] += 1;
	}

	//O(m)
	//sum over each L(i) such that each L(i) contains
	//the number of A(i) values that are in the ith
	//class or lower (see counting sort for more details)
	for (K = 2; K <= m; K++)
	{
		L[K] = L[K] + L[K - 1];
	}

	//-------PERMUTATION-------

	//swap the max value with the first value in the array	
	int temp = arr[maxIndex];
	arr[maxIndex] = arr[0];
	arr[0] = temp;

	//Except when being iterated upwards,
	//j always points to the first A(i) that starts
	//a new class boundary && that class hasn't yet
	//had all of its elements moved inside its borders;

	//This is called a cycle leader since you know 
	//that you can begin permuting again here. You know
	//this becuase it is the lowest index of the class
	//and as such A(j) must be out of place or else all
	//the elements of this class have already been placed
	//within the borders of the this class (which means
	//j wouldn't be pointing to this A(i) in the first place)
	int j = 0;

	//K is the class of an A(i) value. It is always in the range 1..m
	K = m;

	//the number of elements that have been moved
	//into their correct class
	int numMoves = 0;

	//O(n)
	//permute elements into their correct class; each
	//time the class that j is pointing to fills up
	//then iterate j to the next cycle leader
	//
	//do not use the n - 1 optimization because that last element
	//will not have its count decreased (this causes trouble with
	//determining the correct classSize in the last step)
	while (numMoves < n)
	{
		//if j does not point to the begining of a class
		//that has at least 1 element still needing to be
		//moved to within the borders of the class then iterate
		//j upward until such a class is found (such a class
		//must exist). In other words, find the next cycle leader
		while (j >= L[K])
		{
			j++;

			K = ((int)((arr[j] - min) * c)) + 1;
		}
		//evicted always holds the value of an element whose location
		//in the array is free to be written into //aka FLASH
		int evicted = arr[j];

		//while j continues to meet the condition that it is
		//pointing to the start of a class that has at least one
		//element still outside its borders (the class isn't full)
		while (j < L[K])
		{
			//compute the class of the evicted value
			K = ((int)((evicted - min) * c)) + 1;

			//get a location that is inside the evicted
			//element's class boundaries
			int location = L[K] - 1;

			//swap the value currently residing at the new
			//location with the evicted value
			int temp = arr[location];
			arr[location] = evicted;
			evicted = temp;

			//decrease the count for this class
			//see counting sort for why this is done
			L[K] -= 1;

			//another element was moved
			numMoves++;
		}
	}


	int threshold = (int)(1.25 * ((n / m) + 1));
	const int minElements = 30;


	for (K = m - 1; K >= 1; K--)
	{

		int classSize = L[K + 1] - L[K];


		if (classSize > threshold && classSize > minElements)
		{

			doFlashSort(&arr[L[K]], classSize);
		}
		else
		{
			if (classSize > 1)
			{
				insertionSort(&arr[L[K]], classSize);
			}
		}
	}

	delete[] L;
}

void SortingAlgorithm::binaryInsertionSort(int arr[], int n){
	std::clock_t start;
	double duration;
	start = std::clock();
	string sort = "Bianry Insertion Sort";
	
	int i, location, j, k, selected;
	for (i = 1; i < n; ++i)
	{
		j = i - 1;
		selected = arr[i];
		
		location = binarySearch(arr, selected, 0, j);
		
		while (j >= location)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = selected;
	}

	duration = ((std::clock() - start) / (double)CLOCKS_PER_SEC) * 1000;
	printSortingTime(duration, n, sort);
}

//Show All Cases of Sorting Algorithms
void SortingAlgorithm::showCasesSelectionSort(int data_type) {

	printDataType(data_type);

	int size[5] = { 1000, 3000, 10000, 30000, 100000 };

	for (int i = 0; i < 5; i++) {
		int *a = new int[size[i]];
		GenerateData(a, size[i], data_type);
		selectionSort(a, size[i]);
		delete[]a;
	}
}
void SortingAlgorithm::showCasesInsertionSort(int data_type){
	printDataType(data_type);

	int size[5] = { 1000, 3000, 10000, 30000, 100000 };

	for (int i = 0; i < 5; i++) {
		int *a = new int[size[i]];
		GenerateData(a, size[i], data_type);
		insertionSort(a, size[i]);
		delete[]a;
	}
}
void SortingAlgorithm::showCasesBubbleSort(int data_type){
	printDataType(data_type);

	int size[5] = { 1000, 3000, 10000, 30000, 100000 };

	for (int i = 0; i < 5; i++) {
		int *a = new int[size[i]];
		GenerateData(a, size[i], data_type);
		bubbleSort(a, size[i]);
		delete[]a;
	}
}
void SortingAlgorithm::showCasesQuickSort(int data_type) {
	printDataType(data_type);

	int size[5] = { 1000, 3000, 10000, 30000, 100000 };

	for (int i = 0; i < 5; i++) {
		int *a = new int[size[i]];
		GenerateData(a, size[i], data_type);
		quickSort(a, size[i]);
		delete[]a;
	}
}
void SortingAlgorithm::showCasesMergeSort(int data_type){
	printDataType(data_type);

	int size[5] = { 1000, 3000, 10000, 30000, 100000 };

	for (int i = 0; i < 5; i++) {
		int *a = new int[size[i]];
		GenerateData(a, size[i], data_type);
		mergeSort(a, size[i]);
		delete[]a;
	}
}
void SortingAlgorithm::showCasesHeapSort(int data_type){
	printDataType(data_type);

	int size[5] = { 1000, 3000, 10000, 30000, 100000 };

	for (int i = 0; i < 5; i++) {
		int *a = new int[size[i]];
		GenerateData(a, size[i], data_type);
		heapSort(a, size[i]);
		delete[]a;
	}
}
void SortingAlgorithm::showCasesRadixSort(int data_type){
	printDataType(data_type);

	int size[5] = { 1000, 3000, 10000, 30000, 100000 };

	for (int i = 0; i < 5; i++) {
		int *a = new int[size[i]];
		GenerateData(a, size[i], data_type);
		radixSort(a, size[i]);
		delete[]a;
	}
}

void SortingAlgorithm::showCasesCountingSort(int data_type){
	printDataType(data_type);

	int size[5] = { 1000, 3000, 10000, 30000, 100000 };

	for (int i = 0; i < 5; i++) {
		int *a = new int[size[i]];
		GenerateData(a, size[i], data_type);
		countingSort(a, size[i]);
		delete[]a;
	}
}
void SortingAlgorithm::showCasesShellSort(int data_type){
	printDataType(data_type);

	int size[5] = { 1000, 3000, 10000, 30000, 100000 };

	for (int i = 0; i < 5; i++) {
		int *a = new int[size[i]];
		GenerateData(a, size[i], data_type);
		shellSort(a, size[i]);
		delete[]a;
	}
}
void SortingAlgorithm::showCasesShakerSort(int data_type){
	printDataType(data_type);

	int size[5] = { 1000, 3000, 10000, 30000, 100000 };

	for (int i = 0; i < 5; i++) {
		int *a = new int[size[i]];
		GenerateData(a, size[i], data_type);
		shakerSort(a, size[i]);
		delete[]a;
	}
}
void SortingAlgorithm::showCasesFlashSort(int data_type){
	printDataType(data_type);

	int size[5] = {1000, 3000, 10000, 30000, 100000};
	
	for (int i = 0; i < 5; i++) {
		int *a = new int[size[i]];
		GenerateData(a, size[i], data_type);
		flashSort(a, size[i]);
		delete[]a;
	}
}
void SortingAlgorithm::showCasesBinaryInsertionSort(int data_type){
	printDataType(data_type);

	int size[5] = { 1000, 3000, 10000, 30000, 100000 };

	for (int i = 0; i < 5; i++) {
		int *a = new int[size[i]];
		GenerateData(a, size[i], data_type);
		binaryInsertionSort(a, size[i]);
		delete[]a;
	}
}