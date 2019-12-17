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

	}

	void remove(string word) {

	}

	int search(string word) {
		return 0;
	}

	int prefix_number(string pre) {
		return 0;
	}

	string prefix_string() {
		return "";
	}
};