#include "Exercise00_SortTools.h"

void QuickSort(vector<int>& vec);
void QuickSort(vector<int>& vec, int l, int r);
vector<int> Partition(vector<int>& vec, int l, int r);

void QuickSort(vector<int>& vec) {
	if (&vec == nullptr || vec.size() < 2) {
		return;
	}
	QuickSort(vec, 0, vec.size()-1);
}

// l][r
void QuickSort(vector<int>& vec, int l, int r) {
	if (l < r) {
		srand((unsigned)time(nullptr));
		int rand_index = rand() % (r - l);
		Swap(vec, l + rand_index, r);
		vector<int> res = Partition(vec, l, r);
		QuickSort(vec, l, res[0]);
		QuickSort(vec, res[1], r);
	}
}

// l][r
vector<int> Partition(vector<int>& vec, int l, int r) {
	int left_bound = l - 1;
	int right_bound = r;
	while (l < right_bound) {
		if (vec[l] < vec[r]) {
			Swap(vec, left_bound + 1, l);
			left_bound++;
			l++;
		}
		else if (vec[l] > vec[r]){
			Swap(vec, right_bound - 1, l);
			right_bound--;
		}
		else
		{
			l++;
		}
	}
	Swap(vec, right_bound, r);
	return{ left_bound, right_bound + 1};
}