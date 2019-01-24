#pragma once
#include <string>

/*
*这节的主要内容是关于二叉树的
*/


//定义二叉树的节点类
class BinNode
{
public:
	BinNode();
	BinNode(int in_data);
	~BinNode();

	int data;
	BinNode* left;
	BinNode* right;
	BinNode* parent;
private:

};


void pre_order_recur(BinNode* head);
void in_order_recur(BinNode* head);
void pos_order_recur(BinNode* head);

void pre_order_iter(BinNode* head);
void in_order_iter(BinNode* head);
void pos_order_iter(BinNode* head);
void level_order_iter(BinNode* head);

int get_bintree_height(BinNode* head);
void print_bintree(BinNode* head);

BinNode* find_succ_node(BinNode* head);

std::string serial_bintree(BinNode* head);
BinNode* recontruct_serialized_bintree(std::string& str_tree);

void papper_folder(int num, std::string & folder_res);

bool is_balance_tree(BinNode* head);
bool is_search_tree(BinNode* head);
bool is_complete_tree(BinNode* head);
int caculate_complete_tree_node(BinNode* head);