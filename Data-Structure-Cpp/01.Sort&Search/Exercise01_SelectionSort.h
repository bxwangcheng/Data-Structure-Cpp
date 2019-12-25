#pragma once
#include "Exercise00_SortTools.h"

void SelectionSort(vector<int>& x) {
	if (x.size() < 2 || &x == nullptr) {
		return;
	}
	for (int i = 0; i < x.size(); i++) {
		int minIndex = i;
		for (int j = i + 1; j < x.size(); j++) {
			minIndex = x[j] < x[minIndex] ? j : minIndex;
		}
		Swap(x, minIndex, i);
	}
}