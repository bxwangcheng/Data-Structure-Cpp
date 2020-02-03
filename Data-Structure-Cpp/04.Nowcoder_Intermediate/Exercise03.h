#pragma once
#include "Exercise00_NowcoderTools.h"
// 【辅助数组】
/*牛牛有一些排成一行的正方形。每个正方形已经被染成红色或者绿色。牛牛现在可
以选择任意一个正方形然后用这两种颜色的任意一种进行染色,这个正方形的颜色将
会被覆盖。牛牛的目标是在完成染色之后,每个红色R都比每个绿色G距离最左侧近。
牛牛想知道他最少需要涂染几个正方形。
如样例所示: s = RGRGR
我们涂染之后变成RRRGG满足要求了,涂染的个数为2,没有比这个更好的涂染方案。*/

vector<int> PreprocessPaint(const string& color_bar, const char& color);

int Paint_v1(string color) {
	if (color.size() < 2)
		return 0;
	int min_paint = INT_MAX;
	for (int split = 0; split < color.size(); split++) {
		int left_paint = 0;
		for (int i = 0; i < split; i++) {
			if (color[i] == 'G') {
				left_paint++;
			}
		}
		int right_paint = 0;
		for (int i = split; i < color.size(); i++) {
			if (color[i] == 'R') {
				right_paint++;
			}
		}
		min_paint = min(min_paint, left_paint + right_paint);
	}
	return min_paint;
}

int Paint_v2(string color) {
	if (color.size() < 2)
		return 0;
	int min_paint = INT_MAX;
	vector<int> red = PreprocessPaint(color, 'R');
	vector<int> green = PreprocessPaint(color, 'G');
	for (int split = 0; split < color.size() - 1; split++) {
		int left_paint = green[split];
		int right_paint = red[split + 1];
		min_paint = min(min_paint, left_paint + right_paint);
	}
	min_paint = min(min_paint, green[green.size()-1]);
	min_paint = min(min_paint, red[0]);
	return min_paint;
}

vector<int> PreprocessPaint(const string& color_bar, const char& color) {
	if (color_bar.size() < 2)
		return {};
	vector<int> prefix(color_bar.size(), 0);
	if (color == 'G') {
		if (color_bar[0] == color) {
			prefix[0]++;
		}
		for (int i = 1; i < color_bar.size(); i++) {
			if (color_bar[i] == color) {
				prefix[i] = prefix[i - 1] + 1;
			}
			else {
				prefix[i] = prefix[i - 1];
			}
		}
		return prefix;
	}
	else if (color == 'R') {
		if (color_bar[color_bar.size()-1] == color) {
			prefix[color_bar.size() - 1]++;
		}
		for (int i = color_bar.size() - 2; i >= 0; i--) {
			if (color_bar[i] == color) {
				prefix[i] = prefix[i + 1] + 1;
			}
			else {
				prefix[i] = prefix[i + 1];
			}
		}
		return prefix;
	}
	else {
		return {};
	}
}

bool TestExercise03() {
	bool success = true;
	string color_bar = "RGGRRGGG";
	int res1 = Paint_v1(color_bar);
	int res2 = Paint_v2(color_bar);
	if (res1 != res2) {
		success = false;
	}
	return success;
}