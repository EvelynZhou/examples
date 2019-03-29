#include "stdafx.h"
#include "TextQuery.h"
#include "QueryResult.h"

TextQuery::TextQuery(ifstream &is) :file(new vector<string>) {
	string text;
	while (getline(is, text)) {
		file->push_back(text);
		int n = file->size() - 1;
		istringstream line(text);
		string word;
		while (line >> word) {
			auto &lines = wm[word];//map的下标运算符，如果关键字不存在，则创建一个新元素。其value为空指针.lines是引用，改变它也会改变智能指针
			if (!lines)
				lines.reset(new set<line_no>);//第一次遇到word为空指针，因此让他指向新的set
			lines->insert(n);
		}
	}
}

QueryResult TextQuery::query(const string& sought) const {
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}