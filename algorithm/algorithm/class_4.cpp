#include "stdafx.h"

#include<iostream>
#include<stack>
#include <queue>
#include <string>
#include<cmath>
#include<climits>

#include "class_4.h"

using namespace std;

BinNode::BinNode()
{
}

BinNode::BinNode(int in_data)
{
	data = in_data;
}


BinNode::~BinNode()
{
}

void pre_order_recur(BinNode* head) {
	if (head == NULL) return;

	cout << head->data << " " ;
	pre_order_recur(head->left);
	pre_order_recur(head->right);
}

void in_order_recur(BinNode* head) {
	if (head == NULL) return;

	in_order_recur(head->left);
	cout << head->data << " ";
	in_order_recur(head->right);
}

void pos_order_recur(BinNode* head) {
	if (head == NULL) return;

	pos_order_recur(head->left);
	pos_order_recur(head->right);
	cout << head->data << " ";
}

void pre_order_iter(BinNode* head) {
	if (head == NULL) return;
	//���Խ�������ջ��ʵ��
	stack<BinNode*> help_stack;
	if(head->right) help_stack.push(head->right);//���Һ�����ջ���ⲿ�ֿ���ֱ�ӷŵ�ѭ������
	if(head->left) help_stack.push(head->left);
	cout << head->data << " ";

	while (!help_stack.empty()) {
		head = help_stack.top(); help_stack.pop();
		cout << head->data << " ";
		if (head->right)
		{
			help_stack.push(head->right);
		}
		if (head->left) {
			help_stack.push(head->left);
		}
	}
}

//����˼·��ÿ�ζ������ȱ�����������������ߣ�Ȼ���ٴ������������ͬʱҪ����ÿ�������������������
void in_order_iter(BinNode* head) {
	//���ø���ջ
	stack<BinNode*> help_stack;

	//help_stack.push(head);
	//while (!help_stack.empty()) {
	//	head = help_stack.top();
	//	if (head) {//����ǰ�ڵ�������ʱ��ֱ�ӽ���ڵ�ѹ��ջ��
	//		help_stack.push(head->left);
	//		head = head->left;
	//	}
	//	else {//��ǰ�ڵ�û������ʱ��˵����һ���ڵ�Ӧ�����
	//		help_stack.pop();//������ǰ�ڵ�
	//		if(help_stack.empty()) break;
	//		head = help_stack.top(); help_stack.pop();
	//		cout << head->data << " ";
	//		help_stack.push(head->right);//�����ҽڵ�����
	//	}
	//}

	//ţ�ʹ���˼·,Ҫ���Щ������˼·��һ���ģ�һ����˵����ֻѹ��ǿսڵ�
	while (!help_stack.empty() || head != NULL)//����Ƕ��ڵ�һ���ڵ�
	{
		if (head != NULL) {
			help_stack.push(head);//ֻ�Ѳ�ΪNULL�Ľڵ�ѹ����ջ��
			head = head->left;
		}
		else {//ֻҪ��ǰ�ڵ�Ϊ�գ���һ���ڵ�һ��Ҫ���
			head = help_stack.top();
			help_stack.pop();
			cout << head->data << " ";
			head = head->right;
		}
	}

}


//���������������ۣ�
//1��ʲôʱ����ڵ���ջ
//2��ʲôʱ���нڵ���ջ
//3��������������

void pos_order_iter(BinNode* head) {
	if (head == NULL) return;

	stack<BinNode*> help_stack;

	help_stack.push(head);
	BinNode* last = head;
	while (!help_stack.empty()) {
		head = help_stack.top();
		if (head->left != NULL && head->left != last && head->right != last) {//��������������߶�Ҫ�жϣ�
			help_stack.push(head->left);
		}
		else if (head->right != NULL && head->right!= last) {//����ֻҪ����ǰ�ڵ��ҽڵ��ǲ����ϴ�����Ľڵ�Ϳ�����
			help_stack.push(head->right);
		}
		else {
			cout << head->data << " ";
			help_stack.pop();
			last = head;
		}
	}
}

//
int get_bintree_height(BinNode* head) {
	//if(head == NULL) return;
	//return ( get_bintree_height(head->left) > ge_bintree_height(head-right)? 
	//get_bintree_height(head->left):get_bintree_height(head->right) ) + 1
	if (head == NULL ) return 0;

	int left_heght = head->left ? get_bintree_height(head->left) : 0;
	int right_height = head->right ? get_bintree_height(head->right) : 0;
	return (left_heght > right_height ? left_heght : right_height) + 1;
}

