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
	n1->nexts.insert(n2);
	n1->nexts.insert(n3);
	n1->nexts.insert(n4);
	n2->nexts.insert(n5);
	n3->nexts.insert(n5);
	n4->nexts.insert(n5);
	n3->nexts.insert(n2);
	n4->nexts.insert(n2);
	n2->nexts.insert(n1);
	n3->nexts.insert(n1);
	n4->nexts.insert(n1);
	n5->nexts.insert(n2);
	n5->nexts.insert(n3);
	n5->nexts.insert(n4);
	n2->nexts.insert(n3);
	n2->nexts.insert(n3);
	n1->edges.insert(e1);
	n1->edges.insert(e2);
	n1->edges.insert(e3);
	n2->edges.insert(e4);
	n2->edges.insert(e7);
	n2->edges.insert(e8);
	n2->edges.insert(e1_);
	n3->edges.insert(e5);
	n3->edges.insert(e2_);
	n3->edges.insert(e7_);
	n4->edges.insert(e6);
	n4->edges.insert(e3_);
	n4->edges.insert(e8_);
	n5->edges.insert(e4_);
	n5->edges.insert(e5_);
	n5->edges.insert(e6_);
	graph->nodes.insert(pair<int, GraphNode*>(1, n1));
	graph->nodes.insert(pair<int, GraphNode*>(2, n2));
	graph->nodes.insert(pair<int, GraphNode*>(3, n3));
	graph->nodes.insert(pair<int, GraphNode*>(4, n4));
	graph->nodes.insert(pair<int, GraphNode*>(5, n5));
	graph->edges.insert(e1);
	graph->edges.insert(e2);
	graph->edges.insert(e3);
	graph->edges.insert(e4);
	graph->edges.insert(e5);
	graph->edges.insert(e6);
	graph->edges.insert(e7);
	graph->edges.insert(e8);
	graph->edges.insert(e1_);
	graph->edges.insert(e2_);
	graph->edges.insert(e3_);
	graph->edges.insert(e4_);
	graph->edges.insert(e5_);
	graph->edges.insert(e6_);
	graph->edges.insert(e7_);
	graph->edges.insert(e8_);
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
	a->nexts.insert(b);
	a->out++;
	b->in++;
	a->nexts.insert(c);
	a->out++;
	c->in++;
	b->nexts.insert(c);
	b->out++;
	c->in++;
	b->nexts.insert(d);
	b->out++;
	d->in++;
	c->nexts.insert(d);
	c->out++;
	d->in++;
	graph->nodes.insert(pair<int, GraphNode*>(0, a));
	graph->nodes.insert(pair<int, GraphNode*>(1, b));
	graph->nodes.insert(pair<int, GraphNode*>(2, c));
	graph->nodes.insert(pair<int, GraphNode*>(3, d));
	graph->edges.insert(e1);
	graph->edges.insert(e2);
	graph->edges.insert(e3);
	graph->edges.insert(e4);
	graph->edges.insert(e5);
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
	a->nexts.insert(b);
	a->out++;
	b->in++;
	a->nexts.insert(c);
	a->out++;
	c->in++;
	a->nexts.insert(d);
	a->out++;
	d->in++;
	b->nexts.insert(a);
	b->out++;
	a->in++;
	b->nexts.insert(d);
	b->out++;
	d->in++;
	b->nexts.insert(e);
	b->out++;
	e->in++;
	c->nexts.insert(d);
	c->out++;
	d->in++;
	c->nexts.insert(a);
	c->out++;
	a->in++;
	d->nexts.insert(a);
	d->out++;
	a->in++;
	d->nexts.insert(b);
	d->out++;
	b->in++;
	d->nexts.insert(c);
	d->out++;
	c->in++;
	e->nexts.insert(b);
	e->out++;
	b->in++;
	GraphEdge* ab = new GraphEdge(7, a, b);
	a->edges.insert(ab);
	GraphEdge* ac = new GraphEdge(2, a, c);
	a->edges.insert(ac);
	GraphEdge* ad = new GraphEdge(100, a, d);
	a->edges.insert(ad);
	GraphEdge* cd = new GraphEdge(4, c, d);
	c->edges.insert(cd);
	GraphEdge* bd = new GraphEdge(1000, b, d);
	b->edges.insert(bd);
	GraphEdge* be = new GraphEdge(10000, b, e);
	b->edges.insert(be);
	GraphEdge* ba = new GraphEdge(7, b, a);
	b->edges.insert(ba);
	GraphEdge* ca = new GraphEdge(2, c, a);
	c->edges.insert(ca);
	GraphEdge* da = new GraphEdge(100, d, a);
	d->edges.insert(da);
	GraphEdge* dc = new GraphEdge(4, d, c);
	d->edges.insert(dc);
	GraphEdge* db = new GraphEdge(1000, d, b);
	d->edges.insert(db);
	GraphEdge* eb = new GraphEdge(10000, e, b);
	e->edges.insert(eb);
	graph->nodes.insert(pair<int, GraphNode*>(0, a));
	graph->nodes.insert(pair<int, GraphNode*>(1, b));
	graph->nodes.insert(pair<int, GraphNode*>(2, c));
	graph->nodes.insert(pair<int, GraphNode*>(3, d));
	graph->nodes.insert(pair<int, GraphNode*>(4, e));
	graph->edges.insert(ab);
	graph->edges.insert(ac);
	graph->edges.insert(ad);
	graph->edges.insert(cd);
	graph->edges.insert(bd);
	graph->edges.insert(be);
	graph->edges.insert(ba);
	graph->edges.insert(ca);
	graph->edges.insert(da);
	graph->edges.insert(dc);
	graph->edges.insert(db);
	graph->edges.insert(eb);
	return graph;
}

