#pragma once
#include "Exercise00_AdvancedTools.h"

template<class T>
vector<vector<int>> FirstSmallerPosition(vector<T> array) {
	if (array.size() < 1 || &array == nullptr)
		return { {} };
	stack<vector<int>> sub_stack;
	vector<vector<int>> res(array.size(), vector<int>(2, INT_MIN));
	for (int i = 0; i < array.size(); i++) {
		while (!sub_stack.empty() && array[sub_stack.top()[sub_stack.top().size() - 1]] > array[i]) {
			vector<int> pop_list = sub_stack.top();
			sub_stack.pop();
			int left_smaller_sub = sub_stack.empty() ? -1 : sub_stack.top()[sub_stack.top().size() - 1];
			for (int j = 0; j < pop_list.size(); j++) {
				int curr_sub = pop_list[j];
				res[curr_sub][0] = left_smaller_sub;
				res[curr_sub][1] = i;
			}
		}
		if (!sub_stack.empty() && array[sub_stack.top()[sub_stack.top().size() - 1]] == array[i]) {
			sub_stack.top().push_back(i);
		}
		else{
			sub_stack.push({ i });
		}
	}
	while (!sub_stack.empty()) {
		vector<int> pop_list = sub_stack.top();
		sub_stack.pop();
		int left_smaller_sub = sub_stack.empty() ? -1 : sub_stack.top()[sub_stack.top().size() - 1];
		for (int j = 0; j < pop_list.size(); j++) {
			int curr_sub = pop_list[j];
			res[curr_sub][0] = left_smaller_sub;
			res[curr_sub][1] = -1;
		}
	}
	for (int i = 0; i < res.size(); i++) {
		Print(res[i][0]);
		Print("\t");
		Print(res[i][1]);
		Println();
	}
	return res;
}

template<class T>
vector<vector<int>> FirstBiggerPosition(vector<T> array) {
	if (array.size() < 1 || &array == nullptr)
		return { {} };
	stack<vector<int>> sub_stack;
	vector<vector<int>> res(array.size(), vector<int>(2, INT_MIN));
	for (int i = 0; i < array.size(); i++) {
		while (!sub_stack.empty() && array[i] > array[sub_stack.top()[sub_stack.top().size() - 1]]) {
			vector<int> curr_list = sub_stack.top();
			sub_stack.pop();
			for (int j = 0; j < curr_list.size(); j++) {
				int curr_sub = curr_list[j];
				int left_bigger_sub = sub_stack.empty() ? -1 : sub_stack.top()[sub_stack.top().size() - 1];
				res[curr_sub][0] = left_bigger_sub;
				res[curr_sub][1] = i;
			}
		}
		if (!sub_stack.empty() && array[i] == array[sub_stack.top()[sub_stack.top().size() - 1]]) {
			sub_stack.top().push_back(i);
		}
		else {
			sub_stack.push({ i });
		}
	}
	while (!sub_stack.empty()) {
		vector<int> pop_list = sub_stack.top();
		sub_stack.pop();
		int left_bigger_sub = sub_stack.empty() ? -1 : sub_stack.top()[sub_stack.top().size() - 1];
		for (int i = 0; i < pop_list.size(); i++) {
			int curr_sub = pop_list[i];
			res[curr_sub][0] = left_bigger_sub;
			res[curr_sub][1] = -1;
		}
	}
	for (int i = 0; i < res.size(); i++) {
		Print(res[i][0]);
		Print("\t");
		Print(res[i][1]);
		Println();
	}
	return res;
}