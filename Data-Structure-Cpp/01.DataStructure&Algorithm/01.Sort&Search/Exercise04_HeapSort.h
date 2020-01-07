#include "Exercise00_SortTools.h"

template<class T>
struct HeapNode {
	int value_;

	HeapNode(T value) :
		value_(value)
	{}

	bool operator<(HeapNode<T>& a) {
		return value_ < a.value_;
	}

	bool operator>(HeapNode<T>& a) {
		return value_ > a.value_;
	}
};

// heap_size
// parent:	(i-1)/2
// left:	2*i+1
// right:	2*i+2
template<class T>
class Heap {
public:
	vector<HeapNode<T>*> heap;
	int heap_size;

public:
	Heap() :
		heap(vector<HeapNode<T>*>()),
		heap_size(0)
	{}

	void Push(HeapNode<T>* node) {
		if (&node == nullptr) {
			return;
		}
		if (heap.size() > heap_size) {
			heap[heap_size] = node;
		}
		else {
			heap.push_back(node);
		}
		HeapInsert(heap_size);
		heap_size++;
	}

	HeapNode<T>* Pop() {
		HeapNode<T>* return_node = heap[0];
		Swap(heap, 0, heap_size - 1);
		heap_size--;
		Heapify(0);
		return return_node;
	}

	bool isEmpty() {
		return heap_size == 0;
	}

	void HeapInsert(int index) {
		while (*heap[index] > *heap[(index - 1) / 2]) {
			Swap(heap, index, (index - 1) / 2);
			index = (index - 1) / 2;
		}
	}

	void Heapify(int index) {
		int left = 2 * index + 1;
		while (left < heap_size) {
			int bigger = ((left + 1) < heap_size) && (*heap[left + 1] > *heap[left]) ? left + 1 : left;
			bigger = *heap[bigger] > *heap[index] ? bigger : index;
			if (bigger == index) {
				break;
			}
			Swap(heap, bigger, index);
			index = bigger;
			left = 2 * index + 1;
		}
	}
};

void HeapSort(vector<int>& x) {
	if (x.size() < 2 || &x == nullptr) {
		return;
	}
	Heap<int>* heap = new Heap<int>();
	for (int i = 0; i < x.size(); i++) {
		HeapNode<int>* node = new HeapNode<int>(x[i]);
		heap->Push(node);
	}
	int index = x.size()-1;
	while (!heap->isEmpty()) {
		x[index--] = heap->Pop()->value_;
	}
	Print();
}