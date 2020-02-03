#pragma once
#include "Exercise00_NowcoderTools.h"
#include "../01.DataStructure&Algorithm/03.BinaryTree/Exercise00_TreeTools.h"
#include "../01.DataStructure&Algorithm/02.LinkedList/Exercise00_ListTools.h"
// ������DP��
/*˫������ڵ�ṹ�Ͷ������ڵ�ṹ��һ���ģ�������last��Ϊ��left��
next��Ϊ��next�Ļ���
����һ��������������ͷ�ڵ�head����ת����һ�������˫��������������
���ͷ�ڵ㡣*/
struct TreeToListData {
	TreeNode* head;
	TreeNode* tail;
	TreeToListData(TreeNode* h, TreeNode* t) {
		head = h;
		tail = t;
	}
};

TreeToListData* TreeToListProcess(TreeNode* node);
TreeNode* TreeToList(TreeNode* bst_head) {
	if (bst_head == nullptr) {
		return nullptr;
	}
	return TreeToListProcess(bst_head)->head;
}

TreeToListData* TreeToListProcess(TreeNode* node) {
	if (node == nullptr) {
		return new TreeToListData(nullptr, nullptr);
	}
	TreeToListData* left_data = TreeToListProcess(node->left);
	TreeToListData* right_data = TreeToListProcess(node->right);
	if (left_data->tail != nullptr) {
		left_data->tail->right = node;
	}
	node->left = left_data->tail;
	if (right_data->head != nullptr) {
		right_data->head->left = node;
	}
	node->right = right_data->head;
	return new TreeToListData(left_data->head==nullptr?node:left_data->head, right_data->tail==nullptr?node:right_data->tail);
}

void TestExercise37() {
	TreeNode* head = new TreeNode(5);
	head->left = new TreeNode(3);
	head->right = new TreeNode(7);
	head->left->left = new TreeNode(2);
	head->left->right = new TreeNode(4);
	head->right->left = new TreeNode(6);
	head->right->right = new TreeNode(8);
	TreeNode* list_head = TreeToList(head);
}

