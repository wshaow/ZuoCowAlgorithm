#pragma once

#include<map>
#include <string>
#include <list>

class RandomPool
{
public:
	RandomPool();
	~RandomPool();

	void insert(std::string s);
	void delete_data(std::string s);
	std::string getRandom();

private:
	std::map<std::string, int> map_str_int;
	std::map<int, std::string> map_int_str;
};


int islands(int** arr, int m, int n);

class FindUnionSet
{
public:
	FindUnionSet();
	~FindUnionSet();

	void makeSets(std::list<std::string> head);
	std::string findHead(std::string str);
	bool isSameSet(std::string str1, std::string str2);
	void Union(std::string str1, std::string str2);


private:
	std::map<std::string, std::string> m_fathermap;
	std::map<std::string, int> m_sizemap;
};

