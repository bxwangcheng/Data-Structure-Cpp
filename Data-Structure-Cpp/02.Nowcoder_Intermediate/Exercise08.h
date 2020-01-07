#pragma once
#include "Exercise00_NowcoderTools.h"
// ����ϣset��
/*����һ������arr�����ֵΪk��ȥ�����ֶԡ�*/

// {1,3,4,6}

vector<vector<int>> NumberPair(vector<int> numbers, int difference) {
	if (numbers.size() < 2)
		return {};
	set<int> number_dict;
	vector<vector<int>> number_pairs;
	for (int i = 0; i < numbers.size(); i++) {
		number_dict.insert(numbers[i]);
	}
	for (set<int>::iterator index = number_dict.begin(); index != number_dict.end(); index++) {
		if (number_dict.find(*index + difference) != number_dict.end()) {
			number_pairs.push_back({*index, *index+ difference });
		}
	}
	return number_pairs;
}

void TestExercise08() {
	vector<int> arr = { 1,1,2,3,3,5,8,10 };
	auto res = NumberPair(arr, 2);
}

