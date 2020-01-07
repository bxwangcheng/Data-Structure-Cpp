#pragma once
#include "Exercise00_NowcoderTools.h"
// 【打表法】
/*小虎去附近的商店买苹果，奸诈的商贩使用了捆绑交易，只提供6个每袋和8个
每袋的包装包装不可拆分。可是小虎现在只想购买恰好n个苹果，小虎想购买尽
量少的袋数方便携带。如果不能购买恰好n个苹果，小虎将不会购买。输入一个
整数n，表示小虎想购买的个苹果，返回最小使用多少袋子。如果无论如何都不
能正好装下，返回-1。*/

int Bags(int n) {
	if (n < 6 || n % 2 == 1)// 优化1
		return -1;
	int bag8 = n / 8;
	while (bag8 >= 0) {
		int rest = n - 8 * bag8;
		if (rest > 24) {// 优化2
			return -1;
		}
		if (rest % 6 == 0) {
			return (rest / 6) + bag8;
		}
		else {
			bag8--;
		}
	}
	return -1;
}

void TestExercise02() {
	int res = Bags(101);
}