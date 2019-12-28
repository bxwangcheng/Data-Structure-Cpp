#pragma once

/*并查集结构*/
class UnionFind {

public:
	UnionFind(unordered_set<GraphNode*> nodes) :
		set_map_(unordered_map<GraphNode*, unordered_set<GraphNode*>*>())
	{
		for (auto it = nodes.begin(); it != nodes.end(); it++) {
			unordered_set<GraphNode*>* cur_set = new unordered_set<GraphNode*>();
			cur_set->insert(*it);
			set_map_.insert(pair<GraphNode*, unordered_set<GraphNode*>*>(*it, cur_set));
		}
	}

	bool SameSet(GraphNode* a, GraphNode* b) {
		unordered_set<GraphNode*>* set_a = set_map_[a];
		unordered_set<GraphNode*>* set_b = set_map_[b];
		return set_a == set_b;
	}

	void Union(GraphNode* a, GraphNode* b) {
		unordered_set<GraphNode*>* set_a = set_map_[a];
		unordered_set<GraphNode*>* set_b = set_map_[b];
		for (auto it = set_b->begin(); it != set_b->end(); it++) {
			set_a->insert(*it);
			set_map_[*it] = set_a;
		}
	}

public:
	unordered_map<GraphNode*, unordered_set<GraphNode*>*> set_map_;
};