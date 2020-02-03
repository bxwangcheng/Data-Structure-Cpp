#pragma once
#include "Exercise00_NowcoderTools.h"
/*如何仅用队列结构实现栈结构?
如何仅用栈结构实现队列结构?*/

template <typename T>
class QStack {
public:
	QStack() {

	}

	void Push(T val) {
		while (!stock_queue.empty()) {
			push_queue.push(stock_queue.front());
			stock_queue.pop();
		}
		push_queue.push(val);
	}

	T Pop() {
		while (!stock_queue.empty()) {
			push_queue.push(stock_queue.front());
			stock_queue.pop();
		}
		int size = push_queue.size();
		for (int i = 0; i < size - 1; i++) {
			stock_queue.push(push_queue.front());
			push_queue.pop();
		}
		T ret = push_queue.front();
		push_queue.pop();
		return ret;
	}

private:
	queue<T> push_queue;
	queue<T> stock_queue;
};

template<typename T>
class SQueue {
public:
	SQueue() {

	}

	void Add(T val) {
		push_stack.push(val);
	}

	T Poll() {
		while (!stock_stack.empty()) {
			T ret = stock_stack.top();
			stock_stack.pop();
			return ret;
		}
		while (!push_stack.empty()) {
			stock_stack.push(push_stack.top());
			push_stack.pop();
		}
		while (!stock_stack.empty()) {
			T ret = stock_stack.top();
			stock_stack.pop();
			return ret;
		}
		return NULL;
	}

private:
	stack<T> push_stack;
	stack<T> stock_stack;

};

void TestExercise24() {
	//QStack<int> qstk;
	//qstk.Push(1);
	//qstk.Push(2);
	//qstk.Push(3);
	//Println(qstk.Pop());
	//Println(qstk.Pop());
	//qstk.Push(4);
	//Println(qstk.Pop());
	//Println(qstk.Pop());

	SQueue<int> sq;
	sq.Add(1);
	sq.Add(2);
	sq.Add(3);
	Println(sq.Poll());
	sq.Add(4);
	sq.Add(5);
	Println(sq.Poll());
	Println(sq.Poll());
	Println(sq.Poll());
	Println(sq.Poll());
	Println(sq.Poll());

}