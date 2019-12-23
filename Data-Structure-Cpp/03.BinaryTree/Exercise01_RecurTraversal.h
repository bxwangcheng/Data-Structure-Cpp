#include "Exercise00_TreeTools.h"

void recur_traversal(TreeNode* head) {
	if (head == nullptr) {
		return;
	}
	print_to_console(head->value + " ");
	recur_traversal(head->left);
	print_to_console(head->value + " ");
	recur_traversal(head->right);
	print_to_console(head->value + " ");
}

void pre_traversal_recur(TreeNode* head) {
	if (head == nullptr) {
		return;
	}
	print_to_console(head->value + " ");
	pre_traversal_recur(head->left);
	pre_traversal_recur(head->right);
}

void mid_traversal_recur(TreeNode* head) {
	if (head == nullptr) {
		return;
	}
	mid_traversal_recur(head->left);
	print_to_console(head->value + " ");
	mid_traversal_recur(head->right);
}

void pos_traversal_recur(TreeNode* head) {
	if (head == nullptr) {
		return;
	}
	pos_traversal_recur(head->left);
	pos_traversal_recur(head->right);
	print_to_console(head->value + " ");
}