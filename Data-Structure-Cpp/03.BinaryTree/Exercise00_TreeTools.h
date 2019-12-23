#pragma once
#include "../00.BasicTools/basic.h"
#include <algorithm>
#include <math.h>
#include <stack>
#include <queue>

using std::to_string;
using std::max;
using std::stack;
using std::queue;


class TreeNode {

public:
	TreeNode(int value) : 
	value(value),
	left(nullptr),
	right(nullptr)
	{}

public:
	int value;
	TreeNode* left;
	TreeNode* right;
};

void printNode(TreeNode* root);
void printNodeInternal(vector<TreeNode*> nodes, int level, int maxLevel);
void printWhitespaces(int count);
int maxLevel(TreeNode* node);
bool isAllElementsNull(vector<TreeNode*> list);

void printNode(TreeNode* root) {
    int max_level = maxLevel(root);
    printNodeInternal(vector<TreeNode*>{root}, 1, max_level);
}

void printNodeInternal(vector<TreeNode*> nodes, int level, int maxLevel) {
    if (nodes.empty() || isAllElementsNull(nodes))
        return;

    int floor = maxLevel - level;
    int endgeLines = (int)pow(2, (max(floor - 1, 0)));
    int firstSpaces = (int)pow(2, (floor)) - 1;
    int betweenSpaces = (int)pow(2, (floor + 1)) - 1;

    printWhitespaces(firstSpaces);

    vector<TreeNode*> newNodes;
	for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i] != nullptr) {
            TreeNode* cur = nodes[i];
            print_to_console(cur->value);
            newNodes.push_back(cur->left);
            newNodes.push_back(cur->right);
        }
        else {
            newNodes.push_back(nullptr);
            newNodes.push_back(nullptr);
            print_to_console(" ");
        }

        printWhitespaces(betweenSpaces);
    }
    print_to_console_ln("");

    for (int i = 1; i <= endgeLines; i++) {
        for (int j = 0; j < nodes.size(); j++) {
            printWhitespaces(firstSpaces - i);
            TreeNode* cur = nodes[j];
            if (cur == nullptr) {
                printWhitespaces(endgeLines + endgeLines + i + 1);
                continue;
            }

            if (cur->left != nullptr)
                print_to_console("/");
            else
                printWhitespaces(1);

            printWhitespaces(i + i - 1);

            if (cur->right != nullptr)
                print_to_console("\\");
            else
                printWhitespaces(1);

            printWhitespaces(endgeLines + endgeLines - i);
        }
        print_to_console_ln("");
    }

    printNodeInternal(newNodes, level + 1, maxLevel);
}

void printWhitespaces(int count) {
    for (int i = 0; i < count; i++)
        print_to_console(" ");
}

int maxLevel(TreeNode* node) {
    if (node == nullptr)
        return 0;
    return max(maxLevel(node->left), maxLevel(node->right)) + 1;
}

bool isAllElementsNull(vector<TreeNode*> list) {
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
TreeNode* build_test_tree(void) {
    TreeNode* head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    head->left->left = new TreeNode(4);
    head->left->right = new TreeNode(5);
    head->right->left = new TreeNode(6);
    head->right->right = new TreeNode(7);
    return head;
}