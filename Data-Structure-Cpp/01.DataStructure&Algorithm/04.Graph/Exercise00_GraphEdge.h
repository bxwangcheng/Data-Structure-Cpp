#pragma once
using namespace std;

struct GraphNode;

struct GraphEdge
{
	int weight_;
	GraphNode* from;
	GraphNode* to;

	GraphEdge(int weight, GraphNode* from, GraphNode* to) :
		weight_(weight),
		from(from),
		to(to)
	{}
};

// x < y	:	Compare(x,y) is true
struct WeightAscend {
	bool operator()(const GraphEdge* a, const GraphEdge* b) const {
		return a->weight_ < b->weight_;	//小到大，大根堆
	}
};


// x > y	:	Compare(x,y) is true
struct WeightDescend {
	bool operator()(const GraphEdge* a, const GraphEdge* b) const {
		return a->weight_ > b->weight_;	//大到小，小根堆
	}
};

