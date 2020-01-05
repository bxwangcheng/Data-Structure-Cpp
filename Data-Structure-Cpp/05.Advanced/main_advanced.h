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

void test_manacher(void) {
	//Println(Preprocess("1221"));
	//int res = MaxPalindrome("");
	int res = Manacher("123245");
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

void test_monostack(void) {
	vector<double> test = { 3.2,2.1,1.89,4.65,0.22,5.87,6 };
	//auto res = FirstSmallerPosition(test);
	auto res = FirstBiggerPosition(test);
	
}

void test_morris(void) {
	TreeNode* root = new TreeNode(1);
	root->left_ = new TreeNode(2);
	root->right_ = new TreeNode(3);
	root->left_->left_ = new TreeNode(4);
	root->left_->right_ = new TreeNode(5);
	root->right_->left_ = new TreeNode(6);
	root->right_->right_ = new TreeNode(7);
	MorrisPos(root);
}