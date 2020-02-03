#pragma once
#include "Exercise00_NowcoderTools.h"
/*给定一个数组arr长度为N，你可以把任意长度大于0且小于N的前缀作为左部分，剩下的
作为右部分。但是每种划分下都有左部分的最大值和右部分的最大值，请返回最大的，
左部分最大值减去右部分最大值的绝对值。*/
int FindMax(const vector<int>& arr, int start, int end);
int MaxDifference(const vector<int>& arr) {
	if (arr.size() < 1) {
		return 0;
	}
	int global_max = FindMax(arr, 0, arr.size() - 1);
	return global_max - min(arr[0], arr[arr.size() - 1]);
}

int FindMax(const vector<int>& arr, int start, int end) {
	if (start > end || end > arr.size() - 1) {
		return INT_MIN;
	}
	int max_val = INT_MIN;
	for (int i = start; i <= end; i++) {
		max_val = max(max_val, arr[i]);
	}
	return max_val;
}

void TestExercise27() {
	vector<int> arr = { 3,2,4,6,9 };
	Println(MaxDifference(arr));
}