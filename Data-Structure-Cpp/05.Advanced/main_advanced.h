#pragma once
#include "../00.BasicTools/basic.h"
#include "Exercise01_Trie.h"
#include "Exercise02_UnionFind.h"
#include "Exercise03_KMP.h"
#include "Exercise04_Manacher.h"
#include "Exercise05_SlidingWindow.h"
#include "Exercise06_MonotonousStack.h"
#include "Exercise07_MorrisTraversal.h"

void test_trie(void) {
	Trie* trie = new Trie();
	trie->insert("abcd");
	trie->insert("abcd");
	trie->insert("");
	trie->insert("");
	trie->insert("ab");
	trie->insert("abced");
	Println(trie->search(""));
	trie->remove("abcd");
	trie->remove("");
	Println(trie->search(""));
}

void unionfind_main(void) {

}

void test_kmp(void) {
	auto res = getNextArray("aabsaataabsaakaabsaataabsaaax");
}

void manacher_main(void) {

}

void test_slidingWindow(void) {
	vector<int> arr = { 5,3,2,4,6,5,3 };
	SlideWindow* window = new SlideWindow(arr);
	window->MoveRightSlider();
	window->MoveRightSlider();
	window->MoveRightSlider();
	//window->MoveRightSlider();
	//window->MoveRightSlider();
	//window->MoveRightSlider();
	//window->MoveRightSlider();
	window->MoveLeftSlider();
	window->MoveLeftSlider();
	Println(window->Max());
}

void monostack_main(void) {

}

void morris_main(void) {

}