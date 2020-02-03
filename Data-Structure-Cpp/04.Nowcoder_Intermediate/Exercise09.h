#pragma once
#include "Exercise00_NowcoderTools.h"
/*��һ������n������Ԫ�صļ���a��һ������m������Ԫ�صļ���b��
����magic����Ϊ����һ��������ȡ��һ��Ԫ�أ��ŵ���һ��������Ҳ�����
��ÿ�����ϵ�ƽ��ֵ��������ڲ���ǰ��
ע���������㣺
1�������԰�һ�����ϵ�Ԫ��ȡ�գ�������û��ƽ��ֵ��
2��ֵΪx��Ԫ�شӼ���bȡ�����뼯��a��������a���Ѿ���ֵΪx��Ԫ�أ���a��
ƽ��ֵ���䣨��Ϊ����Ԫ�ز����ظ�����b��ƽ��ֵ���ܻ�ı䣨��Ϊx��ȡ��
�ˣ�
�������Խ��ж��ٴ�magic������*/

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