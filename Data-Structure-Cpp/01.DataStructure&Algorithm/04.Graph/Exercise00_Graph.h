#pragma once
#include "Exercise00_GraphTools.h"
#include "Exercise00_GraphNode.h"
#include "Exercise00_GraphEdge.h"

using namespace std;

struct Graph
{
	unordered_map<int, GraphNode*> nodes;
	unordered_set<GraphEdge*> edges;

	Graph() :
		nodes(unordered_map<int, GraphNode*>()),
		edges(unordered_set<GraphEdge*>())
	{
	}
};