void level_order_iter(BinNode* head) {
	if (head == NULL) return;

	queue<BinNode*> help_queue;
	help_queue.push(head);
	while (!help_queue.empty()) {
		head = help_queue.front(); help_queue.pop();
		cout << head->data << " ";
		if (head->left) {
			help_queue.push(head->left);
		}
		if (head->right) {
			help_queue.push(head->right);
		}
	}
}

//ÿ������ռ��17���ַ����ܹ��Ŀռ����height x 2^height 
void print_bintree(BinNode* head, int height,string to, int len) {
	if (head == NULL) return;
	//��ӡͷ���
	print_bintree(head->right, height + 1, "v", len);
	string val = to + to_string(head->data) + to;

	int lenM = val.size();
	int lenL = (len - lenM) / 2;
	int LenR = len - lenM - lenL;

	val = string(lenL, ' ') + val + string(LenR, ' '); //���ַ�����������
	cout << string(height * len, ' ') << val << endl;  //ÿһ��ֻ��һ���ڵ㣬ͻȻ�뵽�����Ǵ�ֱ��ӡ�������
	print_bintree(head->left, height + 1, "^", len);

}

void print_bintree(BinNode* head) {
	print_bintree(head, 0, "H", 17);
}

//Ѱ���������ʱ��ĳ���ڵ�ĺ����ڵ�
BinNode* find_succ_node(BinNode* head) {
	if (head == NULL) return NULL;

	if (head->right != NULL) {//������������Ľڵ�
		head = head->right;
		while (head->left != NULL ) { //���ÿ����Һ���
			head = head->left;
		}
		return head;
	}
	else {//���Ե�ǰ�ڵ���������Ϊ�������ĵ�һ�����Ƚڵ�
		while (head != NULL) {
			if (head->parent->left == head) {
				return head->parent;
			}
			head = head->parent;
		}
	}

	return NULL;
}

string serial_bintree(BinNode* head) {
	//����ʹ���������,һ���ڵ����ݽ�����!���սڵ���#��ʾ
	string res = "";
	if (head == NULL) {
		res += "#";
		return res;
	}

	stack<BinNode* > help_stack;
	help_stack.push(head);
	while (!help_stack.empty()) {
		string temp;
		head = help_stack.top();

		if (head) {
			temp = to_string(head->data);
			res = res + temp + "!";
			help_stack.pop();
			help_stack.push(head->right);
			help_stack.push(head->left);
			
		}
		else {
			res += "#!";
			help_stack.pop();
		}
	}
	return res;
}

void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c)
{
	std::string::size_type pos1, pos2; //�������û�м���

	pos2 = s.find(c);
	pos1 = 0;
	while (std::string::npos != pos2) //����ҵ���
	{
		v.push_back(s.substr(pos1, pos2 - pos1));

		pos1 = pos2 + c.size();
		pos2 = s.find(c, pos1);
	}
	if (pos1 != s.length()) //��ֹû���ҵ������
		v.push_back(s.substr(pos1));
}

BinNode* recontruct_serialized_bintree(string& str_tree) {
	vector<string> vec_strtree;
	SplitString(str_tree, vec_strtree, "!"); //�������
	if (vec_strtree[0].compare("#") == 0) return NULL;
	BinNode* head = new BinNode(stoi(vec_strtree[0]));
	BinNode* res = head;

	stack<BinNode*> help_stack; help_stack.push(head);
	int count_num = 1;
	bool to_right = false;
	while (count_num < vec_strtree.size()) {
		if (vec_strtree[count_num].compare("#") == 0) {
			if (!to_right) {
				head->left = NULL;
				to_right = true; //ֻ������Ϊ��ʱ
			}
			else
			{
				head->right = NULL;
				help_stack.pop(); head = help_stack.top();

				if (head->right != NULL) { //������һ���ڵ���Һ��Ӳ�Ϊ�գ�˵���ýڵ���ʹ���
					help_stack.pop(); head = help_stack.top();
				}
			}
			
		}
		else {
			if ( !to_right)
			{
				head->left = new BinNode(stoi(vec_strtree[count_num]));
				head = head->left;
				help_stack.push(head);
			}
			else {
				head->right = new BinNode(stoi(vec_strtree[count_num]));
				head = head->right;
				help_stack.push(head);
				to_right = false; //����������Ϊ��ʱ
			}
		}

		count_num++;
	}
	return res;
}

