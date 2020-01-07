#pragma once
#include "Exercise00_GraphTools.h"

void Dfs(GraphNode* node) {
	if (node == nullptr) {
		return;
	}
	stack<GraphNode*> stk;
	unordered_set<GraphNode*> visited;
	stk.push(node);
	Print(node->value_ + " ");
	visited.insert(node);
	while (!stk.empty()) {
		GraphNode* cur = stk.top();
		stk.pop();
		for (auto it = cur->nexts_.begin(); it != cur->nexts_.end(); it++) {
			if (visited.find(*it) == visited.end()) {
				stk.push(cur);
				stk.push(*it);
				Print((*it)->value_ + " ");
				visited.insert(*it);
				break;
			}
		}
	}
	Println();
}