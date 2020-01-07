#pragma once
#include "Exercise00_GraphTools.h"
#include "Exercise00_GraphNode.h"
#include "Exercise00_GraphEdge.h"

using namespace std;

struct Graph
{
	unordered_map<int, GraphNode*> nodes_;
	unordered_set<GraphEdge*> edges_;

	Graph() :
		nodes_(unordered_map<int, GraphNode*>()),
		edges_(unordered_set<GraphEdge*>())
	{
	}
};

