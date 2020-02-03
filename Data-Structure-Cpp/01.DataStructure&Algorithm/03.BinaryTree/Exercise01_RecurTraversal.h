#include "Exercise00_TreeTools.h"

/*�������ݹ���������ݹ飩*/
void RecurTraversal(TreeNode* head) {
	if (head == nullptr) {
		return;
	}
	Print(head->value + " ");
	RecurTraversal(head->left);
	Print(head->value + " ");
	RecurTraversal(head->right);
	Print(head->value + " ");
}

/*����������������ݹ飩*/
void PreTraversalRecur(TreeNode* head) {
	if (head == nullptr) {
		return;
	}
	Print(head->value + " ");
	PreTraversalRecur(head->left);
	PreTraversalRecur(head->right);
}

/*����������������ݹ飩*/
void MidTraversalRecur(TreeNode* head) {
	if (head == nullptr) {
		return;
	}
	MidTraversalRecur(head->left);
	Print(head->value + " ");
	MidTraversalRecur(head->right);
}

/*����������������ݹ飩*/
void PosTraversalRecur(TreeNode* head) {
	if (head == nullptr) {
		return;
	}
	PosTraversalRecur(head->left);
	PosTraversalRecur(head->right);
	Print(head->value + " ");
}