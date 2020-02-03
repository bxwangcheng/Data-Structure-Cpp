#pragma once
#include "Exercise00_NowcoderTools.h"
/*��Ʋ�ʵ��TopKRecord�ṹ�����Բ��ϵ������м����ַ��������ҿ��Ը�����
�������ֵ������ʱ��ӡ�����������ǰk���ַ���������Ϊ:
1��k��TopKRecordʵ������ʱָ�������Ҳ��ٱ仯(k�ǹ���TopKRecord�Ĳ���)��
2������ add(String str)����������TopKRecord�м����ַ�����
3������ printTopK()����������ӡ�����������ǰk���ַ�������ӡ����Щ
�ַ����Ͷ�Ӧ�Ĵ������ɣ���Ҫ���ϸ�����˳���ӡ��
4������ڳ��ִ�������ǰk���ַ����У����һ�����ַ����ж���������
�ִ�������ǰ3���ַ�����������Ϊ��
A 100�� B 90�� C 80�� D 80�� E 80�Σ������κ��ַ������ִ�����
������80��
��ôֻ��Ҫ��ӡ3������ӡABC��ABD��ABE�����ԡ�Ҳ����˵��������������
��һ����ֻҪ���ӡk��
Ҫ��
1�����κ�ʱ��add ������ʱ�临�ӶȲ����� O(logk)
2�����κ�ʱ��printTopK������ʱ�临�ӶȲ�����O(k)��*/

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