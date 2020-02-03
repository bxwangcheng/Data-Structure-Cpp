#pragma once
#include "Exercise00_DpTools.h"
/*排成一条线的纸牌博弈问题
【题目】
给定一个整型数组 arr，代表数值不同的纸牌排成一条线。玩家 A 和玩家 B 依次拿走每张纸 牌，
规定玩家 A 先拿，玩家 B 后拿，但是每个玩家每次只能拿走最左或最右的纸牌，玩家 A 和 玩
家 B 都绝顶聪明。请返回最后获胜者的分数。
【举例】
arr=[1,2,100,4]。
开始时，玩家 A 只能拿走 1 或 4。如果玩家 A 拿走 1，则排列变为[2,100,4]，接下来玩家 B
可以拿走 2 或 4，然后继续轮到玩家 A。如果开始时玩家 A 拿走 4，则排列变为[1,2,100]，接
下 来玩家 B 可以拿走 1 或 100，然后继续轮到玩家 A。玩家 A 作为绝顶聪明的人不会先拿 4，
因为 拿 4 之后，玩家 B 将拿走 100。所以玩家 A 会先拿 1，让排列变为[2,100,4]，接下来玩
家 B 不管 怎么选，100 都会被玩家 A 拿走。玩家 A 会获胜，分数为 101。所以返回 101。
arr=[1,100,2]。
开始时，玩家 A 不管拿 1 还是 2，玩家 B 作为绝顶聪明的人，都会把 100 拿走。玩家 B 会
获胜，分数为 100。所以返回 100。*/
int PlayCardsRecursiveFirstProcess(const vector<int>& arr, int start, int end);
int PlayCardsRecursiveSecondProcess(const vector<int>& arr, int start, int end);
int PlayCardsRecursive(const vector<int>& arr) {
	if (arr.size() < 1) {
		return 0;
	}
	int first = PlayCardsRecursiveFirstProcess(arr, 0, arr.size() - 1);
	int second = PlayCardsRecursiveSecondProcess(arr, 0, arr.size() - 1);
	return max(first, second);
}

int PlayCardsRecursiveFirstProcess(const vector<int>& arr, int start, int end) {
	if (start == end) {
		return arr[start];
	}
	int res1 = arr[start] + PlayCardsRecursiveSecondProcess(arr, start + 1, end);
	int res2 = arr[end] + PlayCardsRecursiveSecondProcess(arr, start, end-1);
	return max(res1, res2);
}

int PlayCardsRecursiveSecondProcess(const vector<int>& arr, int start, int end) {
	if (start == end) {
		return 0;
	}
	int res1 = PlayCardsRecursiveFirstProcess(arr, start + 1, end);
	int res2 = PlayCardsRecursiveFirstProcess(arr, start, end-1);
	return min(res1, res2);
}

int PlayCardsDp(const vector<int>& arr) {
	if (arr.size() < 1) {
		return 0;
	}
	vector<vector<int>> first(arr.size(), vector<int>(arr.size(),-1));
	vector<vector<int>> second(arr.size(), vector<int>(arr.size(), -1));
	for (int start = 0; start < arr.size() - 1; start++) {
		for (int end = start + 1; end < arr.size(); end++) {
			first[start][end] = max(arr[start] + second[start + 1][end], arr[end] + second[start][end - 1]);
			second[start][end] = min(first[start + 1][end], first[start][end - 1]);
		}
	}
	return max(first[0][arr.size()-1],second[0][arr.size()-1]);
}

void TestDp03() {
	Println(PlayCardsRecursive({ 1,100,2 }));
	Println(PlayCardsDp({ 1,100,2 }));
}