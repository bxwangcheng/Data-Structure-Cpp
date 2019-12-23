#include "Exercise00_TreeTools.h"

void pre_traversal_unrecur(TreeNode* head) {
	if (head == nullptr) {
		return;
	}
	stack<TreeNode*> stack;
	stack.push(head);
	while (!stack.empty()) {
		TreeNode* cur = stack.top();
		print_to_console(cur->value);
		print_to_console(" ");
		stack.pop();
		if (cur->right != nullptr) {
			stack.push(cur->right);
		}
		if (cur->left != nullptr) {
			stack.push(cur->left);
		}
	}
	print_to_console_ln();
}

void mid_traversal_unrecur(TreeNode* head) {
	if (head == nullptr) {
		return;
	}
	stack<TreeNode*> stk;
	stk.push(head);
	while (head->left != nullptr) {
		stk.push(head->left);
		head = head->left;
	}
	while (!stk.empty()) {
		TreeNode* cur = stk.top();
		stk.pop();
		print_to_console(cur->value);
		print_to_console(" ");
		if (cur->right != nullptr) {
			stk.push(cur->right);
			cur = cur->right;
			while (cur->left != nullptr) {
				stk.push(cur->left);
				cur = cur->left;
			}
		}
	}
	print_to_console_ln();
}

void pos_traversal_unrecur(TreeNode* head) {
	if (head == nullptr) {
		return;
	}
	stack<TreeNode*> stk;
	stack<TreeNode*> res;
	stk.push(head);
	while (!stk.empty()) {
		TreeNode* cur = stk.top();
		res.push(cur);
		stk.pop();
		if (cur->left != nullptr) {
			stk.push(cur->left);
		}
		if (cur->right != nullptr) {
			stk.push(cur->right);
		}
	}
	while (!res.empty()) {
		TreeNode* cur = res.top();
		print_to_console(cur->value);
		print_to_console(" ");
		res.pop();
	}
	print_to_console_ln();
}

void width_traversal_unrecur(TreeNode* head) {
	if (head == nullptr) {
		return;
	}
	queue<TreeNode*> q;
	q.push(head);
	while (!q.empty()) {
		TreeNode* cur = q.front();
		print_to_console(cur->value);
		print_to_console(" ");
		q.pop();
		if (cur->left != nullptr) {
			q.push(cur->left);
		}
		if (cur->right != nullptr) {
			q.push(cur->right);
		}
	}
	print_to_console_ln();
}