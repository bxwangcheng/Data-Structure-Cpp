#pragma once
#include "../00.BasicTools/basic.h"
#include "Exercise01_Trie.h"
#include "Exercise02_UnionFind.h"
#include "Exercise03_KMP.h"
#include "Exercise04_Manacher.h"
#include "Exercise05_SlidingWindow.h"
#include "Exercise06_MonotonousStack.h"
#include "Exercise07_MorrisTraversal.h"

void trie_main(void) {
	Trie* trie = new Trie();
	trie->insert("abcd");
	trie->insert("abcd");
	trie->insert("");
	trie->insert("");
	trie->insert("ab");
	trie->insert("abced");
	print_to_console(trie->search(""));
	trie->remove("abcd");
	trie->remove("");
	print_to_console(trie->search(""));
}

void unionfind_main(void) {

}

void kmp_main(void) {

}

void manacher_main(void) {

}

void sliding_main(void) {

}

void monostack_main(void) {

}

void morris_main(void) {

}