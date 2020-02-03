#pragma once
#include "Exercise00_DpTools.h"
/*矩阵的最小路径和
【题目】
给定一个矩阵 m，从左上角开始每次只能向右或者向下走，最后到达右下角的位置，路径
上所有的数字累加起来就是路径和，返回所有的路径中最小的路径和。
【举例】
如果给定的 m 如下: 1359 8134 5061 8840
路径 1，3，1，0，6，1，0 是所有路径中路径和最小的，所以返回12*/
int MinPathRecursiveProcess(const vector<vector<int>>& matrix, int row, int col);
int MinPathRecursive(const vector<vector<int>>& matrix) {
	if (matrix.size() < 1) {
		return -1;
	}
	if (matrix[0].size() < 1) {
		return -1;
	}
	return MinPathRecursiveProcess(matrix, matrix.size() - 1, matrix[0].size() - 1);
}

// 递归含义：返回从左上角matrix[0][0]到达当前位置matrix[row][col]的最小路径和
int MinPathRecursiveProcess(const vector<vector<int>>& matrix, int row, int col) {
	if (row == 0 && col == 0) {
		return matrix[0][0];
	}
	int cur_path = matrix[row][col];
	if (row == 0) {
		return MinPathRecursiveProcess(matrix, row, col - 1) + cur_path;
	}
	if (col == 0) {
		return MinPathRecursiveProcess(matrix, row - 1, col) + cur_path;
	}
	return min(MinPathRecursiveProcess(matrix, row - 1, col), MinPathRecursiveProcess(matrix, row, col - 1)) + cur_path;
}

int MinPathDp(const vector<vector<int>>& matrix) {
	if (matrix.size() < 1) {
		return -1;
	}
	if (matrix[0].size() < 1) {
		return -1;
	}
	vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
	dp[0][0] = matrix[0][0];
	for (int row = 1; row < matrix.size(); row++) {
		dp[row][0] = dp[row - 1][0] + matrix[row][0];
	}
	for (int col = 1; col < matrix[0].size(); col++) {
		dp[0][col] = dp[0][col - 1] + matrix[0][col];
	}
	for (int row = 1; row < matrix.size(); row++) {
		for (int col = 1; col < matrix[0].size(); col++) {
			dp[row][col] = min(dp[row][col-1], dp[row-1][col]) + matrix[row][col];
		}
	}
	return dp[matrix.size() - 1][matrix[0].size() - 1];
}

int MinPathDpZip(const vector<vector<int>>& matrix){
	if (matrix.size() < 1) {
		return -1;
	}
	if (matrix[0].size() < 1) {
		return -1;
	}
	vector<int> dp_zip(matrix[0].size());
	dp_zip[0] = matrix[0][0];
	int row = 0;
	for (int col = 1; col < matrix[0].size(); col++) {
		dp_zip[col] = dp_zip[col - 1] + matrix[row][col];
	}
	row++;
	while (row < matrix.size()) {
		dp_zip[0] = dp_zip[0] + matrix[row][0];
		for (int col = 1; col < matrix[0].size(); col++) {
			dp_zip[col] = min(dp_zip[col - 1], dp_zip[col]) + matrix[row][col];
		}
		row++;
	}
	return dp_zip[matrix[0].size() - 1];
}

void TestDp01() {
	vector<vector<int>> matrix = {	{1,3,5,9},
									{8,1,3,4},
									{5,0,6,1},
									{8,8,4,0} };
	Println(MinPathRecursive(matrix));
	Println(MinPathDp(matrix));
	Println(MinPathDpZip(matrix));
}