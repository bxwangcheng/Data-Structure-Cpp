#include "Exercise00_SortTools.h"

class HeapNode {

public:
	HeapNode(int value) :
		value(value),
		left(nullptr),
		right(nullptr)
	{}

public:
	int value;
	HeapNode* left;
	HeapNode* right;
};

//void heap_sort(vector<int>& x) {
//	if (x.size() < 2 || &x == nullptr) {
//		return;
//	}
//	HeapNode* head = new HeapNode(x[0]);
//	for (int i = 0; i < x.size(); i++) {
//		heap_insert(new HeapNode(x[i]));
//	}
//}
//
//void heapify(HeapNode* head) {
//
//}
//
//void heap_insert(HeapNode* head) {
//
//}