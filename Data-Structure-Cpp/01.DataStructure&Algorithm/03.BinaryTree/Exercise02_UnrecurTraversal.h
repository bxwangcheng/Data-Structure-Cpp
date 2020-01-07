#include "Exercise00_TreeTools.h"

/*����������������ǵݹ飩*/
void PreTraversalUnrecur(TreeNode* head) {
	if (head == nullptr) {
		return;
	}
	stack<TreeNode*> stack;
	stack.push(head);
	while (!stack.empty()) {
		TreeNode* cur = stack.top();
		Print(to_string(cur->value_)+" ");
		stack.pop();
		if (cur->right_ != nullptr) {
			stack.push(cur->right_);
		}
		if (cur->left_ != nullptr) {
			stack.push(cur->left_);
		}
	}
	Println();
}

/*����������������ǵݹ飩*/
void MidTraversalUnrecur(TreeNode* head) {
	if (head == nullptr) {
		return;
	}
	stack<TreeNode*> stk;
	stk.push(head);
	while (head->left_ != nullptr) {
		stk.push(head->left_);
		head = head->left_;
	}
	while (!stk.empty()) {
		TreeNode* cur = stk.top();
		stk.pop();
		Print(to_string(cur->value_)+" ");
		if (cur->right_ != nullptr) {
			stk.push(cur->right_);
			cur = cur->right_;
			while (cur->left_ != nullptr) {
				stk.push(cur->left_);
				cur = cur->left_;
			}
		}
	}
	Println();
}

/*����������������ǵݹ飩*/
void PosTraversalUnrecur(TreeNode* head) {
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
		if (cur->left_ != nullptr) {
			stk.push(cur->left_);
		}
		if (cur->right_ != nullptr) {
			stk.push(cur->right_);
		}
	}
	while (!res.empty()) {
		TreeNode* cur = res.top();
		Print(to_string(cur->value_)+" ");
		res.pop();
	}
	Println();
}

/*��������ȱ������ǵݹ飩*/
void WidthTraversalUnrecur(TreeNode* head) {
	if (head == nullptr) {
		return;
	}
	queue<TreeNode*> q;
	q.push(head);
	while (!q.empty()) {
		TreeNode* cur = q.front();
		Print(to_string(cur->value_)+" ");
		q.pop();
		if (cur->left_ != nullptr) {
			q.push(cur->left_);
		}
		if (cur->right_ != nullptr) {
			q.push(cur->right_);
		}
	}
	Println();
}