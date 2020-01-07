#pragma once
#include "Exercise00_TreeTools.h"
#include "Exercise01_RecurTraversal.h"
#include "Exercise02_UnrecurTraversal.h"
#include "Exercise03_TreeDP.h"

void test_tree(void) {
    /*TreeNode* root = new TreeNode(2);
    TreeNode* n11 = new TreeNode(7);
    TreeNode* n12 = new TreeNode(5);
    TreeNode* n21 = new TreeNode(2);
    TreeNode* n22 = new TreeNode(6);
    TreeNode* n23 = new TreeNode(3);
    TreeNode* n24 = new TreeNode(6);
    TreeNode* n31 = new TreeNode(5);
    TreeNode* n32 = new TreeNode(8);
    TreeNode* n33 = new TreeNode(4);
    TreeNode* n34 = new TreeNode(5);
    TreeNode* n35 = new TreeNode(8);
    TreeNode* n36 = new TreeNode(4);
    TreeNode* n37 = new TreeNode(5);
    TreeNode* n38 = new TreeNode(8);
    TreeNode* n41 = new TreeNode(10);
    TreeNode* n42 = new TreeNode(11);
    n31->left = n41;
    n31->right = n42;

    root->left = n11;
    root->right = n12;

    n11->left = n21;
    n11->right = n22;
    n12->left = n23;
    n12->right = n24;
    
    n21->left = n31;
    n21->right = n32;
    n22->left = n33;
    n22->right = n34;
    n23->left = n35;
    n23->right = n36;
    n24->left = n37;
    n24->right = n38;*/
    TreeNode* head = BuildTestTree(0);
    PreTraversalUnrecur(head);
    //Println(BalancedTree(head));
	//printNode(root);
  
}

