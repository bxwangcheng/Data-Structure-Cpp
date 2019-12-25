#pragma once
#include <unordered_set>

using namespace std;

class GraphEdge;

class GraphNode
{
public:
	GraphNode(string value) :
		value_(value),
		in_(0),
		out_(0),
		nexts_(unordered_set<GraphNode*>()),
		edges_(unordered_set<GraphEdge*>())
	{}

public:
	string value_;
	int in_;
	int out_;
	unordered_set<GraphNode*> nexts_;
	unordered_set<GraphEdge*> edges_;
};

