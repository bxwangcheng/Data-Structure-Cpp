#pragma once
#include "Exercise00_NowcoderTools.h"
// ����ѧ������ʽ�ֽ⡿
/*����s��m��ʼ����s = "a"; m = s;
�ٶ������ֲ�������һ�ֲ�����
m = s;
s = s + s;
�ڶ��ֲ�����
s = s + m;
����С�Ĳ��������������Խ�sƴ�ӵ����ȵ���n*/

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