#pragma once
#include "Exercise00_GraphTools.h"

GraphNode* getNextNode(unordered_map<GraphNode*, int> distance_map, unordered_set<GraphNode*> selected_nodes);

unordered_map<GraphNode*, int> Dijkstra(GraphNode* head) {
	if (&head == nullptr) {
		return {};
	}
	unordered_map<GraphNode*, int> distance_map;
	distance_map.insert(pair<GraphNode*, int>(head, 0));
	unordered_set<GraphNode*> selected_nodes;
	GraphNode* min_node = getNextNode(distance_map, selected_nodes);
	while (min_node != nullptr) {
		int curr_distance = distance_map[min_node];
		for (auto it = min_node->edges.begin(); it != min_node->edges.end(); it++) {
			GraphNode* to_node = (*it)->to;
			int next_distance = (*it)->weight_;
			if (distance_map.find(to_node) == distance_map.end()) {
				distance_map.insert(pair<GraphNode*, int>(to_node, curr_distance + next_distance));
			}
			distance_map[to_node] = min(distance_map[to_node], curr_distance + next_distance);
		}
		selected_nodes.insert(min_node);
		min_node = getNextNode(distance_map, selected_nodes);
	}
	return distance_map;
}

GraphNode* getNextNode(unordered_map<GraphNode*, int> distance_map, unordered_set<GraphNode*> selected_nodes) {
	GraphNode* next_node = nullptr;
	int min_distance  = INT_MAX;
	for (auto it = distance_map.begin(); it != distance_map.end(); it++) {
		if ((selected_nodes.find(it->first) == selected_nodes.end()) &&
			(it->second < min_distance)) {
			min_distance = it->second;
			next_node = it->first;
		}
	}
	return next_node;
}
