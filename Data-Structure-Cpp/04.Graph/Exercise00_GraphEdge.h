#pragma once
using namespace std;

class GraphNode;

class GraphEdge
{

public:
	GraphEdge(int weight, GraphNode* from, GraphNode* to) :
		weight_(weight),
		from_(from),
		to_(to)
	{}

public:
	int weight_;
	GraphNode* from_;
	GraphNode* to_;
};
