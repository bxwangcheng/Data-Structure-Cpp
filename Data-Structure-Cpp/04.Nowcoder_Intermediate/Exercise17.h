#pragma once
#include "Exercise00_NowcoderTools.h"
/*用螺旋的方式打印矩阵，比如如下的矩阵
0 1 2 3
4 5 6 7
8 9 10 11
打印顺序为：0 1 2 3 7 11 10 9 8 4 5 6*/

void SpinPrintBorder(const vector<vector<int>>& matrix, int row_lu, int col_lu, int row_rd, int col_rd);

void SpinPrint(const vector<vector<int>>& matrix) {
	if (matrix.size() < 1) {
		return;
	}
	const int ROW = matrix.size();
	const int COL = matrix[0].size();
	int row_lu = 0;
	int col_lu = 0;
	int row_rd = ROW - 1;
	int col_rd = COL - 1;
	while (row_lu <= row_rd && col_lu <= col_rd) {
		SpinPrintBorder(matrix, row_lu++, col_lu++, row_rd--, col_rd--);
	}
	Println();
}

void SpinPrintBorder(const vector<vector<int>>& matrix, int row_lu, int col_lu, int row_rd, int col_rd) {
	if (matrix.size() < 1) {
		return;
	}
	if (row_lu == row_rd) {
		for (int i = col_lu; i <= col_rd; i++) {
			Print(matrix[row_lu][i]);
			Print(" ");
		}
		return;
	}
	if (col_lu == col_rd) {
		for (int i = row_lu; i <= row_rd; i++) {
			Print(matrix[i][col_lu]);
			Print(" ");
		}
		return;
	}
	for (int i = col_lu; i <= col_rd; i++) {
		Print(matrix[row_lu][i]);
		Print(" ");
	}
	for (int i = row_lu + 1; i <= row_rd; i++) {
		Print(matrix[i][col_rd]);
		Print(" ");
	}
	for (int i = col_rd - 1; i >= col_lu; i--) {
		Print(matrix[row_rd][i]);
		Print(" ");
	}
	for (int i = row_rd - 1; i > row_lu; i--) {
		Print(matrix[i][col_lu]);
		Print(" ");
	}
}

void TestExercise17() {
	vector<vector<int>> matrix1 = {	{0,1,2,3},
									{4,5,6,7},
									{8,9,10,11} };
	vector<vector<int>> matrix2 = { {0,1,2},
									{3,4,5},
									{6,7,8},
									{9,10,11} };
	vector<vector<int>> matrix3 = { {0,1,2,3},
									{4,5,6,7},
									{8,9,10,11},
									{12,13,14,15} };
	SpinPrint(matrix1);
	SpinPrint(matrix2);
	SpinPrint(matrix3);
}
