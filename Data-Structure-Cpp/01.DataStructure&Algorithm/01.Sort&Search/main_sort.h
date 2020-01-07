#pragma once
#include "Exercise01_SelectionSort.h"
#include "Exercise02_BubbleSort.h"
#include "Exercise03_InsertionSort.h"
#include "Exercise04_HeapSort.h"
#include "Exercise05_MergeSort.h"
#include "Exercise06_QuickSort.h"
#include "Exercise07_BinarySearch.h"

void test_sort(void) {
	int test_times = 200000;
	int max_size = 20;
	int max_value = 100;
	bool res = true;
	for (int i = 0; i < test_times; i++) {
		vector<int> vec = GenerateArray(max_size, max_value);
		vector<int> dup(vec);
		Comparator(dup);
		//selection_sort(vec);
		//bubble_sort(vec);
		//insertion_sort(vec);
		//merge_sort(vec);
		QuickSort(vec);
		if (!Equal(vec, dup)) {
			res = false;
			break;
		}
	}
	res ? Println("success!") : Println("fail!");


	//vector<int> vec = { 3,2,5,1,7,4,9 };
	//Print(vec);
	//HeapSort(vec);
	//Println();
	//Print(vec);

	//auto vec = generate_random_matrix(10, 100);
	//print_matrix(vec);
	//Find(vec[0][0], vec);

	//vector<int> vec = { 1,1,1,1,2,2,2,3,3,3,4,4 };
	//Println(Rightmost(vec, 3));
	//Println(Leftmost(vec, 3));

	//HeapNode<int>* n3 = new HeapNode<int>(3);
	//HeapNode<int>* n1 = new HeapNode<int>(1);
	//HeapNode<int>* n4 = new HeapNode<int>(4);
	//HeapNode<int>* n2 = new HeapNode<int>(2);
	//Heap<int>* heap = new Heap<int>();
	//heap->Push(n3);
	//heap->Push(n4);
	//heap->Push(n1);
	//heap->Push(n2);

	//
	//while (!heap->isEmpty()) {
	//	Println(heap->Pop()->value_);
	//}
	
}