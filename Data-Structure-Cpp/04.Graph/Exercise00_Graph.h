#pragma once
#include <unordered_map>
#include <unordered_set>
#include "Exercise00_GraphNode.h"
#include "Exercise00_GraphEdge.h"

using namespace std;

class Graph
{

public:
	Graph() :
		nodes_(unordered_map<int, GraphNode*>()),
		edges_(unordered_set<GraphEdge*>())
	{
	}

public:
	unordered_map<int, GraphNode*> nodes_;
	unordered_set<GraphEdge*> edges_;
};

