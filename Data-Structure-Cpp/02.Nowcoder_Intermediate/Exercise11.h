#pragma once
#include "Exercise00_NowcoderTools.h"
// ����̬�滮��
/*һ���Ϸ�������ƥ�����������¶���:
�ٿմ�""��һ���Ϸ�������ƥ������
�����"X"��"Y"���ǺϷ�������ƥ������,"XY"Ҳ��һ���Ϸ�������ƥ������
�����"X"��һ���Ϸ�������ƥ������,��ô"(X)"Ҳ��һ���Ϸ�������ƥ������
��ÿ���Ϸ����������ж����������Ϲ������ɡ�
����: "","()","()()","((()))"���ǺϷ�����������
����Ϸ��Ӵ��ĳ���*/
// �Ӵ� ������ ���⣬����ÿ��λ����Ϊ��β���������DP�Ͽ�

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