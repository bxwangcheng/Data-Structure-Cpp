#pragma once
#include "Exercise00_NowcoderTools.h"
// ��̰�ġ������ֲ��ҡ�
/*����һ����������arr�����������ϴ�������n����arr[0]��arr[1]...arr[n��1]��
����һ������L������һ������ΪL�����ӣ�����������ܸ������еļ����㡣*/

int LeftmostBigger(vector<int> array, int l, int r, int value);

// ����Ѱ��
int Robe_v1(vector<int> knots, int length) {
	if (knots.size() < 1 || length < 1)
		return 0;
}

// ���ּ���
int Robe_v2(vector<int> knots, int length) {
	if (knots.size() < 1 || length < 1)
		return 0;
	int max_covered = INT_MIN;
	for (int i = 0; i < knots.size(); i++) {
		int start_sub = (knots[i] - length) < 0 ? 0 : LeftmostBigger(knots, 0, i, knots[i] - length);
		max_covered = max(max_covered, i - start_sub + 1);
	}
	return max_covered;
}

// ��������
int Robe_v3(vector<int> knots, int length) {
	if (knots.size() < 1 || length < 1)
		return 0;
	int right = 0;
	int max_covered = INT_MIN;
	for (int left = 0; left < knots.size(); left++) {
		if (right < knots.size()) {
			while (knots[left] + length >= knots[right]) {
				right++;
				if (right == knots.size())
				{
					break;
				}
			}
		}
		max_covered = max(max_covered, right - left);
	}
	return max_covered;
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

bool TestExercise01() {
	int test_time = 1000000;
	bool res = true;
	vector<int> arr = { 1,3,5,12,17,33,35,42,51,60,78 };
	for (int i = 0; i < test_time; i++) {
		srand((unsigned)time(nullptr));
		int length = (rand() % (50)) + 1;
		int res1 = Robe_v2(arr, length);
		int res2 = Robe_v3(arr, length);
		if (res1 != res2) {
			res = false;
			break;
		}
	}
	return res;
}