#pragma once
#include "Exercise00_NowcoderTools.h"
// �������
/*С��ȥ�������̵���ƻ������թ���̷�ʹ���������ף�ֻ�ṩ6��ÿ����8��
ÿ���İ�װ��װ���ɲ�֡�����С������ֻ�빺��ǡ��n��ƻ����С���빺��
���ٵĴ�������Я����������ܹ���ǡ��n��ƻ����С�������Ṻ������һ��
����n����ʾС���빺��ĸ�ƻ����������Сʹ�ö��ٴ��ӡ����������ζ���
������װ�£�����-1��*/

int Bags(int n) {
	if (n < 6 || n % 2 == 1)// �Ż�1
		return -1;
	int bag8 = n / 8;
	while (bag8 >= 0) {
		int rest = n - 8 * bag8;
		if (rest > 24) {// �Ż�2
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