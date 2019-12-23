#pragma once
#include <string>
#include <Windows.h>

using std::string;
using std::wstring;
using std::to_string;

void print_to_console(string str) {
	const char* p = (char*)str.c_str();
	size_t size = strlen(p) + 1;
	wchar_t* w_p = new wchar_t[size];
	size_t outSize;
	mbstowcs_s(&outSize, w_p, size, p, size - 1);
	OutputDebugString(w_p);
}

void print_to_console(int x) {
	string str = to_string(x);
	const char* p = (char*)str.c_str();
	size_t size = strlen(p) + 1;
	wchar_t* w_p = new wchar_t[size];
	size_t outSize;
	mbstowcs_s(&outSize, w_p, size, p, size - 1);
	OutputDebugString(w_p);
}

void print_to_console(double x) {
	string str = to_string(x);
	const char* p = (char*)str.c_str();
	size_t size = strlen(p) + 1;
	wchar_t* w_p = new wchar_t[size];
	size_t outSize;
	mbstowcs_s(&outSize, w_p, size, p, size - 1);
	OutputDebugString(w_p);
}

void print_to_console_ln(string str) {
	str += "\n";
	const char* p = (char*)str.c_str();
	size_t size = strlen(p) + 1;
	wchar_t* w_p = new wchar_t[size];
	size_t outSize;
	mbstowcs_s(&outSize, w_p, size, p, size - 1);
	OutputDebugString(w_p);
}

void print_to_console_ln() {
	string str = "\n";
	const char* p = (char*)str.c_str();
	size_t size = strlen(p) + 1;
	wchar_t* w_p = new wchar_t[size];
	size_t outSize;
	mbstowcs_s(&outSize, w_p, size, p, size - 1);
	OutputDebugString(w_p);
}

void print_to_console_ln(int x) {
	string str = to_string(x);
	str += "\n";
	const char* p = (char*)str.c_str();
	size_t size = strlen(p) + 1;
	wchar_t* w_p = new wchar_t[size];
	size_t outSize;
	mbstowcs_s(&outSize, w_p, size, p, size - 1);
	OutputDebugString(w_p);
}

void print_to_console_ln(double x) {
	string str = to_string(x);
	str += "\n";
	const char* p = (char*)str.c_str();
	size_t size = strlen(p) + 1;
	wchar_t* w_p = new wchar_t[size];
	size_t outSize;
	mbstowcs_s(&outSize, w_p, size, p, size - 1);
	OutputDebugString(w_p);
}