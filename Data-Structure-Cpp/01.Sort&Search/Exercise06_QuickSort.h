#include "Exercise00_SortTools.h"

void quick_sort(vector<int>& vec);
void quick_sort(vector<int>& vec, int l, int r);
vector<int> partition(vector<int>& vec, int l, int r);

void quick_sort(vector<int>& vec) {
	if (&vec == nullptr || vec.size() < 2) {
		return;
	}
	quick_sort(vec, 0, vec.size()-1);
}

// l][r
void quick_sort(vector<int>& vec, int l, int r) {
	if (l < r) {
		srand((unsigned)time(nullptr));
		int rand_index = rand() % (r - l);
		swap(vec, l + rand_index, r);
		vector<int> res = partition(vec, l, r);
		quick_sort(vec, l, res[0]);
		quick_sort(vec, res[1], r);
	}
}

// l][r
vector<int> partition(vector<int>& vec, int l, int r) {
	int left_bound = l - 1;
	int right_bound = r;
	while (l < right_bound) {
		if (vec[l] < vec[r]) {
			swap(vec, left_bound + 1, l);
			left_bound++;
			l++;
		}
		else if (vec[l] > vec[r]){
			swap(vec, right_bound - 1, l);
			right_bound--;
		}
		else
		{
			l++;
		}
	}
	swap(vec, right_bound, r);
	return{ left_bound, right_bound + 1};
}