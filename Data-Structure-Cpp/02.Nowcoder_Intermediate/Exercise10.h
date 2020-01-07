#pragma once
#include "Exercise00_NowcoderTools.h"
// ����̬�滮��
/*����������ת��Ϊ�ַ�����ԭ�����£�1��Ӧ a��2��Ӧb����..26��Ӧz������12258
����ת��Ϊ"abbeh", "aveh", "abyh", "lbeh" and "lyh"������Ϊ5����дһ����
������������ת���Ĳ�ͬ�ַ����ĸ�����*/

int ConvertAlphabetProcess(string str, int index);
int ConvertAlphabet(int number) {
	if (number <= 0)
		return 0;
	string str = to_string(number);
	return ConvertAlphabetProcess(str, 0);
}

int ConvertAlphabetProcess(string str, int index) {
	if (index == str.size()) {
		return 1;
	}
	if (str[index] == '0') {
		return 0;
	}
	int res = ConvertAlphabetProcess(str, index + 1);
	if (index == str.size() - 1) {
		return res;
	}
	if (((str[index] - '0') * 10 + str[index + 1] - '0') < 27 && ((str[index] - '0') * 10 + str[index + 1] - '0') > 0) {
		res += ConvertAlphabetProcess(str, index + 2);
	}
	return res;
}

int ConvertAlphabetDp(int number) {
	if (number <= 0) {
		return 0;
	}
	string str = to_string(number);
	vector<int> dp(str.size() + 1);
	dp[str.size()] = 1;
	dp[str.size() - 1] = str[str.size() - 1] == '0' ? 0 : 1;
	for (int i = str.size() - 2; i >= 0; i--) {
		if (str[i] == '0') {
			dp[i] = 0;
		}
		else {
			if (((str[i] - '0') * 10 + str[i + 1] - '0') < 27 &&
				((str[i] - '0') * 10 + str[i + 1] - '0') > 0) {
				dp[i] = dp[i + 1] + dp[i + 2];
			}
			else {
				dp[i] = dp[i + 1];
			}
		}
	}
	return dp[0];
}

void TestExercise10() {
	int res1 = ConvertAlphabet(12258);
	int res2 = ConvertAlphabetDp(12258);
}