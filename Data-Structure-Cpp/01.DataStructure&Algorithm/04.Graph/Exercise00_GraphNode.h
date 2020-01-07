#pragma once
#include <unordered_set>

using namespace std;

struct GraphEdge;

struct GraphNode
{
	string value_;
	int in_;
	int out_;
	unordered_set<GraphNode*> nexts_;
	unordered_set<GraphEdge*> edges_;

	GraphNode(string value) :
		value_(value),
		in_(0),
		out_(0),
		nexts_(unordered_set<GraphNode*>()),
		edges_(unordered_set<GraphEdge*>())
	{}
};

struct ValueAscend {
	bool operator()(const GraphNode* a, const GraphNode* b) const {
		return a->value_ < b->value_;
	}
};

struct ValueDescend {
	bool operator()(const GraphNode* a, const GraphNode* b) const {
		return a->value_ > b->value_;
	}
};

