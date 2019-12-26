#pragma once
#include "../00.BasicTools/basic.h"
#include "Exercise00_GraphEdge.h"
#include "Exercise00_Graph.h"
#include "Exercise00_GraphNode.h"

/*并查集结构*/
class UnionFind {

public:
	UnionFind(vector<GraphNode*> nodes) :
		set_map_(unordered_map<GraphNode*, unordered_set<GraphNode*>*>())
	{
		for (auto it = nodes.begin(); it != nodes.end(); it++) {
			GraphNode* cur = *it;
			unordered_set<GraphNode*>* cur_set = new unordered_set<GraphNode*>();
			cur_set->insert(*it);
			set_map_.insert(pair<GraphNode*, unordered_set<GraphNode*>*>(cur, cur_set));
		}
	}

	bool SameSet(GraphNode* a, GraphNode* b) {
		unordered_set<GraphNode*>* set_a = set_map_[a];
		unordered_set<GraphNode*>* set_b = set_map_[b];
		return set_a == set_b;
	}

	void Union(GraphNode* a, GraphNode* b) {
		unordered_set<GraphNode*>* set_a = set_map_[a];
		unordered_set<GraphNode*>* set_b = set_map_[b];
		for (auto it = set_b->begin(); it != set_b->end();it++) {
			set_a->insert(*it);
			set_map_[*it] = set_a;
		}
	}

public:
	unordered_map<GraphNode*, unordered_set<GraphNode*>*> set_map_;
};

/*
	a---d
	|\ /|
	| c |
	|/ \|
	b---e
*/
/*生成测试图*/
Graph* GenerateGraph() {
	Graph* graph = new Graph();
	GraphNode* n1 = new GraphNode("a");
	GraphNode* n2 = new GraphNode("b");
	GraphNode* n3 = new GraphNode("c");
	GraphNode* n4 = new GraphNode("d");
	GraphNode* n5 = new GraphNode("e");
	GraphEdge* e1 = new GraphEdge(12, n1, n2);
	GraphEdge* e2 = new GraphEdge(13, n1, n3);
	GraphEdge* e3 = new GraphEdge(14, n1, n4);
	GraphEdge* e4 = new GraphEdge(25, n2, n5);
	GraphEdge* e5 = new GraphEdge(35, n3, n5);
	GraphEdge* e6 = new GraphEdge(45, n4, n5);
	GraphEdge* e7 = new GraphEdge(23, n2, n3);
	GraphEdge* e8 = new GraphEdge(24, n2, n4);
	GraphEdge* e1_ = new GraphEdge(12, n2, n1);
	GraphEdge* e2_ = new GraphEdge(13, n3, n1);
	GraphEdge* e3_ = new GraphEdge(14, n4, n1);
	GraphEdge* e4_ = new GraphEdge(25, n5, n2);
	GraphEdge* e5_ = new GraphEdge(35, n5, n3);
	GraphEdge* e6_ = new GraphEdge(45, n5, n4);
	GraphEdge* e7_ = new GraphEdge(23, n3, n2);
	GraphEdge* e8_ = new GraphEdge(24, n4, n2);
	n1->nexts_.insert(n2);
	n1->nexts_.insert(n3);
	n1->nexts_.insert(n4);
	n2->nexts_.insert(n5);
	n3->nexts_.insert(n5);
	n4->nexts_.insert(n5);
	n3->nexts_.insert(n2);
	n4->nexts_.insert(n2);
	n2->nexts_.insert(n1);
	n3->nexts_.insert(n1);
	n4->nexts_.insert(n1);
	n5->nexts_.insert(n2);
	n5->nexts_.insert(n3);
	n5->nexts_.insert(n4);
	n2->nexts_.insert(n3);
	n2->nexts_.insert(n3);
	n1->edges_.insert(e1);
	n1->edges_.insert(e2);
	n1->edges_.insert(e3);
	n2->edges_.insert(e4);
	n2->edges_.insert(e7);
	n2->edges_.insert(e8);
	n2->edges_.insert(e1_);
	n3->edges_.insert(e5);
	n3->edges_.insert(e2_);
	n3->edges_.insert(e7_);
	n4->edges_.insert(e6);
	n4->edges_.insert(e3_);
	n4->edges_.insert(e8_);
	n5->edges_.insert(e4_);
	n5->edges_.insert(e5_);
	n5->edges_.insert(e6_);
	graph->nodes_.insert(pair<int, GraphNode*>(1, n1));
	graph->nodes_.insert(pair<int, GraphNode*>(2, n2));
	graph->nodes_.insert(pair<int, GraphNode*>(3, n3));
	graph->nodes_.insert(pair<int, GraphNode*>(4, n4));
	graph->nodes_.insert(pair<int, GraphNode*>(5, n5));
	graph->edges_.insert(e1);
	graph->edges_.insert(e2);
	graph->edges_.insert(e3);
	graph->edges_.insert(e4);
	graph->edges_.insert(e5);
	graph->edges_.insert(e6);
	graph->edges_.insert(e7);
	graph->edges_.insert(e8);
	graph->edges_.insert(e1_);
	graph->edges_.insert(e2_);
	graph->edges_.insert(e3_);
	graph->edges_.insert(e4_);
	graph->edges_.insert(e5_);
	graph->edges_.insert(e6_);
	graph->edges_.insert(e7_);
	graph->edges_.insert(e8_);
	return graph;
}

