#include "Exercise00_ListTools.h"
/*
【复制含有随机指针节点的链表】
	rand_指针是单链表节点结构中新增的指针
	rand_可能指向链表中的任意一个节点，也可能指向null
	给定一个由ListNodeR节点类型组成的无环单链表的头节点head
	请实现一个函数完成这个链表的复制，并返回复制的新链表的头节点。

	要求：时间复杂度O(N)，额外空间复杂度O(1)
	【基本解法】【哈希表】遍历链表，构建原节点对应新节点的key-value哈希表
				再次遍历链表，设置next和rand指针
				(1)通过原节点查找到新节点
				(2)将新节点的next，rand设置为原节点的next，rand指向的节点
					作为key查找到的value

	【优化空间】遍历一次链表，每到一个原节点，创建一个新节点挂在它下一个
				只要通过原节点能找到新节点就行！哈希表也是这个道理
				再次遍历，只看rand指针，将原节点下一个节点(对应新节点)的
				rand指针指向原节点的rand指针指向节点的下一个节点(对应新节点)
				最后分离新老链表
*/
class ListNodeR {

public:
	ListNodeR(int value) :
		value(value),
		next(nullptr),
		rand_(nullptr)
	{}

public:
	int value;
	ListNodeR* next;
	ListNodeR* rand_;
};

ListNodeR* GenerateTestList() {
	ListNodeR* head = new ListNodeR(1);
	ListNodeR* n2 = new ListNodeR(2);
	ListNodeR* n3 = new ListNodeR(3);
	ListNodeR* n4 = new ListNodeR(4);
	ListNodeR* n5 = new ListNodeR(5);
	head->next = n2;
	head->rand_ = n3;
	n2->next = n3;
	n2->rand_ = head;
	n3->next = n4;
	n3->rand_ = n3;
	n4->next = n5;
	n4->rand_ = n2;
	n5->rand_ = n4;
	return head;
}

ListNodeR* Duplicate(ListNodeR* head) {
	if (head == nullptr) {
		return nullptr;
	}
	unordered_map<ListNodeR*, ListNodeR*> tmp;
	ListNodeR* cur = head;
	while (cur != nullptr) {
		tmp.insert(pair<ListNodeR*, ListNodeR*>(cur, new ListNodeR(cur->value)));
		cur = cur->next;
	}
	cur = head;
	while (cur != nullptr) {
		tmp[cur]->next = tmp[cur->next];
		tmp[cur]->rand_ = tmp[cur->rand_];
		cur = cur->next;
	}
	return tmp[head];
}

ListNodeR* DuplicateV2(ListNodeR* head) {
	if (head == nullptr) {
		return nullptr;
	}
	ListNodeR* cur = head;
	while (cur != nullptr) {
		ListNodeR* new_node = new ListNodeR(cur->value);
		new_node->next = cur->next;
		cur->next = new_node;
		cur = new_node->next;
	}
	cur = head;
	while (cur != nullptr) {
		cur->next->rand_ = cur->rand_->next;
		cur = cur->next->next;
	}
	ListNodeR* new_head = head->next;
	cur = head;
	while (cur->next->next != nullptr) {
		ListNodeR* next = cur->next->next;
		cur->next->next = cur->next->next->next;
		cur->next = next;
		cur = cur->next;
	}
	cur->next = nullptr;
	return new_head;
}