#pragma once
#include "Exercise00_NowcoderTools.h"
/*给定一个正方形矩阵，只用有限几个变量，实现矩阵中每个位置的数顺时针转动
90度，比如如下的矩阵
0	1	2	3
4	5	6	7
8	9	10	11
12	13	14	15
矩阵应该被调整为：
12	8	4	0
13	9	5	1
14	10	6	2
15	11	7	3*/

void RotateMatrixBorder(vector<vector<int>>& matrix, int row_lu, int col_lu, int row_rd, int col_rd);

void RotateMatrix(vector<vector<int>>& matrix) {
	if (matrix.size() < 1) {
		return;
	}
	if (matrix.size() != matrix[0].size()) {
		return;
	}
	int lu_row = 0;
	int lu_col = 0;
	int rd_row = matrix.size() - 1;
	int rd_col = matrix.size() - 1;
	while (lu_row < rd_row) {
		RotateMatrixBorder(matrix, lu_row++, lu_col++, rd_row--, rd_col--);
	}
}

void RotateMatrixBorder(vector<vector<int>>& matrix, int row_lu, int col_lu, int row_rd, int col_rd) {
	if (matrix.size() < 1) {
		return;
	}
	if (matrix.size() != matrix[0].size()) {
		return;
	}
	for (int i = 0; i < col_rd - col_lu; i++) {
		int tmp = matrix[row_lu][col_lu + i];
		matrix[row_lu][col_lu + i] = matrix[row_rd - i][col_lu];
		matrix[row_rd - i][col_lu] = matrix[row_rd][col_rd - i];
		matrix[row_rd][col_rd - i] = matrix[row_lu + i][col_rd];
		matrix[row_lu + i][col_rd] = tmp;
	}
}

void TestExercise18() {
	vector<vector<int>> matrix = {	{0,1,2,3},
									{4,5,6,7},
									{8,9,10,11},
									{12,13,14,15} };
	Print(matrix);
	RotateMatrix(matrix);
	Print(matrix);
}