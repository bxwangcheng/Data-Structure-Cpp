#include "Exercise00_TreeTools.h"

/*¶þ²æÊ÷µÝ¹éÐò±éÀú£¨µÝ¹é£©*/
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

/*¶þ²æÊ÷ÏÈÐò±éÀú£¨µÝ¹é£©*/
void PreTraversalRecur(TreeNode* head) {
	if (head == nullptr) {
		return;
	}
	Print(head->value_ + " ");
	PreTraversalRecur(head->left_);
	PreTraversalRecur(head->right_);
}

/*¶þ²æÊ÷ÖÐÐò±éÀú£¨µÝ¹é£©*/
void MidTraversalRecur(TreeNode* head) {
	if (head == nullptr) {
		return;
	}
	MidTraversalRecur(head->left_);
	Print(head->value_ + " ");
	MidTraversalRecur(head->right_);
}

/*¶þ²æÊ÷ºóÐò±éÀú£¨µÝ¹é£©*/
void PosTraversalRecur(TreeNode* head) {
	if (head == nullptr) {
		return;
	}
	PosTraversalRecur(head->left_);
	PosTraversalRecur(head->right_);
	Print(head->value_ + " ");
}