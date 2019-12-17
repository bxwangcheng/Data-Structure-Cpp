#pragma once
#include <string>

using std::string;
using std::to_string;

void print_to_console(string x) {
	/* Qt Moudule */
	qDebug() << QString::fromStdString(x);
	/* Qt Moudule */
}

void print_to_console(int x) {
	/* Qt Moudule */
	string str = to_string(x);
	qDebug() << QString::fromStdString(str);
	/* Qt Moudule */
}