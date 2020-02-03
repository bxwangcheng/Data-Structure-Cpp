#pragma once
#include "Exercise00_GraphTools.h"

unordered_set<GraphEdge*> Prim(Graph* graph) {
	if (graph == nullptr){
		return {};
	}
	unordered_set<GraphNode*> visited;
	unordered_set<GraphEdge*> mst;
	priority_queue<GraphEdge*, vector<GraphEdge*>, WeightDescend> sorted_edges;
	for (auto node = graph->nodes.begin(); node != graph->nodes.end(); node++) {
		GraphNode* cur_node = node->second;
		if (visited.find(cur_node) == visited.end()) {
			visited.insert(cur_node);
			for (auto edge = cur_node->edges.begin(); edge != cur_node->edges.end(); edge++) {
				sorted_edges.push(*edge);
			}
			while (!sorted_edges.empty()) {
				GraphEdge* cur_edge = sorted_edges.top();
				sorted_edges.pop();
				if (visited.find(cur_edge->to) == visited.end()) {
					mst.insert(cur_edge);
					visited.insert(cur_edge->to);
					for (auto it = cur_edge->to->edges.begin(); it != cur_edge->to->edges.end(); it++) {
						sorted_edges.push(*it);
					}
				}
			}
		}
	}
	return mst;
}