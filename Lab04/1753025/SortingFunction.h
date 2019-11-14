#pragma once

#include <iostream>
#include <ctime>
#include <string>

using namespace std;

//Sorting Function
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void bubbleSort(int arr[], int n);
void quickSort(int arr[], int n);
void mergeSort(int arr[], int n);
void heapSort(int arr[], int n); 
void radixSort(int arr[], int n); 

void countingSort(int ar[], int n);
void shellSort(int arr[], int n);
void shakerSort(int arr[], int n);
void flashSort(int arr[], int n);
void binaryInsertionSort(int arr[], int n); 

//show All Cases Of Sorting Algorithms
void showSelectionSort(int data_type);
void showInsertionSort(int data_type);
void showBubbleSort(int data_type);
void showQuickSort(int data_type);
void showMergeSort(int data_type);
void showHeapSort(int data_type);
void showRadixSort(int data_type);

void showCountingSort(int data_type);
void showShellSort(int data_type);
void showShakerSort(int data_type);
void showFlashSort(int data_type);
void showBinaryInsertionSort(int data_type);

//Support Functions
void swap(int *x, int *y);
void printArr(int a[], int n);
void printSortingTime(int duration, int n, string sort);
void printDataType(int data_type);
void sortingMenu();

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