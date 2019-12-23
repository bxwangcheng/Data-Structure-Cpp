#pragma once
#include "Exercise01_SelectionSort.h"
#include "Exercise02_BubbleSort.h"
#include "Exercise03_InsertionSort.h"
#include "Exercise04_HeapSort.h"
#include "Exercise05_MergeSort.h"
#include "Exercise06_QuickSort.h"
#include "Exercise07_BinarySearch.h"

void test_sort(void) {
	//int test_times = 200000;
	//int max_size = 20;
	//int max_value = 100;
	//bool res = true;
	//for (int i = 0; i < test_times; i++) {
	//	vector<int> vec = generate_random_vector(max_size, max_value);
	//	vector<int> dup(vec);
	//	comparator(dup);
	//	//selection_sort(vec);
	//	//bubble_sort(vec);
	//	//insertion_sort(vec);
	//	//merge_sort(vec);
	//	quick_sort(vec);
	//	if (!equal(vec, dup)) {
	//		res = false;
	//		break;
	//	}
	//}
	//res ? print_to_console_ln("success!") : print_to_console_ln("fail!");


	//vector<int> vec = { 3,2,5,1,7,4,9 };
	//print_vector(vec);
	//quick_sort(vec);
	//print_vector(vec);

	//auto vec = generate_random_matrix(10, 100);
	//print_matrix(vec);
	//Find(vec[0][0], vec);

	vector<int> vec = { 1,1,1,1,2,2,2,3,3,3,4,4 };
	print_to_console_ln(rightmost(vec, 3));
	print_to_console_ln(leftmost(vec, 3));

}