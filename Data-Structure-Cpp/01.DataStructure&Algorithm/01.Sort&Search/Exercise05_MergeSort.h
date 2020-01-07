#include "Exercise00_SortTools.h"

void MergeSort(vector<int>& vec);
vector<int> MergeSortProcess(vector<int>& vec, int l, int r);
vector<int> Merge(vector<int>& x, vector<int>& y);

void MergeSort(vector<int>& vec) {
	if (&vec == nullptr || vec.size() < 2) {
		return;
	}
	vector<int> res = MergeSortProcess(vec, 0, vec.size() - 1);
	for (int i = 0; i < res.size(); i++) {
		vec[i] = res[i];
	}
}

vector<int> MergeSortProcess(vector<int>& vec, int l, int r) {
	if (&vec == nullptr || vec.size()==0) {
		return {};
	}
	if (l == r) {
		return {vec[l]};
	}
	int mid = l + ((r - l) >> 1);
	vector<int> arr1 = MergeSortProcess(vec, l, mid);
	vector<int> arr2 = MergeSortProcess(vec, mid + 1, r);
	vector<int> res = Merge(arr1, arr2);
	return res;
}

// x, y are sortted
vector<int> Merge(vector<int>& x, vector<int>& y) {
	vector<int> res(x.size() + y.size());
	int p1 = 0;
	int p2 = 0;
	int index = 0;
	while (p1 < x.size() && p2 < y.size()) {
		if (x[p1] <= y[p2]) {
			res[index++] = x[p1++];
		}
		else {
			res[index++] = y[p2++];
		}
	}
	while (p1 < x.size()) {
		res[index++] = x[p1++];
	}
	while (p2 < y.size()) {
		res[index++] = y[p2++];
	}
	return res;
}