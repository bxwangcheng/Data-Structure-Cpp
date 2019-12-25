#pragma once
#include "../00.BasicTools/basic.h"

class ListNode {

public:
	ListNode(int value) :
		value_(value),
		next_(nullptr)
	{}

public:
	int value_;
	ListNode* next_;
};

class BinaryListNode {

public:
	BinaryListNode(int value) : 
		value_(value),
		last_(nullptr),
		next_(nullptr)
	{}

public:
	int value_;
	BinaryListNode* last_;
	BinaryListNode* next_;
};

void Print(ListNode* head) {
	ListNode* cur = head;
	string output;
	while (cur != nullptr) {
		output += to_string(cur->value_) + "->";
		cur = cur->next_;
	}
	output += "null";
	Println(output);
}

void Print(BinaryListNode* head) {
	BinaryListNode* cur = head;
	string output;
	while (cur->next_ != nullptr) {
		output += to_string(cur->value_) + "->";
		cur = cur->next_;
	}
	output += to_string(cur->value_) + "->null";
	Println(output);
	output = "";
	while (cur != nullptr) {
		output += to_string(cur->value_) + "->";
		cur = cur->last_;
	}
	output += "null";
	Println(output);
}

ListNode* GenerateLinkedList(int max_size, int max_value) {
	srand((unsigned)time(nullptr));
	int size = (rand() % (max_size + 1));
	ListNode* head = new ListNode((rand() % (2 * max_size + 1)) - max_size);
	ListNode* cur = head;
	while (size > 1) {
		int value = (rand() % (2 * max_size + 1)) - max_size;
		cur->next_ = new ListNode(value);
		cur = cur->next_;
		size--;
	}
	return head;
}

BinaryListNode* GenerateBinaryLinkedList(int max_size, int max_value) {
	srand((unsigned)time(nullptr));
	int size = (rand() % (max_size + 1));
	BinaryListNode* head = new BinaryListNode((rand() % (2 * max_size + 1)) - max_size);
	BinaryListNode* cur = head;
	while (size > 1) {
		int value = (rand() % (2 * max_size + 1)) - max_size;
		cur->next_ = new BinaryListNode(value);
		cur->next_->last_ = cur;
		cur = cur->next_;
		size--;
	}
	return head;
}

ListNode* ConvertToLinkedList(vector<int> arr) {
	if (arr.size() < 1 || &arr == nullptr) {
		return nullptr;
	}
	ListNode* head = new ListNode(arr[0]);
	ListNode* cur = head;
	for (int i = 1; i < arr.size(); i++) {
		cur->next_ = new ListNode(arr[i]);
		cur = cur->next_;
	}
	return head;
}