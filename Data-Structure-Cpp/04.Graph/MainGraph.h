#pragma once
#include "Exercise01_BFS.h"
#include "Exercise02_DFS.h"
#include "Exercise03_TopologySort.h"
#include "Exercise04_Kruskal.h"
#include "Exercise05_Prim.h"
#include "Exercise06_Dijkstra.h"

void graph_main(void) {
	Graph* graph = new Graph();
	Node* a = new Node(1);
	Node* b = new Node(2);
	Node* c = new Node(3);
	Node* d = new Node(4);
	Node* e = new Node(5);
	a->nexts.insert(b);
	a->nexts.insert(c);
	a->nexts.insert(d);

	b->nexts.insert(e);
	c->nexts.insert(e);
	d->nexts.insert(e);

	Edge* a1 = new Edge(1, a, b);
	Edge* a2 = new Edge(2, a, c);
	Edge* a3 = new Edge(3, a, d);
	Edge* b1 = new Edge(4, b, e);
	Edge* c1 = new Edge(5, c, e);
	Edge* d1 = new Edge(6, d, e);

	a->edges.insert(a1);
	a->edges.insert(a2);
	a->edges.insert(a3);
	b->edges.insert(b1);
	c->edges.insert(c1);
	d->edges.insert(d1);
}