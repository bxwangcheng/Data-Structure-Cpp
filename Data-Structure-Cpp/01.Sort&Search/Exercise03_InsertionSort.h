#include "Exercise00_SortTools.h"

void InsertionSort(vector<int>& x) {
	if (x.size() < 2 || &x == nullptr) {
		return;
	}
	for (int e = 1; e < x.size(); e++) {
		for (int i = e; i > 0; i--) {
			if (x[i - 1] > x[i]) {
				Swap(x, i-1, i);
			}
		}
	}
}