#include "Exercise00_SortTools.h"

class HeapNode {

public:
	HeapNode(int value) :
		value_(value),
		left_(nullptr),
		right_(nullptr)
	{}

public:
	int value_;
	HeapNode* left_;
	HeapNode* right_;
};

//void HeapSort(vector<int>& x) {
//	if (x.size() < 2 || &x == nullptr) {
//		return;
//	}
//	HeapNode* head = new HeapNode(x[0]);
//	for (int i = 0; i < x.size(); i++) {
//		heap_insert(new HeapNode(x[i]));
//	}
//}
//
//void Heapify(HeapNode* head) {
//
//}
//
//void HeapInsert(HeapNode* head) {
//
//}