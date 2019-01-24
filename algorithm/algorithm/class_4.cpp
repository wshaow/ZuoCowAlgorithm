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
	//可以借助辅助栈来实现
	stack<BinNode*> help_stack;
	if(head->right) help_stack.push(head->right);//先右孩子入栈，这部分可以直接放到循环当中
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

//整体思路是每次都是最先遍历到左子树的最左边，然后再从下往上输出，同时要考察每棵子树的右子树的情况
void in_order_iter(BinNode* head) {
	//利用辅助栈
	stack<BinNode*> help_stack;

	//help_stack.push(head);
	//while (!help_stack.empty()) {
	//	head = help_stack.top();
	//	if (head) {//当当前节点有数据时，直接将左节点压入栈中
	//		help_stack.push(head->left);
	//		head = head->left;
	//	}
	//	else {//当前节点没有数据时，说明上一个节点应该输出
	//		help_stack.pop();//弹出当前节点
	//		if(help_stack.empty()) break;
	//		head = help_stack.top(); help_stack.pop();
	//		cout << head->data << " ";
	//		help_stack.push(head->right);//考察右节点的情况
	//	}
	//}

	//牛客代码思路,要简洁些，但是思路是一样的，一般来说我们只压入非空节点
	while (!help_stack.empty() || head != NULL)//这个是对于第一个节点
	{
		if (head != NULL) {
			help_stack.push(head);//只把不为NULL的节点压入了栈中
			head = head->left;
		}
		else {//只要当前节点为空，上一个节点一定要输出
			head = help_stack.top();
			help_stack.pop();
			cout << head->data << " ";
			head = head->right;
		}
	}

}


//这里分三种情况讨论：
//1、什么时候将左节点入栈
//2、什么时候将有节点入栈
//3、其它输出的情况

void pos_order_iter(BinNode* head) {
	if (head == NULL) return;

	stack<BinNode*> help_stack;

	help_stack.push(head);
	BinNode* last = head;
	while (!help_stack.empty()) {
		head = help_stack.top();
		if (head->left != NULL && head->left != last && head->right != last) {//这里必须左右两边都要判断，
			help_stack.push(head->left);
		}
		else if (head->right != NULL && head->right!= last) {//这里只要看当前节点右节点是不是上次输出的节点就可以了
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

//每个数据占用17个字符，总共的空间就是height x 2^height 
void print_bintree(BinNode* head, int height,string to, int len) {
	if (head == NULL) return;
	//打印头结点
	print_bintree(head->right, height + 1, "v", len);
	string val = to + to_string(head->data) + to;

	int lenM = val.size();
	int lenL = (len - lenM) / 2;
	int LenR = len - lenM - lenL;

	val = string(lenL, ' ') + val + string(LenR, ' '); //将字符调整到中央
	cout << string(height * len, ' ') << val << endl;  //每一行只有一个节点，突然想到这里是垂直打印的切入点
	print_bintree(head->left, height + 1, "^", len);

}

void print_bintree(BinNode* head) {
	print_bintree(head, 0, "H", 17);
}

//寻找中序遍历时，某个节点的后续节点
BinNode* find_succ_node(BinNode* head) {
	if (head == NULL) return NULL;

	if (head->right != NULL) {//找右子树最左的节点
		head = head->right;
		while (head->left != NULL ) { //不用考虑右孩子
			head = head->left;
		}
		return head;
	}
	else {//找以当前节点所在子树为左子树的第一个祖先节点
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
	//这里使用先序遍历,一个节点数据结束用!，空节点用#表示
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
	std::string::size_type pos1, pos2; //这个类型没有见过

	pos2 = s.find(c);
	pos1 = 0;
	while (std::string::npos != pos2) //如果找到了
	{
		v.push_back(s.substr(pos1, pos2 - pos1));

		pos1 = pos2 + c.size();
		pos2 = s.find(c, pos1);
	}
	if (pos1 != s.length()) //防止没有找到的情况
		v.push_back(s.substr(pos1));
}

BinNode* recontruct_serialized_bintree(string& str_tree) {
	vector<string> vec_strtree;
	SplitString(str_tree, vec_strtree, "!"); //先序遍历
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
				to_right = true; //只有在左为空时
			}
			else
			{
				head->right = NULL;
				help_stack.pop(); head = help_stack.top();

				if (head->right != NULL) { //若果下一个节点的右孩子不为空，说明该节点访问过了
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
				to_right = false; //在右子树不为空时
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

//想想如何返回不平衡的节点,或者是它的高度
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


//搜索二叉树的中序遍历时升序的
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

	return level - 1; //这里要减1， 如果从0开始不用减，但是下面求子树的节点个数时需要多减1
							//这个最好还是根据图来写
}

int bs(BinNode* head, int l, int h) { //l当前节点所在的level，根节点为1， h为树的总高度
	if (l == h) return 1;

	if (get_most_left_level(head->right, l + 1) == h) { //这里只要等于h就可
		return (1 << (h - l)) + bs(head->right, l + 1, h); //是1左移，不是2
	}
	else {
		return (1 << (h - l - 1)) + bs(head->left, l + 1, h);
	}

}

int caculate_complete_tree_node(BinNode* head) {
	if (head == NULL) return 0;

	return bs(head, 1, get_most_left_level(head, 1));//这里从1开始
}
