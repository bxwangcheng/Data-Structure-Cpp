#pragma once
#include "Exercise00_GraphTools.h"

void Bfs(GraphNode* node) {
	if (node == nullptr) {
		return;
	}
	queue<GraphNode*> q;
	unordered_set<GraphNode*> visited;
	q.push(node);
	visited.insert(node);
	while (!q.empty()) {
		GraphNode* cur = q.front();
		q.pop();
		Print(cur->value_+" ");
		for (auto it = cur->nexts_.begin(); it != cur->nexts_.end(); it++) {
			GraphNode* cur = *it;
			if (visited.find(cur) == visited.end()) {
				visited.insert(cur);
				q.push(cur);
			}
		}
	}
	Println();
}
