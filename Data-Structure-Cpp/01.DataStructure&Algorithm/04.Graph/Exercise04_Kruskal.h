#pragma once
#include "Exercise00_GraphTools.h"
#include "../05.Advanced/Exercise02_UnionFind.h"

unordered_set<GraphEdge*> Kruskal(Graph* graph) {
	if (graph == nullptr) {
		return {};
	}
	priority_queue<GraphEdge*, vector<GraphEdge*>, WeightDescend> edges;
	for (auto it = graph->edges.begin(); it != graph->edges.end(); it++) {
		edges.push(*it);
	}
	unordered_set<GraphNode*> nodes;
	for (auto it = graph->nodes.begin(); it != graph->nodes.end(); it++) {
		nodes.insert(it->second);
	}
	UnionFind* unionfind = new UnionFind(nodes);
	unordered_set<GraphEdge*> mst;
	while (!edges.empty()) {
		GraphEdge* cur = edges.top();
		edges.pop();
		unordered_set<GraphNode*>* from_set = unionfind->set_map_[cur->from];
		unordered_set<GraphNode*>* to_set = unionfind->set_map_[cur->to];
		if (!unionfind->SameSet(cur->from, cur->to)) {
			unionfind->Union(cur->from, cur->to);
			mst.insert(cur);
		}
	}
	return mst;
}
