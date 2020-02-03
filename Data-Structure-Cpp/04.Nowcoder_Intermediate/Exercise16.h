#pragma once
#include "Exercise00_NowcoderTools.h"
/*用zigzag的方式打印矩阵，比如如下的矩阵
0 1 2 3
4 5 6 7
8 9 10 11
打印顺序为：0 1 4 8 5 2 3 6 9 10 7 11*/
void PrintDiagonal(const vector<vector<int>>& matrix, bool up_to_down, int x_ru, int y_ru, int x_ld, int y_ld);
void ZigzagPrint(const vector<vector<int>>& matrix) {
	if (matrix.size() < 1) {
		return;
	}
	int x_ru = 0;
	int y_ru = 0;
	int x_ld = 0;
	int y_ld = 0;
	bool up_to_down = false;
	while (y_ld != matrix[0].size()) {
		PrintDiagonal(matrix, up_to_down, x_ru, y_ru, x_ld, y_ld);
		up_to_down = !up_to_down;
		if (y_ru < matrix.size()-1) {
			y_ru++;
		}
		else {
			x_ru++;
		}
		if (x_ld < matrix[0].size()-1) {
			x_ld++;
		}
		else {
			y_ld++;
		}
	}
	Println();
}

void PrintDiagonal(const vector<vector<int>>& matrix, bool up_to_down, int x_ru, int y_ru, int x_ld, int y_ld) {
	if (matrix.size() < 1) {
		return;
	}
	if (x_ru == x_ld && y_ru == y_ld) {
		Print(matrix[y_ld][x_ld]);
		Print(" ");
		return;
	}
	if (!up_to_down) {
		while (y_ru >= y_ld) {
			Print(matrix[y_ru--][x_ru++]);
			Print(" ");
		}
	}
	else {
		while (y_ru >= y_ld) {
			Print(matrix[y_ld++][x_ld--]);
			Print(" ");
		}
	}
}

void TestExercise16() {
	vector<vector<int>> matrix = { {0,1,2,3},
									{4,5,6,7},
									{8,9,10,11} };
	ZigzagPrint(matrix);
	//PrintDiagonal(matrix, true, 0,1,1,0);
}