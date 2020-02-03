#pragma once
#include "Exercise00_NowcoderTools.h"
/*���һ���ַ���Ϊstr�����ַ���strǰ������Ĳ���Ų�������γɵ��ַ�����
��str����ת�ʡ�����str="12345"��str����ת����"12345"��"23451"��
"34512"��"45123"��"51234"�����������ַ���a��b�����ж�a��b�Ƿ�Ϊ��ת
�ʡ�
���磺
a="cdab"��b="abcd"������true��
a="1ab2"��b="ab12"������false��
a="2ab1"��b="ab12"������true��*/
bool isSubString(const string& aa, const string& a);
bool isRotateString(const string& a, const string& b) {
	string aa = a + a;
	return isSubString(aa, b);
}

// ʹ��kmp����
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