Graph* GeneratePrimGraph() {
	GraphNode* a = new GraphNode("A");
	GraphNode* b = new GraphNode("B");
	GraphNode* c = new GraphNode("C");
	GraphNode* d = new GraphNode("D");
	GraphNode* e = new GraphNode("E");
	GraphNode* f = new GraphNode("F");
	a->nexts.insert(b);
	a->nexts.insert(c);
	a->nexts.insert(d);
	b->nexts.insert(a);
	b->nexts.insert(c);
	b->nexts.insert(e);
	c->nexts.insert(a);
	c->nexts.insert(b);
	c->nexts.insert(d);
	c->nexts.insert(e);
	c->nexts.insert(f);
	d->nexts.insert(a);
	d->nexts.insert(c);
	d->nexts.insert(f);
	e->nexts.insert(b);
	e->nexts.insert(c);
	e->nexts.insert(f);
	f->nexts.insert(c);
	f->nexts.insert(d);
	f->nexts.insert(e);
	GraphEdge* ab = new GraphEdge(6, a, b);
	a->edges.insert(ab);
	a->out++;
	b->in++;
	GraphEdge* ac = new GraphEdge(1, a, c);
	a->edges.insert(ac);
	a->out++;
	c->in++;
	GraphEdge* ad = new GraphEdge(5, a, d);
	a->edges.insert(ad);
	a->out++;
	d->in++;
	GraphEdge* bc = new GraphEdge(5, b, c);
	b->edges.insert(bc);
	b->out++;
	c->in++;
	GraphEdge* cd = new GraphEdge(5, c, d);
	c->edges.insert(cd);
	c->out++;
	d->in++;
	GraphEdge* be = new GraphEdge(3, b, e);
	b->edges.insert(be);
	b->out++;
	e->in++;
	GraphEdge* ce = new GraphEdge(6, c, e);
	c->edges.insert(ce);
	c->out++;
	e->in++;
	GraphEdge* cf = new GraphEdge(4, c, f);
	c->edges.insert(cf);
	c->out++;
	f->in++;
	GraphEdge* df = new GraphEdge(2, d, f);
	d->edges.insert(df);
	d->out++;
	f->in++;
	GraphEdge* ef = new GraphEdge(6, e, f);
	e->edges.insert(ef);
	e->out++;
	f->in++;
	GraphEdge* ba = new GraphEdge(6, b, a);
	b->edges.insert(ba);
	b->out++;
	a->in++;
	GraphEdge* ca = new GraphEdge(1, c, a);
	c->edges.insert(ca);
	c->out++;
	a->in++;
	GraphEdge* da = new GraphEdge(5, d, a);
	d->edges.insert(da);
	d->out++;
	a->in++;
	GraphEdge* cb = new GraphEdge(5, c, b);
	c->edges.insert(cb);
	c->out++;
	b->in++;
	GraphEdge* dc = new GraphEdge(5, d, c);
	d->edges.insert(dc);
	d->out++;
	c->in++;
	GraphEdge* eb = new GraphEdge(3, e, b);
	e->edges.insert(eb);
	e->out++;
	b->in++;
	GraphEdge* ec = new GraphEdge(6, e, c);
	e->edges.insert(ec);
	e->out++;
	c->in++;
	GraphEdge* fc = new GraphEdge(4, f, c);
	f->edges.insert(fc);
	f->out++;
	c->in++;
	GraphEdge* fd = new GraphEdge(2, f, d);
	f->edges.insert(fd);
	f->out++;
	d->in++;
	GraphEdge* fe = new GraphEdge(6, f, e);
	f->edges.insert(fe);
	f->out++;
	e->in++;
	Graph* graph = new Graph();
	graph->nodes.insert(pair<int, GraphNode*>(0, a));
	graph->nodes.insert(pair<int, GraphNode*>(1, b));
	graph->nodes.insert(pair<int, GraphNode*>(2, c));
	graph->nodes.insert(pair<int, GraphNode*>(3, d));
	graph->nodes.insert(pair<int, GraphNode*>(4, e));
	graph->nodes.insert(pair<int, GraphNode*>(5, f));
	graph->edges.insert(ab);
	graph->edges.insert(ac);
	graph->edges.insert(ad);
	graph->edges.insert(bc);
	graph->edges.insert(cd);
	graph->edges.insert(be);
	graph->edges.insert(ce);
	graph->edges.insert(cf);
	graph->edges.insert(df);
	graph->edges.insert(ef);
	graph->edges.insert(ba);
	graph->edges.insert(ca);
	graph->edges.insert(da);
	graph->edges.insert(cb);
	graph->edges.insert(dc);
	graph->edges.insert(eb);
	graph->edges.insert(ec);
	graph->edges.insert(fc);
	graph->edges.insert(fd);
	graph->edges.insert(fe);
	return graph;
}