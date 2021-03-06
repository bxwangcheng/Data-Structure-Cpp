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
using std::to_string;
using std::max;

void Print(string str) {
	const char* p = (char*)str.c_str();
	size_t size = strlen(p) + 1;
	wchar_t* w_p = new wchar_t[size];
	size_t outSize;
	mbstowcs_s(&outSize, w_p, size, p, size - 1);
	OutputDebugStringA(p);
}

void Print(int x) {
	string str = to_string(x);
	const char* p = (char*)str.c_str();
	size_t size = strlen(p) + 1;
	wchar_t* w_p = new wchar_t[size];
	size_t outSize;
	mbstowcs_s(&outSize, w_p, size, p, size - 1);
	OutputDebugStringA(p);
}

void Print(double x) {
	string str = to_string(x);
	const char* p = (char*)str.c_str();
	size_t size = strlen(p) + 1;
	wchar_t* w_p = new wchar_t[size];
	size_t outSize;
	mbstowcs_s(&outSize, w_p, size, p, size - 1);
	OutputDebugStringA(p);
}

//template<class T>
//void Print(T x) {
//	if (x == true) {
//		OutputDebugString(L"true");
//	}
//	else {
//		OutputDebugString(L"false");
//	}
//}

//void Println(bool x) {
//	if (x == true) {
//		OutputDebugString(L"true\n");
//	}
//	else {
//		OutputDebugString(L"false\n");
//	}
//}

void Println(string str) {
	str += "\n";
	const char* p = (char*)str.c_str();
	size_t size = strlen(p) + 1;
	wchar_t* w_p = new wchar_t[size];
	size_t outSize;
	mbstowcs_s(&outSize, w_p, size, p, size - 1);
	OutputDebugStringA(p);
}

void Println() {
	string str = "\n";
	const char* p = (char*)str.c_str();
	size_t size = strlen(p) + 1;
	wchar_t* w_p = new wchar_t[size];
	size_t outSize;
	mbstowcs_s(&outSize, w_p, size, p, size - 1);
	OutputDebugStringA(p);
}

void Print() {
	string str = " ";
	const char* p = (char*)str.c_str();
	size_t size = strlen(p) + 1;
	wchar_t* w_p = new wchar_t[size];
	size_t outSize;
	mbstowcs_s(&outSize, w_p, size, p, size - 1);
	OutputDebugStringA(p);
}

void Println(int x) {
	string str = to_string(x);
	str += "\n";
	const char* p = (char*)str.c_str();
	size_t size = strlen(p) + 1;
	wchar_t* w_p = new wchar_t[size];
	size_t outSize;
	mbstowcs_s(&outSize, w_p, size, p, size - 1);
	OutputDebugStringA(p);
}

void Println(double x) {
	string str = to_string(x);
	str += "\n";
	const char* p = (char*)str.c_str();
	size_t size = strlen(p) + 1;
	wchar_t* w_p = new wchar_t[size];
	size_t outSize;
	mbstowcs_s(&outSize, w_p, size, p, size - 1);
	OutputDebugStringA(p);
}