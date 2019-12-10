#pragma once

#include <iostream>
#include <ctime>
#include <string>
#include <vector>
using namespace std;

class SortingAlgorithm{
public:
	//Sorting Function
	void selectionSort(int arr[], int n);
	void insertionSort(int arr[], int n);
	void bubbleSort(int arr[], int n);
	void quickSort(int arr[], int n);
	void mergeSort(int arr[], int n);
	void heapSort(int arr[], int n);
	void radixSort(int arr[], int n);

	void countingSort(int arr[], int n);
	void shellSort(int arr[], int n);
	void shakerSort(int arr[], int n);
	void flashSort(int arr[], int n);
	void binaryInsertionSort(int arr[], int n);

	//show All Cases Of Sorting Algorithms
	void showCasesSelectionSort(int data_type);
	void showCasesInsertionSort(int data_type);
	void showCasesBubbleSort(int data_type);
	void showCasesQuickSort(int data_type);
	void showCasesMergeSort(int data_type);
	void showCasesHeapSort(int data_type);
	void showCasesRadixSort(int data_type);

	void showCasesCountingSort(int data_type);
	void showCasesShellSort(int data_type);
	void showCasesShakerSort(int data_type);
	void showCasesFlashSort(int data_type);
	void showCasesBinaryInsertionSort(int data_type);

	//Support Functions
	void swap(int *x, int *y);
	void printArr(int a[], int n);
	void printSortingTime(int duration, int n, string sort);
	void printDataType(int data_type);
	void sortingMenu();
	int findMax(int arr[], int n);
	void isContinue();

	//--Quicksort --pivot in last
	int partition(int arr[], int p, int r);
	void lastQuickSort(int arr[], int p, int r);

	//--Quicksort --pivot in middle
	int middlePartition(int arr[], int left, int right);
	void middleQuickSort(int arr[], int left, int right);

	//--Heapsort
	void HeapRebuild(int arr[], int n, int largest);

	//--Mergesort
	void Merge(int arr[], int left, int m, int right);
	void doMergeSort(int arr[], int left, int right);

	//--RadixSort
	void subCountSort(int arr[], int n, int div);

	//Binary-InsertionSort
	int binarySearch(int arr[], int select, int left, int right);

	//FlashSort
	void doFlashSort(int arr[], int n);
};

