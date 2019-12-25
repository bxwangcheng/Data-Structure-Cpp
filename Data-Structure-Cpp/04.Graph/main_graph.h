#pragma once
#include "Exercise01_BFS.h"
#include "Exercise02_DFS.h"
#include "Exercise03_TopologySort.h"
#include "Exercise04_Kruskal.h"
#include "Exercise05_Prim.h"
#include "Exercise06_Dijkstra.h"

void test_graph(void) {
	//Graph* graph = GenerateGraph();
	//GraphNode* node = graph->nodes_.at(1);
	//Dfs(node);
	auto res = TopologySort(GenerateTopologyGraph());
}