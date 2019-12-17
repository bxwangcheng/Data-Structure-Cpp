#include "Exercise00_SortTools.h"

int binary_search(vector<int>& x, int value) {
	if (x.size() < 1 || &x == nullptr) {
		return -1;
	}
	int l = 0;
	int r = x.size()-1;
	while (l < r) {
		int mid = l + ((r - l) >> 2);
		if (x[mid] < value) {
			l = mid + 1;
		}
		else if (x[mid] > value) {
			r = mid - 1;
		}
		else {
			return mid;
		}
	}
	return l;
}