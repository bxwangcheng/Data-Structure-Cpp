#pragma once
#include "Exercise00_NowcoderTools.h"
/*����һ������arr����֪�������е�ֵ���ǷǸ��ģ���������鿴��һ��������
�뷵��������װ����ˮ
���磬arr = {3��1��2��5��2��4}������ֵ������ֱ��ͼ����������״������
������װ��5��ˮ
�ٱ��磬arr = {4��5��1��3��2}������������װ��2��ˮ*/
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

// ��arr[left..right]�Ϸ���>base_height�����ֵ
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
