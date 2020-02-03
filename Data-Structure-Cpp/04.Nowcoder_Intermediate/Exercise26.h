#pragma once
#include "Exercise00_NowcoderTools.h"
/*给定一个数组arr，已知其中所有的值都是非负的，将这个数组看作一个容器，
请返回容器能装多少水
比如，arr = {3，1，2，5，2，4}，根据值画出的直方图就是容器形状，该容
器可以装下5格水
再比如，arr = {4，5，1，3，2}，该容器可以装下2格水*/
int FindMaxHeight(const vector<int>& arr, int left, int right, int base_height);
int Container_v1(const vector<int>& arr) {
	if (arr.size() < 3) {
		return 0;
	}
	vector<int> water(arr.size(), 0);
	int total = 0;
	for (int i = 1; i < arr.size() - 1; i++) {
		int left_max = FindMaxHeight(arr, 0, i - 1, arr[i]);
		int right_max = FindMaxHeight(arr, i + 1, arr.size() - 1, arr[i]);
		water[i] = (left_max == -1 || right_max == -1) ? 0 : min(left_max, right_max)-arr[i];
		total += water[i];
	}
	return total;
}

// 在arr[left..right]上返回>base_height的最大值
int FindMaxHeight(const vector<int>& arr, int left, int right, int base_height) {
	int max_height = INT_MIN;
	for (int i = left; i <= right; i++) {
		if (arr[i] > base_height) {
			max_height = max(max_height, arr[i]);
		}
	}
	return max_height == INT_MIN ? -1 : max_height;
}

int Container_v2(const vector<int>& arr) {
	if (arr.size() < 3) {
		return 0;
	}
	int total = 0;

	/*
	
	*/


	return total;
}

void TestExercise26() {
	vector<int> arr1 = { 4,5,1,3,2 };
	vector<int> arr2 = { 3,1,2,5,2,4 };
	Println(Container_v1(arr1));
	Println(Container_v1(arr2));
}
