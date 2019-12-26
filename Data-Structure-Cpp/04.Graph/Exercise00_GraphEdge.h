#pragma once
using namespace std;

struct GraphNode;

struct GraphEdge
{
	int weight_;
	GraphNode* from_;
	GraphNode* to_;

	GraphEdge(int weight, GraphNode* from, GraphNode* to) :
		weight_(weight),
		from_(from),
		to_(to)
	{}
};

struct WeightAscend {
	bool operator()(const GraphEdge* a, const GraphEdge* b) const {
		return a->weight_ < b->weight_;	//小到大
	}
};

struct WeightDescend {
	bool operator()(const GraphEdge* a, const GraphEdge* b) const {
		return a->weight_ > b->weight_;	//大到小
	}
};

