#include "Exercise00_ListTools.h"

/*判断是否回文链表*/
bool Palindrome(ListNode* head) {
	if (head == nullptr) {
		return false;
	}
	ListNode* slow_ptr = head;
	ListNode* fast_ptr = head;
	while (fast_ptr != nullptr && fast_ptr->next != nullptr) {
		fast_ptr = fast_ptr->next->next;
		slow_ptr = slow_ptr->next;
	}
	ListNode* tmp = ReverseLinkedList(slow_ptr);
	while (tmp != head && tmp != nullptr) {
		if (tmp->value != head->value) {
			return false;
		}
		tmp = tmp->next;
		head = head->next;
	}
	return true;
}
