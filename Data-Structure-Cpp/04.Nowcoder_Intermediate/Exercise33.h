#pragma once
#include "Exercise00_NowcoderTools.h"
/*设计并实现TopKRecord结构，可以不断地向其中加入字符串，并且可以根据字
符串出现的情况随时打印加入次数最多的前k个字符串。具体为:
1）k在TopKRecord实例生成时指定，并且不再变化(k是构造TopKRecord的参数)。
2）含有 add(String str)方法，即向TopKRecord中加入字符串。
3）含有 printTopK()方法，即打印加入次数最多的前k个字符串，打印有哪些
字符串和对应的次数即可，不要求严格按排名顺序打印。
4）如果在出现次数最多的前k个字符串中，最后一名的字符串有多个，比如出
现次数最多的前3个字符串具体排名为：
A 100次 B 90次 C 80次 D 80次 E 80次，其他任何字符串出现次数都
不超过80次
那么只需要打印3个，打印ABC、ABD、ABE都可以。也就是说可以随意抛弃最
后一名，只要求打印k个
要求：
1）在任何时候，add 方法的时间复杂度不超过 O(logk)
2）在任何时候，printTopK方法的时间复杂度不超过O(k)。*/

struct TopKRecordNode {
	string str;
	int freq;

	TopKRecordNode(string s, int f) {
		this->str = s;
		this->freq = f;
	}
};

struct TopKRecordNodeCompare {
	bool SmallHeap(TopKRecordNode* a, TopKRecordNode* b) const {
		return a->freq > b->freq;
	}
};


class TopKRecord {
public:
	TopKRecord(int k):
		heap_size(0)
	{
		heap.resize(k, nullptr);
	};

	void Add(string str) {
		TopKRecordNode* cur = nullptr;
		int pre_index = -1;
		if (freq_tab.find(str) == freq_tab.end()) {
			cur = new TopKRecordNode(str, 1);
			freq_tab.insert(pair<string, TopKRecordNode*>(str, cur));
			pos_tab.insert(pair<TopKRecordNode*, int>(cur, -1));
		}
		else {
			cur = freq_tab[str];
			freq_tab[str]->freq++;
			pre_index = pos_tab[cur];
		}
		if (pre_index == -1) {
			if (heap_size < heap.size()) {
				heap[heap_size] = cur;
				pos_tab[cur] = heap_size;
				HeapInsert(heap_size);
				heap_size++;
			}
			else {
				if (heap[0]->freq < cur->freq) {
					Swap(heap, 0, pos_tab[cur]);
					Heapify(0);
				}
			}
		}
		else {
			Heapify(pos_tab[cur]);
		}
	};

	void PrintTopK() {
		for (int i = 0; i < heap_size; i++) {
			Print(heap[i]->str);
			Print(":\t");
			Println(heap[i]->freq);
		}
	}

private:
	map<string, TopKRecordNode*> freq_tab;
	map<TopKRecordNode*, int> pos_tab;
	vector<TopKRecordNode*> heap;
	int heap_size;

private:
	void HeapInsert(int index) {
		int parent = (index - 1) / 2;
		while (parent<index) {
			if (heap[index]->freq < heap[parent]->freq) {
				Swap(heap, index, parent);
				index = parent;
				parent = (index - 1) / 2;
			}
			else {
				break;
			}
		}
	};

	void Heapify(int index) {
		int left_child = 2 * index + 1;
		int min_child;
		if (left_child < heap_size) {
			min_child = ((left_child + 1) < heap_size && heap[left_child + 1] < heap[left_child]) ? left_child + 1 : left_child;
		}else{
			return;
		}
		min_child = heap[min_child] < heap[index] ? min_child : index;
		if (min_child == index) {
			Swap(heap, min_child, index);
		}
		else {
			return;
		}
	};

	void Swap(vector<TopKRecordNode*>& heap, int a, int b) {
		if (a == b) {
			return;
		}
		TopKRecordNode* tmp = heap[a];
		heap[a] = heap[b];
		heap[b] = tmp;
		pos_tab[heap[a]] = pos_tab[heap[b]];
		pos_tab[heap[b]] = pos_tab[tmp];
	}
};

void TestExercise33() {
	TopKRecord* topk = new TopKRecord(3);
	topk->Add("a");
	topk->Add("b");
	topk->Add("c");
	topk->Add("d");
	topk->Add("a");
	topk->Add("c");
	topk->Add("c");
	topk->Add("d");
	topk->PrintTopK();

}