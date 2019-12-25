#pragma once
#include "Exercise00_ListTools.h"
#include "Exercise01_ReverseLinkedList.h"
#include "Exercise02_ListPartition.h"
#include "Exercise03_ListDuplicate.h"
#include "Exercise04_DoublePointer.h"

void test_list(void) {
	//ListNode* head1 = GenerateLinkedList(10, 100);
	//print_linked_list(head1);

	//BinaryListNode* head2 = GenerateBinaryLinkedList(10, 100);
	//print_linked_list(head2);

	//ListNode* head3 = ReverseLinkedList(head1);
	//print_linked_list(head3);
	//print_linked_list(ReverseLinkedList(head2));

	//ListNode* head1 = ConvertToLinkedList({ 3,2,4,6,5,1,5,8,2,4,9 });
	//ListNode* head2 = ConvertToLinkedList({ 3,2,4,6,1,8,2,4,9 });
	//ListNode* head3 = ConvertToLinkedList({ 6,5,5,8,9 });
	//ListNode* head4 = ConvertToLinkedList({ 3,2,4,5,1,5,2,4 });
	//ListNode* sort1 = Partition(head1, 5);
	//ListNode* sort2 = Partition(head2, 5);
	//ListNode* sort3 = Partition(head3, 5);
	//ListNode* sort4 = Partition(head4, 5);
	//Print(sort1);
	//Print(sort2);
	//Print(sort3);
	//Print(sort4);

	//auto l = GenerateTestList();
	//auto d = DuplicateV2(l);

	ListNode* head1 = ConvertToLinkedList({ 1,2 });
	ListNode* head2 = ConvertToLinkedList({ 1,2,3,3,2,1 });
	Println(Palindrome(head1));
	Println(Palindrome(head2));
}