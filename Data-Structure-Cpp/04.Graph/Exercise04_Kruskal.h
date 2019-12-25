#pragma once
#include "Exercise00_GraphTools.h"

unordered_set<GraphNode*> Kruskal(Graph* graph) {
	if (graph == nullptr) {
		return {};
	}

}

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
	GraphEdge* ba = new GraphEdge(7, b,a);
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
}
