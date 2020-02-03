#pragma once
#include "Exercise00_NowcoderTools.h"
/*已知一棵二叉树中没有重复节点，并且给定了这棵树的中序遍历数组和先序遍历
数组，返回后序遍历数组。
比如给定：
int[] pre = { 1, 2, 4, 5, 3, 6, 7 };
int[] in = { 4, 2, 5, 1, 6, 3, 7 };
返回：
{4,5,2,6,7,3,1}*/
void SetPosTraversalProcess(const vector<int>& in, const vector<int>& pre, vector<int>& pos,
	int s_in, int e_in,
	int s_pre, int e_pre,
	int s_pos, int e_pos);
int FindRootIndex(const vector<int>& arr, int start, int end, int val);

vector<int> GetPosTraversal(const vector<int>& in, const vector<int>& pre) {
	if (in.size() != pre.size() || in.size() < 1) {
		return {};
	}
	if (in.size() == 1) {
		return in;
	}
	vector<int> pos(in.size(), 0);
	SetPosTraversalProcess(in, pre, pos,
		0, in.size()-1,
		0, pre.size()-1,
		0, pos.size()-1);
	return pos;
}

void SetPosTraversalProcess(const vector<int>& in, const vector<int>& pre, vector<int>& pos,
	int s_in, int e_in,
	int s_pre, int e_pre,
	int s_pos, int e_pos) {
	if (s_in > e_in) {
		return;
	}
	if (s_in == e_in) {
		pos[s_pos] = in[s_in];
		return;
	}

	int root_index = FindRootIndex(in, s_in, e_in, pre[s_pre]);
	int left_len = root_index - s_in;
	int right_len = e_in - root_index;
	pos[e_pos] = pre[s_pre];
	SetPosTraversalProcess(in, pre, pos,
		s_in, s_in + left_len-1,
		s_pre + 1, s_pre + left_len,
		s_pos, s_pos + left_len - 1);
	SetPosTraversalProcess(in, pre, pos,
		root_index+1,e_in,
		s_pre + left_len+1, e_pre,
		s_pos + left_len, e_pos-1);
}

int FindRootIndex(const vector<int>& arr, int start, int end, int val) {
	if (start > end) {
		return -1;
	}
	if (start == end) {
		return arr[start];
	}
	for (int i = start; i <= end; i++) {
		if (arr[i] == val) {
			return i;
		}
	}
	return -1;
}

void TestExercise39() {
	vector<int> pre = { 1, 2, 4, 5, 3, 6, 7 };
	vector<int> in = { 4, 2, 5, 1, 6, 3, 7 };
	auto res = GetPosTraversal(in, pre);
	Print(res);
}