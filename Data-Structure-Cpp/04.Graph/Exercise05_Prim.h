#pragma once
#include "Exercise00_GraphTools.h"

unordered_set<GraphEdge*> Prim(Graph* graph) {
	if (graph == nullptr){
		return {};
	}
	unordered_set<GraphNode*> visited;
	unordered_set<GraphEdge*> mst;
	priority_queue<GraphEdge*, vector<GraphEdge*>, WeightDescend> sorted_edges;
	for (auto node = graph->nodes_.begin(); node != graph->nodes_.end(); node++) {
		GraphNode* cur_node = node->second;
		if (visited.find(cur_node) == visited.end()) {
			visited.insert(cur_node);
			for (auto edge = cur_node->edges_.begin(); edge != cur_node->edges_.end(); edge++) {
				sorted_edges.push(*edge);
			}
			while (!sorted_edges.empty()) {
				GraphEdge* cur_edge = sorted_edges.top();
				sorted_edges.pop();
				if (visited.find(cur_edge->to_) == visited.end()) {
					mst.insert(cur_edge);
					visited.insert(cur_edge->to_);
					for (auto it = cur_edge->to_->edges_.begin(); it != cur_edge->to_->edges_.end(); it++) {
						sorted_edges.push(*it);
					}
				}
			}
		}
	}
	return mst;
}