#pragma once
#include "Exercise00_NowcoderTools.h"
/*小Q正在给一条长度为n的道路设计路灯安置方案。
为了让问题更简单,小Q把道路视为n个方格,需要照亮的地方用'.'表示, 不需要
照亮的障碍物格子用'X'表示。小Q现在要在道路上设置一些路灯, 对于安置在
pos位置的路灯, 这盏路灯可以照亮pos - 1, pos, pos + 1这三个位置。
小Q希望能安置尽量少的路灯照亮所有'.'区域, 希望你能帮他计算一下最少需
要多少盏路灯。
输入描述：
输入的第一行包含一个正整数t(1 <= t <= 1000), 表示测试用例数
接下来每两行一个测试数据, 第一行一个正整数n(1 <= n <= 1000),表示道路
的长度。第二行一个字符串s表示道路的构造,只包含'.'和'X'。
输出描述：
对于每个测试用例, 输出一个正整数表示最少需要多少盏路灯。*/

int LightUpRoad(string arr) {
	if (arr.size() < 1) {
		return -1;
	}
}

// arr[index..]往后需要多少灯
// pre表示之前有没有点亮
int LightUpRoadProcess(string arr, bool pre, int index) {
	if (index == arr.size()) {
		return pre ? 0 : -1;
	}
	if (index == arr.size() - 1) {
		if (arr[index] == 'X' && pre) {
			return 0;
		}
		if (arr[index] == 'X' && !pre) {
			return -1;
		}
		return 1;
	}
	if (pre) {
		int p1 = LightUpRoadProcess(arr, false, index + 1);
		int p2 = LightUpRoadProcess(arr, true, index + 2);
		return p1 + p2;
	}
	else {

		return arr[index] == 'X' ? -1 : 1 + LightUpRoadProcess(arr, true, index + 1);
	}
	

}