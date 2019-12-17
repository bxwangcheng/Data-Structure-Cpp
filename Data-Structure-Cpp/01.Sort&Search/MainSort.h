#pragma once
#include "Exercise01_SelectionSort.h"
#include "Exercise02_BubbleSort.h"
#include "Exercise03_InsertionSort.h"
#include "Exercise04_HeapSort.h"
#include "Exercise05_MergeSort.h"
#include "Exercise06_QuickSort.h"
#include "Exercise07_BinarySearch.h"

void sort_main(void) {
	int test_times = 200000;
	int max_size = 20;
	int max_value = 100;
	bool res = true;
	for (int i = 0; i < test_times; i++) {
		vector<int> vec = generate_random_vector(max_size, max_value);
		vector<int> dup(vec);
		comparator(dup);
		selection_sort(vec);
		//bubble_sort(vec);
		//insertion_sort(vec);
		if (!equal(vec, dup)) {
			res = false;
			break;
		}
	}
	res ? print_to_console("success!") : print_to_console("fail!");
}