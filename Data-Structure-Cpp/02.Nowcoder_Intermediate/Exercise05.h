#pragma once
#include "Exercise00_NowcoderTools.h"
/*给定一个函数f，可以1～5的数字等概率返回一个。请加工出1～7的数字等概率
返回一个的函数g。
给定一个函数f，可以a～b的数字等概率返回一个。请加工出c～d的数字等概率
返回一个的函数g。
给定一个函数f，以p概率返回0，以1-p概率返回1。请加工出等概率返回0和1的
函数g*/

int RawRand(int a, int b) {
	if (a > b)
		return -1;
	if (a == b)
		return a;
	return (rand() % (b - a + 1)) + 1;
}

int MakeBinaryRand(int (*RawRand)(int, int), int a, int b) {
	if (RawRand == nullptr)
		return -1;
	int res = 0;
	int mid = a + ((b - a) >> 1);
	if ((b - a + 1) % 2) {
		do {
			res = RawRand(a, b);
		} while (res == mid);
	}
	else {
		res = RawRand(a, b);
	}
	return res > mid ? 1 : 0;
}

int MakeAnyRand(int c, int d) {
	if (c > d)
		return -1;
	if (c == d)
		return c;
	int bits = ceil(log(d - c + 1) / log(2));
	int res;
	do {
		res = 0;
		for (int i = 0; i < bits; i++) {
			res += (MakeBinaryRand(RawRand, 1, 5) << i);
		}
	} while (res > (d - c));
	return res + 1;
}

void TestExercise05() {
	int test_count = 20000;
	int one = 0;
	int two = 0;
	int three = 0;
	int four = 0;
	int five = 0;
	int six = 0;
	int seven = 0;
	srand((unsigned)time(nullptr));
	for (int i = 0; i < test_count; i++) {
		switch (MakeAnyRand(1, 7)) {
		case 1:
			one++;
			break;
		case 2:
			two++;
			break;
		case 3:
			three++;
			break;
		case 4:
			four++;
			break;
		case 5:
			five++;
			break;
		case 6:
			six++;
			break;
		case 7:
			seven++;
			break;
		default:
			Println("wrong!");
		}
	}
	Println(one);
	Println(two);
	Println(three);
	Println(four);
	Println(five);
	Println(six);
	Println(seven);
}