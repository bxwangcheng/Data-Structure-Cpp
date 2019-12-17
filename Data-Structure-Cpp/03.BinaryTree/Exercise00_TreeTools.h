#pragma once
#include "../00.BasicTools/basic.h"

using std::to_string;

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