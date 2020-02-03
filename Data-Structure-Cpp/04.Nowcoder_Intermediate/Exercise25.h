#pragma once
#include "Exercise00_NowcoderTools.h"
// 【动态规划】【空间压缩】
/*动态规划的空间压缩技巧
给你一个二维数组matrix，其中每个数都是正数，要求从左上角走到右下角。每
一步只能向右或者向下，沿途经过的数字要累加起来。最后请返回最小的路径和。*/
int MinRouteProcess(const vector<vector<int>>& matrix, int row, int col);
int MinRoute(const vector<vector<int>>& matrix) {
	if (matrix.size() < 1) {
		return -1;
	}
	return MinRouteProcess(matrix, matrix.size() - 1, matrix[0].size() - 1);
}

int MinRouteProcess(const vector<vector<int>>& matrix, int row, int col) {
	if (row == 0 && col == 0) {
		return matrix[0][0];
	}
	int res;
	if (col == 0) {
		res = MinRouteProcess(matrix, row - 1, col) + matrix[row][col];
		return res;
	}
	if (row == 0) {
		res = MinRouteProcess(matrix, row, col - 1) + matrix[row][col];
		return res;
	}
	int res1 = MinRouteProcess(matrix, row, col - 1) + matrix[row][col];
	int res2 = MinRouteProcess(matrix, row - 1, col) + matrix[row][col];
	return min(res1, res2);
}

int MinRouteDp(const vector<vector<int>>& matrix) {
	if (matrix.size() < 1) {
		return -1;
	}
	int ROW = matrix.size();
	int COL = matrix[0].size();
	vector<vector<int>> dp(ROW, vector<int>(COL, 0));
	dp[ROW - 1][COL - 1] = matrix[ROW - 1][COL - 1];
	for (int row = ROW - 2; row >= 0; row--) {
		dp[row][COL - 1] = dp[row + 1][COL - 1] + matrix[row][COL - 1];
	}
	for (int col = COL - 2; col >= 0; col--) {
		dp[ROW - 1][col] = dp[ROW - 1][col + 1] + matrix[ROW - 1][col];
	}
	for (int row = ROW - 2; row >= 0; row--) {
		for (int col = COL - 2; col >= 0; col--) {
			dp[row][col] = matrix[row][col] + min(dp[row + 1][col], dp[row][col + 1]);
		}
	}
	return dp[0][0];
}

int MinRouteDpZip(const vector<vector<int>>& matrix) {
	if (matrix.size() < 1) {
		return -1;
	}
	vector<int> zip_dp(matrix[0].size());
	int ROW = matrix.size();
	int COL = matrix[0].size();
	zip_dp[0] = matrix[0][0];
	for (int col = 1; col < COL; col++) {
		zip_dp[col] = zip_dp[col - 1] + matrix[0][col];
	}
	int row = 1;
	while (row < ROW) {
		zip_dp[0] = matrix[row][0] + zip_dp[0];
		for (int col = 1; col < COL; col++) {
			zip_dp[col] = min(zip_dp[col - 1], zip_dp[col]) + matrix[row][col];
		}
		row++;
	}
	return zip_dp[COL - 1];
}

void TestExercise25() {
	vector<vector<int>> matrix = { {3,4,5,2},
									{6,3,1,7},
									{0,6,8,9} };
	Println(MinRoute(matrix));
	Println(MinRouteDp(matrix));
	Println(MinRouteDpZip(matrix));
}
