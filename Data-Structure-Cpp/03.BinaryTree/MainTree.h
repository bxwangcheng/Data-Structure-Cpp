#pragma once
#include "Exercise00_TreeTools.h"
#include "Exercise01_RecurTraversal.h"
#include "Exercise02_UnrecurTraversal.h"
#include "Exercise03_TreeDP.h"

void tree_main(void) {
	TreeNode* head = new TreeNode(1);
	head->left = new TreeNode(2);
	head->right = new TreeNode(3);
	head->left->left = new TreeNode(4);
	head->left->right = new TreeNode(5);
	head->right->left = new TreeNode(6);
	head->right->right = new TreeNode(7);
	recur_traversal(head);
}

