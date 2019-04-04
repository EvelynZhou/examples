#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <memory>
#include <map>
#include <set>
#include <string>
#include <sstream>
//��Ҫ��ͷ�ļ������̫��ͷ�ļ���һ�������cpp��
using namespace std;
class QueryResult;                                  //��������ʹ�á�Ҫ�������ݶ࣬��򵥵ķ����Ƕ���һ����
class TextQuery
{
public:
	using line_no = vector<string>::size_type;      //���ͳ�Ա�������ȶ����ʹ��
	TextQuery(ifstream &);                          //���캯��������Ҫ��ѯ���ı�
	QueryResult query(const string&)const;          //��ѯ����������Ҫ��ѯ�ĵ��ʣ����ز�ѯ���
	~TextQuery();
private:
	shared_ptr<vector<string>> file;                //�����ļ�
	map<string, shared_ptr<set<line_no>>> wm;       //���ʵ��кż��ϵ�ӳ��

};