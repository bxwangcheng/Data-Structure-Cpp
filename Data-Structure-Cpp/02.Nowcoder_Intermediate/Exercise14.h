#pragma once
#include "Exercise00_NowcoderTools.h"
#include "../01.DataStructure&Algorithm/03.BinaryTree/Exercise00_TreeTools.h"
// 【树型DP】
/*二叉树每个结点都有一个int型权值，给定一棵二叉树，要求计算出从根结点到
叶结点的所有路径中，权值和最大的值为多少。*/

int MaxWeightProcess(TreeNode* node);
int MaxWeight(TreeNode* root) {
	if (root == nullptr) {
		return 0;
	}
	return MaxWeightProcess(root);
}

int MaxWeightProcess(TreeNode* node) {
	if (node->left_ == nullptr && node->right_ == nullptr) {
		return node->value_;
	}
	int next = INT_MIN;
	if (node->left_ != nullptr) {
		next = MaxWeightProcess(node->left_);
	}
	if (node->right_ != nullptr) {
		next = max(next, MaxWeightProcess(node->right_));
	}
	return next + node->value_;	
}

void TestExercise14() {
	TreeNode* root = new TreeNode(1);
	root->left_ = new TreeNode(2);
	root->right_ = new TreeNode(3);
	Println(MaxWeight(root));
}