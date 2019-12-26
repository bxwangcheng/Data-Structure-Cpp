#pragma once
#include "../00.BasicTools/basic.h"

class TreeNode {

public:
	TreeNode(int value) : 
	value_(value),
	left_(nullptr),
	right_(nullptr)
	{}

public:
	int value_;
	TreeNode* left_;
	TreeNode* right_;
};

void PrintNode(TreeNode* root);
void PrintNodeInternal(vector<TreeNode*> nodes, int level, int maxLevel);
void PrintWhitespaces(int count);
int MaxLevel(TreeNode* node);
bool AllElementsNull(vector<TreeNode*> list);

void PrintNode(TreeNode* root) {
    int max_level = MaxLevel(root);
    PrintNodeInternal(vector<TreeNode*>{root}, 1, max_level);
}

void PrintNodeInternal(vector<TreeNode*> nodes, int level, int maxLevel) {
    if (nodes.empty() || AllElementsNull(nodes))
        return;

    int floor = maxLevel - level;
    int endgeLines = (int)pow(2, (max(floor - 1, 0)));
    int firstSpaces = (int)pow(2, (floor)) - 1;
    int betweenSpaces = (int)pow(2, (floor + 1)) - 1;

    PrintWhitespaces(firstSpaces);

    vector<TreeNode*> newNodes;
	for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i] != nullptr) {
            TreeNode* cur = nodes[i];
            Print(cur->value_);
            newNodes.push_back(cur->left_);
            newNodes.push_back(cur->right_);
        }
        else {
            newNodes.push_back(nullptr);
            newNodes.push_back(nullptr);
            Print(" ");
        }

        PrintWhitespaces(betweenSpaces);
    }
    Println("");

    for (int i = 1; i <= endgeLines; i++) {
        for (int j = 0; j < nodes.size(); j++) {
            PrintWhitespaces(firstSpaces - i);
            TreeNode* cur = nodes[j];
            if (cur == nullptr) {
                PrintWhitespaces(endgeLines + endgeLines + i + 1);
                continue;
            }

            if (cur->left_ != nullptr)
                Print("/");
            else
                PrintWhitespaces(1);

            PrintWhitespaces(i + i - 1);

            if (cur->right_ != nullptr)
                Print("\\");
            else
                PrintWhitespaces(1);

            PrintWhitespaces(endgeLines + endgeLines - i);
        }
        Println("");
    }

    PrintNodeInternal(newNodes, level + 1, maxLevel);
}

void PrintWhitespaces(int count) {
    for (int i = 0; i < count; i++)
        Print(" ");
}

int MaxLevel(TreeNode* node) {
    if (node == nullptr)
        return 0;
    return max(MaxLevel(node->left_), MaxLevel(node->right_)) + 1;
}

bool AllElementsNull(vector<TreeNode*> list) {
    for (int i = 0; i < list.size();i++) {
        if (list[i] != nullptr)
            return false;
    }
    return true;
}

//              1
//            /   \
//           2     3
//          / \   / \
//         4   5 6   7
TreeNode* BuildTestTree(int type) {
    TreeNode* head = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n6 = new TreeNode(6);
    TreeNode* n7 = new TreeNode(7);

    switch (type) {
    case 0:
        head->left_ = n2;
        head->right_ = n3;
        n2->left_ = n4;
        n2->right_ = n5;
        n3->left_ = n6;
        n3->right_ = n7;
        break;

    case 1:
        head->left_ = n2;
        head->right_ = nullptr;
        n2->left_ = n4;
        n2->right_ = n5;
        break;

    case 2:
        head->left_ = n2;
        head->right_ = n3;
        n2->left_ = n4;
        n2->right_ = n5;
        n3->left_ = nullptr;
        n3->right_ = n7;
        break;
    }
    
    return head;
}