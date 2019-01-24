#include "stdafx.h"

#include <map>
#include<cstdlib>
#include <ctime>
#include "class_5.h"

using namespace std;

RandomPool::RandomPool()
{
}

RandomPool::~RandomPool()
{
}

void RandomPool::insert(std::string s) {
	map_str_int[s] = map_str_int.size();
	map_int_str[map_int_str.size()] = s;
}
void RandomPool::delete_data(std::string s) {
	map<string, int> ::iterator f_index;
	f_index = map_str_int.find(s);
	if (f_index != map_str_int.end()) {
		int delete_index = map_str_int[s];//当前要删除的字符串的位置	
		int last_index = map_str_int.size() - 1;
		string last_str = map_int_str[last_index];

		map_str_int[last_str] = delete_index;
		map_int_str[delete_index] = last_str;
		map_str_int.erase(s);
		map_int_str.erase(last_index);

	}


}
std::string RandomPool::getRandom() {
	int total_size = map_str_int.size();
	if (total_size == 0) return "";
	srand(time(0));
	int index = rand() % total_size;
	return map_int_str[index];
}

void infect(int** arr, int i, int j, int m, int n) {
	if (i < 0 || i >= m || j < 0 || j >= n || *((int*)arr + i * n + j) != 1) {
		return;
	}

	*((int*)arr + i * n + j) = 2;

	infect(arr, i, j - 1, m, n);
	infect(arr, i, j + 1, m, n);
	infect(arr, i - 1, j, m, n);
	infect(arr, i + 1, j, m, n);

}

int islands(int** arr, int m, int n) {
	int res = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (*((int*)arr + i * n + j) == 1) {
				res++;
				infect(arr, i, j, m, n);
			}
		}
	}

	return res;
}


FindUnionSet::FindUnionSet()
{
}

FindUnionSet::~FindUnionSet()
{
}

void FindUnionSet::makeSets(std::list<string> head) {//将head中的每一个节点都作为一个set
	list<string>::iterator list_t = head.begin();

	while (list_t != head.end()){
		m_fathermap[*list_t] = *list_t;
		m_sizemap[*list_t] = 1;
		list_t++;
	}
}

std::string FindUnionSet::findHead(std::string str) { //找到str对应的代表节点
	map<string, string>::iterator iter_temp = m_fathermap.find(str);

	if (iter_temp == m_fathermap.end()) {
		return 0;
	}

}
bool FindUnionSet::isSameSet(std::string str1, std::string str2) {//判断str1和str2是否在同一个集合
	return 0;
}

void FindUnionSet::Union(std::string str1, std::string str2) { //将节点1和节点2所在的set合并

}