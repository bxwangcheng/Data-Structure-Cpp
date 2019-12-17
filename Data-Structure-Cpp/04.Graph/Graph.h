#pragma once
#include <unordered_map>
#include <unordered_set>
#include "Node.h"
#include "Edge.h"

using namespace std;

class Graph
{

//public:
//	Graph();

public:
	unordered_map<int, Node*> nodes;
	unordered_set<Edge*> edges;
};

