#pragma once
#include "../../00.BasicTools/basic.h"
#include "Exercise00_GraphEdge.h"
#include "Exercise00_Graph.h"
#include "Exercise00_GraphNode.h"



/*
	a---d
	|\ /|
	| c |
	|/ \|
	b---e
*/
/*Éú³É²âÊÔÍ¼*/
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
	a->edges_.insert(ab);
	GraphEdge* ac = new GraphEdge(2, a, c);
	a->edges_.insert(ac);
	GraphEdge* ad = new GraphEdge(100, a, d);
	a->edges_.insert(ad);
	GraphEdge* cd = new GraphEdge(4, c, d);
	c->edges_.insert(cd);
	GraphEdge* bd = new GraphEdge(1000, b, d);
	b->edges_.insert(bd);
	GraphEdge* be = new GraphEdge(10000, b, e);
	b->edges_.insert(be);
	GraphEdge* ba = new GraphEdge(7, b, a);
	b->edges_.insert(ba);
	GraphEdge* ca = new GraphEdge(2, c, a);
	c->edges_.insert(ca);
	GraphEdge* da = new GraphEdge(100, d, a);
	d->edges_.insert(da);
	GraphEdge* dc = new GraphEdge(4, d, c);
	d->edges_.insert(dc);
	GraphEdge* db = new GraphEdge(1000, d, b);
	d->edges_.insert(db);
	GraphEdge* eb = new GraphEdge(10000, e, b);
	e->edges_.insert(eb);
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

Graph* GeneratePrimGraph() {
	GraphNode* a = new GraphNode("A");
	GraphNode* b = new GraphNode("B");
	GraphNode* c = new GraphNode("C");
	GraphNode* d = new GraphNode("D");
	GraphNode* e = new GraphNode("E");
	GraphNode* f = new GraphNode("F");
	a->nexts_.insert(b);
	a->nexts_.insert(c);
	a->nexts_.insert(d);
	b->nexts_.insert(a);
	b->nexts_.insert(c);
	b->nexts_.insert(e);
	c->nexts_.insert(a);
	c->nexts_.insert(b);
	c->nexts_.insert(d);
	c->nexts_.insert(e);
	c->nexts_.insert(f);
	d->nexts_.insert(a);
	d->nexts_.insert(c);
	d->nexts_.insert(f);
	e->nexts_.insert(b);
	e->nexts_.insert(c);
	e->nexts_.insert(f);
	f->nexts_.insert(c);
	f->nexts_.insert(d);
	f->nexts_.insert(e);
	GraphEdge* ab = new GraphEdge(6, a, b);
	a->edges_.insert(ab);
	a->out_++;
	b->in_++;
	GraphEdge* ac = new GraphEdge(1, a, c);
	a->edges_.insert(ac);
	a->out_++;
	c->in_++;
	GraphEdge* ad = new GraphEdge(5, a, d);
	a->edges_.insert(ad);
	a->out_++;
	d->in_++;
	GraphEdge* bc = new GraphEdge(5, b, c);
	b->edges_.insert(bc);
	b->out_++;
	c->in_++;
	GraphEdge* cd = new GraphEdge(5, c, d);
	c->edges_.insert(cd);
	c->out_++;
	d->in_++;
	GraphEdge* be = new GraphEdge(3, b, e);
	b->edges_.insert(be);
	b->out_++;
	e->in_++;
	GraphEdge* ce = new GraphEdge(6, c, e);
	c->edges_.insert(ce);
	c->out_++;
	e->in_++;
	GraphEdge* cf = new GraphEdge(4, c, f);
	c->edges_.insert(cf);
	c->out_++;
	f->in_++;
	GraphEdge* df = new GraphEdge(2, d, f);
	d->edges_.insert(df);
	d->out_++;
	f->in_++;
	GraphEdge* ef = new GraphEdge(6, e, f);
	e->edges_.insert(ef);
	e->out_++;
	f->in_++;
	GraphEdge* ba = new GraphEdge(6, b, a);
	b->edges_.insert(ba);
	b->out_++;
	a->in_++;
	GraphEdge* ca = new GraphEdge(1, c, a);
	c->edges_.insert(ca);
	c->out_++;
	a->in_++;
	GraphEdge* da = new GraphEdge(5, d, a);
	d->edges_.insert(da);
	d->out_++;
	a->in_++;
	GraphEdge* cb = new GraphEdge(5, c, b);
	c->edges_.insert(cb);
	c->out_++;
	b->in_++;
	GraphEdge* dc = new GraphEdge(5, d, c);
	d->edges_.insert(dc);
	d->out_++;
	c->in_++;
	GraphEdge* eb = new GraphEdge(3, e, b);
	e->edges_.insert(eb);
	e->out_++;
	b->in_++;
	GraphEdge* ec = new GraphEdge(6, e, c);
	e->edges_.insert(ec);
	e->out_++;
	c->in_++;
	GraphEdge* fc = new GraphEdge(4, f, c);
	f->edges_.insert(fc);
	f->out_++;
	c->in_++;
	GraphEdge* fd = new GraphEdge(2, f, d);
	f->edges_.insert(fd);
	f->out_++;
	d->in_++;
	GraphEdge* fe = new GraphEdge(6, f, e);
	f->edges_.insert(fe);
	f->out_++;
	e->in_++;
	Graph* graph = new Graph();
	graph->nodes_.insert(pair<int, GraphNode*>(0, a));
	graph->nodes_.insert(pair<int, GraphNode*>(1, b));
	graph->nodes_.insert(pair<int, GraphNode*>(2, c));
	graph->nodes_.insert(pair<int, GraphNode*>(3, d));
	graph->nodes_.insert(pair<int, GraphNode*>(4, e));
	graph->nodes_.insert(pair<int, GraphNode*>(5, f));
	graph->edges_.insert(ab);
	graph->edges_.insert(ac);
	graph->edges_.insert(ad);
	graph->edges_.insert(bc);
	graph->edges_.insert(cd);
	graph->edges_.insert(be);
	graph->edges_.insert(ce);
	graph->edges_.insert(cf);
	graph->edges_.insert(df);
	graph->edges_.insert(ef);
	graph->edges_.insert(ba);
	graph->edges_.insert(ca);
	graph->edges_.insert(da);
	graph->edges_.insert(cb);
	graph->edges_.insert(dc);
	graph->edges_.insert(eb);
	graph->edges_.insert(ec);
	graph->edges_.insert(fc);
	graph->edges_.insert(fd);
	graph->edges_.insert(fe);
	return graph;
}