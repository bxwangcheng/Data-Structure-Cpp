#pragma once
#include "Exercise00_GraphTools.h"
#include "../05.Advanced/Exercise02_UnionFind.h"

unordered_set<GraphEdge*> Kruskal(Graph* graph) {
	if (graph == nullptr) {
		return {};
	}
	priority_queue<GraphEdge*, vector<GraphEdge*>, WeightDescend> edges;
	for (auto it = graph->edges_.begin(); it != graph->edges_.end(); it++) {
		edges.push(*it);
	}
	unordered_set<GraphNode*> nodes;
	for (auto it = graph->nodes_.begin(); it != graph->nodes_.end(); it++) {
		nodes.insert(it->second);
	}
	UnionFind* unionfind = new UnionFind(nodes);
	unordered_set<GraphEdge*> mst;
	while (!edges.empty()) {
		GraphEdge* cur = edges.top();
		edges.pop();
		unordered_set<GraphNode*>* from_set = unionfind->set_map_[cur->from_];
		unordered_set<GraphNode*>* to_set = unionfind->set_map_[cur->to_];
		if (!unionfind->SameSet(cur->from_, cur->to_)) {
			unionfind->Union(cur->from_, cur->to_);
			mst.insert(cur);
		}
	}
	return mst;
}
