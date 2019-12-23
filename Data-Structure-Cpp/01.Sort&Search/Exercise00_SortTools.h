#pragma once
#include <vector>
#include <algorithm> 
#include <time.h>
#include "../00.BasicTools/basic.h"

using std::vector;
using std::string;
using std::sort;
using std::to_string;

vector<int> generate_random_vector(int max_size, int max_value) {
	srand((unsigned)time(nullptr));
	vector<int> res;
	int size = (rand() % (max_size + 1));
	for (int i = 0; i < size; i++) {
		int value = (rand() % (2 * max_size + 1)) - max_size;
		res.push_back(value);
	}
	return res;
}

vector<vector<int>> generate_random_matrix(int max_size, int max_value) {
	srand((unsigned)time(nullptr));
	int size = (rand() % (max_size + 1));
	vector<vector<int>> res(size, vector<int>(size));
	for (int j = 0; j < size; j++) {
		for (int i = 0; i < size; i++) {
			int value = (rand() % (2 * max_size + 1)) - max_size;
			res[i][j]=value;
		}
	}
	return res;
}

void print_vector(vector<int>& x) {
	string output = "";
	for (int i = 0; i < x.size(); i++) {
		output += to_string(x[i]) + " ";
	}
	print_to_console_ln(output);
}

void print_matrix(vector<vector<int>>& x) {
	string output = "";
	for (int j = 0; j < x.size(); j++) {
		string row = "";
		for (int i = 0; i < x.size(); i++) {
			row += to_string(x[i][j]) + "\t\t";
		}
		output += row + "\n";
	}
	print_to_console_ln(output);
}

void swap(vector<int>& x, int a, int b) {
	if (a == b) {
		return;
	}
	int tmp = x[a];
	x[a] = x[b];
	x[b] = tmp;
}

void comparator(vector<int>& x) {
	sort(x.begin(), x.end());
}

bool equal(vector<int>& x, vector<int>& y) {
	if (&x == nullptr || &y == nullptr || (x.size() != y.size()) ) {
		return false;
	}
	for (int i = 0; i < x.size(); i++) {
		if (x[i] != y[i]) {
			return false;
		}
	}
	return true;
}