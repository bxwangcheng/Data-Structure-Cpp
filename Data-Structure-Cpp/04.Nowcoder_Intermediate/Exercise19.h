#pragma once
#include "Exercise00_NowcoderTools.h"
// 【二分查找】
/*给定一个元素为非负整数的二维数组matrix，每行和每列都是从小到大有序的。
再给定一个非负整数aim，请判断aim是否在matrix中。*/

bool SearchMatrix(const vector<vector<int>>& matrix, const int aim) {
	if (matrix.size() < 1) {
		return false;
	}
	if (matrix[0].size() < 1) {
		return false;
	}
	bool res = false;
	const int ROW = matrix.size();
	const int COL = matrix[0].size();

	for (int col = COL - 1; col >= 0; col--) {
		int row = 0;
		if (matrix[row][col] > aim) {
			continue;
		}
		else if (matrix[row][col] < aim) {
			while (row < ROW) {
				if (matrix[row][col] == aim) {
					return true;
				}
				row++;
			}
		}
		else {
			return true;
		}
	}
	return res;
}

void TestExercise19() {
	vector<vector<int>> matrix = { {0,1,2,3},
									{4,5,6,7},
									{8,9,10,11},
									{12,13,14,15} };
	//for (int i = 0; i < 16; i++) {
	//	bool res = SearchMatrix(matrix, i);
	//	Println(res ? "true" : "false");
	//}

	for (int i = 16; i < 100; i++) {
		bool res = SearchMatrix(matrix, i);
		Println(res ? "true" : "false");
	}
	//bool res = SearchMatrix(matrix, 4);
	//Println(res ? "true" : "false");
}