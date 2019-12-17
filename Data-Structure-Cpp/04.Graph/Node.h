#pragma once
#include <unordered_set>

using namespace std;

class Edge;

class Node
{
public:
	Node(int value) :
		value(value)
	{}

public:
	int value;
	unordered_set<Node*> nexts;
	unordered_set<Edge*> edges;
};

