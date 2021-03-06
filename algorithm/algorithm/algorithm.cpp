// algorithm.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <stdlib.h>
#include<iostream>

#include "sort_algorithm.h"
#include"class_3.h"
#include "class_4.h"
#include"class_5.h"
#include "class_6.h"
#include "class_7.h"

#pragma warning (disable:4018) //屏蔽warning，这条对应的是无符号数和有符号数的大小比较

void sort_algorithm_test();
void class_3_test(int index);
void class_4_test(int index);
void class_5_test(int index);
void class_6_test(int index);
void class_7_test(int index);

int main()
{
	
	//class_3_test(13);
	//class_4_test(4);
	//class_5_test(2);
	//class_6_test(3);
	system("pause");
    return 0;
}

void sort_algorithm_test() {
	int a[12] = { 5,4,7,6,8,9,100,12,15,17,12,12 };
	int b[] = { 5,2,4,3,1,12,12, 12,12 };// { 1, 3, 4, 2, 5 };
	vector<int> arr(a, a + 12);
	vector<int> A(a, a + 12);
	vector<int> B(b, b + 9);
	print_vector(arr);
	//bubble_sort(arr, 0, 11);

	//select_sort(arr, 0, 11);

	//insert_sort(arr, 0, 11);

	//merge_sort(arr, 0, 11);
	//merge_sort_iter(arr, 0, 11);

	//int res = small_sum_iter(arr, 0, 4);

	//int res = inversion_pair(arr, 0, 4);
	//printf("%d \n", res);

	//int  position = small_big_data(arr, 0, 11, 10);
	//printf("%d \n", position);

	//vector<int> res;
	//res = nether_lands_flag(arr, 0, 11, 12);
	//printf("%d %d \n", res[0], res[1]);

	//quick_sort(arr, 0, 11);
	//quick_sort_iter(arr, 0, 11);

	//heap_sort(arr, 0, 11);

	//count_sort(arr, 0, 11);

	//bucket_sort(arr, 0, 11);

	//radix_sort(arr, 0, 11);

	//get_max_gap(arr, 0, 11);

	radix_sort(A, 0, 11);
	get_all_not_include(A, B);

	print_vector(A);
	print_vector(B);
}
void class_3_test(int index) {
	switch (index)
	{
	case 0: { //数组实现固定大小的栈和队列
		//Array_to_stack s(10);
		//s.push(10);
		//cout << s.peek() << endl;
		//s.push(100);
		//cout << s.peek() << endl;
		//s.pop();
		//cout << s.peek() << endl;
		//s.pop();
		//cout << s.peek() << endl;

		Array_to_queue q(10);
		q.push(30);
		q.push(20);
		q.push(30);
		q.push(20);
		q.push(30);
		q.push(20);
		q.push(30);
		q.push(20);
		q.push(30);
		q.push(20);
		q.push(30);
		q.push(20);
		cout << q.peek() << endl;
		cout << q.poll() << endl;

		break;
		}
	case 1: {//最小栈问题
		GetMinStack	my_get_min_stack;
		my_get_min_stack.push(4);
		cout << my_get_min_stack.get_min() << endl;
		my_get_min_stack.push(3);
		cout << my_get_min_stack.get_min() << endl;
		my_get_min_stack.push(1);
		cout << my_get_min_stack.get_min() << endl;
		my_get_min_stack.pop();
		cout << my_get_min_stack.get_min() << endl;
		break;
	}
	case 2: {
		Stack_to_queue sq;
		sq.push(1);
		cout << sq.peek() << endl;
		sq.push(2);
		cout << sq.peek() << endl;
		sq.push(3);
		cout << sq.peek() << endl;
		cout << sq.poll() << endl;
		cout << sq.poll() << endl;
		cout << sq.poll() << endl;

		Queue_to_stack qs;
		qs.push(1);
		cout << qs.peek() << endl;
		qs.push(2);
		cout << qs.peek() << endl;
		qs.push(3);
		cout << qs.peek() << endl;

		cout << qs.pop() << endl;
		cout << qs.pop() << endl;
		cout << qs.pop() << endl;
		break;
	}
	case 3: {//猫狗队列
		dog my_dog;
		cat my_cat;
		Petqueue pq;
		cout << pq.isempty() << endl;
		pq.add(my_dog);
		cout << pq.poll_cat().get_pettype() << endl;
		cout << pq.pollAll().get_pettype() << endl;

		break;
	}
	case 4: {
		int a[5][4] = { {1,2,3,4},
						{5,6,7,8 },
						{9,10,11,12},
						{13,14,15,16},
						{17,18,19,20} };
		vector<vector<int> > vec_a(5, vector<int>(4));
		for (int i = 0; i < vec_a.size(); i++) {
			for (int j = 0; j < vec_a[i].size(); j++) {
				vec_a[i][j] = a[i][j];
			}
		}
		print_matrix_spiral_order(vec_a, 5, 4);

	}
	case 5: {
		int a[4][4] = { { 1,2,3,4 },
		{ 5,6,7,8 },
		{ 9,10,11,12 },
		{ 13,14,15,16 } };
		vector<vector<int> > vec_a(4, vector<int>(4));
		for (int i = 0; i < vec_a.size(); i++) {
			for (int j = 0; j < vec_a[i].size(); j++) {
				vec_a[i][j] = a[i][j];
			}
		}
		rotate_matrix(vec_a);
		print_matrix(vec_a);
		break;
	}
	case 6: {//反转list
		//
		//myNode* head = new myNode(1,NULL);
		//head->next = new myNode(2, NULL);
		//head->next->next = new myNode(3, NULL);
		//print_list(head);
		//head = reverse_list(head);
		//print_list(head);

		DoublemyNode* head = new DoublemyNode(1, NULL, NULL);
		head->next = new DoublemyNode(2, (DoublemyNode*)NULL, head);
		head->next->next = new DoublemyNode(3, NULL, head->next);
		print_double_list(head);
		head = reverse_doublelist(head);
		print_double_list(head);
		break;
	}
	case 7: {//zigzag打印矩阵
		int a[4][4] = { { 1,2,3,4 },
		{ 5,6,7,8 },
		{ 9,10,11,12 },
		{ 13,14,15,16 } };
		vector<vector<int> > vec_a(4, vector<int>(4));
		for (int i = 0; i < vec_a.size(); i++) {
			for (int j = 0; j < vec_a[i].size(); j++) {
				vec_a[i][j] = a[i][j];
			}
		}

		zigzag_print_matrix(vec_a);
		break;
	}
	case 8: {//在已排序的matrix中找数
		int a[4][4] = { { 1,2,3,4 },
		{ 5,6,7,8 },
		{ 9,10,11,12 },
		{ 13,14,15,16 } };
		vector<vector<int> > vec_a(4, vector<int>(4));
		for (int i = 0; i < vec_a.size(); i++) {
			for (int j = 0; j < vec_a[i].size(); j++) {
				vec_a[i][j] = a[i][j];
			}
		}

		vector<int> res = find_num_in_sorted_matrix(vec_a, 100);
		print_vector(res);
		break;
	}
	case 9: {//找两个已排序链表的相同部分
		myNode* head = new myNode(1,NULL);
		head->next = new myNode(2, NULL);
		head->next->next = new myNode(3, NULL);
		print_list(head);

		myNode* head2 = new myNode(0,NULL);
		head2->next = new myNode(2, NULL);
		head2->next->next = new myNode(3, NULL);
		print_list(head2);
		print_list_common_part(head, head2);
		break;
	}
	case 10: {//判断链表中的数据是否是回文
		myNode* head = new myNode(1, NULL);
		head->next = new myNode(2, NULL);
		head->next->next = new myNode(3, NULL);
		head->next->next->next = new myNode(2, NULL);
		head->next->next->next->next = new myNode(1, NULL);
		print_list(head);
		if (isplalindrome(head)) {
			cout << "链表中的数据是回文的" << endl;
		}
		else {
			cout << "链表中的数据不是回文的" << endl;
		}
		print_list(head);
		break;
	}
	case 11: {//链表的荷兰国旗问题
		myNode* head = new myNode(2, NULL);
		head->next = new myNode(2, NULL);
		head->next->next = new myNode(2, NULL);
		head->next->next->next = new myNode(2, NULL);
		head->next->next->next->next = new myNode(2, NULL);
		print_list(head);

		myNode* res = list_netherland(head, 2);
		print_list(res);
		break;
	}
	case 12: {//复制带有随机指针的链表
		RandomNode* head = new RandomNode(1);
		head->next = new RandomNode(2);
		head->next->next = new RandomNode(3);
		head->next->next->next = new RandomNode(4);
		head->next->next->next->next = new RandomNode(5);
		head->next->next->next->next->next = new RandomNode(6);

		head->random = head->next->next->next->next->next; // 1 -> 6
		head->next->random = head->next->next->next->next->next;//2 -> 6
		head->next->next->random = head->next->next->next->next;//3->5
		head->next->next->next->random = head->next->next->next;//4->3
		head->next->next->next->next->random = NULL;
		head->next->next->next->next->next->random = head->next->next->next;//6 -> 4
		print_randomNodelist(head);
		cout << "=================================" << endl;
		RandomNode* temp = copy_list_with_random(head);
		print_randomNodelist(temp);
		break;
	}
	case 13: {//单链表相交
			  // 1->2->3->4->5->6->7->null
		myNode* head1 = new myNode(1);
		head1->next = new myNode(2);
		head1->next->next = new myNode(3);
		head1->next->next->next = new myNode(4);
		head1->next->next->next->next = new myNode(5);
		head1->next->next->next->next->next = new myNode(6);
		head1->next->next->next->next->next->next = new myNode(7);

		// 0->9->8->6->7->null
		myNode* head2 = new myNode(0);
		head2->next = new myNode(9);
		head2->next->next = new myNode(8);
		head2->next->next->next = head1->next->next->next->next->next; // 8->6
		//myNode* res = find_first_intersect_node(head1, head2);
		//if (res) {
		//	cout << res->data << endl;
		//}
		//else {
		//	cout << "没有交点！" << endl;
		//}
		

	//==================================================================================

		// 1->2->3->4->5->6->7->4...
		head1 = new myNode(1);
		head1->next = new myNode(2);
		head1->next->next = new myNode(3);
		head1->next->next->next = new myNode(4);
		head1->next->next->next->next = new myNode(5);
		head1->next->next->next->next->next = new myNode(6);
		head1->next->next->next->next->next->next = new myNode(7);
		head1->next->next->next->next->next->next = head1->next->next->next; // 7->4

																	// 0->9->8->2...
		head2 = new myNode(0);
		head2->next = new myNode(9);
		head2->next->next = new myNode(8);
		head2->next->next->next = head1->next; // 8->2

		//myNode* res = find_first_intersect_node(head1, head2);
		//if (res) {
		//	cout << res->data << endl;
		//}
		//else {
		//	cout << "没有交点！" << endl;
		//}
		//=======================================================================================
		// 0->9->8->6->4->5->6..
		head2 = new myNode(0);
		head2->next = new myNode(9);
		head2->next->next = new myNode(8);
		head2->next->next->next = head1->next->next->next->next->next; // 8->6

		myNode* res = find_first_intersect_node(head1, head2);
		if (res) {
			cout << res->data << endl;
		}
		else {
			cout << "没有交点！" << endl;
		}
		break;
	}
	default:
		break;
	}
}
void class_4_test(int index) {
	switch (index)
	{
	case 0: {
		BinNode* head = new BinNode(5);
		head->left = new BinNode(3);
		head->right = new BinNode(8);
		head->left->left = new BinNode(2);
		head->left->right = new BinNode(4);
		head->left->left->left = new BinNode(1);
		head->right->left = new BinNode(7);
		head->right->left->left = new BinNode(6);
		head->right->right = new BinNode(10);
		head->right->right->left = new BinNode(9);
		head->right->right->right = new BinNode(11);

		cout << "==============递归版本===============" << endl;
		cout << "先序遍历：";
		pre_order_recur(head);
		cout << endl;
		cout << "中序遍历：";
		in_order_recur(head);
		cout << endl;
		cout << "后序遍历：";
		pos_order_recur(head);
		cout << endl;

		cout << "=============非递归版本==============" << endl;
		cout << "先序遍历：";
		pre_order_iter(head);
		cout << endl;
		cout << "中序遍历：";
		in_order_iter(head);
		cout << endl;
		cout << "后序遍历：";
		pos_order_iter(head);
		cout << endl;
		cout << "层次遍历：";
		level_order_iter(head);
		cout << endl;
		break;
	}
	case 1: {//形象话的打印二叉树
		BinNode* head = new BinNode(5);
		head->left = new BinNode(3);
		head->right = new BinNode(8);
		head->left->left = new BinNode(2);
		head->left->right = new BinNode(4);
		head->left->left->left = new BinNode(1);
		head->right->left = new BinNode(7);
		head->right->left->left = new BinNode(6);
		head->right->right = new BinNode(10);
		head->right->right->left = new BinNode(9);
		head->right->right->right = new BinNode(11);
		print_bintree(head);
		break;
	}
	case 2: {//寻找后继节点
		BinNode* head = new BinNode(5);
		head->parent = NULL;

		head->left = new BinNode(3);
		head->left->parent = head;

		head->right = new BinNode(8);
		head->right->parent = head;

		head->left->left = new BinNode(2);
		head->left->left->parent = head->left;

		head->left->right = new BinNode(4);
		head->left->right->parent = head->left;

		head->left->left->left = new BinNode(1);
		head->left->left->left->parent = head->left->left;

		head->right->left = new BinNode(7);
		head->right->left->parent = head->right;

		head->right->left->left = new BinNode(6);
		head->right->left->left->parent = head->right->left;

		head->right->right = new BinNode(10);
		head->right->right->parent = head->right;

		head->right->right->left = new BinNode(9);
		head->right->right->left->parent = head->right->right;

		head->right->right->right = new BinNode(11);
		head->right->right->right->parent = head->right->right;

		BinNode* res = find_succ_node(head);
		if (res == NULL) {
			cout << "当前节点为最后一个节点 " << endl;
		}
		else {
			cout << res->data << endl;
		}
		break;
	}
	case 3: {
		BinNode* head = new BinNode(5);
		head->parent = NULL;

		head->left = new BinNode(3);
		head->left->parent = head;

		head->right = new BinNode(8);
		head->right->parent = head;

		head->left->left = new BinNode(2);
		head->left->left->parent = head->left;

		head->left->right = new BinNode(4);
		head->left->right->parent = head->left;

		head->left->left->left = new BinNode(1);
		head->left->left->left->parent = head->left->left;

		head->right->left = new BinNode(7);
		head->right->left->parent = head->right;

		head->right->left->left = new BinNode(6);
		head->right->left->left->parent = head->right->left;

		head->right->right = new BinNode(10);
		head->right->right->parent = head->right;

		head->right->right->left = new BinNode(9);
		head->right->right->left->parent = head->right->right;

		head->right->right->right = new BinNode(11);
		head->right->right->right->parent = head->right->right;

		string res = serial_bintree(head);
		cout << res << endl;
		BinNode* re_tree = recontruct_serialized_bintree(res);
		print_bintree(re_tree);
		break;
	}
	case 4: {//折纸问题，这里用的是递归的方式可以考虑使用迭代的方式实现
		string res;
		papper_folder(3, res);
		break;
	}
	case 5: {//判断一棵二叉树是否是平衡二叉树
		BinNode* head = new BinNode(5);
		head->parent = NULL;

		head->left = new BinNode(3);
		head->left->parent = head;

		head->right = new BinNode(8);
		head->right->parent = head;

		head->left->left = new BinNode(2);
		head->left->left->parent = head->left;

		head->left->right = new BinNode(4);
		head->left->right->parent = head->left;

		head->left->left->left = new BinNode(1);
		head->left->left->left->parent = head->left->left;

		head->right->left = new BinNode(7);
		head->right->left->parent = head->right;

		head->right->left->left = new BinNode(6);
		head->right->left->left->parent = head->right->left;

		head->right->right = new BinNode(10);
		head->right->right->parent = head->right;

		head->right->right->left = new BinNode(9);
		head->right->right->left->parent = head->right->right;

		head->right->right->right = new BinNode(11);
		head->right->right->right->parent = head->right->right;

		//head->right->right->right->right = new BinNode(11);
		//head->right->right->right->right->right = new BinNode(11);
		//head->right->right->right->right->right->right = new BinNode(11);
		cout << get_bintree_height(head) << endl;

		bool res = is_balance_tree(head);
		if (res) cout << "是平衡树" << endl;
		else cout << "不是平衡树" << endl;
		break;
	}
	case 6: {//判断一棵二叉树是否是搜索二叉树
		BinNode* head = new BinNode(5);
		head->parent = NULL;

		head->left = new BinNode(3);
		head->left->parent = head;

		head->right = new BinNode(8);
		head->right->parent = head;

		head->left->left = new BinNode(2);
		head->left->left->parent = head->left;

		head->left->right = new BinNode(4);
		head->left->right->parent = head->left;

		head->left->left->left = new BinNode(1);
		head->left->left->left->parent = head->left->left;

		head->right->left = new BinNode(7);
		head->right->left->parent = head->right;

		head->right->left->left = new BinNode(6);
		head->right->left->left->parent = head->right->left;

		head->right->right = new BinNode(10);
		head->right->right->parent = head->right;

		head->right->right->left = new BinNode(9);
		head->right->right->left->parent = head->right->right;

		head->right->right->right = new BinNode(11);
		head->right->right->right->parent = head->right->right;

		bool res = is_search_tree(head);
		if (res) cout << "是BST" << endl;
		else cout << "不是BST" << endl;

		print_bintree(head);
		break;
	}
	case 7: {//判断一棵二叉树是否是完全二叉树
		BinNode* head = new BinNode(5);
		head->parent = NULL;

		head->left = new BinNode(3);
		head->left->parent = head;

		head->right = new BinNode(8);
		head->right->parent = head;

		head->left->left = new BinNode(2);
		head->left->left->parent = head->left;

		head->left->right = new BinNode(4);
		head->left->right->parent = head->left;

		//head->left->left->left = new BinNode(1);
		//head->left->left->left->parent = head->left->left;

		head->right->left = new BinNode(7);
		head->right->left->parent = head->right;

		//head->right->left->left = new BinNode(6);
		//head->right->left->left->parent = head->right->left;

		head->right->right = new BinNode(10);
		head->right->right->parent = head->right;

		//head->right->right->left = new BinNode(9);
		//head->right->right->left->parent = head->right->right;

		//head->right->right->right = new BinNode(11);
		//head->right->right->right->parent = head->right->right;

		bool res = is_complete_tree(head);
		if (res) cout << "是完全二叉树" << endl;
		else cout << "不是完全二叉树" << endl;

		print_bintree(head);
		break;
	}
	case 8: {//计算完全二叉树的节点数
		BinNode* head = new BinNode(5);
		head->parent = NULL;

		head->left = new BinNode(3);
		head->left->parent = head;

		head->right = new BinNode(8);
		head->right->parent = head;

		head->left->left = new BinNode(2);
		head->left->left->parent = head->left;

		head->left->right = new BinNode(4);
		head->left->right->parent = head->left;

		head->left->left->left = new BinNode(1);
		head->left->left->left->parent = head->left->left;

		head->right->left = new BinNode(7);
		head->right->left->parent = head->right;

		//head->right->left->left = new BinNode(6);
		//head->right->left->left->parent = head->right->left;

		head->right->right = new BinNode(10);
		head->right->right->parent = head->right;

		//head->right->right->left = new BinNode(9);
		//head->right->right->left->parent = head->right->right;

		//head->right->right->right = new BinNode(11);
		//head->right->right->right->parent = head->right->right;

		cout <<"节点数为："<< caculate_complete_tree_node(head)<<endl;
		print_bintree(head);
		break;
	}
	default:
		break;
	}
}
void class_5_test(int index) {
	switch (index)
	{
	case 0: {//补充map的经典用法
		map<int, string> m;
		m[1] = "nihao";
		cout << m[1] << endl;
		m[1] = "hello";
		cout << m[1] << endl;

		break;
	}
	case 1: {
		RandomPool rp;
		rp.insert("nihao");
		rp.insert("wu");
		rp.insert("shao");
		rp.insert("yj");
		cout << rp.getRandom() << endl;
		rp.delete_data("shao");
		cout << rp.getRandom() << endl;
		rp.delete_data("wu");
		rp.delete_data("yj");
		cout << rp.getRandom() << endl;
		break;
	}
	case 2: {//islands
		int arr[][9] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
						{ 0, 1, 1, 1, 0, 1, 1, 1, 0 },
						{ 0, 1, 1, 1, 0, 0, 0, 1, 0 },
						{ 0, 1, 1, 0, 0, 0, 0, 0, 0 },
						{ 0, 0, 0, 0, 0, 1, 1, 0, 0 },
						{ 0, 0, 0, 0, 1, 1, 1, 0, 0 },
						{ 0, 0, 0, 0, 0, 0, 0, 0, 0 }, };

		cout << islands((int**)arr, 7, 9)<<endl;

		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 9; j++) {
				cout << arr[i][j] << "  ";
			}
			cout << endl;
		}
		break;
	}
	case 3: {//之后增加并查集的实现，有时间也可以实现以下一致性hash

		break;
	}
	default:		
		break;
	}
}
void class_6_test(int index) {
	switch (index) {
	case 0: {//测试邻接矩阵
		vector<vector<int> > a(5, vector<int>(2, 0));
		a[0][0] = 0; a[0][1] = 1;
		a[1][0] = 3; a[1][1] = 1;
		a[2][0] = 2; a[2][1] = 1;
		a[3][0] = 1; a[3][1] = 3;
		a[4][0] = 3; a[4][1] = 2;

		Digraph d(a, 4);
		for (int i = 0; i < 4; i++) {
			cout << d.arc[2][i] << " ";
		}
		cout << endl;
		break;
	}
	case 1: {
		vector<vector<int> > a(5, vector<int>(2, 0));
		a[0][0] = 0; a[0][1] = 1;
		a[1][0] = 3; a[1][1] = 1;
		a[2][0] = 2; a[2][1] = 1;
		a[3][0] = 1; a[3][1] = 3;
		a[4][0] = 3; a[4][1] = 2;

		AdjListDigraph b(a, 4);
		edgeNode* head = b.vertex[1].head;
		while ( head != nullptr)
		{
			cout << head->index << " ";
			head = head->next;
		}
		cout << endl;
		break;
	}
	case 2: {
		vector<vector<int> > a(5, vector<int>(2, 0));
		a[0][0] = 1; a[0][1] = 0;
		a[1][0] = 3; a[1][1] = 1;
		a[2][0] = 2; a[2][1] = 1;
		a[3][0] = 1; a[3][1] = 3;
		a[4][0] = 3; a[4][1] = 2;

		DFSTraverse d(a, 4);
		d.DFStraverse2(1);
		break;
	}
	case 3: {
		vector<vector<int> > a(5, vector<int>(2, 0));
		a[0][0] = 1; a[0][1] = 0;
		a[1][0] = 3; a[1][1] = 1;
		a[2][0] = 2; a[2][1] = 1;
		a[3][0] = 1; a[3][1] = 3;
		a[4][0] = 3; a[4][1] = 2;

		BFSTraverse d(a, 4);
		d.BFSTraverse2(1);
		break;
	}
	default: break;
	}
}
void class_7_test(int index) {
	switch (index)
	{
	case 0: {//前缀树测试
		TrieTree t;
		t.insert("abcd");
		t.remove("abcd");
		if (t.search("abcd"))
			cout << "true" << endl;
		else cout << "false" << endl;
		
		break;
	}
	case 1: {
		int a[] = { 6, 7, 8, 9 };
		vector<int> price(a, a + 4);
		cout << less_money(price) << endl;

		break;
	}
	case 2:{
		int a[] = { 6, 7, 8, 9 };
		vector<int> costs(a, a + 4);
		vector<int> profit(a, a + 4);
		cout<< IPO(costs, profit, 2, 10)<<endl;
		break;
	}
	case 3: {
		medianQuick m;
		m.addNum(1); m.addNum(2); m.addNum(3); m.addNum(4);
		m.addNum(5); m.addNum(6); m.addNum(8); m.addNum(7);
		m.addNum(9);
		cout << m.getMedian() << endl;
	}
	case 4: {
		vector<string> s;
		s.push_back("jibw");
		s.push_back("ji");
		s.push_back("jp");
		s.push_back("bw");
		s.push_back("jibw");
		cout << LowestLexicography(s) << endl;
		break;
	}
	case 5: {//实现了但是没有写测试

		break;
	}
	default:
		break;
	}
}