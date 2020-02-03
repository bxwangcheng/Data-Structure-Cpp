#include "Exercise00_TreeTools.h"

/*二叉树先序遍历（非递归）*/
void PreTraversalUnrecur(TreeNode* head) {
	if (head == nullptr) {
		return;
	}
	stack<TreeNode*> stack;
	stack.push(head);
	while (!stack.empty()) {
		TreeNode* cur = stack.top();
		Print(to_string(cur->value)+" ");
		stack.pop();
		if (cur->right != nullptr) {
			stack.push(cur->right);
		}
		if (cur->left != nullptr) {
			stack.push(cur->left);
		}
	}
	Println();
}

/*二叉树中序遍历（非递归）*/
void MidTraversalUnrecur(TreeNode* head) {
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
		Print(to_string(cur->value)+" ");
		if (cur->right != nullptr) {
			stk.push(cur->right);
			cur = cur->right;
			while (cur->left != nullptr) {
				stk.push(cur->left);
				cur = cur->left;
			}
		}
	}
	Println();
}

/*二叉树后序遍历（非递归）*/
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
		if (cur->left != nullptr) {
			stk.push(cur->left);
		}
		if (cur->right != nullptr) {
			stk.push(cur->right);
		}
	}
	while (!res.empty()) {
		TreeNode* cur = res.top();
		Print(to_string(cur->value)+" ");
		res.pop();
	}
	Println();
}

/*二叉树宽度遍历（非递归）*/
void WidthTraversalUnrecur(TreeNode* head) {
	if (head == nullptr) {
		return;
	}
	queue<TreeNode*> q;
	q.push(head);
	while (!q.empty()) {
		TreeNode* cur = q.front();
		Print(to_string(cur->value)+" ");
		q.pop();
		if (cur->left != nullptr) {
			q.push(cur->left);
		}
		if (cur->right != nullptr) {
			q.push(cur->right);
		}
	}
	Println();
}