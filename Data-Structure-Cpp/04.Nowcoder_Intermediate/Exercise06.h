#pragma once
#include "Exercise00_NowcoderTools.h"
// 【动态规划】
/*给定一个非负整数n，代表二叉树的节点个数。返回能形成多少种不同的二叉树结构*/

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