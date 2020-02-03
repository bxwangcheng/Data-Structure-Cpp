#pragma once
#include "Exercise00_NowcoderTools.h"
/*����һ������arr����ΪN������԰����ⳤ�ȴ���0��С��N��ǰ׺��Ϊ�󲿷֣�ʣ�µ�
��Ϊ�Ҳ��֡�����ÿ�ֻ����¶����󲿷ֵ����ֵ���Ҳ��ֵ����ֵ���뷵�����ģ�
�󲿷����ֵ��ȥ�Ҳ������ֵ�ľ���ֵ��*/
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