#pragma once
#include <vector>
#include <list>

//有向图的邻接矩阵表示
struct Digraph {
	int vertexNum;
	int edgeNum;
	std::vector<std::vector<int> > arc; //存储每个节点之间的连通性
	Digraph() {}
	Digraph(const std::vector< std::vector<int> >& edge, int vNum);
	~Digraph();
};


struct edgeNode {
	int index;//对应顶点的编号
	edgeNode* next;
	edgeNode(int i, edgeNode* n) { index = i; next = n; }
};

struct vertexNode {
	int id;
	edgeNode* head;
};

struct AdjListDigraph {
	int vertexNum;
	int edgeNum;

	std::vector<vertexNode> vertex;
	AdjListDigraph(){}
	AdjListDigraph(const std::vector<std::vector<int> > &a, int vNum);
	~AdjListDigraph();

};

struct OrthogonalEdge
{
	int adj;//邻接也就是第二个值
	int negadj;//逆邻接，第一个值
	OrthogonalEdge* adjNext; //邻接的下一个值
	OrthogonalEdge* negadjnext;//逆邻接的下一个值
	OrthogonalEdge(){}
	OrthogonalEdge(int h, int t, OrthogonalEdge* he, OrthogonalEdge* ta) {
		adj = h;
		negadj = t;
		adjNext = he;
		negadjnext = ta;

	}

};

struct OrthogonalVetex{
	int data;
	OrthogonalEdge* adjhead;//以当前节点为入的头
	OrthogonalEdge* negadjhead;//以当前节点为尾的头
	OrthogonalVetex() {}
	OrthogonalVetex(int d, OrthogonalEdge* i, OrthogonalEdge* o) {
		data = d;
		adjhead = i;
		negadjhead = o;
	}

};


class OrthogonalList
{
public:
	OrthogonalList();
	~OrthogonalList();
	OrthogonalList(const std::vector<std::vector<int> > &a, int vNum);

	int EdgeNum;
	int vertexNum;
	std::vector<OrthogonalVetex> vertex;
private:

};

class DFSTraverse
{
public:
	DFSTraverse();
	~DFSTraverse();
	DFSTraverse(const std::vector<std::vector<int> > &a, int vNum) {
		digraph = Digraph(a, vNum); //可以直接这样赋值，即使没有重载等于号
		adjgraph = AdjListDigraph(a, vNum);//这样复制是浅拷贝，结束后析构函数会清除内容
		orthgrath = OrthogonalList(a, vNum);//这里必须定义一个深拷贝，要不然这里要释放两次
	}
	//这里的遍历时假设各顶点都有边相连的情况
	void DFStraverse1(int begin);//对链接矩阵遍历
	void DFStraverse2(int begin);//对连接链表遍历
	void DFStraverse3(int begin);//对十字链表遍历

private:
	Digraph digraph;
	AdjListDigraph adjgraph;
	OrthogonalList orthgrath;
};

class BFSTraverse
{
public:
	BFSTraverse();
	BFSTraverse(const std::vector<std::vector<int> > &a, int vNum);
	~BFSTraverse();

	void BFSTraverse1(int begin);//使用邻接矩阵进行BFS
	void BFSTraverse2(int begin);//使用邻接链表进行BFS


private:
	Digraph digraph;
	AdjListDigraph adjgraph;
	OrthogonalList orthgrath;
};


//带权边
struct WeightedEdge
{
	int ver;
	int weight;

	WeightedEdge(){}
	WeightedEdge(int v1, int w) {
		ver = v1;  weight = w;
	}

};

struct WeightGraph //采用邻接链表的形式
{
	int edgeNum;
	int vertexNum;

	std::vector<std::list<WeightedEdge> > edge;
	WeightGraph(){}
	WeightGraph(const std::vector<std::vector<int> > &a, int vNum);
};

void prim1(WeightGraph& w, int begin);
