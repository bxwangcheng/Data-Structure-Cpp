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
		rightmost = cur->left;
		if (rightmost != nullptr) {
			while (rightmost->right != nullptr && rightmost->right != cur) {
				rightmost = rightmost->right;
			}
			if (rightmost->right == nullptr) {
				Print(cur->value);
				Print(" ");
				rightmost->right = cur;
				cur = cur->left;
				continue;
			}
			else {
				Print(cur->value);
				Print(" ");
				rightmost->right = nullptr;
			}
		}
		else {
			Print(cur->value);
			Print(" ");
		}
		cur = cur->right;
	}
	Println();
}

void MorrisPre(TreeNode* root) {
	if (root == nullptr)
		return;
	TreeNode* cur = root;
	TreeNode* rightmost = nullptr;
	while (cur != nullptr) {
		rightmost = cur->left;
		if (rightmost != nullptr) {
			while (rightmost->right != nullptr && rightmost->right != cur) {
				rightmost = rightmost->right;
			}
			if (rightmost->right == nullptr) {
				Print(cur->value);
				Print(" ");
				rightmost->right = cur;
				cur = cur->left;
				continue;
			}
			else {
				rightmost->right = nullptr;
			}
		}
		else {
			Print(cur->value);
			Print(" ");
		}
		cur = cur->right;
	}
	Println();
}

void MorrisMid(TreeNode* root) {
	if (root == nullptr)
		return;
	TreeNode* cur = root;
	TreeNode* rightmost = nullptr;
	while (cur != nullptr) {
		rightmost = cur->left;
		if (rightmost != nullptr) {
			while (rightmost->right != nullptr && rightmost->right != cur) {
				rightmost = rightmost->right;
			}
			if (rightmost->right == nullptr) {
				rightmost->right = cur;
				cur = cur->left;
				continue;
			}
			else {
				rightmost->right = nullptr;
			}
		}
		Print(cur->value);
		Print(" ");
		cur = cur->right;
	}
	Println();
}

void MorrisPos(TreeNode* root) {
	if (root == nullptr)
		return;
	TreeNode* cur = root;
	TreeNode* rightmost = nullptr;
	while (cur != nullptr) {
		rightmost = cur->left;
		if (rightmost != nullptr) {
			while (rightmost->right != nullptr && rightmost->right != cur) {
				rightmost = rightmost->right;
			}
			if (rightmost->right == nullptr) {
				rightmost->right = cur;
				cur = cur->left;
				continue;
			}
			else {
				rightmost->right = nullptr;
				ReversePrintRightBound(cur->left);
			}
		}
		cur = cur->right;
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
		next = node->right;
		node->right = last;
		last = node;
		node = next;
	}
	while (last != nullptr) {
		Print(last->value);
		Print(" ");
		last = last->right;
	}
	next = nullptr;
	node = nullptr;
	while (last != nullptr) {
		next = last->right;
		last->right = node;
		node = last;
		last = next;
	}
}