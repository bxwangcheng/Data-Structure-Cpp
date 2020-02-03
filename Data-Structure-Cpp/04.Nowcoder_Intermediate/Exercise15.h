#pragma once
#include "Exercise00_NowcoderTools.h"
/*��n���������������һ���ſ����Ϸ���һ���Զ�װ�û�ץȡһ������Ʒ��ÿ����
�����ϣ��ŵ�ÿ�������ϵ���Щ��Ʒ�����ж����٣�������Ʒ��������ͬ����Ҫ����
��ÿ�������ϵ���Ʒ�����ƶ��Ӷ�������Ʒ������Ȳ��ܴ����ÿ����Ʒ����̫��
ÿ��ֻ�ܰ�һ����Ʒ�����ƶ���Ϊ��ʡ����ֻ�����ڵĻ������ƶ���������ڰᶯ��
С������ǰ���£�ʹÿ�������ϵ���Ʒ������ȡ��������ʹÿ�������ϵ���Ʒ��ͬ��
����-1��
����[1,0,5]��ʾ��3��������ÿ�������Ϸֱ���1��0��5����Ʒ��������Щ�ֺ�
��һ�֣�1 0 <- 5 => 1 1 4 �ڶ��֣�1 <-1<- 4 => 2 1 3 �����֣�
2 1 <- 3 => 2 2 2
�ƶ���3�֣�ÿ�������ϵ���Ʒ��ȣ����Է���3
����[2,2,3]��ʾ��3��������ÿ�������Ϸֱ���2��2��3����Ʒ��
��Щ��Ʒ������ô�ƶ���������ʹ������������Ʒ������ȣ�����-1*/

vector<int> MovePackagesPreSum(const vector<int>& x);
int MovePackages(const vector<int>& x) {
	if (x.size() < 2) {
		return 0;
	}
	int sum = 0;
	for (int i = 0; i < x.size(); i++) {
		sum += x[i];
	}
	if (sum % x.size()) {
		return -1;
	}
	int avg = sum / x.size();
	vector<int> ops(x.size(), 0);
	int max_ops = INT_MIN;
	vector<int> pre_sum = MovePackagesPreSum(x);
	for (int i = 0; i < x.size(); i++) {
		int left_need = i == 0 ? 0 : i * avg - pre_sum[i - 1];
		int right_need = i == x.size() - 1 ? 0 : (x.size() - 1 - i) * avg - pre_sum[x.size() - 1] + pre_sum[i];
		if (left_need && right_need) {
			ops[i] = left_need + right_need;
		}
		else {
			ops[i] = max(abs(left_need), abs(right_need));
		}
		max_ops = max(max_ops, ops[i]);
	}
	return max_ops;
}

vector<int> MovePackagesPreSum(const vector<int>& x) {
	vector<int> pre_sum(x.size(), 0);
	pre_sum[0] = x[0];
	for (int i = 1; i < x.size(); i++) {
		pre_sum[i] = pre_sum[i - 1] + x[i];
	}
	return pre_sum;
}

void TestExercise15() {
	Println(MovePackages({ 4,6,2,0 }));
}
