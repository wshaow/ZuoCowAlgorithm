#pragma once
#include <vector>
#include <list>

//����ͼ���ڽӾ����ʾ
struct Digraph {
	int vertexNum;
	int edgeNum;
	std::vector<std::vector<int> > arc; //�洢ÿ���ڵ�֮�����ͨ��
	Digraph() {}
	Digraph(const std::vector< std::vector<int> >& edge, int vNum);
	~Digraph();
};


struct edgeNode {
	int index;//��Ӧ����ı��
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
	int adj;//�ڽ�Ҳ���ǵڶ���ֵ
	int negadj;//���ڽӣ���һ��ֵ
	OrthogonalEdge* adjNext; //�ڽӵ���һ��ֵ
	OrthogonalEdge* negadjnext;//���ڽӵ���һ��ֵ
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
	OrthogonalEdge* adjhead;//�Ե�ǰ�ڵ�Ϊ���ͷ
	OrthogonalEdge* negadjhead;//�Ե�ǰ�ڵ�Ϊβ��ͷ
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
		digraph = Digraph(a, vNum); //����ֱ��������ֵ����ʹû�����ص��ں�
		adjgraph = AdjListDigraph(a, vNum);//����������ǳ�����������������������������
		orthgrath = OrthogonalList(a, vNum);//������붨��һ�������Ҫ��Ȼ����Ҫ�ͷ�����
	}
	//����ı���ʱ��������㶼�б����������
	void DFStraverse1(int begin);//�����Ӿ������
	void DFStraverse2(int begin);//�������������
	void DFStraverse3(int begin);//��ʮ���������

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

	void BFSTraverse1(int begin);//ʹ���ڽӾ������BFS
	void BFSTraverse2(int begin);//ʹ���ڽ��������BFS


private:
	Digraph digraph;
	AdjListDigraph adjgraph;
	OrthogonalList orthgrath;
};


//��Ȩ��
struct WeightedEdge
{
	int ver;
	int weight;

	WeightedEdge(){}
	WeightedEdge(int v1, int w) {
		ver = v1;  weight = w;
	}

};

struct WeightGraph //�����ڽ��������ʽ
{
	int edgeNum;
	int vertexNum;

	std::vector<std::list<WeightedEdge> > edge;
	WeightGraph(){}
	WeightGraph(const std::vector<std::vector<int> > &a, int vNum);
};

void prim1(WeightGraph& w, int begin);
