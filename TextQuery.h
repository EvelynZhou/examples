#pragma once
#ifndef queryresult_h
#define queryresult_h

using namespace std;
class QueryResult;
class TextQuery {
public:
	using line_no = vector<string>::size_type;
	TextQuery(ifstream &);
	QueryResult query(const string&) const;//²éÑ¯º¯Êý
private:
	shared_ptr<vector<string>> file;
	map<string, shared_ptr<set<line_no>>> wm;
};
#endif