#include "Exercise00_ListTools.h"
#include <unordered_map>

using std::unordered_map;
using std::pair;
/*
�����ƺ������ָ��ڵ������
	rand_ָ���ǵ�����ڵ�ṹ��������ָ��
	rand_����ָ�������е�����һ���ڵ㣬Ҳ����ָ��null
	����һ����ListNodeR�ڵ�������ɵ��޻��������ͷ�ڵ�head
	��ʵ��һ����������������ĸ��ƣ������ظ��Ƶ��������ͷ�ڵ㡣

	Ҫ��ʱ�临�Ӷ�O(N)������ռ临�Ӷ�O(1)
	�������ⷨ������ϣ��������������ԭ�ڵ��Ӧ�½ڵ��key-value��ϣ��
				�ٴα�����������next��randָ��
				(1)ͨ��ԭ�ڵ���ҵ��½ڵ�
				(2)���½ڵ��next��rand����Ϊԭ�ڵ��next��randָ��Ľڵ�
					��Ϊkey���ҵ���value

	���Ż��ռ䡿����һ������ÿ��һ��ԭ�ڵ㣬����һ���½ڵ��������һ��
				ֻҪͨ��ԭ�ڵ����ҵ��½ڵ���У���ϣ��Ҳ���������
				�ٴα�����ֻ��randָ�룬��ԭ�ڵ���һ���ڵ�(��Ӧ�½ڵ�)��
				randָ��ָ��ԭ�ڵ��randָ��ָ��ڵ����һ���ڵ�(��Ӧ�½ڵ�)
				��������������
*/
class ListNodeR {

public:
	ListNodeR(int value) :
		value_(value),
		next_(nullptr),
		rand_(nullptr)
	{}

public:
	int value_;
	ListNodeR* next_;
	ListNodeR* rand_;
};

ListNodeR* GenerateTestList() {
	ListNodeR* head = new ListNodeR(1);
	ListNodeR* n2 = new ListNodeR(2);
	ListNodeR* n3 = new ListNodeR(3);
	ListNodeR* n4 = new ListNodeR(4);
	ListNodeR* n5 = new ListNodeR(5);
	head->next_ = n2;
	head->rand_ = n3;
	n2->next_ = n3;
	n2->rand_ = head;
	n3->next_ = n4;
	n3->rand_ = n3;
	n4->next_ = n5;
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
		tmp.insert(pair<ListNodeR*, ListNodeR*>(cur, new ListNodeR(cur->value_)));
		cur = cur->next_;
	}
	cur = head;
	while (cur != nullptr) {
		tmp[cur]->next_ = tmp[cur->next_];
		tmp[cur]->rand_ = tmp[cur->rand_];
		cur = cur->next_;
	}
	return tmp[head];
}

ListNodeR* DuplicateV2(ListNodeR* head) {
	if (head == nullptr) {
		return nullptr;
	}
	ListNodeR* cur = head;
	while (cur != nullptr) {
		ListNodeR* new_node = new ListNodeR(cur->value_);
		new_node->next_ = cur->next_;
		cur->next_ = new_node;
		cur = new_node->next_;
	}
	cur = head;
	while (cur != nullptr) {
		cur->next_->rand_ = cur->rand_->next_;
		cur = cur->next_->next_;
	}
	ListNodeR* new_head = head->next_;
	cur = head;
	while (cur->next_->next_ != nullptr) {
		ListNodeR* next = cur->next_->next_;
		cur->next_->next_ = cur->next_->next_->next_;
		cur->next_ = next;
		cur = cur->next_;
	}
	cur->next_ = nullptr;
	return new_head;
}