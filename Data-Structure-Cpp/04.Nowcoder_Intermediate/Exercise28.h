#pragma once
#include "Exercise00_NowcoderTools.h"
/*如果一个字符串为str，把字符串str前面任意的部分挪到后面形成的字符串叫
作str的旋转词。比如str="12345"，str的旋转词有"12345"、"23451"、
"34512"、"45123"和"51234"。给定两个字符串a和b，请判断a和b是否互为旋转
词。
比如：
a="cdab"，b="abcd"，返回true。
a="1ab2"，b="ab12"，返回false。
a="2ab1"，b="ab12"，返回true。*/
bool isSubString(const string& aa, const string& a);
bool isRotateString(const string& a, const string& b) {
	string aa = a + a;
	return isSubString(aa, b);
}

// 使用kmp加速
bool isSubString(const string& aa, const string& a) {
	if (aa == "" || a == "") {
		return false;
	}
	if (aa.size() < a.size()) {
		return false;
	}
	int p1 = 0;
	int p2 = 0;
	while (p1 < aa.size()) {
		while (p2 < a.size()) {
			if (p1 > aa.size()) {
				return false;
			}
			if (aa[p1] == a[p2]) {
				p1++;
				p2++;
			}
			else {
				p1++;
				p2 = 0;
			}
		}
		return true;
	}
	return false;
}

void TestExercise28() {
	//string a = "abcdefg";
	//vector<string> test = { "abcdefg","","a","b","c","f","g","abo","abcdefo", "efg", "cde" };
	//for (int i = 0; i < test.size(); i++) {
	//	Println(isSubString(a, test[i]) ? "true" : "false");
	//}
	Println(isRotateString("cdab", "abcd") ? "true" : "false");
	Println(isRotateString("1ab2", "ab12") ? "true" : "false");
	Println(isRotateString("2ab1", "ab12") ? "true" : "false");
}
