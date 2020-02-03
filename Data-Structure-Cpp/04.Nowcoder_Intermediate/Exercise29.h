#pragma once
#include "Exercise00_NowcoderTools.h"
// 【差分公式】【斐波那契数列】
/*母牛问题
最开始只有一只成熟母牛，每只成熟母牛1年生1只
3年成熟，第4年可以生牛，问第N年母牛数量*/

/*字符串只由'0'和'1'两种字符构成，
当字符串长度为1时，所有可能的字符串为"0"、"1"；
当字符串长度为2时，所有可能的字符串为"00"、"01"、"10"、"11"；
当字符串长度为3时，所有可能的字符串为"000"、"001"、"010"、"011"、"100"、
"101"、"110"、"111"
...
如果某一个字符串中，只要是出现'0'的位置，左边就靠着'1'，这样的字符串叫作达
标字符串。
给定一个正数N，返回所有长度为N的字符串中，达标字符串的数量。
比如，N=3，返回3，因为只有"101"、"110"、"111"达标。*/

int Cow(int year) {
	if (year < 1) {
		return 0;
	}
	if (year < 5) {
		return year;
	}
	// 根据初值计算 matrix
	// |F(4), F(3), F(2)| = |F(3), F(2), F(1)| * matrix
	// |F(5), F(4), F(3)| = |F(4), F(3), F(2)| * matrix
	// |F(6), F(5), F(4)| = |F(5), F(4), F(3)| * matrix
	vector<vector<int>> matrix = { {},
									{},
									{} };
	matrix = MatrixPower(matrix, year - 3);
	return 3 * matrix[0][0] + 2 * matrix[1][0] + matrix[2][0];
}

//int CountValidString(int N) {
//
//}