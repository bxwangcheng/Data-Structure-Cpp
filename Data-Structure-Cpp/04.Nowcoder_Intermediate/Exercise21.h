#pragma once
#include "Exercise00_NowcoderTools.h"

// 【TopK结构】
/*给定一个字符串类型的数组arr，求其中出现次数最多的前K个*/

struct TopKNode {
	string str;
	int times;
	TopKNode(string str, int times) {
		this->str = str;
		this->times = times;
	}
};

class TopK {
public:
	TopK(int size) :
		heap_size(0),
		heap(vector<TopKNode*>())
	{
		heap.resize(size);
	};

	void Add(string str) {
		TopKNode* cur = nullptr;
		int pre_index = -1;
		if (times_dict.find(str) == times_dict.end()) {
			cur = new TopKNode(str, 1);
			times_dict.insert(pair<string, TopKNode*>(str, cur));
			pos_dict.insert(pair<TopKNode*, int>(cur, -1));
		}
		else {
			cur = times_dict[str];
			cur->times++;
			pre_index = pos_dict[cur];
		}
		if (pre_index == -1) {
			if (heap_size == heap.size()) {
				if (cur->times > heap[0]->times) {
					 pos_dict[heap[0]] = -1;
					 pos_dict[cur] = 0;
					 heap[0] = cur;
					 Heapify(0);
				}
			}
			else {
				heap[heap_size] = cur;
				pos_dict[cur] = heap_size;
				HeapInsert(heap_size);
				heap_size++;
			}
		}
		else {
			Heapify(pre_index);
		}
	};

	void PrintTopK() {
		for (int i = 0; i < heap_size; i++) {
			Print(heap[i]->str);
			Print(":\t");
			Println(heap[i]->times);
		}
	}

private:
	unordered_map<TopKNode*, int> pos_dict;
	unordered_map<string, TopKNode*> times_dict;
	vector<TopKNode*> heap;
	int heap_size;
	void Heapify(int index) {
		int left_child = 2 * index + 1;
		int right_child = 2 * index + 2;
		int smaller_child = -1;
		while (left_child < heap_size) {
			smaller_child = ((right_child < heap_size) && heap[right_child]->times < heap[left_child]->times) ? right_child : left_child;
			smaller_child = heap[index]->times > heap[smaller_child]->times ? smaller_child : index;
			if (smaller_child == index) {
				return;
			}
			Swap(heap, smaller_child, index);
			pos_dict[heap[smaller_child]] = index;
			pos_dict[heap[index]] = smaller_child;
			index = smaller_child;
			left_child = 2 * index + 1;
			right_child = 2 * index + 2;
		}
	};
	void HeapInsert(int index) {
		while (heap[index]->times < heap[(index - 1) / 2]->times) {
			Swap(heap, index, (index - 1) / 2);
			pos_dict[heap[index]] = (index - 1) / 2;
			pos_dict[heap[(index - 1) / 2]] = index;
		}
	};
};

void TestExercise21() {
	TopK* top = new TopK(3);
	top->Add("A");
	top->Add("B");
	top->Add("C");
	top->Add("C");
	top->Add("D");
	top->Add("D");
	top->PrintTopK();
}
