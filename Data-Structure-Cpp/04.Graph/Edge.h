#pragma once
using namespace std;

class Node;

class Edge
{

public:
	Edge(int weight, Node* from, Node* to) :
		weight(weight),
		from(from),
		to(to)
	{}

public:
	int weight;
	Node* from;
	Node* to;
};
