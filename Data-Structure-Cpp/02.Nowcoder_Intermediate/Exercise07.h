#pragma once
#include "Exercise00_NowcoderTools.h"
/*һ�������������ַ��������������:
�ٿ��ַ����������ġ�
�����s���������ַ�������ô(s)Ҳ�������ġ�
�����s��t���������ַ��������������������γɵ�stҲ�������ġ�
���磬"(()())", ""��"(())()"�������������ַ�����"())(", "()(" �� ")"
�ǲ������������ַ�����
ţţ��һ�������ַ���s,������Ҫ����������λ�þ����ٵ��������,����ת��
Ϊһ�������������ַ���������ţţ������Ҫ��Ӷ��ٸ����š�*/

bool BracketValid(string bracket) {
	if (bracket.size() < 2)
		return false;
	int count = 0;
	for (int i = 0; i < bracket.size(); i++) {
		if (bracket[i] == '(') {
			count++;
		}
		else if (bracket[i] == ')') {
			count--;
		}
		else {
			return false;
		}
	}
	return count == 0 ? true : false;
}

vector<int> BracketNeed(string bracket) {
	if (bracket.size() < 1)
		return {};
	int count = 0;
	int need = 0;
	for (int i = 0; i < bracket.size(); i++) {
		if (bracket[i] == '(') {
			count++;
		}
		else if (bracket[i] == ')') {
			if (count == 0) {
				need++;
			}
			else {
				count--;
			}
		}
		else {
			return {};
		}
	}
	return { need, count };
}