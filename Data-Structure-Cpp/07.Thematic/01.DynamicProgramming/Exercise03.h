#pragma once
#include "Exercise00_DpTools.h"
/*�ų�һ���ߵ�ֽ�Ʋ�������
����Ŀ��
����һ���������� arr��������ֵ��ͬ��ֽ���ų�һ���ߡ���� A ����� B ��������ÿ��ֽ �ƣ�
�涨��� A ���ã���� B ���ã�����ÿ�����ÿ��ֻ��������������ҵ�ֽ�ƣ���� A �� ��
�� B �������������뷵������ʤ�ߵķ�����
��������
arr=[1,2,100,4]��
��ʼʱ����� A ֻ������ 1 �� 4�������� A ���� 1�������б�Ϊ[2,100,4]����������� B
�������� 2 �� 4��Ȼ������ֵ���� A�������ʼʱ��� A ���� 4�������б�Ϊ[1,2,100]����
�� ����� B �������� 1 �� 100��Ȼ������ֵ���� A����� A ��Ϊ�����������˲������� 4��
��Ϊ �� 4 ֮����� B ������ 100��������� A ������ 1�������б�Ϊ[2,100,4]����������
�� B ���� ��ôѡ��100 ���ᱻ��� A ���ߡ���� A ���ʤ������Ϊ 101�����Է��� 101��
arr=[1,100,2]��
��ʼʱ����� A ������ 1 ���� 2����� B ��Ϊ�����������ˣ������ 100 ���ߡ���� B ��
��ʤ������Ϊ 100�����Է��� 100��*/
int PlayCardsRecursiveFirstProcess(const vector<int>& arr, int start, int end);
int PlayCardsRecursiveSecondProcess(const vector<int>& arr, int start, int end);
int PlayCardsRecursive(const vector<int>& arr) {
	if (arr.size() < 1) {
		return 0;
	}
	int first = PlayCardsRecursiveFirstProcess(arr, 0, arr.size() - 1);
	int second = PlayCardsRecursiveSecondProcess(arr, 0, arr.size() - 1);
	return max(first, second);
}

int PlayCardsRecursiveFirstProcess(const vector<int>& arr, int start, int end) {
	if (start == end) {
		return arr[start];
	}
	int res1 = arr[start] + PlayCardsRecursiveSecondProcess(arr, start + 1, end);
	int res2 = arr[end] + PlayCardsRecursiveSecondProcess(arr, start, end-1);
	return max(res1, res2);
}

int PlayCardsRecursiveSecondProcess(const vector<int>& arr, int start, int end) {
	if (start == end) {
		return 0;
	}
	int res1 = PlayCardsRecursiveFirstProcess(arr, start + 1, end);
	int res2 = PlayCardsRecursiveFirstProcess(arr, start, end-1);
	return min(res1, res2);
}

int PlayCardsDp(const vector<int>& arr) {
	if (arr.size() < 1) {
		return 0;
	}
	vector<vector<int>> first(arr.size(), vector<int>(arr.size(),-1));
	vector<vector<int>> second(arr.size(), vector<int>(arr.size(), -1));
	for (int start = 0; start < arr.size() - 1; start++) {
		for (int end = start + 1; end < arr.size(); end++) {
			first[start][end] = max(arr[start] + second[start + 1][end], arr[end] + second[start][end - 1]);
			second[start][end] = min(first[start + 1][end], first[start][end - 1]);
		}
	}
	return max(first[0][arr.size()-1],second[0][arr.size()-1]);
}

void TestDp03() {
	Println(PlayCardsRecursive({ 1,100,2 }));
	Println(PlayCardsDp({ 1,100,2 }));
}