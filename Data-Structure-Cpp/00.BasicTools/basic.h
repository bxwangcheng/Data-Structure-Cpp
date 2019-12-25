#pragma once
#include <string>
#include <Windows.h>

using std::string;
using std::wstring;
using std::to_string;

void Print(string str) {
	const char* p = (char*)str.c_str();
	size_t size = strlen(p) + 1;
	wchar_t* w_p = new wchar_t[size];
	size_t outSize;
	mbstowcs_s(&outSize, w_p, size, p, size - 1);
	OutputDebugString(w_p);
}

void Print(int x) {
	string str = to_string(x);
	const char* p = (char*)str.c_str();
	size_t size = strlen(p) + 1;
	wchar_t* w_p = new wchar_t[size];
	size_t outSize;
	mbstowcs_s(&outSize, w_p, size, p, size - 1);
	OutputDebugString(w_p);
}

void Print(double x) {
	string str = to_string(x);
	const char* p = (char*)str.c_str();
	size_t size = strlen(p) + 1;
	wchar_t* w_p = new wchar_t[size];
	size_t outSize;
	mbstowcs_s(&outSize, w_p, size, p, size - 1);
	OutputDebugString(w_p);
}

void Print(bool x) {
	if (x == true) {
		OutputDebugString(L"true");
	}
	else {
		OutputDebugString(L"false");
	}
}

void Println(bool x) {
	if (x == true) {
		OutputDebugString(L"true\n");
	}
	else {
		OutputDebugString(L"false\n");
	}
}

void Println(string str) {
	str += "\n";
	const char* p = (char*)str.c_str();
	size_t size = strlen(p) + 1;
	wchar_t* w_p = new wchar_t[size];
	size_t outSize;
	mbstowcs_s(&outSize, w_p, size, p, size - 1);
	OutputDebugString(w_p);
}

void Println() {
	string str = "\n";
	const char* p = (char*)str.c_str();
	size_t size = strlen(p) + 1;
	wchar_t* w_p = new wchar_t[size];
	size_t outSize;
	mbstowcs_s(&outSize, w_p, size, p, size - 1);
	OutputDebugString(w_p);
}

void Print() {
	string str = " ";
	const char* p = (char*)str.c_str();
	size_t size = strlen(p) + 1;
	wchar_t* w_p = new wchar_t[size];
	size_t outSize;
	mbstowcs_s(&outSize, w_p, size, p, size - 1);
	OutputDebugString(w_p);
}

void Println(int x) {
	string str = to_string(x);
	str += "\n";
	const char* p = (char*)str.c_str();
	size_t size = strlen(p) + 1;
	wchar_t* w_p = new wchar_t[size];
	size_t outSize;
	mbstowcs_s(&outSize, w_p, size, p, size - 1);
	OutputDebugString(w_p);
}

void Println(double x) {
	string str = to_string(x);
	str += "\n";
	const char* p = (char*)str.c_str();
	size_t size = strlen(p) + 1;
	wchar_t* w_p = new wchar_t[size];
	size_t outSize;
	mbstowcs_s(&outSize, w_p, size, p, size - 1);
	OutputDebugString(w_p);
}