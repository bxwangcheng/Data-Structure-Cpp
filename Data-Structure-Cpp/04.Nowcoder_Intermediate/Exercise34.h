#pragma once
#include "Exercise00_NowcoderTools.h"
/*牛牛准备参加学校组织的春游, 出发前牛牛准备往背包里装入一些零食, 牛牛的背包容
量为w。
牛牛家里一共有n袋零食, 第i袋零食体积为v[i]。
牛牛想知道在总体积不超过背包容量的情况下，他一共有多少种零食放法(总体积为0也
算一种放法)。*/
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