#pragma once
#include "Exercise00_NowcoderTools.h"
/*找到一棵二叉树中，最大的搜索二叉子树，返回最大搜索二叉子树的节点个数。*/
struct MaxBstSizeData {
	bool isBst;
	int max_bst;
	int max;
	int min;
	MaxBstSizeData(bool is, int bst, int ma, int mi) {
		isBst = is;
		max_bst = bst;
		max = ma;
		min = mi;
	}
};
MaxBstSizeData* MaxBstSizeProcess(TreeNode* node);
int MaxBstSize(TreeNode* head) {
	if (head == nullptr) {
		return 0;
	}
	return MaxBstSizeProcess(head)->max_bst;
}

MaxBstSizeData* MaxBstSizeProcess(TreeNode* node) {
	if (node == nullptr) {
		return nullptr;
	}
	MaxBstSizeData* left_data = MaxBstSizeProcess(node->left);
	MaxBstSizeData* right_data = MaxBstSizeProcess(node->right);
	int max = node->value;
	int min = node->value;
	int max_bst = 0;
	if (left_data != nullptr) {
		max = max(max, left_data->max);
		min = min(min, left_data->min);
		max_bst = max(left_data->max_bst, max_bst);
	}
	if (right_data != nullptr) {
		max = max(max, right_data->max);
		min = min(min, right_data->min);
		max_bst = max(right_data->max_bst, max_bst);
	}
	bool isBst = false;
	if (left_data != nullptr) {
		int debug = left_data->max;
	}
	
	if ((left_data == nullptr || 
		(left_data != nullptr && left_data->max < node->value && left_data->isBst))
		&&
		(right_data == nullptr || 
		(right_data != nullptr && right_data->min > node->value && right_data->isBst))
		) {
		isBst = true;
		int tmp = (left_data==nullptr?0:left_data->max_bst) + (right_data==nullptr?0:right_data->max_bst) + 1;
		max_bst = max(max_bst, tmp);
	}
	return new MaxBstSizeData(isBst, max_bst, max, min);
}


void TestExercise38() {
	TreeNode* head = new TreeNode(8);
	head->left = new TreeNode(9);
	head->right = new TreeNode(10);
	head->left->left = new TreeNode(7);
	head->left->right = new TreeNode(10);
	head->right->left = new TreeNode(9);
	head->right->right = new TreeNode(11);
	head->right->right->right = new TreeNode(12);
	//PrintNode(head);
	Println(MaxBstSize(head));
}