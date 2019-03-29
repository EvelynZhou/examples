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
			auto &lines = wm[word];//map���±������������ؼ��ֲ����ڣ��򴴽�һ����Ԫ�ء���valueΪ��ָ��.lines�����ã��ı���Ҳ��ı�����ָ��
			if (!lines)
				lines.reset(new set<line_no>);//��һ������wordΪ��ָ�룬�������ָ���µ�set
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