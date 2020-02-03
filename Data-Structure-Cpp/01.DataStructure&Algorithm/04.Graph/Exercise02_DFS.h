#pragma once
#include "Exercise00_GraphTools.h"

void Dfs(GraphNode* node) {
	if (node == nullptr) {
		return;
	}
	stack<GraphNode*> stk;
	unordered_set<GraphNode*> visited;
	stk.push(node);
	Print(node->value + " ");
	visited.insert(node);
	while (!stk.empty()) {
		GraphNode* cur = stk.top();
		stk.pop();
		for (auto it = cur->nexts.begin(); it != cur->nexts.end(); it++) {
			if (visited.find(*it) == visited.end()) {
				stk.push(cur);
				stk.push(*it);
				Print((*it)->value + " ");
				visited.insert(*it);
				break;
			}
		}
	}
	Println();
}