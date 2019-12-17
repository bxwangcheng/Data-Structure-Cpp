#pragma once
#include "Exercise00_ListTools.h"
#include "Exercise01_ReverseLinkedList.h"
#include "Exercise02_ListPartition.h"
#include "Exercise03_ListDuplicate.h"
#include "Exercise04_DoublePointer.h"

void list_main(void) {
	ListNode* head1 = generate_random_list(10, 100);
	print_linked_list(head1);

	BinaryListNode* head2 = generate_random_binary_list(10, 100);
	print_linked_list(head2);

	ListNode* head3 = reverse_list(head1);
	print_linked_list(head3);
	//print_linked_list(reverse_list(head2));
}