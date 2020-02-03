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

/*����һ���Ϸ����������������������¶����������:
�ٿմ�""�������0
������ַ���"X"�������x,�ַ���"Y"�������y,��ô�ַ���"XY"�����Ϊ
max(x,y) 3�����"X"�������x,��ô�ַ���"(X)"�������x+1
����: "()()()"�������1,"((()))"�������3��ţţ���ڸ���һ���Ϸ�������
����,��Ҫ����������ȡ�*/

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

int MaxBracketDepth(string bracket) {
	if (bracket.size() < 2) {
		return -1;
	}
	int count = 0;
	int max_depth = INT_MIN;
	for (int i = 0; i < bracket.size(); i++) {
		if (bracket[i] == '(') {
			count++;
			max_depth = max(max_depth, count);
		}
		else if(bracket[i] == ')')
		{
			count--;
		}
		else {
			return -1;
		}
	}
	return count == 0 ? max_depth : -1;
 }