//   _______
//   |     |
//A->B->C->D
//|_____|
Graph* GenerateTopologyGraph() {
	Graph* graph = new Graph();
	GraphNode* a = new GraphNode("A");
	GraphNode* b = new GraphNode("B");
	GraphNode* c = new GraphNode("C");
	GraphNode* d = new GraphNode("D");
	GraphEdge* e1 = new GraphEdge(1, a, b);
	GraphEdge* e2 = new GraphEdge(1, a, c);
	GraphEdge* e3 = new GraphEdge(1, b, c);
	GraphEdge* e4 = new GraphEdge(1, b, d);
	GraphEdge* e5 = new GraphEdge(1, c, d);
	a->nexts_.insert(b);
	a->out_++;
	b->in_++;
	a->nexts_.insert(c);
	a->out_++;
	c->in_++;
	b->nexts_.insert(c);
	b->out_++;
	c->in_++;
	b->nexts_.insert(d);
	b->out_++;
	d->in_++;
	c->nexts_.insert(d);
	c->out_++;
	d->in_++;
	graph->nodes_.insert(pair<int, GraphNode*>(0, a));
	graph->nodes_.insert(pair<int, GraphNode*>(1, b));
	graph->nodes_.insert(pair<int, GraphNode*>(2, c));
	graph->nodes_.insert(pair<int, GraphNode*>(3, d));
	graph->edges_.insert(e1);
	graph->edges_.insert(e2);
	graph->edges_.insert(e3);
	graph->edges_.insert(e4);
	graph->edges_.insert(e5);
	return graph;
}

//      7
//   A-----B
//   |\    |\10000
//   | \100| \
// 2 |  \  |  E
//   |   \ |1000
//   |    \|
//   C-----D
//      4
Graph* GenerateKruskalGraph() {
	Graph* graph = new Graph();
	GraphNode* a = new GraphNode("A");
	GraphNode* b = new GraphNode("B");
	GraphNode* c = new GraphNode("C");
	GraphNode* d = new GraphNode("D");
	GraphNode* e = new GraphNode("E");
	a->nexts_.insert(b);
	a->out_++;
	b->in_++;
	a->nexts_.insert(c);
	a->out_++;
	c->in_++;
	a->nexts_.insert(d);
	a->out_++;
	d->in_++;
	b->nexts_.insert(a);
	b->out_++;
	a->in_++;
	b->nexts_.insert(d);
	b->out_++;
	d->in_++;
	b->nexts_.insert(e);
	b->out_++;
	e->in_++;
	c->nexts_.insert(d);
	c->out_++;
	d->in_++;
	c->nexts_.insert(a);
	c->out_++;
	a->in_++;
	d->nexts_.insert(a);
	d->out_++;
	a->in_++;
	d->nexts_.insert(b);
	d->out_++;
	b->in_++;
	d->nexts_.insert(c);
	d->out_++;
	c->in_++;
	e->nexts_.insert(b);
	e->out_++;
	b->in_++;
	GraphEdge* ab = new GraphEdge(7, a, b);
	GraphEdge* ac = new GraphEdge(2, a, c);
	GraphEdge* ad = new GraphEdge(100, a, d);
	GraphEdge* cd = new GraphEdge(4, c, d);
	GraphEdge* bd = new GraphEdge(1000, b, d);
	GraphEdge* be = new GraphEdge(10000, b, e);
	GraphEdge* ba = new GraphEdge(7, b, a);
	GraphEdge* ca = new GraphEdge(2, c, a);
	GraphEdge* da = new GraphEdge(100, d, a);
	GraphEdge* dc = new GraphEdge(4, d, c);
	GraphEdge* db = new GraphEdge(1000, d, b);
	GraphEdge* eb = new GraphEdge(10000, e, b);
	graph->nodes_.insert(pair<int, GraphNode*>(0, a));
	graph->nodes_.insert(pair<int, GraphNode*>(1, b));
	graph->nodes_.insert(pair<int, GraphNode*>(2, c));
	graph->nodes_.insert(pair<int, GraphNode*>(3, d));
	graph->nodes_.insert(pair<int, GraphNode*>(4, e));
	graph->edges_.insert(ab);
	graph->edges_.insert(ac);
	graph->edges_.insert(ad);
	graph->edges_.insert(cd);
	graph->edges_.insert(bd);
	graph->edges_.insert(be);
	graph->edges_.insert(ba);
	graph->edges_.insert(ca);
	graph->edges_.insert(da);
	graph->edges_.insert(dc);
	graph->edges_.insert(db);
	graph->edges_.insert(eb);
	return graph;
}