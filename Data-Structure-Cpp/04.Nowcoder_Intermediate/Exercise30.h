#pragma once
#include "Exercise00_NowcoderTools.h"
// 【差分】【斐波那契数列】【贪心】
/*在迷迷糊糊的大草原上，小红捡到了n根木棍，第i根木棍的长度为i，
小红现在很开心。想选出其中的三根木棍组成美丽的三角形。
但是小明想捉弄小红，想去掉一些木棍，使得小红任意选三根木棍都不能组成
三角形。
请问小明最少去掉多少根木棍呢？
给定N，返回至少去掉多少根？*/

// 太难了吧放弃了
int RemoveSticks(int N) {
	if (N < 4) {
		return 0;
	}
	int num = 3;
	int k1 = 2;
	int k2 = 3;
	while(k1+k2<=N){
		num++;
		k1 = k1 + k2;
		k2 = k1 - k2;
	}
	return N - num;
}
