#pragma once
#include "Exercise00_NowcoderTools.h"
/*ţţ׼���μ�ѧУ��֯�Ĵ���, ����ǰţţ׼����������װ��һЩ��ʳ, ţţ�ı�����
��Ϊw��
ţţ����һ����n����ʳ, ��i����ʳ���Ϊv[i]��
ţţ��֪�����������������������������£���һ���ж�������ʳ�ŷ�(�����Ϊ0Ҳ
��һ�ַŷ�)��*/
int BagWaysProcess(const vector<int>& products, int index, int rest_bag_size);
int BagWays(const vector<int>& products, int rest_bag_size) {
	return BagWaysProcess(products, 0, rest_bag_size);
}

int BagWaysProcess(const vector<int>& products, int index, int rest_bag_size) {
	if (rest_bag_size < 0) {
		return -1;
	}
	if (index == products.size()) {
		return 1;
	}
	int ways = 0;
	int next = BagWaysProcess(products, index + 1, rest_bag_size);
	ways += next == -1 ? 0 : next;
	next = BagWaysProcess(products, index + 1, rest_bag_size - products[index]);
	ways += next == -1 ? 0 : next;
	return ways;
}

void TestExercise34() {
	vector<int> products = { 4,3,2,9 };
	Println(BagWays(products, 8));
}