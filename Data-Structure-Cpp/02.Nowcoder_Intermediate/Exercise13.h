#pragma once
#include "Exercise00_NowcoderTools.h"
// 【递归】【打表法】
/*牛牛和羊羊都很喜欢青草。今天他们决定玩青草游戏。
最初有一个装有n份青草的箱子,牛牛和羊羊依次进行,牛牛先开始。在每个回合中,每个
玩家必须吃一些箱子中的青草,所吃的青草份数必须是4的x次幂,比如1,4,16,64等等。
不能在箱子中吃到有效份数青草的玩家落败。假定牛牛和羊羊都是按照最佳方法进行游
戏,请输出胜利者的名字。*/

string GrassWinner_v1(int n) {
	if (n < 0) {
		return "无效";
	}
	if (n < 5) {
		return (n == 0 || n == 2) ? "后手" : "先手";
	}
	int eat = 1;
	while (eat <= n) {
		if (GrassWinner_v1(n - eat) == "后手") {
			return "先手";
		}
		if (eat > n / 4) {
			break;
		}
		eat *= 4;
	}
	return "后手";
}

string GrassWinner_v2(int n) {
	if (n < 0) {
		return "无效";
	}
	return (n % 5 == 0 || n % 5 == 2) ? "后手" : "先手";
}

bool TestExercise13() {
	int test_time = 60;
	for (int i = 0; i < test_time; i++) {
		if (GrassWinner_v1(i) != GrassWinner_v2(i)) {
			return false;
		}
	}
	return true;
}