#pragma once
#include "Exercise00_NowcoderTools.h"
/*一个完整的括号字符串定义规则如下:
①空字符串是完整的。
②如果s是完整的字符串，那么(s)也是完整的。
③如果s和t是完整的字符串，将它们连接起来形成的st也是完整的。
例如，"(()())", ""和"(())()"是完整的括号字符串，"())(", "()(" 和 ")"
是不完整的括号字符串。
牛牛有一个括号字符串s,现在需要在其中任意位置尽量少地添加括号,将其转化
为一个完整的括号字符串。请问牛牛至少需要添加多少个括号。*/

/*对于一个合法的括号序列我们又有以下定义它的深度:
①空串""的深度是0
②如果字符串"X"的深度是x,字符串"Y"的深度是y,那么字符串"XY"的深度为
max(x,y) 3、如果"X"的深度是x,那么字符串"(X)"的深度是x+1
例如: "()()()"的深度是1,"((()))"的深度是3。牛牛现在给你一个合法的括号
序列,需要你计算出其深度。*/

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