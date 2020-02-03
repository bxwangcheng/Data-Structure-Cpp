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
		Print(cur->value+" ");
		for (auto it = cur->nexts.begin(); it != cur->nexts.end(); it++) {
			GraphNode* cur = *it;
			if (visited.find(cur) == visited.end()) {
				visited.insert(cur);
				q.push(cur);
			}
		}
	}
	Println();
}
