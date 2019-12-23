#pragma once
#include "Exercise00_ListTools.h"
#include "Exercise01_ReverseLinkedList.h"
#include "Exercise02_ListPartition.h"
#include "Exercise03_ListDuplicate.h"
#include "Exercise04_DoublePointer.h"

void test_list(void) {
	//ListNode* head1 = generate_random_list(10, 100);
	//print_linked_list(head1);

	//BinaryListNode* head2 = generate_random_binary_list(10, 100);
	//print_linked_list(head2);

	//ListNode* head3 = reverse_list(head1);
	//print_linked_list(head3);
	//print_linked_list(reverse_list(head2));

	ListNode* head1 = generate_list({ 3,2,4,6,5,1,5,8,2,4,9 });
	ListNode* head2 = generate_list({ 3,2,4,6,1,8,2,4,9 });
	ListNode* head3 = generate_list({ 6,5,5,8,9 });
	ListNode* head4 = generate_list({ 3,2,4,5,1,5,2,4 });
	ListNode* sort1 = partition(head1, 5);
	ListNode* sort2 = partition(head2, 5);
	ListNode* sort3 = partition(head3, 5);
	ListNode* sort4 = partition(head4, 5);
	print_linked_list(sort1);
	print_linked_list(sort2);
	print_linked_list(sort3);
	print_linked_list(sort4);
}