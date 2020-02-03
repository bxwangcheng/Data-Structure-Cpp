#pragma once
#include "Exercise00_AdvancedTools.h"

vector<vector<int>> MultiMatrix(const vector<vector<int>>& a, const vector<vector<int>>& b) {
	if (a.size() < 1 || b.size() < 1) {
		return { {} };
	}
	if (a[0].size() < 1 || b[0].size() < 1) {
		return { {} };
	}
	if (a[0].size() != b.size()) {
		return { {} };
	}
	const int ROW = a.size();
	const int COL = b[0].size();
	vector<vector<int>> res(ROW, vector<int>(COL, 0));
	for (int row = 0; row < ROW; row++) {
		for (int col = 0; col < COL; col++) {
			for (int i = 0; i < COL; i++) {
				res[row][col] += a[row][i] * b[i][col];
			}
		}
	}
	return res;
}

vector<vector<int>> MatrixPower(const vector<vector<int>>& matrix, int N) {
	if (matrix.size() < 1) {
		return { {} };
	}
	if (matrix[0].size() < 1) {
		return { {} };
	}
	if (matrix[0].size() != matrix.size()) {
		return { {} };
	}
	vector<vector<int>> res(matrix.size(), vector<int>(matrix.size(), 0));
	for (int i = 0; i < matrix.size(); i++) {
		res[i][i] = 1;
	}
	vector<vector<int>> tmp(matrix);
	for (; N != 0; N >>= 1) {
		if ((N & 1) != 0) {
			res = MultiMatrix(tmp, res);
		}
		tmp = MultiMatrix(tmp, tmp);
	}
	return res;
}