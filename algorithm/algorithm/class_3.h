#pragma once

#include <vector>
#include <stack>
#include <queue>
#include <string>

using namespace std;
//本来想用vector实现，结果发现是固定大小的所以还是用数组实现
class Array_to_stack
{
public:
	//构造函数和析构函数
	Array_to_stack();
	Array_to_stack(int init_size);
	~Array_to_stack();
	//功能函数
	int peek();//返回栈元素顶部的值

	void push(int in_data);

	void pop();

private:
	int _size; //指示当前已存数据的大小
	int* _stack; 
	int _total_size;
};


class Array_to_queue
{
public:
	Array_to_queue();
	Array_to_queue(int init_size);
	~Array_to_queue();

	int peek(); //返回头位置的值
	void push(int in_data); //在末尾添加元素
	int poll(); //队列头部的节点出队

private:
	int* _queue;
	int _total_size;
	int _size;
	int _first;
	int _last;
};


class GetMinStack
{
public:
	GetMinStack();
	~GetMinStack();

	void push(int in_data);
	int pop();
	int get_min();

private:
	vector<int> my_stack;
	vector<int> min_stack;
};


class Stack_to_queue
{
public:
	Stack_to_queue();
	~Stack_to_queue();

	void push(int in_data);
	int peek();
	int poll();
private:
	stack<int> push_stack;
	stack<int> pop_stack;
};

class Queue_to_stack
{
public:
	Queue_to_stack();
	~Queue_to_stack();

	void push(int in_data);
	int pop();
	int peek();

private:
	void swap();
	queue<int> my_queue;
	queue<int> help_queue;
};


class pet
{
public:
	pet();
	~pet();
	pet(string in_pet) { pet_type = in_pet; }
	string get_pettype();
	void set_pettype(string in_type);

private:
	string pet_type;
};

class dog :public pet
{
public:
	dog();
	~dog();

private:

};

class cat :public pet
{
public:
	cat();
	~cat();

private:

};

class pet_in_queuq
{
public:
	pet_in_queuq();
	~pet_in_queuq();

	pet_in_queuq(pet in_pet, int in_time);
	pet get_pet();
	int pet_get_intime();

private:
	pet my_pet;
	int in_time;
};



class Petqueue
{
public:
	Petqueue();
	~Petqueue();

	void add(pet in_pet);
	pet pollAll();
	dog poll_dog();
	cat poll_cat();

	bool isempty();
	bool is_dog_empty();
	bool is_cat_empty();

private:
	queue<pet_in_queuq> dog_pet;
	queue<pet_in_queuq> cat_pet;
	int time_stick;
};

void print_matrix_spiral_order(vector<vector<int> > &a, int row_num, int col_num);

void rotate_matrix(vector<vector<int> > &arr);

void print_matrix(const vector<vector<int> > &arr);

class myNode
{
public:
	myNode();
	~myNode();

	myNode(int in_data, myNode* in_next);
	myNode(int in_data);
	int data;
	myNode* next;

private:
};


class DoublemyNode
{
public:
	int data;
	DoublemyNode* next;
	DoublemyNode* pre;

	DoublemyNode();
	~DoublemyNode();

	DoublemyNode(int in_data, DoublemyNode* in_next, DoublemyNode* in_last);

private:

};



myNode* reverse_list(myNode* node);

void print_list(myNode* head);

DoublemyNode* reverse_doublelist(DoublemyNode* head);

void print_double_list(DoublemyNode* head);

void zigzag_print_matrix(vector<vector<int> > &arr);

vector<int>  find_num_in_sorted_matrix(vector<vector<int> > &arr, int num);

void print_list_common_part(myNode* head1, myNode* head2);

bool isplalindrome(myNode* head);

myNode* list_netherland(myNode* head, int pivot);

void release_list(myNode* head);

class RandomNode
{
public:
	int data;
	RandomNode* next;
	RandomNode* random;

	RandomNode();
	RandomNode(int in_data);
	~RandomNode();

private:

};

RandomNode* copy_list_with_random(RandomNode* head);

void print_randomNodelist(RandomNode* head);

myNode* find_first_intersect_node(myNode* head1, myNode* head2);