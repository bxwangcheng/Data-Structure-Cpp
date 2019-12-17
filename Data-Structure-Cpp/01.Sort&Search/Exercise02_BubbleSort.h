#include "Exercise00_SortTools.h"

void bubble_sort(vector<int>& x) {
	if (x.size() < 2 || &x == nullptr) {
		return;
	}
	for (int e = x.size() - 1; e > 0; e--) {
		for (int i = 0; i < e; i++) {
			if (x[i] > x[i + 1]) {
				swap(x, i, i + 1);
			}
		}
	}
}