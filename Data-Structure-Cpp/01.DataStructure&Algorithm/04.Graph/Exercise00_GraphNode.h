#pragma once
#include <unordered_set>

using namespace std;

struct GraphEdge;

struct GraphNode
{
	string value;
	int in;
	int out;
	unordered_set<GraphNode*> nexts;
	unordered_set<GraphEdge*> edges;

	GraphNode(string value) :
		value(value),
		in(0),
		out(0),
		nexts(unordered_set<GraphNode*>()),
		edges(unordered_set<GraphEdge*>())
	{}
};

struct ValueAscend {
	bool operator()(const GraphNode* a, const GraphNode* b) const {
		return a->value < b->value;
	}
};

struct ValueDescend {
	bool operator()(const GraphNode* a, const GraphNode* b) const {
		return a->value > b->value;
	}
};

