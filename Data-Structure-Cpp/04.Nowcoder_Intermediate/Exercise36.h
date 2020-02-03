#pragma once
#include "Exercise00_NowcoderTools.h"
// 【前缀树】
/*给你一个字符串类型的数组arr，譬如：
String[] arr = { "b\\cst", "d\\", "a\\d\\e", "a\\b\\c" };
你把这些路径中蕴含的目录结构给画出来，子目录直接列在父目录下面，并比父目录
向右进两格，就像这样:
a
	b
		c
	d
		e
b
	cst
d

同一级的需要按字母顺序排列，不能乱。*/

struct DirNode {
	string str;
	map<string, DirNode*> ways;
	DirNode(string s) {
		this->str = s;
	}
};

string getSpace(int n);
vector<string> Split(const string& str, const string& pattern);
void PrintFolderTreeProcess(DirNode* node, int level);
DirNode* GenerateFolderTree(const vector<string>& arr);
void PrintFolder(const vector<string>& arr) {
	if (arr.size() < 1) {
		return;
	}
	DirNode* head = GenerateFolderTree(arr);
	PrintFolderTreeProcess(head, 0);
}



void PrintFolderTreeProcess(DirNode* node, int level) {
	if (node == nullptr) {
		return;
	}
	if (level != 0) {
		Print(getSpace((level - 1) * 2));
		Println(node->str);
	}
	for (auto it = node->ways.begin(); it != node->ways.end(); it++) {
		PrintFolderTreeProcess(it->second, level + 1);
	}
}

string getSpace(int n) {
	string spaces="";
	for (int i = 0; i < n; i++) {
		spaces += "\t";
	}
	return spaces;
}

DirNode* GenerateFolderTree(const vector<string>& arr) {
	DirNode* head = new DirNode("");
	for (int i = 0; i < arr.size(); i++) {
		DirNode* cur = head;
		vector<string> cur_folder = Split(arr[i], "\\");
		for (int j = 0; j < cur_folder.size(); j++) {
			if (cur->ways.find(cur_folder[j]) == cur->ways.end()) {
				cur->ways.insert(pair<string, DirNode*>(cur_folder[j], new DirNode(cur_folder[j])));
			}
			cur = cur->ways[cur_folder[j]];
		}
	}
	return head;
}

vector<string> Split(const string& str, const string& pattern) {
	if (str == "") {
		return {};
	}
	vector<string> res;
	string m_str =  str + pattern;
	int pos = m_str.find(pattern);
	while (pos != -1) {
		res.push_back(m_str.substr(0, pos));
		m_str = m_str.substr(pos + 1);
		pos = m_str.find(pattern);
	}
	return res;
}

void TestExercise36() {
	vector<string> str = { "b\\cst", "d\\", "a\\d\\e", "a\\b\\c" };
	PrintFolder(str);
}
