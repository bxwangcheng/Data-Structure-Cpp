#pragma once

// aabsaa t aabsaa k aabsaat aabsaa ax
vector<int> getNextArray(string str) {
	if (str.size() < 1 || &str == nullptr) {
		return {};
	}
	vector<int> next(str.size());
	next[0] = -1;
	next[1] = 0;
	int i = 2;
	int cn = 0;//当前比对位置，也是i-1的最长前缀后缀
	while (i < str.size()) {
		if (str[i - 1] == str[cn]) {
			next[i] = cn + 1;// i位置的最长前缀后缀时i-1值+1
			i++;
			cn++;
		}
		else if (cn > 0) {
			cn = next[cn];
		}
		else {
			next[i] = 0;
			i++;
		}
	}
	return next;
}

int kmp(string str1, string str2) {
	if (str1.size() < 1 || str2.size() < 1 || &str1 == nullptr || &str2 == nullptr
		|| (str1.size() < str2.size())) {
		return -1;
	}
	vector<int> next = getNextArray(str2);
	int i1 = 0;
	int i2 = 0;
	while (i1 < str1.size() && i2 < str2.size()) {
		if (str1[i1] == str2[i2]) {
			i1++;
			i2++;
		}
		else if (next[i2] == -1) {// 隐含i2==0
			i1++;
		}
		else {
			i2 = next[i2];
		}
	}
	return i2 == str2.size() ? i1 - i2 : -1;
}