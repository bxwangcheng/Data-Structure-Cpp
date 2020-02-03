#pragma once
#include <string>
#include <Windows.h>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <deque>

using std::deque;
using std::priority_queue;
using std::queue;
using std::stack;
using std::map;
using std::set;
using std::unordered_map;
using std::unordered_set;
using std::pair;
using std::string;
using std::wstring;
using std::vector;
using std::ostringstream;
using std::to_string;
using std::max;
using std::min;

void Print();
void Print(string str);
void Print(int x);
void Print(double x);
void Print(const vector<int>& x);
void Print(const vector<vector<int>>& x);
void Println();
void Println(string str);
void Println(int x);
void Println(double x);

void Print(string str) {
	const char* p = (char*)str.c_str();
	OutputDebugStringA(p);
}

void Print(int x) {
	string str = to_string(x);
	const char* p = (char*)str.c_str();
	OutputDebugStringA(p);
}

void Print(double x) {
	string str = to_string(x);
	const char* p = (char*)str.c_str();
	OutputDebugStringA(p);
}

void Print(const vector<int>& x) {
	string output = "";
	for (int i = 0; i < x.size(); i++) {
		output += to_string(x[i]) + " ";
	}
	Println(output);
}

void Print(const vector<vector<int>>& x) {
	string output = "";
	int ROW = x.size();
	int COL = x[0].size();
	for (int row = 0; row < ROW; row++) {
		string row_str = "";
		for (int col = 0; col < COL; col++) {
			row_str += to_string(x[row][col]) + "\t\t";
		}
		output += row_str + "\n";
	}
	Println(output);
}

void Println(const vector<vector<int>>& x) {
	string output = "";
	int ROW = x.size();
	int COL = x[0].size();
	for (int row = 0; row < ROW; row++) {
		string row_str = "";
		for (int col = 0; col < COL; col++) {
			row_str += to_string(x[row][col]) + "\t\t";
		}
		output += row_str + "\n";
	}
	Println(output);
}

void Println(string str) {
	str += "\n";
	const char* p = (char*)str.c_str();
	OutputDebugStringA(p);
}

void Println() {
	string str = "\n";
	const char* p = (char*)str.c_str();
	OutputDebugStringA(p);
}

void Print() {
	string str = " ";
	const char* p = (char*)str.c_str();
	OutputDebugStringA(p);
}

void Println(int x) {
	string str = to_string(x);
	str += "\n";
	const char* p = (char*)str.c_str();
	OutputDebugStringA(p);
}

void Println(double x) {
	string str = to_string(x);
	str += "\n";
	const char* p = (char*)str.c_str();
	OutputDebugStringA(p);
}