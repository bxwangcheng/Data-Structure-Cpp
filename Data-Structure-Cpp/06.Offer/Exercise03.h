#pragma once
#include "Exercise00_OfferTools.h"


struct NewListNode {
	int val;
	struct NewListNode* next;
    NewListNode(int x) :
		val(x), next(NULL) {
	}
};


vector<int> printListFromTailToHead(NewListNode* head) {
    if (head == nullptr)
        return {};
    NewListNode* next = nullptr;
    NewListNode* last = nullptr;
    while (head != nullptr) {
        next = head->next;
        head->next = last;
        last = head;
        head = next;
    }
    vector<int> result;
    while (last != nullptr) {
        result.push_back(last->val);
        last = last->next;
    }
    return result;
}