#include "Exercise00_TreeTools.h"

/*¶þ²æÊ÷µÝ¹éÐò±éÀú£¨µÝ¹é£©*/
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

/*¶þ²æÊ÷ÏÈÐò±éÀú£¨µÝ¹é£©*/
void PreTraversalRecur(TreeNode* head) {
	if (head == nullptr) {
		return;
	}
	Print(head->value + " ");
	PreTraversalRecur(head->left);
	PreTraversalRecur(head->right);
}

/*¶þ²æÊ÷ÖÐÐò±éÀú£¨µÝ¹é£©*/
void MidTraversalRecur(TreeNode* head) {
	if (head == nullptr) {
		return;
	}
	MidTraversalRecur(head->left);
	Print(head->value + " ");
	MidTraversalRecur(head->right);
}

/*¶þ²æÊ÷ºóÐò±éÀú£¨µÝ¹é£©*/
void PosTraversalRecur(TreeNode* head) {
	if (head == nullptr) {
		return;
	}
	PosTraversalRecur(head->left);
	PosTraversalRecur(head->right);
	Print(head->value + " ");
}