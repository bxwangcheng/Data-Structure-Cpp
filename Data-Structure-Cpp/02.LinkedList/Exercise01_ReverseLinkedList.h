#include "Exercise00_ListTools.h"

ListNode* reverse_list(ListNode* head) {
	if (head == nullptr) {
		return nullptr;
	}
	ListNode* last = nullptr;
	ListNode* next = nullptr;
	while (head != nullptr) {
		next = head->next;
		head->next = last;
		last = head;
		head = next;
	}
	return last;
}

BinaryListNode* reverse_list(BinaryListNode* head) {
	if (head == nullptr) {
		return nullptr;
	}
	BinaryListNode* last = nullptr;
	BinaryListNode* next = nullptr;
	while (head != nullptr) {
		next = head->next;
		last = head->last;
		head->next = last;
		head->last = next;
		last = head;
		head = next;
	}
	return last;
}