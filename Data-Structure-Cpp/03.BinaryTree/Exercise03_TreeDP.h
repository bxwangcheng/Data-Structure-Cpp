#include "Exercise00_TreeTools.h"

/*二叉树高度*/
int Height(TreeNode* head) {
	if (head == nullptr) {
		return 0;
	}
	int left_height = Height(head->left_);
	int right_height = Height(head->right_);
	return max(left_height, right_height) + 1;
}

int Width(TreeNode* head) {
	if (head == nullptr) {
		return -1;
	}

}

/*二叉搜索树 递归参数*/
struct BstProcessInfo {
	bool bst_;
	int max_;
	int min_;

	BstProcessInfo(bool bst, int min, int max) {
		this->bst_ = bst;
		this->min_ = min;
		this->max_ = max;
	}
};

/*二叉搜索树 递归*/
BstProcessInfo* BstProcess(TreeNode* head) {
	if (head == nullptr) {
		return nullptr;
	}
	int min = head->value_;
	int max = head->value_;
	BstProcessInfo* left_data = BstProcess(head->left_);
	BstProcessInfo* right_data = BstProcess(head->right_);
	if (left_data != nullptr) {
		min = min(left_data->min_, min);
		max = max(left_data->max_, max);
	}
	if (right_data != nullptr) {
		min = min(right_data->min_, min);
		max = max(right_data->max_, max);
	}
	bool bst = true;
	if (left_data != nullptr && (!left_data->bst_ || left_data->max_ > head->value_)) {
		bst = false;
	}
	if (right_data != nullptr && (!right_data->bst_ || right_data->min_ < head->value_)) {
		bst = false;
	}
	return new BstProcessInfo(bst, min, max);
}

/*二叉搜索树*/
bool BinarySearchTree(TreeNode* head) {
	if (head == nullptr) {
		return false;
	}
	return BstProcess(head)->bst_;
}

/*完全二叉树*/
bool CompleteBinaryTree(TreeNode* head) {
	if (head == nullptr) {
		return false;
	}
	bool leaf = false;
	queue<TreeNode*> q;
	q.push(head);
	while (!q.empty()) {
		TreeNode* cur = q.front();
		q.pop();
		if (cur->left_ == nullptr && cur->right_ != nullptr) {
			return false;
		}
		else if(cur->left_ == nullptr || cur->right_ == nullptr){
			leaf = true;
		}
		if (leaf && (cur->left_ != nullptr || cur->right_ != nullptr)) {
			return false;
		}
	}
	return true;
}

/*平衡二叉树 递归参数*/
struct BtProcessInfo {
	bool balanced_;
	int height_;

	BtProcessInfo(bool balanced, int height) :
		balanced_(balanced),
		height_(height)
	{}
};

/*平衡二叉树 递归*/
BtProcessInfo* BtProcess(TreeNode* head){
	if (head == nullptr) {
		return new BtProcessInfo(true, 0);
	}
	BtProcessInfo* left_info = BtProcess(head->left_);
	BtProcessInfo* right_info = BtProcess(head->right_);
	int height = max(left_info->height_, right_info->height_) + 1;
	bool balanced = true;
	if (!left_info->balanced_ || !right_info->balanced_) {
		balanced = false;
	}
	balanced = abs(left_info->height_ - right_info->height_) < 2 ? true : false;
	return new BtProcessInfo(balanced, height);
}

/*平衡二叉树*/
bool BalancedTree(TreeNode* head) {
	if (head == nullptr) {
		return false;
	}
	return BtProcess(head)->balanced_;
}