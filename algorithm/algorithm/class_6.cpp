#include "stdafx.h"
#include <climits>
#include<stack>
#include<iostream>
#include<queue>
#include"class_6.h"
using namespace std;

//edge stores every edge pair
Digraph::Digraph(const std::vector< std::vector<int> >& edge, int vNum) {
	edgeNum = edge.size();
	vertexNum = vNum;
	vector<vector<int> > temp(vertexNum, vector<int>(vertexNum, INT_MAX));
 	arc = temp; //或者使用resize属性
	for (int i = 0; i < edgeNum; i++) {
		arc[edge[i][0]][edge[i][1]] = 1; //这种事无权图的情况，如果是用权图使用下面的语句
		//arc[edge[i][0]][edge[i][1]] = edge[i][2];
		//如果是无向图加上下面的
		//arc[edge[i][1]][edge[i][0]] = 1;
	}
}

Digraph::~Digraph() {

}

AdjListDigraph::AdjListDigraph(const std::vector<std::vector<int> > &a, int vNum) {
	vertexNum = vNum;
	edgeNum = a.size();

	vertex.resize(vNum);
	for (int i = 0; i < vNum; i++) { //初始化id,和头结点
		vertex[i].head = nullptr;
		vertex[i].id = i;
	}

	for (int i = 0; i < edgeNum; i++) {  //如果要构建逆邻接链表将0和1互换
		edgeNode* next = vertex[a[i][0]].head; //当前都节点
		edgeNode* enode = new edgeNode(a[i][1], next);//新建头节点
		vertex[a[i][0]].head = enode;//更换头节点
	}
}

AdjListDigraph::~AdjListDigraph() {
	//释放新建的节点
	//for (int i = 0; i < vertexNum; i++) {
	//	while (vertex[i].head != nullptr) {
	//		edgeNode* next = vertex[i].head->next;
	//		delete vertex[i].head;
	//		vertex[i].head = next;
	//	}
	//}
}

OrthogonalList::OrthogonalList()
{
}
OrthogonalList::OrthogonalList(const std::vector<std::vector<int> > &a, int vNum) {
	vertexNum = vNum;
	EdgeNum = a.size();

	vertex.resize(vertexNum);
	for (int i = 0; i < vertexNum; i++) {
		vertex[i].data = i;
		vertex[i].negadjhead = nullptr;
		vertex[i].adjhead = nullptr;
	}

	for (int i = 0; i < EdgeNum; i++) {
		//其实可以把邻接链表和逆邻接链表分开考虑，只要不搞乱就可以了
		//head对应邻接链表
		int head = a[i][0];
		OrthogonalEdge* adj = vertex[head].adjhead;
		//tail对应逆链接链表
		int tail = a[i][1];
		OrthogonalEdge* negadj = vertex[tail].negadjhead;
		
		OrthogonalEdge* enode = new OrthogonalEdge(tail, head, adj, negadj);
		vertex[head].adjhead = enode; //adj 对应tail，遍历adj得到邻接链表
		vertex[tail].negadjhead = enode;//negadj对应head，遍历得到逆邻接链表
	}

	//输出出度的话只要遍历firstout然后一直往out走到尽头就可以了，入度同理
	//这里要思考一个问题就是如何释放，或者或如何遍历
}

OrthogonalList::~OrthogonalList()//补充释放部分，其实释放和邻接链表是一致的
{
	//for (int i = 0; i < vertexNum; i++) {
	//	OrthogonalEdge* head = vertex[i].adjhead;
	//	while (head != nullptr)
	//	{
	//		OrthogonalEdge* next = head->adjNext;
	//		if(head) delete head;
	//		head = next;
	//	}
	//}
}

DFSTraverse::DFSTraverse()
{

}

DFSTraverse::~DFSTraverse()
{
}

void DFSTraverse::DFStraverse1(int begin) {//对链接矩阵遍历,回溯的非递归版
	vector<bool> visited(digraph.vertexNum, false);
	stack<int> help_stack;
	help_stack.push(begin);
	while (!help_stack.empty())
	{
		int head = help_stack.top(); help_stack.pop();
		cout << head << endl; visited[head] = true;
		for (int i = 0; i < digraph.vertexNum; i++)
		{
			if (digraph.arc[head][i] != INT_MAX && !visited[i]) { //选择
				help_stack.push(i);//如果当前节点的没有选择了，回溯到上一节点
			}
		}
	}
}

void DFSTraverse::DFStraverse2(int begin) {//对邻接链表遍历
	stack<int> help_stack;
	vector<bool> visited(adjgraph.vertexNum, false);

	help_stack.push(begin);
	while (!help_stack.empty()) {
		int head = help_stack.top(); help_stack.pop();
		cout << head << endl; visited[head] = true;
		edgeNode* headNode = adjgraph.vertex[head].head;
		while (headNode != nullptr)
		{
			if (!visited[headNode->index]) {
				help_stack.push(headNode->index);
			}
			headNode = headNode->next;
		}
	}
}

void DFSTraverse::DFStraverse3(int begin) {//对十字链表遍历
	//这里其实和上面是一样的只需要考虑out部分

}


BFSTraverse::BFSTraverse()
{
}

BFSTraverse::~BFSTraverse()
{
}

BFSTraverse::BFSTraverse(const std::vector<std::vector<int> > &a, int vNum) {
	digraph = Digraph(a, vNum);
	adjgraph = AdjListDigraph(a, vNum);
}

void BFSTraverse::BFSTraverse1(int begin) {//使用邻接矩阵进行BFS
	queue<int> help_queue;
	vector<bool> visited(digraph.vertexNum, false);

	help_queue.push(begin);
	while (!help_queue.empty()) {
		int head = help_queue.front(); help_queue.pop();
		cout << head << endl; visited[head] = true;
		for (int i = 0; i < digraph.vertexNum; i++)
		{
			if (digraph.arc[head][i] != INT_MAX && !visited[i]) {
				help_queue.push(i);
			}
		}
	}
}
void BFSTraverse::BFSTraverse2(int begin) {//使用邻接链表进行BFS
	queue<int> help_queue;
	vector<bool> visited(adjgraph.vertexNum, false);

	help_queue.push(begin);
	while (!help_queue.empty()) {
		int head = help_queue.front(); help_queue.pop();
		cout << head << endl; visited[head] = true;
		edgeNode* headNode = adjgraph.vertex[head].head;
		while (headNode != nullptr) {
			if (!visited[headNode->index]) {
				help_queue.push(headNode->index);
			}
			headNode = headNode->next;
		}
	}
}

WeightGraph::WeightGraph(const std::vector<std::vector<int> > &a, int vNum) {
	vertexNum = vNum;
	edgeNum = a.size();

	edge.resize(vNum);
	for (int i = 0; i < edgeNum; i++) {
		WeightedEdge w1( a[i][1], a[i][2]);
		WeightedEdge w2(a[i][0], a[i][2]);
		edge[a[i][0]].push_back(w1);//无向图两边都要添加
		edge[a[i][1]].push_back(w2);
	}
}

void prim1(WeightGraph& w, int begin) {

}
