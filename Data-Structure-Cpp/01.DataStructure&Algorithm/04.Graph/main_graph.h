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
	//priority_queue<GraphEdge*, vector<GraphEdge*>, WeightAscend> heap1;
	//priority_queue<GraphEdge*, vector<GraphEdge*>, WeightDescend> heap2;
	//sort1.insert(e2);
	//sort1.insert(e4);
	//sort1.insert(e1);
	//sort1.insert(e3);
	//heap1.push(e2);
	//heap1.push(e4);
	//heap1.push(e1);
	//heap1.push(e3);
	//sort2.insert(e2);
	//sort2.insert(e4);
	//sort2.insert(e1);
	//sort2.insert(e3);
	//heap2.push(e2);
	//heap2.push(e4);
	//heap2.push(e1);
	//heap2.push(e3);
	//for (auto it = sort1.begin(); it != sort1.end(); it++) {
	//	Print((*it)->weight_);
	//}
	//Println();
	//for (auto it = sort2.begin(); it != sort2.end(); it++) {
	//	Print((*it)->weight_);
	//}

	//while (!heap1.empty()) {
	//	Println(heap1.top()->weight_);
	//	heap1.pop();
	//}
	//while (!heap2.empty()) {
	//	Println(heap2.top()->weight_);
	//	heap2.pop();
	//}
	//Println();
	//auto res = Prim(GeneratePrimGraph());
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
	//Println();

	auto res = Dijkstra(GeneratePrimGraph()->nodes_[0]);
	for (auto it = res.begin(); it != res.end(); it++) {
		Println(it->first->value_ + ": " + to_string(it->second));
	}
}