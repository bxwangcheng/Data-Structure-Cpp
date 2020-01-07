#pragma once
#include <vector>
#include <string>

using std::vector;
using std::string;

class TrieNode {

public:
	TrieNode() : 
		pass(0),
		end(0),
		ways(vector<TrieNode*>(26, nullptr))
	{}

public:
	int pass;
	int end;
	vector<TrieNode*> ways;
};

class Trie {

private:
	TrieNode* root;

public:
	Trie() :
		root(new TrieNode())
	{}

public:
	void insert(string word) {
		if (&word == nullptr) {
			return;
		}
		if (word != "") {
			root->pass++;
		}
		int index = -1;
		TrieNode* cur = root;
		for (int i = 0; i < word.size(); i++) {
			index = word[i] - 'a';
			if (cur->ways[index] == nullptr) {
				cur->ways[index] = new TrieNode();
			}
			cur = cur->ways[index];
			cur->pass++;
		}
		cur->end++;
	}

	void remove(string word) {
		if (&word == nullptr) {
			return;
		}
		int index = -1;
		TrieNode* cur = root;
		for (int i = 0; i < word.size(); i++) {
			index = word[i] - 'a';
			if (--cur->ways[index]->pass == 0) {
				cur->ways[index] = nullptr;
				return;
			}
			cur = cur->ways[index];
		}
		cur->end--;
	}

	int search(string word) {
		if (&word == nullptr) {
			return -1;
		}
		int index = -1;
		TrieNode* cur = root;
		for (int i = 0; i < word.size(); i++) {
			index = word[i] - 'a';
			if (cur->ways[index] != nullptr) {
				cur = cur->ways[index];
			}
			else
			{
				return 0;
			}
		}
		return cur->end;
	}

	int prefix_number(string pre) {
		return 0;
	}

	string prefix_string() {
		return "";
	}
};