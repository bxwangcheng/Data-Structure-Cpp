#include "Exercise00_SortTools.h"

void BubbleSort(vector<int>& x) {
	if (x.size() < 2 || &x == nullptr) {
		return;
	}
	for (int e = x.size() - 1; e > 0; e--) {
		for (int i = 0; i < e; i++) {
			if (x[i] > x[i + 1]) {
				Swap(x, i, i + 1);
			}
		}
	}
}