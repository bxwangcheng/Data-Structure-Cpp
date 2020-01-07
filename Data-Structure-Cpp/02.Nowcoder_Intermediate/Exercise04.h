#pragma once
#include "Exercise00_NowcoderTools.h"
// 【辅助数组】
/*给定一个N*N的矩阵matrix，只有0和1两种值，返回边框全是1的最大正方形的边
长长度。
例如:
01111
01001
01001
01111
01011
其中边框全是1的最大正方形的大小为4*4，所以返回4。*/

int MaxSquare_v1(const vector<vector<int>>& matrix) {
	if (matrix.size() < 1)
		return -1;
	if (matrix[0].size() < 1)
		return -1;
	int ROW = matrix.size();
	int COL = matrix[0].size();
	int max_square = INT_MIN;
	for (int row = 0; row < ROW; row++) {
		for (int col = 0; col < COL; col++) {
			for (int length = 1; length <= min(COL - col, ROW - row); length++) {
				int cur_len = 0;
				for (int i = 0; i < length; i++) {
					if (matrix[row][col + i]) {
						cur_len++;
					}
					else {
						break;
					}
				}
				for (int i = 0; i < length; i++) {
					if (matrix[row + i][col]) {
						cur_len++;
					}
					else {
						break;
					}
				}
				for (int i = 0; i < length; i++) {
					if (matrix[row + length - 1][col + i]) {
						cur_len++;
					}
					else {
						break;
					}
				}
				for (int i = 0; i < length; i++) {
					if (matrix[row + i][col + length - 1]) {
						cur_len++;
					}
					else {
						break;
					}
				}
				if (cur_len == 4 * length) {
					max_square = max(max_square, length);
				}
			}

		}
	}
	return max_square;
}

vector<vector<int>>PreprocessMaxSquare(const vector<vector<int>>& matrix, string orientation);
int MaxSquare_v2(const vector<vector<int>>& matrix) {
	if (matrix.size() < 1)
		return -1;
	if (matrix[0].size() < 1)
		return -1;
	int ROW = matrix.size();
	int COL = matrix[0].size();
	int max_square = INT_MIN;
	vector<vector<int>> right = PreprocessMaxSquare(matrix, "right");
	vector<vector<int>> down = PreprocessMaxSquare(matrix, "down");
	for (int row = 0; row < ROW; row++) {
		for (int col = 0; col < COL; col++) {
			for (int length = 1; length <= min(COL - col, ROW - row); length++) {
				int p1 = right[row][col];
				int p2 = down[row][col];
				int p3 = down[row][col + length - 1];
				int p4 = right[row + length - 1][col];
				if ( p1 >= length &&  p2 >= length &&
					p3 >= length && 
					p4 >= length) {
					max_square = max(max_square, length);
				}
				else {
					continue;
				}
			}
		}
	}
	return max_square;
}

vector<vector<int>>PreprocessMaxSquare(const vector<vector<int>>& matrix, string orientation) {
	if (matrix.size() < 1)
		return { {} };
	if (matrix[0].size() < 1)
		return { {} };

	if (orientation == "right") {
		vector<vector<int>> right(matrix.size(), vector<int>(matrix[0].size(), 0));
		for (int row = 0; row < matrix.size(); row++) {
			for (int col = matrix[0].size() - 1; col >= 0; col--) {
				if (col == matrix[0].size() - 1) {
					if (matrix[row][col]) {
						right[row][col] = 1;
					}
					else {
						right[row][col] = 0;
					}
				}
				else {
					if (matrix[row][col]) {
						right[row][col] = right[row][col + 1] + 1;
					}
					else {
						right[row][col] = 0;
					}
				}
			}
		}
		return right;
	}
	if (orientation == "down") {
		vector<vector<int>> down(matrix.size(), vector<int>(matrix[0].size(), 0));
		for (int row = matrix.size() - 1; row >= 0; row--) {
			for (int col = 0; col < matrix[0].size(); col++) {
				if (row == matrix.size() - 1) {
					if (matrix[row][col]) {
						down[row][col] = 1;
					}
					else {
						down[row][col] = 0;
					}
				}
				else {
					if (matrix[row][col]) {
						down[row][col] = down[row + 1][col] + 1;
					}
					else {
						down[row][col] = 0;
					}
				}
			}
		}
		return down;
	}
	return { {} };
}

void TestExercise04() {
	vector<vector<int>> matrix = {  {1,1,1,1,1,1},
									{1,0,1,0,0,1},
									{1,1,1,0,0,1},
									{1,1,1,1,1,1}
	};
	int res1 = MaxSquare_v1(matrix);
	int res2 = MaxSquare_v2(matrix);
}