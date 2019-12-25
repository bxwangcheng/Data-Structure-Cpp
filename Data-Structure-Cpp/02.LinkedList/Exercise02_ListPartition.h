#include "Exercise00_ListTools.h"

ListNode* Partition(ListNode* head, int value) {
	if (head == nullptr) {
		return nullptr;
	}
	ListNode* smaller_head = nullptr;
	ListNode* smaller_tail = nullptr;
	ListNode* equal_head = nullptr;
	ListNode* equal_tail = nullptr;
	ListNode* bigger_head = nullptr;
	ListNode* bigger_tail = nullptr;
	while (head != nullptr) {
		if (head->value_ < value) {
			if (smaller_head == nullptr) {
				smaller_head = new ListNode(head->value_);
				smaller_tail = smaller_head;
				smaller_head->next_ = smaller_tail;
			}
			else {
				smaller_tail->next_ = new ListNode(head->value_);
				smaller_tail = smaller_tail->next_;
			}
		}
		else if (head->value_ > value) {
			if (bigger_head == nullptr) {
				bigger_head = new ListNode(head->value_);
				bigger_tail = bigger_head;
				bigger_head->next_ = bigger_tail;
			}
			else {
				bigger_tail->next_ = new ListNode(head->value_);
				bigger_tail = bigger_tail->next_;
			}
		}
		else {
			if (equal_head == nullptr) {
				equal_head = new ListNode(head->value_);
				equal_tail = equal_head;
				equal_head->next_ = equal_tail;
			}
			else {
				equal_tail->next_ = new ListNode(head->value_);
				equal_tail = equal_tail->next_;
			}
		}
		head = head->next_;
	}
	int type = 7;
	if (smaller_head == nullptr) {
		type -= 4;
	}
	if (equal_head == nullptr) {
		type -= 2;
	}
	if (bigger_head == nullptr) {
		type -= 1;
	}
	switch (type) {
	case 0:
		return nullptr;

	case 1:
		return bigger_head;

	case 2:
		return equal_head;

	case 3:
		equal_tail->next_ = bigger_head;
		return equal_head;

	case 4:
		return smaller_head;

	case 5:
		smaller_tail->next_ = bigger_head;
		return smaller_head;

	case 6:
		smaller_tail->next_ = equal_head;
		return smaller_head;

	case 7:
		smaller_tail->next_ = equal_head;
		equal_tail->next_ = bigger_head;
		return smaller_head;
	}
}

