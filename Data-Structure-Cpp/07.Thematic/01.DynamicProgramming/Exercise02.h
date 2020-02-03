#pragma once
#include "Exercise00_DpTools.h"
/*机器人达到指定位置方法数
【题目】
假设有排成一行的 N 个位置，记为 1~N，N 一定大于或等于 2。开始时机器人在其中的 start 位
置上(start 一定是 1~N 中的一个)，机器人可以往左走或者往右走，如果机器人来到 1 位置， 那
么下一步只能往右来到 2 位置;如果机器人来到 N 位置，那么下一步只能往左来到 N-1 位置。
规定机器人必须走 steps 步，最终能来到 target 位置(target 也一定是 1~N 中的一个)的方法有多少种。给
定四个参数 N、start、steps、target，返回方法数。
【举例】
N=5,start=2,steps=3,target=3
上面的参数代表所有位置为 1 2 3 4 5。机器人最开始在 2 位置上，必须经过 3 步，最后到
达 3 位置。走的方法只有如下 3 种: 1)从2到1，从1到2，从2到3 2)从2到3，从3到2，从2到3
3)从2到3，从3到4，从4到3
所以返回方法数 3。 

N=3,start=1,steps=3,target=3
上面的参数代表所有位置为 1 2 3。机器人最开始在 1 位置上，必须经过 3 步，最后到达 3
位置。怎么走也不可能，所以返回方法数 0。*/
int RobotWalkRecursiveProcess(const int N, int cur_pos, int rest_steps, const int target_pos);
int RobotWalkRecursive(const int N, const int start_pos, const int steps, const int target_pos) {
	if (N < 2) {
		return 0;
	}
	return RobotWalkRecursiveProcess(N, start_pos, steps, target_pos);
}

// 返回从当前位置cur_pos到目标位置target_pos的方法数，剩余rest_steps
int RobotWalkRecursiveProcess(const int N, int cur_pos, int rest_steps, const int target_pos) {
	if (rest_steps == 0) {
		return cur_pos == target_pos ? 1 : 0;
	}
	if (cur_pos == 1) {
		return RobotWalkRecursiveProcess(N, cur_pos + 1, rest_steps - 1, target_pos);
	}
	if (cur_pos == N) {
		return RobotWalkRecursiveProcess(N, cur_pos - 1, rest_steps - 1, target_pos);
	}
	int left_ways = RobotWalkRecursiveProcess(N, cur_pos - 1, rest_steps - 1, target_pos);
	int right_ways = RobotWalkRecursiveProcess(N, cur_pos + 1, rest_steps - 1, target_pos);
	return left_ways + right_ways;
}

int RobotWalkDp(const int N, const int start_pos, const int steps, const int target_pos) {
	if (N < 2 || steps<1 || target_pos>N || target_pos<1 || start_pos>N || start_pos < 1) {
		return 0;
	}
	vector<vector<int>> dp(N + 1, vector<int>(steps + 1, 0));
	dp[target_pos][0] = 1;
	for (int col = 1; col <= steps;col++) {
		dp[1][col] = dp[2][col - 1];
		for (int row = 2; row < N; row++) {
			dp[row][col] = dp[row - 1][col - 1] + dp[row + 1][col - 1];
		}
		dp[N][col] = dp[N-1][col - 1];
	}
	return dp[start_pos][steps];
}

int RobotWalkDpZip(const int N, const int start_pos, const int steps, const int target_pos) {
	if (N < 2 || steps < 1 || start_pos < 1 || start_pos>N || target_pos<1 || target_pos>N) {
		return 0;
	}
	vector<int> dp_zip(N+1, 0);
	dp_zip[target_pos] = 1;
	int col = 1;
	while (col <= steps) {
		int left_up = dp_zip[1];
		for (int row = 1; row <= N; row++) {
			int tmp = dp_zip[row];
			if (row == 1) {
				dp_zip[row] = dp_zip[row + 1];
			}
			else if (row == N) {
				dp_zip[row] = left_up;
			}
			else {
				dp_zip[row] = left_up + dp_zip[row + 1];
			}
			left_up = tmp;
		}
		col++;
	}
	return dp_zip[start_pos];
}

void TestDp02() {
	Println(RobotWalkRecursive(5, 2, 3, 3));
	Println(RobotWalkDp(5, 2, 3, 3));
	Println(RobotWalkDpZip(5, 2, 3, 3));
	Println(RobotWalkRecursive(3, 1, 3, 3));
	Println(RobotWalkDp(3, 1, 3, 3));
	Println(RobotWalkDpZip(3, 1, 3, 3));
}