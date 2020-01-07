#pragma once
#include "Exercise00_NowcoderTools.h"
/*给一个包含n个整数元素的集合a，一个包含m个整数元素的集合b。
定义magic操作为，从一个集合中取出一个元素，放到另一个集合里，且操作过
后每个集合的平均值都大大于于操作前。
注意以下两点：
1）不可以把一个集合的元素取空，这样就没有平均值了
2）值为x的元素从集合b取出放入集合a，但集合a中已经有值为x的元素，则a的
平均值不变（因为集合元素不会重复），b的平均值可能会改变（因为x被取出
了）
问最多可以进行多少次magic操作？*/

int MaxMagic(const set<int>& a, const set<int>& b) {
	if (a.size() < 1 || b.size() < 1)
		return 0;
	double sum_a = 0;
	double sum_b = 0;
	for (set<int>::iterator it = a.begin(); it != a.end(); it++) {
		sum_a += *it;
	}
	for (set<int>::iterator it = b.begin(); it != b.end(); it++) {
		sum_b += *it;
	}
	set<int> bigger;
	int sum_bigger = 0;
	set<int> smaller;
	int sum_smaller = 0;
	if (sum_a / a.size() > sum_b / b.size()) {
		bigger = a;
		smaller = b;
		sum_bigger = sum_a;
		sum_smaller = sum_b;
	}
	else if (sum_a / a.size() > sum_b / b.size()) {
		bigger = b;
		smaller = a;
		sum_bigger = sum_b;
		sum_smaller = sum_a;
	}
	else {
		return 0;
	}
	int magic_count = 0;
	for (set<int>::iterator it = bigger.begin(); it != bigger.end(); it++) {
		if (*it > (sum_smaller / smaller.size()) && *it < (sum_bigger / bigger.size()) && smaller.find(*it) == smaller.end()) {
			bigger.erase(it);
			smaller.insert(*it);
			sum_bigger -= *it;
			sum_smaller += *it;
			magic_count++;
		}
	}
	return magic_count;
}