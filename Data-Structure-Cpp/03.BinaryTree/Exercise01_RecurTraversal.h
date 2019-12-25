#include "Exercise00_TreeTools.h"

/*�������ݹ���������ݹ飩*/
void RecurTraversal(TreeNode* head) {
	if (head == nullptr) {
		return;
	}
	Print(head->value_ + " ");
	RecurTraversal(head->left_);
	Print(head->value_ + " ");
	RecurTraversal(head->right_);
	Print(head->value_ + " ");
}

/*����������������ݹ飩*/
void PreTraversalRecur(TreeNode* head) {
	if (head == nullptr) {
		return;
	}
	Print(head->value_ + " ");
	PreTraversalRecur(head->left_);
	PreTraversalRecur(head->right_);
}

/*����������������ݹ飩*/
void MidTraversalRecur(TreeNode* head) {
	if (head == nullptr) {
		return;
	}
	MidTraversalRecur(head->left_);
	Print(head->value_ + " ");
	MidTraversalRecur(head->right_);
}

/*����������������ݹ飩*/
void PosTraversalRecur(TreeNode* head) {
	if (head == nullptr) {
		return;
	}
	PosTraversalRecur(head->left_);
	PosTraversalRecur(head->right_);
	Print(head->value_ + " ");
}