#pragma once
#include "Exercise00_DpTools.h"
/*�����˴ﵽָ��λ�÷�����
����Ŀ��
�������ų�һ�е� N ��λ�ã���Ϊ 1~N��N һ�����ڻ���� 2����ʼʱ�����������е� start λ
����(start һ���� 1~N �е�һ��)�������˿��������߻��������ߣ�������������� 1 λ�ã� ��
ô��һ��ֻ���������� 2 λ��;������������� N λ�ã���ô��һ��ֻ���������� N-1 λ�á�
�涨�����˱����� steps �������������� target λ��(target Ҳһ���� 1~N �е�һ��)�ķ����ж����֡���
���ĸ����� N��start��steps��target�����ط�������
��������
N=5,start=2,steps=3,target=3
����Ĳ�����������λ��Ϊ 1 2 3 4 5���������ʼ�� 2 λ���ϣ����뾭�� 3 �������
�� 3 λ�á��ߵķ���ֻ������ 3 ��: 1)��2��1����1��2����2��3 2)��2��3����3��2����2��3
3)��2��3����3��4����4��3
���Է��ط����� 3�� 

N=3,start=1,steps=3,target=3
����Ĳ�����������λ��Ϊ 1 2 3���������ʼ�� 1 λ���ϣ����뾭�� 3 ������󵽴� 3
λ�á���ô��Ҳ�����ܣ����Է��ط����� 0��*/
int RobotWalkRecursiveProcess(const int N, int cur_pos, int rest_steps, const int target_pos);
int RobotWalkRecursive(const int N, const int start_pos, const int steps, const int target_pos) {
	if (N < 2) {
		return 0;
	}
	return RobotWalkRecursiveProcess(N, start_pos, steps, target_pos);
}

// ���شӵ�ǰλ��cur_pos��Ŀ��λ��target_pos�ķ�������ʣ��rest_steps
int RobotWalkRecursiveProcess(const int N, int cur_pos, int rest_steps, const int target_pos) {
	if (rest_steps == 0) {
		return cur_pos == target_pos ? 1 : 0;
	}
	if (cur_pos == 1) {
		return RobotWalkRecursiveProcess(N, cur_pos + 1, rest_steps - 1, target_pos);
	}
	if (cur_pos == N) {
		return RobotWalkRecursiveProcess(N, cur_pos - 1, rest_steps - 1, target_pos);
	}
	int left_ways = RobotWalkRecursiveProcess(N, cur_pos - 1, rest_steps - 1, target_pos);
	int right_ways = RobotWalkRecursiveProcess(N, cur_pos + 1, rest_steps - 1, target_pos);
	return left_ways + right_ways;
}

int RobotWalkDp(const int N, const int start_pos, const int steps, const int target_pos) {
	if (N < 2 || steps<1 || target_pos>N || target_pos<1 || start_pos>N || start_pos < 1) {
		return 0;
	}
	vector<vector<int>> dp(N + 1, vector<int>(steps + 1, 0));
	dp[target_pos][0] = 1;
	for (int col = 1; col <= steps;col++) {
		dp[1][col] = dp[2][col - 1];
		for (int row = 2; row < N; row++) {
			dp[row][col] = dp[row - 1][col - 1] + dp[row + 1][col - 1];
		}
		dp[N][col] = dp[N-1][col - 1];
	}
	return dp[start_pos][steps];
}

int RobotWalkDpZip(const int N, const int start_pos, const int steps, const int target_pos) {
	if (N < 2 || steps < 1 || start_pos < 1 || start_pos>N || target_pos<1 || target_pos>N) {
		return 0;
	}
	vector<int> dp_zip(N+1, 0);
	dp_zip[target_pos] = 1;
	int col = 1;
	while (col <= steps) {
		int left_up = dp_zip[1];
		for (int row = 1; row <= N; row++) {
			int tmp = dp_zip[row];
			if (row == 1) {
				dp_zip[row] = dp_zip[row + 1];
			}
			else if (row == N) {
				dp_zip[row] = left_up;
			}
			else {
				dp_zip[row] = left_up + dp_zip[row + 1];
			}
			left_up = tmp;
		}
		col++;
	}
	return dp_zip[start_pos];
}

void TestDp02() {
	Println(RobotWalkRecursive(5, 2, 3, 3));
	Println(RobotWalkDp(5, 2, 3, 3));
	Println(RobotWalkDpZip(5, 2, 3, 3));
	Println(RobotWalkRecursive(3, 1, 3, 3));
	Println(RobotWalkDp(3, 1, 3, 3));
	Println(RobotWalkDpZip(3, 1, 3, 3));
}