void papper_folder(int num, int i, bool down, std::string & folder_res) {
	if (i > num) return;

	papper_folder(num, i + 1, true, folder_res);
	down ? folder_res.append("down ") : folder_res.append("up ");
	papper_folder(num, i + 1, false, folder_res);
}

void papper_folder(int num, std::string & folder_res) {
	papper_folder(num, 1, true, folder_res);
	cout << folder_res << endl;
}

int balance_height(BinNode* head, int& lev, bool& is_balance) {
	if (head == NULL) return 0;

	lev = lev + 1;
	int lH = balance_height(head->left, lev, is_balance);
	if (is_balance == false) {
		return lev;
	}

	int  rH = balance_height(head->right, lev, is_balance);
	if (is_balance == false) {
		return lev;
	}

	if (abs(lH - rH) > 1) {
		is_balance = false;
		return lev;
	}

	return max(rH, lH) + 1;
}

//������η��ز�ƽ��Ľڵ�,���������ĸ߶�
bool is_balance_tree(BinNode* head) {
	int solution = 1;
	switch (solution)
	{
	case 0: {
		if (head == NULL) return true;
		stack<BinNode*> help_stack;
		help_stack.push(head);

		while (!help_stack.empty()) {
			head = help_stack.top(); help_stack.pop();
			int lH = get_bintree_height(head->left);
			int rH = get_bintree_height(head->right);

			if (abs(lH - rH) > 1) {
				return false;
			}

			if (head->right) {
				help_stack.push(head->right);
			}

			if (head->left) {
				help_stack.push(head->left);
			}
		}
		return true;
	}
	case 1: {
		int lev = 0;
		bool isbanlance = true;
		int heigh = balance_height(head, lev, isbanlance);
		return isbanlance;
	}
	default:
		break;
	}
}


//�������������������ʱ�����
bool is_search_tree(BinNode* head) {
	if (head == NULL) return true;

	stack<BinNode* > help_stack;
	int last = INT_MIN;

	while (!help_stack.empty() || head) {

		if (head) {
			help_stack.push(head);
			head = head->left;
		}
		else {
			head = help_stack.top(); help_stack.pop();

			if (last > head->data) {
				return false;
			}
			cout << head->data << " ";
			last = head->data;

			head = head->right;
		}
	}

	cout << endl;
	return true;
}

bool is_complete_tree(BinNode* head) {
	if (head == NULL) return true;

	queue<BinNode*> help_queue;
	bool leaf_state = false;

	help_queue.push(head);
	while (!help_queue.empty()) {
		head = help_queue.front(); help_queue.pop();
		cout << head->data << " ";

		if (!leaf_state && (head->left == NULL && head->right != NULL)) {
			return false;
		}

		if (leaf_state && (head->left != NULL || head->right != NULL)) {
			return false;
		}

		if (head->left) {
			help_queue.push(head->left);
		}

		if (head->right) {
			help_queue.push(head->right);
		}
		else {
			leaf_state = true;
		}

	}
	cout << endl;
	return true;
}

int get_most_left_level(BinNode* head, int level) {
	while (head) {
		level++;
		head = head->left;
	}

	return level - 1; //����Ҫ��1�� �����0��ʼ���ü������������������Ľڵ����ʱ��Ҫ���1
							//�����û��Ǹ���ͼ��д
}

int bs(BinNode* head, int l, int h) { //l��ǰ�ڵ����ڵ�level�����ڵ�Ϊ1�� hΪ�����ܸ߶�
	if (l == h) return 1;

	if (get_most_left_level(head->right, l + 1) == h) { //����ֻҪ����h�Ϳ�
		return (1 << (h - l)) + bs(head->right, l + 1, h); //��1���ƣ�����2
	}
	else {
		return (1 << (h - l - 1)) + bs(head->left, l + 1, h);
	}

}

int caculate_complete_tree_node(BinNode* head) {
	if (head == NULL) return 0;

	return bs(head, 1, get_most_left_level(head, 1));//�����1��ʼ
}
