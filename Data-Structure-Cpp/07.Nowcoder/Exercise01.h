#pragma once
#include "Exercise00_NowcoderTools.h"
/*给定一个有序数组arr，代表数轴上从左到右有n个点arr[0]、arr[1]...arr[n－1]，
给定一个正数L，代表一根长度为L的绳子，求绳子最多能覆盖其中的几个点。*/

int LeftmostBigger(vector<int> array, int l, int r, int value);

// 暴力寻找
int Exercise01_v1(vector<int> knots, int length) {
	if (knots.size() < 1 || length < 1)
		return 0;
}

// 二分加速
int Exercise01_v2(vector<int> knots, int length) {
	if (knots.size() < 1 || length < 1)
		return 0;
	int max_covered = INT_MIN;
	for (int i = 0; i < knots.size(); i++) {
		int start_sub = (knots[i] - length) < 0 ? 0 : LeftmostBigger(knots, 0, i, knots[i] - length);
		max_covered = max(max_covered, start_sub - i + 1);
	}
	return max_covered;
}

// 滑动窗口
int Exercise01_v3(vector<int> knots, int length) {
	if (knots.size() < 1 || length < 1)
		return 0;
}

// 在array的[a..b]区间上寻找大于value的最左位置
int LeftmostBigger(vector<int> array, int l, int r, int value) {
	if (array.size() < 1 || l > r)
		return -1;
	while (l < r) {
		int mid = l + ((r - l) >> 1);
		if (array[mid] >= value) {
			r = mid;
		}
		else if (array[mid] < value) {
			l = mid + 1;
		}
	}
	return l;
}