#pragma once
#include "Exercise00_NowcoderTools.h"
/*有n个打包机器从左到右一字排开，上方有一个自动装置会抓取一批放物品到每个打
包机上，放到每个机器上的这些物品数量有多有少，由于物品数量不相同，需要工人
将每个机器上的物品进行移动从而到达物品数量相等才能打包。每个物品重量太大、
每次只能搬一个物品进行移动，为了省力，只在相邻的机器上移动。请计算在搬动最
小轮数的前提下，使每个机器上的物品数量相等。如果不能使每个机器上的物品相同，
返回-1。
例如[1,0,5]表示有3个机器，每个机器上分别有1、0、5个物品，经过这些轮后：
第一轮：1 0 <- 5 => 1 1 4 第二轮：1 <-1<- 4 => 2 1 3 第三轮：
2 1 <- 3 => 2 2 2
移动了3轮，每个机器上的物品相等，所以返回3
例如[2,2,3]表示有3个机器，每个机器上分别有2、2、3个物品，
这些物品不管怎么移动，都不能使三个机器上物品数量相等，返回-1*/

vector<int> MovePackagesPreSum(const vector<int>& x);
int MovePackages(const vector<int>& x) {
	if (x.size() < 2) {
		return 0;
	}
	int sum = 0;
	for (int i = 0; i < x.size(); i++) {
		sum += x[i];
	}
	if (sum % x.size()) {
		return -1;
	}
	int avg = sum / x.size();
	vector<int> ops(x.size(), 0);
	int max_ops = INT_MIN;
	vector<int> pre_sum = MovePackagesPreSum(x);
	for (int i = 0; i < x.size(); i++) {
		int left_need = i == 0 ? 0 : i * avg - pre_sum[i - 1];
		int right_need = i == x.size() - 1 ? 0 : (x.size() - 1 - i) * avg - pre_sum[x.size() - 1] + pre_sum[i];
		if (left_need && right_need) {
			ops[i] = left_need + right_need;
		}
		else {
			ops[i] = max(abs(left_need), abs(right_need));
		}
		max_ops = max(max_ops, ops[i]);
	}
	return max_ops;
}

vector<int> MovePackagesPreSum(const vector<int>& x) {
	vector<int> pre_sum(x.size(), 0);
	pre_sum[0] = x[0];
	for (int i = 1; i < x.size(); i++) {
		pre_sum[i] = pre_sum[i - 1] + x[i];
	}
	return pre_sum;
}

void TestExercise15() {
	Println(MovePackages({ 4,6,2,0 }));
}
