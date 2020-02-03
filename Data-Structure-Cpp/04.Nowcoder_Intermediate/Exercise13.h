#pragma once
#include "Exercise00_NowcoderTools.h"
// ���ݹ顿�������
/*ţţ�����򶼺�ϲ����ݡ��������Ǿ����������Ϸ��
�����һ��װ��n����ݵ�����,ţţ���������ν���,ţţ�ȿ�ʼ����ÿ���غ���,ÿ��
��ұ����һЩ�����е����,���Ե���ݷ���������4��x����,����1,4,16,64�ȵȡ�
�����������гԵ���Ч������ݵ������ܡ��ٶ�ţţ�������ǰ�����ѷ���������
Ϸ,�����ʤ���ߵ����֡�*/

string GrassWinner_v1(int n) {
	if (n < 0) {
		return "��Ч";
	}
	if (n < 5) {
		return (n == 0 || n == 2) ? "����" : "����";
	}
	int eat = 1;
	while (eat <= n) {
		if (GrassWinner_v1(n - eat) == "����") {
			return "����";
		}
		if (eat > n / 4) {
			break;
		}
		eat *= 4;
	}
	return "����";
}

string GrassWinner_v2(int n) {
	if (n < 0) {
		return "��Ч";
	}
	return (n % 5 == 0 || n % 5 == 2) ? "����" : "����";
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