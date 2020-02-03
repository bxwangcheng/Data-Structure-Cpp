#include "Exercise00_SortTools.h"

//template<class T>
//struct HeapNode {
//	T value;
//
//	HeapNode(T value) :
//		value(value)
//	{}
//
//	bool operator<(HeapNode<T>& a) {
//		return value < a.value;
//	}
//
//	bool operator>(HeapNode<T>& a) {
//		return value > a.value;
//	}
//};
//
//// heap_size
//// parent:	(i-1)/2
//// left:	2*i+1
//// right:	2*i+2
//template<class T>
//class Heap {
//public:
//	vector<T*> heap;
//	int heap_size;
//
//public:
//	Heap() :
//		heap(vector<T*>()),
//		heap_size(0)
//	{}
//
//	void Push(T* node) {
//		if (&node == nullptr) {
//			return;
//		}
//		if (heap.size() > heap_size) {
//			heap[heap_size] = node;
//		}
//		else {
//			heap.push_back(node);
//		}
//		HeapInsert(heap_size);
//		heap_size++;
//	}
//
//	T* Pop() {
//		T* return_node = heap[0];
//		Swap(heap, 0, heap_size - 1);
//		heap_size--;
//		Heapify(0);
//		return return_node;
//	}
//
//	bool isEmpty() {
//		return heap_size == 0;
//	}
//
//	void HeapInsert(int index) {
//		while (*heap[index] > * heap[(index - 1) / 2]) {
//			Swap(heap, index, (index - 1) / 2);
//			index = (index - 1) / 2;
//		}
//	}
//
//	void Heapify(int index) {
//		int left = 2 * index + 1;
//		while (left < heap_size) {
//			int bigger = ((left + 1) < heap_size) && (*heap[left + 1] > * heap[left]) ? left + 1 : left;
//			bigger = *heap[bigger] > * heap[index] ? bigger : index;
//			if (bigger == index) {
//				break;
//			}
//			Swap(heap, bigger, index);
//			index = bigger;
//			left = 2 * index + 1;
//		}
//	}
//};
//
//void HeapSort(vector<int>& x) {
//	if (x.size() < 2 || &x == nullptr) {
//		return;
//	}
//	Heap<HeapNode<int>>* heap = new Heap<HeapNode<int>>();
//	for (int i = 0; i < x.size(); i++) {
//		HeapNode<int>* node = new HeapNode<int>(x[i]);
//		heap->Push(node);
//	}
//	int index = x.size() - 1;
//	while (!heap->isEmpty()) {
//		x[index--] = heap->Pop()->value;
//	}
//	Print();
//}


template <class T>
class Heap {
public:
	Heap() :
		heap_size(0)
	{
		heap = new vector<T>();
	};

	~Heap() {
		delete heap;
	};

	void Push(T value) {
		if (heap_size >= heap->size()) {
			heap->push_back(value);
		}
		else {
			heap[heap_size] = value;
		}
		HeapInsert(heap_size++);
	};

	T Pop() {
		T res = heap[0];
		Swap(heap, 0, heap_size - 1);
		heap_size--;
		Heapify(0);
		return res;
	};

	void HeapInsert(int pos) {
		int parent = (pos - 1) / 2;
		while (heap[pos] < heap[parent]) {
			Swap(heap, pos, parent);
			pos = parent;
			parent = (pos - 1) / 2;
		}
	};

	void Heapify(int pos) {
		int left_child = 2 * pos + 1;
		while (left_child < heap_size) {
			int right_child = left_child + 1;
			int min_child = right_child < heap_size && heap[right_child] < heap[left_child] ? right_child : left_child;
			min_child = heap[min_child] < heap[pos] ? min_child : pos;
			if (min_child == pos) {
				break;
			}
			Swap(heap, pos, min_child);
			pos = min_child;
			left_child = 2 * pos + 1;
		}
	};

private:
	vector<T>* heap;
	int heap_size;
};