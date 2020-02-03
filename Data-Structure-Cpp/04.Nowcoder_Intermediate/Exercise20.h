#pragma once
#include "Exercise00_NowcoderTools.h"
// 【数学】【因式分解】
/*假设s和m初始化，s = "a"; m = s;
再定义两种操作，第一种操作：
m = s;
s = s + s;
第二种操作：
s = s + m;
求最小的操作步骤数，可以将s拼接到长度等于n*/

string Op1(string& str);
void Op2(string& str, const string& m);
bool isPrime(const int num);
vector<int> Factorize(int value);

int MinSmStep(string& str, const int n) {
	if (str.size() > n) {
		return -1;
	}
	if (str.size() == n) {
		return 0;
	}
	if (str.size() != 1) {
		return -1;
	}
	if (isPrime(n)) {
		return n - 1;
	}
	vector<int> factor = Factorize(n);
	int sum = 0;
	for (int i = 0; i < factor.size(); i++) {
		sum += factor[i];
	}
	return sum-factor.size();
}

string Op1(string& str) {
	str = str + str;
	string m = str;
	return m;
}

void Op2(string& str, const string& m) {
	str = str + m;
}

bool isPrime(const int num) {
	if (num < 2) {
		return false;
	}
	for (int i = 2; i < num; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

vector<int> Factorize(int value) {
	vector<int> fac;
	for (int i = 2; i < value; i++) {
		while (value % i == 0) {
			fac.push_back(i);
			value = value / i;
		}
	}
	fac.push_back(value);
	return fac;
}

void TestExercise20() {
	string s = "a";
	Println(MinSmStep(s, 12));
}