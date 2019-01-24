#pragma once
#include <string>
#include <vector>
#include<queue>
#include<functional>

class TrieNode
{
public:
	TrieNode();
	~TrieNode();
	int path;//经过当前路径的数目
	int end;//以当前节点为结尾的数目
	TrieNode* next;

private:

};

class TrieTree
{
public:
	TrieTree();
	~TrieTree();

	void insert(std::string s);
	void remove(std::string s);
	bool search(std::string s);

private:
	TrieNode root;
};

int less_money(std::vector<int>& price);

struct CostProfit
{
	int cost;
	int profit;
};

int IPO(std::vector<int>& costs, std::vector<int>& profits, int k, int m);

class medianQuick {
public:
	void addNum(int s);
	int getMedian();

private:
	std::priority_queue<int, std::vector<int>, std::greater<int> > min_heap;
	std::priority_queue<int, std::vector<int>, std::less<int> > max_heap;
	void modifyHeap();
};

std::string LowestLexicography(std::vector<std::string> s);

struct program {
	int end;
	int begin;
	program(int e, int b) { end = e; begin = b; }
};

int bestArrange(std::vector<program> arrange, int start);

