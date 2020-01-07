#pragma once
#include "Exercise00_OfferTools.h"


struct NewTreeNode {
     int val;
     NewTreeNode*left;
     NewTreeNode*right;
     NewTreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 

NewTreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
    if (pre.size() < 1 || vin.size() < 1)
        return {};
    NewTreeNode* root = new NewTreeNode(pre[0]);
    for (int i = 0; i < vin.size(); i++) {
        if (vin[i] == pre[0]) {
            vector<int> left_pre_sub(pre.begin() + 1, pre.begin() + i + 1);
            vector<int> right_pre_sub(pre.begin() + i + 1, pre.end());
            vector<int> left_mid_sub(vin.begin(), vin.begin() + i + 1);
            vector<int> right_mid_sub(vin.begin() + i + 2, vin.end());
            root->left = reConstructBinaryTree(left_pre_sub, left_mid_sub);
            root->right = reConstructBinaryTree(right_pre_sub, right_mid_sub);
            break;
        }
    }
    return root;
}