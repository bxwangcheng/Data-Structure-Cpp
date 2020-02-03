#pragma once
#include "Exercise00_NowcoderTools.h"
// 【动态规划】
/*一个合法的括号匹配序列有以下定义:
①空串""是一个合法的括号匹配序列
②如果"X"和"Y"都是合法的括号匹配序列,"XY"也是一个合法的括号匹配序列
③如果"X"是一个合法的括号匹配序列,那么"(X)"也是一个合法的括号匹配序列
④每个合法的括号序列都可以由以上规则生成。
例如: "","()","()()","((()))"都是合法的括号序列
求最长合法子串的长度*/
// 子串 子序列 问题，考虑每个位置作为结尾的情况，往DP上靠

int MaxSubBracketLength(string bracket) {
	if (bracket.size() < 2) {
		return 0;
	}
	vector<int> dp(bracket.size(), 0);
	int max_length = INT_MIN;
	dp[0] = 0;
	for (int i = 1; i < dp.size(); i++) {
		if (bracket[i] != ')') {
			dp[i] = 0;
		}
		else {
			int pre = i - dp[i - 1] - 1;
			if (pre >= 0 && bracket[pre] == '(') {
				dp[i] = dp[i - 1] + 2;
				if (pre >= 1) {
					dp[i] += dp[pre - 1];
				}
			}
		}
		max_length = max(max_length, dp[i]);
	}
	return max_length;
}

void TestExercise11() {
	Println(MaxSubBracketLength("2(()())"));
}