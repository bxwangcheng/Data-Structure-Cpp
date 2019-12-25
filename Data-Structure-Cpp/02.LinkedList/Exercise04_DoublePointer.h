#include "Exercise00_ListTools.h"

/*判断是否回文链表*/
bool Palindrome(ListNode* head) {
	if (head == nullptr) {
		return false;
	}
	ListNode* slow_ptr = head;
	ListNode* fast_ptr = head;
	while (fast_ptr != nullptr && fast_ptr->next_ != nullptr) {
		fast_ptr = fast_ptr->next_->next_;
		slow_ptr = slow_ptr->next_;
	}
	ListNode* tmp = ReverseLinkedList(slow_ptr);
	while (tmp != head && tmp != nullptr) {
		if (tmp->value_ != head->value_) {
			return false;
		}
		tmp = tmp->next_;
		head = head->next_;
	}
	return true;
}
