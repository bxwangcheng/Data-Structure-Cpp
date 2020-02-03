#pragma once
#include "Exercise00_NowcoderTools.h"
/*ʵ��һ�������ջ����ʵ��ջ�Ļ������ܵĻ����ϣ���ʵ�ַ���ջ����СԪ��
�Ĳ�����
Ҫ��1.pop��push��getMin������ʱ�临�Ӷȶ���O(1)��2.��Ƶ�ջ���Ϳ���
ʹ���ֳɵ�ջ�ṹ*/

template<typename T>
struct MinStack {
	MinStack() {

	}

	void Push(T val) {
		if (raw_stack.empty()) {
			raw_stack.push(val);
			min_stack.push(val);
		}
		else {
			T min = min_stack.top();
			if (val >= min) {
				min_stack.push(min);
			}
			else {
				min_stack.push(val);
			}
			raw_stack.push(val);
		}
	}

	T Pop() {
		if (!raw_stack.empty()) {
			T ret = raw_stack.top();
			raw_stack.pop();
			min_stack.pop();
			return ret;
		}
	}

	T getMin() {
		if (!min_stack.empty()) {
			return min_stack.top();
		}
	}

private:
	stack<T> raw_stack;
	stack<T> min_stack;
};

void TestExercise23() {
	MinStack<int>* mstk = new MinStack<int>();
	mstk->Push(1);
	mstk->Push(2);
	mstk->Push(3);
	Println(mstk->getMin());
	Println(mstk->Pop());
	Println(mstk->Pop());
	Println(mstk->Pop());
}