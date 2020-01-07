#pragma once
#include "Exercise00_AdvancedTools.h"
#include "../03.BinaryTree/Exercise00_TreeTools.h"

void ReversePrintRightBound(TreeNode* node);

void Morris(TreeNode* root) {
	if (root == nullptr)
		return;
	TreeNode* cur = root;
	TreeNode* rightmost = nullptr;
	while (cur != nullptr) {
		rightmost = cur->left_;
		if (rightmost != nullptr) {
			while (rightmost->right_ != nullptr && rightmost->right_ != cur) {
				rightmost = rightmost->right_;
			}
			if (rightmost->right_ == nullptr) {
				Print(cur->value_);
				Print(" ");
				rightmost->right_ = cur;
				cur = cur->left_;
				continue;
			}
			else {
				Print(cur->value_);
				Print(" ");
				rightmost->right_ = nullptr;
			}
		}
		else {
			Print(cur->value_);
			Print(" ");
		}
		cur = cur->right_;
	}
	Println();
}

void MorrisPre(TreeNode* root) {
	if (root == nullptr)
		return;
	TreeNode* cur = root;
	TreeNode* rightmost = nullptr;
	while (cur != nullptr) {
		rightmost = cur->left_;
		if (rightmost != nullptr) {
			while (rightmost->right_ != nullptr && rightmost->right_ != cur) {
				rightmost = rightmost->right_;
			}
			if (rightmost->right_ == nullptr) {
				Print(cur->value_);
				Print(" ");
				rightmost->right_ = cur;
				cur = cur->left_;
				continue;
			}
			else {
				rightmost->right_ = nullptr;
			}
		}
		else {
			Print(cur->value_);
			Print(" ");
		}
		cur = cur->right_;
	}
	Println();
}

void MorrisMid(TreeNode* root) {
	if (root == nullptr)
		return;
	TreeNode* cur = root;
	TreeNode* rightmost = nullptr;
	while (cur != nullptr) {
		rightmost = cur->left_;
		if (rightmost != nullptr) {
			while (rightmost->right_ != nullptr && rightmost->right_ != cur) {
				rightmost = rightmost->right_;
			}
			if (rightmost->right_ == nullptr) {
				rightmost->right_ = cur;
				cur = cur->left_;
				continue;
			}
			else {
				rightmost->right_ = nullptr;
			}
		}
		Print(cur->value_);
		Print(" ");
		cur = cur->right_;
	}
	Println();
}

void MorrisPos(TreeNode* root) {
	if (root == nullptr)
		return;
	TreeNode* cur = root;
	TreeNode* rightmost = nullptr;
	while (cur != nullptr) {
		rightmost = cur->left_;
		if (rightmost != nullptr) {
			while (rightmost->right_ != nullptr && rightmost->right_ != cur) {
				rightmost = rightmost->right_;
			}
			if (rightmost->right_ == nullptr) {
				rightmost->right_ = cur;
				cur = cur->left_;
				continue;
			}
			else {
				rightmost->right_ = nullptr;
				ReversePrintRightBound(cur->left_);
			}
		}
		cur = cur->right_;
	}
	ReversePrintRightBound(root);
	Println();
}

void ReversePrintRightBound(TreeNode* node) {
	if (node == nullptr)
		return;
	TreeNode* next = nullptr;
	TreeNode* last = nullptr;
	while (node != nullptr) {
		next = node->right_;
		node->right_ = last;
		last = node;
		node = next;
	}
	while (last != nullptr) {
		Print(last->value_);
		Print(" ");
		last = last->right_;
	}
	next = nullptr;
	node = nullptr;
	while (last != nullptr) {
		next = last->right_;
		last->right_ = node;
		node = last;
		last = next;
	}
}