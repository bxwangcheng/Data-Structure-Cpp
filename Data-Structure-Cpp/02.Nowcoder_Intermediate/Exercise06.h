#pragma once
#include "Exercise00_NowcoderTools.h"
// ����̬�滮��
/*����һ���Ǹ�����n������������Ľڵ�������������γɶ����ֲ�ͬ�Ķ������ṹ*/

int BinaryTreePosibility(int n) {
	if (n < 2)
		return 1;
	vector<int> dp(n+1, 0);
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i < n + 1; i++) {
		for (int j = 0; j < i; j++) {
			dp[i] += dp[i - j - 1] * dp[j];
		}
	}
	return dp[n];
}

void TestExercise06() {
	int res = BinaryTreePosibility(3);
}