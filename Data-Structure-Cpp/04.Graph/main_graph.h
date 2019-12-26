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
	//auto res = TopologySort(GenerateTopologyGraph());
	//GraphNode* a = new GraphNode("A");
	//GraphNode* b = new GraphNode("B");
	//GraphNode* c = new GraphNode("C");
	//GraphEdge* e1 = new GraphEdge(1, a, b);
	//GraphEdge* e2 = new GraphEdge(2, b, a);
	//GraphEdge* e3 = new GraphEdge(3, a, c);
	//GraphEdge* e4 = new GraphEdge(4, c, a);
	//set<GraphEdge*, WeightAscend> sort1;
	//set<GraphEdge*, WeightDescend> sort2;
	//sort1.insert(e2);
	//sort1.insert(e4);
	//sort1.insert(e1);
	//sort1.insert(e3);
	//sort2.insert(e2);
	//sort2.insert(e4);
	//sort2.insert(e1);
	//sort2.insert(e3);
	//for (auto it = sort1.begin(); it != sort1.end(); it++) {
	//	Print((*it)->weight_);
	//}
	//Println();
	//for (auto it = sort2.begin(); it != sort2.end(); it++) {
	//	Print((*it)->weight_);
	//}
	//Println();
	auto res = Kruskal(GenerateKruskalGraph());
	//auto graph = GenerateKruskalGraph();
	//vector<GraphNode*> nodes;
	//for (auto it = graph->nodes_.begin(); it != graph->nodes_.end(); it++) {
	//	nodes.push_back(it->second);
	//}
	//UnionFind* unionfind = new UnionFind(nodes);
	//auto it = unionfind->set_map_.begin();
	//auto n1 = &(it->first);
	//auto s1 = &(it->second);
	//it++;
	//auto n2 = &(it->first);
	//auto s2 = &(it->second);
	//auto isSame1 = unionfind->SameSet(*n1, *n2);
	//auto isSame2 = unionfind->SameSet(*n1, *n1);
	//unionfind->Union(*n1, *n2);
	//auto isSame = unionfind->SameSet(*n1, *n2);
	Println();
}