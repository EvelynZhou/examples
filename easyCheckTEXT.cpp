// easyCheckTEXT.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "TextQuery.h"
#include "QueryResult.h"

void runQueries(ifstream &infile);
int main()
{
	ifstream file("D:\\MyData\\C++primerExample\\easyTextCheck\\file.txt");
	runQueries(file);
    return 0;
}

ostream &print(ostream &os, const QueryResult &qr) {
	os << qr.sought << " occurs " << qr.lines->size() << " "
		<< "time" << endl;
	for (auto num : *qr.lines) {//因为是指针，所以必须解引用
		os << "\t(line" << num + 1 << ")" 
			<< *(qr.file->begin() + num) << endl;//得到vecor中相应偏移之后位置的元素
	}
	return os;
}

void runQueries(ifstream &infile) {
	TextQuery tp(infile);
	while (true) {
		cout << "enter word to look for, or q to quit:"<<endl;
		string s;
		if (!(cin >> s) || s == "q") break;
		print(cout, tp.query(s)) << endl;
	}
}