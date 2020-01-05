#pragma once
#include "Exercise00_NowcoderTools.h"
/*����һ����������arr�����������ϴ�������n����arr[0]��arr[1]...arr[n��1]��
����һ������L������һ������ΪL�����ӣ�����������ܸ������еļ����㡣*/

int LeftmostBigger(vector<int> array, int l, int r, int value);

// ����Ѱ��
int Exercise01_v1(vector<int> knots, int length) {
	if (knots.size() < 1 || length < 1)
		return 0;
}

// ���ּ���
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

// ��������
int Exercise01_v3(vector<int> knots, int length) {
	if (knots.size() < 1 || length < 1)
		return 0;
}

// ��array��[a..b]������Ѱ�Ҵ���value������λ��
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