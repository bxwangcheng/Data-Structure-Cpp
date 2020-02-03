#pragma once
#include "../../00.BasicTools/basic.h"

class ListNode {

public:
	ListNode(int value) :
		value(value),
		next(nullptr)
	{}

public:
	int value;
	ListNode* next;
};

class BinaryListNode {

public:
	BinaryListNode(int value) : 
		value(value),
		last(nullptr),
		next(nullptr)
	{}

public:
	int value;
	BinaryListNode* last;
	BinaryListNode* next;
};

void Print(ListNode* head) {
	ListNode* cur = head;
	string output;
	while (cur != nullptr) {
		output += to_string(cur->value) + "->";
		cur = cur->next;
	}
	output += "null";
	Println(output);
}

void Print(BinaryListNode* head) {
	BinaryListNode* cur = head;
	string output;
	while (cur->next != nullptr) {
		output += to_string(cur->value) + "->";
		cur = cur->next;
	}
	output += to_string(cur->value) + "->null";
	Println(output);
	output = "";
	while (cur != nullptr) {
		output += to_string(cur->value) + "->";
		cur = cur->last;
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
		cur->next = new ListNode(value);
		cur = cur->next;
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
		cur->next = new BinaryListNode(value);
		cur->next->last = cur;
		cur = cur->next;
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
		cur->next = new ListNode(arr[i]);
		cur = cur->next;
	}
	return head;
}