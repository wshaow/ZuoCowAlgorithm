#include "stdafx.h"
#include<queue>
#include <iostream>
#include<functional>
#include<algorithm>
#include "class_7.h"

using namespace std;

TrieNode::TrieNode()
{
	path = 0;
	this->end = 0;
}

TrieNode::~TrieNode()
{
}

TrieTree::TrieTree()
{
	root.next = new TrieNode[26]; //不可以像java一样直接在TrieNode中直接new
}

TrieTree::~TrieTree()
{
	//使用层次遍历释放空间
	queue<TrieNode*> help_vector;
	help_vector.push(root.next); //指针真的要画个图分析一下
	while ( !help_vector.empty()) {
		TrieNode* curNode = help_vector.front(); help_vector.pop();
		for (int i = 0; i < 26; i++) {
			if (curNode[i].path != 0) {
				help_vector.push(curNode[i].next);
				cout << 'a' + i << endl;
			}
		}
		cout << "delete root" << endl;
		delete[] curNode;
	}
}

void TrieTree::insert(std::string s) {
	TrieNode* curNext = root.next;
	for (int i = 0; i < s.length(); i++) {
		if (i == s.length() - 1) {
			curNext[s[i] - 'a'].end++;
		}

		if (curNext[s[i] - 'a'].path == 0) {
			curNext[s[i] - 'a'].path++;
			curNext[s[i] - 'a'].next = new TrieNode[26];
		}
		else {
			curNext[s[i] - 'a'].path++;
		}
		curNext = curNext[s[i] - 'a'].next;
	}
}
void TrieTree::remove(std::string s) {
	if (search(s)) {
		TrieNode* curNext = root.next;
		int end_point;
		for (int i = 0; i < s.length(); i++) {
			curNext[s[i] - 'a'].path--;
			if (curNext[s[i] - 'a'].path == 0) {
				end_point = i + 1; //从下一个开始删。这个要画图理解
				curNext = curNext[s[i] - 'a'].next;
				break;
			}
			curNext = curNext[s[i] - 'a'].next;
		}

		TrieNode* old_next;

		for (int i = end_point; i < s.length(); i++) {
			old_next = curNext;
			curNext = curNext[s[i] - 'a'].next;
			old_next[s[i] - 'a'].path = 0;
			delete[] old_next;
		}
	}
}

bool TrieTree::search(std::string s) {
	TrieNode* curNext = root.next;
	for (int i = 0; i < s.length(); i++) {
		if (curNext[s[i] - 'a'].path == 0) {
			return false;
		}
		curNext = curNext[s[i] - 'a'].next;
	}
	return true;
}

int less_money(std::vector<int>& price) {
	priority_queue<int, vector<int>, greater<int> > minHeap;

	for (int i = 0; i < price.size(); i++) {
		minHeap.push(price[i]);
	}

	int totalCost = 0;
	while (minHeap.size() != 1)
	{
		int temp1 = minHeap.top(); minHeap.pop();
		totalCost += temp1;
		int temp2 = minHeap.top(); minHeap.pop();
		totalCost += temp2;
		minHeap.push(temp1 + temp2);
	}
	return totalCost;
}

struct cmp_cost {
	bool operator ()(const CostProfit &a,const CostProfit &b) {
		return a.cost > b.cost;//最小值优先
	}
};
struct cmp_profit {
	bool operator ()(const CostProfit &a, const CostProfit &b) {
		return a.profit < b.profit;//最大值优先
	}
};

int IPO(std::vector<int>& costs, std::vector<int>& profits, int k, int m) {
	priority_queue<CostProfit, vector<CostProfit>, cmp_cost> min_cost_heap;
	priority_queue<CostProfit, vector<CostProfit>, cmp_profit> max_profit_heap;

	for (int i = 0; i < costs.size(); i++) {
		CostProfit temp;
		temp.cost = costs[i];
		temp.profit = profits[i];
		min_cost_heap.push(temp);
	}

	int w = m;
	while (k--) { //做k次项目
		while (!min_cost_heap.empty() && min_cost_heap.top().cost <= w ) { //cost中有能做的项目，且手中的钱够做项目
			max_profit_heap.push(min_cost_heap.top()); min_cost_heap.pop();
		}

		if (max_profit_heap.empty()) { //如果不存在能做的项目
			return w;
		}
		else { //如果存在能做的项目
			w += max_profit_heap.top().profit; max_profit_heap.pop();
		}
	}
	return w;
}



void medianQuick::modifyHeap() {
	if (min_heap.size() - max_heap.size() == 2) {
		max_heap.push(min_heap.top()); min_heap.pop();
	}

	if (max_heap.size() - min_heap.size() == 2) { //如果用小于号由于大小是无符号数，为负数的时候要出问题
		min_heap.push(max_heap.top()); max_heap.pop();
	}
}

void medianQuick::addNum(int s) {
	if (max_heap.empty()) {
		max_heap.push(s);
		return;
	}

	if (max_heap.top() >= s) {
		max_heap.push(s);
	}
	else {
		if (min_heap.empty()) {
			min_heap.push(s);
			return;
		}
		min_heap.push(s);
	}
	modifyHeap();
}

int medianQuick::getMedian() {
	int min_heap_size = min_heap.size();
	int max_heap_size = max_heap.size();

	if (min_heap_size + max_heap_size == 0) {
		return -1;
	}

	if ((min_heap_size + max_heap_size && 1) == 0) {//偶数
		return (min_heap.top() + max_heap.top()) / 2;
	}

	return min_heap_size > max_heap_size ? min_heap.top() : max_heap.top();
}
bool string_cmp(string& str1, string& str2) {
	if (str1 + str2 < str2 + str1) {
		return true;
	}
	return false;
}

std::string LowestLexicography(std::vector<std::string> s) {
	string result = "";
	sort(s.begin(), s.end(), string_cmp);
	for (int i = 0; i < s.size(); i++) {
		result += s[i];
	}
	return result;
}

bool program_cmp(program &p1, program &p2) {
	if (p1.end < p2.end) {
		return true;
	}
	return false;
}

int bestArrange(std::vector<program> arrange, int start) {
	sort(arrange.begin(), arrange.end(), program_cmp);
	int num = 0;
	for (int i = 0; i < arrange.size(); i++) {
		if (start < arrange[i].begin) {
			num++;
			start = arrange[i].end;
		}
	}
	return num;
}