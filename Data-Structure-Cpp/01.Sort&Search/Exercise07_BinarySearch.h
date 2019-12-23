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

int leftmost(vector<int>& x, int value) {
	if (x.size() < 1 || &x == nullptr) {
		return -1;
	}
	int l = 0;
	int r = x.size() - 1;
	while (l < r) {
		int mid = l + ((r - l) >> 1);
		if (x[mid] < value) {
			l = mid + 1;
		}
		else if (x[mid] > value) {
			r = mid - 1;
		}
		else {
			r = mid;
		}
	}
}

int rightmost(vector<int>& x, int value) {
	if (x.size() < 1 || &x == nullptr) {
		return -1;
	}
	int l = 0;
	int r = x.size() - 1;
	while (l < r) {
		int mid = l + ((r - l) >> 1);
		if (value < x[mid]) {
			r = mid - 1;
		}
		else if (value >= x[mid]) {
			l = mid + 1;
		}
	}
	return l;
}

bool Find(int target, vector<vector<int> > array) {
	if (&array == nullptr || array.size() < 1) {
		return false;
	}
	if (array[0].size() < 1) {
		return false;
	}
	int N = array.size();
	int M = array[0].size();
	int left = 0;
	int right = M - 1;
	for (int i = 0; i < M; i++) {
		int mid = left + ((right - left) >> 1);
		while (left < right) {
			if (array[i][mid] < target) {
				left = mid + 1;
			}
			else if (array[i][mid] > target) {
				right = mid - 1;
			}
			else {
				return true;
			}
		}
	}
	return false;
}