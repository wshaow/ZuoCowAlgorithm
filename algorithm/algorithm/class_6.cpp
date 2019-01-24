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
 	arc = temp; //����ʹ��resize����
	for (int i = 0; i < edgeNum; i++) {
		arc[edge[i][0]][edge[i][1]] = 1; //��������Ȩͼ��������������Ȩͼʹ����������
		//arc[edge[i][0]][edge[i][1]] = edge[i][2];
		//���������ͼ���������
		//arc[edge[i][1]][edge[i][0]] = 1;
	}
}

Digraph::~Digraph() {

}

AdjListDigraph::AdjListDigraph(const std::vector<std::vector<int> > &a, int vNum) {
	vertexNum = vNum;
	edgeNum = a.size();

	vertex.resize(vNum);
	for (int i = 0; i < vNum; i++) { //��ʼ��id,��ͷ���
		vertex[i].head = nullptr;
		vertex[i].id = i;
	}

	for (int i = 0; i < edgeNum; i++) {  //���Ҫ�������ڽ�����0��1����
		edgeNode* next = vertex[a[i][0]].head; //��ǰ���ڵ�
		edgeNode* enode = new edgeNode(a[i][1], next);//�½�ͷ�ڵ�
		vertex[a[i][0]].head = enode;//����ͷ�ڵ�
	}
}

AdjListDigraph::~AdjListDigraph() {
	//�ͷ��½��Ľڵ�
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
		//��ʵ���԰��ڽ���������ڽ�����ֿ����ǣ�ֻҪ�����ҾͿ�����
		//head��Ӧ�ڽ�����
		int head = a[i][0];
		OrthogonalEdge* adj = vertex[head].adjhead;
		//tail��Ӧ����������
		int tail = a[i][1];
		OrthogonalEdge* negadj = vertex[tail].negadjhead;
		
		OrthogonalEdge* enode = new OrthogonalEdge(tail, head, adj, negadj);
		vertex[head].adjhead = enode; //adj ��Ӧtail������adj�õ��ڽ�����
		vertex[tail].negadjhead = enode;//negadj��Ӧhead�������õ����ڽ�����
	}

	//������ȵĻ�ֻҪ����firstoutȻ��һֱ��out�ߵ���ͷ�Ϳ����ˣ����ͬ��
	//����Ҫ˼��һ�������������ͷţ����߻���α���
}

OrthogonalList::~OrthogonalList()//�����ͷŲ��֣���ʵ�ͷź��ڽ�������һ�µ�
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

void DFSTraverse::DFStraverse1(int begin) {//�����Ӿ������,���ݵķǵݹ��
	vector<bool> visited(digraph.vertexNum, false);
	stack<int> help_stack;
	help_stack.push(begin);
	while (!help_stack.empty())
	{
		int head = help_stack.top(); help_stack.pop();
		cout << head << endl; visited[head] = true;
		for (int i = 0; i < digraph.vertexNum; i++)
		{
			if (digraph.arc[head][i] != INT_MAX && !visited[i]) { //ѡ��
				help_stack.push(i);//�����ǰ�ڵ��û��ѡ���ˣ����ݵ���һ�ڵ�
			}
		}
	}
}

void DFSTraverse::DFStraverse2(int begin) {//���ڽ��������
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

void DFSTraverse::DFStraverse3(int begin) {//��ʮ���������
	//������ʵ��������һ����ֻ��Ҫ����out����

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

void BFSTraverse::BFSTraverse1(int begin) {//ʹ���ڽӾ������BFS
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
void BFSTraverse::BFSTraverse2(int begin) {//ʹ���ڽ��������BFS
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
		edge[a[i][0]].push_back(w1);//����ͼ���߶�Ҫ���
		edge[a[i][1]].push_back(w2);
	}
}

void prim1(WeightGraph& w, int begin) {

}
