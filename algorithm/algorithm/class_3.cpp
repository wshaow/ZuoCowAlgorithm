#include "stdafx.h"
#include"class_3.h"
#include<climits>
#include<iostream>
#include<map>

Array_to_stack::Array_to_stack()
{
	//默认大小为10
	_stack = new int[10];
	_total_size = 10;
	_size = 0;
}

Array_to_stack::Array_to_stack(int init_size) {
	if (init_size < 1) {
		_stack = 0;
		_total_size = 0;
		return;
	}

	_stack = new int[init_size];
	_total_size = init_size;
	_size = 0;
}

Array_to_stack::~Array_to_stack()
{
	if (_stack) delete[] _stack;
}

int Array_to_stack::peek() {
	if (_size < 1) return INT_MIN;

	return _stack[_size - 1];
}

void Array_to_stack::push(int in_data) {
	if (_size == _total_size) return;

	_stack[_size++] = in_data;
}

void Array_to_stack::pop() {
	if (_size < 1) return;

	_size--;
}


Array_to_queue::Array_to_queue()
{
	_total_size = 10;
	_queue = new int[_total_size];
	_size = 0;
	_first = 0;
	_last = 0;
}

Array_to_queue::Array_to_queue(int init_size) {
	if (init_size < 1) return;

	_queue = new int[init_size];
	_total_size = init_size;
	_size = 0;
	_first = 0;
	_last = 0; //指向的是下一个要填充的位置
}

Array_to_queue::~Array_to_queue()
{
	if (_queue) delete[]_queue;
}

int Array_to_queue::peek() {
	if (_size == 0) return INT_MIN;

	return _queue[_first]; 
}

int Array_to_queue::poll() {
	if (_size == 0) return INT_MIN;

	int temp = _first;
	_first = (_first + 1) < _total_size ? _first + 1: _total_size - 1;
	_size--; //不要忘记加加减减
	return _queue[temp];
}

void Array_to_queue::push(int in_data) {
	if (_size == _total_size) return;

	_size++;
	_queue[_last] = in_data;
	_last = (_last + 1) < _total_size ? _last + 1 : _total_size;
}

GetMinStack::GetMinStack()
{
}

GetMinStack::~GetMinStack()
{
}

void GetMinStack::push(int in_data) {

	if (my_stack.empty()) {
		min_stack.push_back(in_data);
	}
	else {
		//最简单粗暴的实现方法，来一个数据比较是否比当前栈中的数据的最小值小，若是则最小栈压入该数，否则压入之前的最小值
		min_stack.push_back(in_data < min_stack[min_stack.size() - 1] ? in_data : min_stack[min_stack.size() - 1]);
		//第二种实现方法是：如果不小于则不压入，否则压入，出栈的时候要判断与出栈数据的关系
	}

	my_stack.push_back(in_data);
}

int GetMinStack::pop() {
	if (my_stack.empty())
	{
		return -1;
	}
	min_stack.pop_back();
	int res = my_stack[my_stack.size() - 1];
	my_stack.pop_back();

	return res;
}
int GetMinStack::get_min() {
	if (min_stack.empty()) return -1;
	return min_stack[min_stack.size() - 1];
}

Stack_to_queue::Stack_to_queue()
{
}

Stack_to_queue::~Stack_to_queue()
{
}

void Stack_to_queue::push(int in_data) {
	push_stack.push(in_data);
}
int Stack_to_queue::peek() {
	if (pop_stack.empty()) {
		while (!push_stack.empty()) {
			pop_stack.push(push_stack.top());
			push_stack.pop();
		}
	}
	if (pop_stack.empty()) return -1;
	return pop_stack.top();
}
int Stack_to_queue::poll() {
	if (pop_stack.empty()) {
		while (!push_stack.empty()) {
			pop_stack.push(push_stack.top());
			push_stack.pop();
		}
	}
	if (pop_stack.empty()) return -1;
	int res = pop_stack.top();
	pop_stack.pop();
	return res;
}

Queue_to_stack::Queue_to_stack()
{
}

Queue_to_stack::~Queue_to_stack()
{
}

void Queue_to_stack::push(int in_data) {
	my_queue.push(in_data);
}
int Queue_to_stack::pop() {
	if (my_queue.empty()) return -1;

	while (my_queue.size() != 1) { //不要把这里的条件搞错
		help_queue.push(my_queue.front());
		my_queue.pop();
	}

	int res = my_queue.front();
	my_queue.pop();
	//交换两个queue
	swap();
	return res;
}
int Queue_to_stack::peek() {
	if (my_queue.empty()) return -1;
	return my_queue.back();
}

void Queue_to_stack::swap() {
	my_queue.swap(help_queue);
}


pet::pet()
{
}

pet::~pet()
{
}

string pet::get_pettype() {
	return pet_type;

}
void pet::set_pettype(string in_type) {
	pet_type = in_type;
}

dog::dog()
{
	set_pettype("dog");
}

dog::~dog()
{
}

cat::cat()
{
	set_pettype("cat");
}

cat::~cat()
{
}

pet_in_queuq::pet_in_queuq()
{
}

pet_in_queuq::~pet_in_queuq()
{
}

pet_in_queuq::pet_in_queuq(pet in_pet, int in_time) {
	my_pet.set_pettype(in_pet.get_pettype());
	this->in_time = in_time;
}
pet pet_in_queuq::get_pet() {
	return my_pet;
}
int pet_in_queuq::pet_get_intime() {
	return in_time;
}

Petqueue::Petqueue()
{
	time_stick = 0;
}

Petqueue::~Petqueue()
{
}

void Petqueue::add(pet in_pet) {
	pet_in_queuq temp_petin(in_pet, time_stick++);
	if (temp_petin.get_pet().get_pettype() == "dog")
	{
		dog_pet.push(temp_petin);
	}
	else {
		cat_pet.push(temp_petin);
	}

}
pet Petqueue::pollAll() {
	if (!(dog_pet.empty() && cat_pet.empty())) {
		if (dog_pet.empty()) {
			pet res = cat(); cat_pet.pop();
			return res;
		}
		else if (cat_pet.empty()) {
			pet res = dog(); dog_pet.pop();
			return res;
		}
		else if (dog_pet.front().pet_get_intime() < cat_pet.front().pet_get_intime()) {
			pet res = dog(); dog_pet.pop();
			return res;
		}
		else {
			pet res = cat(); cat_pet.pop();
			return res;
		}
	}
	else{
		cout << "No Pet!" << endl;
		pet res_dog("No Pet!");
		return res_dog;
	}

}
dog Petqueue::poll_dog() {
	if (dog_pet.empty())
	{
		dog res;
		res.set_pettype("No dog pet!");
		return res;
	}
	else {
		dog res = dog(); dog_pet.pop();
		return res;
	}
}
cat Petqueue::poll_cat() {
	if (cat_pet.empty())
	{
		cat res;
		res.set_pettype("No cat pet!");
		return res;
	}
	else {
		cat res = cat(); dog_pet.pop();
		return res;
	}
}

bool Petqueue::isempty() {
	if (dog_pet.empty() && cat_pet.empty()) {
		return true;
	}
	else {
		return false;
	}
}
bool Petqueue::is_dog_empty() {
	if (dog_pet.empty()) {
		return true;
	}
	else {
		return false;
	}
}
bool Petqueue::is_cat_empty() {
	if (cat_pet.empty()) {
		return true;
	}
	else
	{
		return false;
	}
}


void print_matrix_spiral_order(vector<vector<int> >& a, int row_begin, int row_end, int col_begin, int col_end) {
	if ((row_begin > row_end) || (col_begin > col_end)) return;

	for (int i = col_begin; i <= col_end; i++) {
		cout << a[row_begin][i] << " ";
	}
	for (int i = row_begin+1; i <= row_end; i++) { //起始+1
		cout << a[i][col_end] << " ";
	}
	for (int i = col_end-1; i >= col_begin; i--) { //开始位置减1
		cout << a[row_end][i] << " ";
	}
	for (int i = row_end-1; i> row_begin; i--) //开始位置减1，且最后一个不打印
	{
		cout << a[i][col_begin] << " ";
	}
	print_matrix_spiral_order(a, ++row_begin, --row_end, ++col_begin, --col_end);
}

//这里的实现方法是采用递归的方式求解，也可以使用迭代的方法求解，只要用一个while（!(row_begin > row_end) || (col_begin > col_end)）就可以了
void print_matrix_spiral_order(vector<vector<int> >& a, int row_num, int col_num) {
	print_matrix_spiral_order(a, 0, row_num - 1, 0, col_num - 1);
}

void rotate_matrix(vector<vector<int> > &arr, int row_begin, int row_end, int col_begin, int col_end) {
	int times = row_end - row_begin;
	for (int i = 0; i < times; i++) //这里不能取到等于号
	{
		int temp = arr[row_begin][col_begin + i];

		arr[row_begin][col_begin + i] = arr[row_end - i][col_begin];
		arr[row_end - i][col_begin] = arr[row_end][col_end - i];
		arr[row_end][col_end - i] = arr[row_begin+i][col_end];
		arr[row_begin+i][col_end] = temp;
	}
}

void rotate_matrix(vector<vector<int> > &arr) {
	int row_begin = 0;
	int col_begin = 0;
	int row_end = arr.size() - 1;
	int col_end = arr.size() - 1; //因为是正方形矩阵起始可以直传两个参数
	while (row_begin <= row_end) {
		rotate_matrix(arr, row_begin++, row_end--, col_begin++, col_end--);
	}
}

void print_matrix(const vector<vector<int> > &arr) {
	cout << "[";
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			cout << arr[i][j] << ",";
		}
		cout << endl;
	}
	cout << "]" << endl;
}


myNode::~myNode()
{
}

myNode::myNode() { next = 0; }

myNode::myNode(int in_data) { data = in_data; }

myNode::myNode(int in_data, myNode* in_next) { data = in_data; next = in_next; }

DoublemyNode::DoublemyNode() { next = 0; pre = 0; }

DoublemyNode::DoublemyNode(int in_data, DoublemyNode* in_next, DoublemyNode* in_last) {
	data = in_data;
	next = in_next;
	pre = in_last;
}

DoublemyNode::~DoublemyNode() {
}


//使用pre和next的写法很简洁
myNode* reverse_list(myNode* node) {
	myNode* pre = NULL;
	myNode* next = NULL;

	while (node) {
		next = node->next;
		node->next = pre;

		pre = node;
		node = next;
	}
	return pre;//因为此时node为null
}

DoublemyNode* reverse_doublelist(DoublemyNode* head) {
	DoublemyNode* pre = NULL;
	DoublemyNode* next = NULL;

	while (head) {
		next = head->next;
		head->next = pre;
		head->pre = next;

		pre = head;
		head = next;
	}
	return pre;
}

void print_list(myNode* head) {
	//判断是否有环
	if (head == NULL) {
		cout << "链表中没有数据！";
		return;
	}
	else if (head->next == NULL) {
		cout << "无环链表打印" << endl;
		cout << head->data << " " << endl;
		return;
	}
	else if (head->next->next == NULL) {
		cout << "无环链表打印" << endl;
		cout << head->data << " " << head->next->data << " " << endl;
		return;
	}
	bool is_loop = true;

	myNode* slow = head->next;
	myNode* fast = head->next->next;
	while (slow != fast) {
		if (fast->next == NULL || fast->next->next == NULL) { //前后都是fast
			is_loop = false;
			break;//记得break
		}
		slow = slow->next;
		fast = fast->next->next;
	}

	if (is_loop) {
		cout << "有环链表：" << endl;
		//找到入环的节点
		fast = head;
		while (fast != slow) {
			fast = fast->next;
			slow = slow->next;
		}

		int pass_num = 0;
		fast = head;
		while ( fast != slow || pass_num != 1 ) {
			cout << fast->data << " ";
			if (fast == slow) {
				pass_num++;
			}
			fast = fast->next;
		}

		cout << "返回到" << fast->data << endl;
	}
	else {
		cout << "无环链表打印" << endl;
		myNode* temp = head;
		while (temp) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

}

void print_double_list(DoublemyNode* head) {
	DoublemyNode* temp = head;
	while (temp) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}


void zigzag_print_matrix(vector<vector<int> > &arr, int ur, int uc, int dr, int dc, bool f) {
	if (f) {//从下往上遍历
		while ((ur - 1 != dr)) {
			cout << arr[dr--][dc++] << " ";
		}
	}
	else {
		while ((ur != dr + 1)) {
			cout << arr[ur++][uc--] << " ";
		}
	}
}

//尽量用等于与不等于来做条件判断
void zigzag_print_matrix(vector<vector<int> > &arr) {
	int up_row = 0; 
	int up_col = 0;
	int down_row = 0; 
	int down_col = 0;

	int end_row = arr.size() - 1;
	int end_col = arr[0].size() - 1;

	bool to_up = true;
	while (down_col != end_col + 1) {//感觉这个退出条件有问题
		zigzag_print_matrix(arr, up_row, up_col, down_row, down_col, to_up);
		//这里更新顺序不能错， 先更新非判决条件的变量，否则在等于时要出错
		up_row = up_col == end_col ? up_row + 1 : up_row;
		up_col = up_col == end_col ? up_col : up_col + 1;

		down_col = down_row == end_row ? down_col + 1 : down_col;
		down_row = down_row == end_row ? down_row : down_row + 1;
		
		to_up = !to_up;
	}
}


//void bin_search(vector<vector<int> > &arr, int row, int col, int begin_index, int num) {
//
//}

//普通的方法就是从右上角开始搜索，这里可以使用二分搜索的方法，这样时间复杂度为O(logN+logM) 貌似不是这个复杂度
//二分查找，如果找到了直接返回对应的index，否则返回最后一个比要查找值最小的数，细想发现这样貌似反而复杂了
vector<int>  find_num_in_sorted_matrix(vector<vector<int> > &arr, int num) {
	int row = 0;
	int col = arr[0].size() - 1;
	while (col > -1 && row != arr.size()) {
		if (arr[row][col] == num) {
			vector<int> res;
			res.push_back(row);
			res.push_back(col);
			return res;
		}
		else if (arr[row][col] < num) {
			row++;
		}
		else {
			col--;
		}
	}

	vector<int> res;
	return res;
}

void print_list_common_part(myNode* head1, myNode* head2) {
	while (head1 && head2) {
		if (head1->data < head2->data) {
			head1 = head1->next;
		}
		else if (head1->data > head2->data) {
			head2 = head2->next;
		}
		else {//这里不用考虑多个重复的情况，因为只要打印一次两个链表中共有的数据就可以了
			cout << head2->data << " ";
			head1 = head1->next;
			head2 = head2->next;
		}
	}
	cout << endl;
}

bool isplalindrome(myNode* head) {
	int solution = 2;
	switch (solution)
	{
	case 0: {//方案一，直接利用辅助栈
		stack<int> help_stack;
		myNode* temp = head;
		while (head) {
			help_stack.push(head->data);
			head = head->next;
		}
		head = temp;
		while (head) {
			if (head->data != help_stack.top()) {
				return false;
			}
			head = head->next;
			help_stack.pop();
		}
		return true;
	}
	case 1: {//方案二，利用快慢指针和辅助栈
		myNode* slow = head->next;
		myNode* fast = head;

		//找到中间位置即slow所在的位置,此时slow就是下半部分所在的起始位置
		while (fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		//入栈
		stack<int> help_stack;
		while (slow) {
			help_stack.push(slow->data);
			slow = slow->next;
		}

		//对比
		while (help_stack.empty()) {
			if (head->data != help_stack.top()) {
				return false;
			}
			head = head->next;
			help_stack.pop();
		}
		return true;
	}
	case 2: {//改变链表结构法
		myNode* slow = head->next;
		myNode* fast = head;
		while (fast->next && fast->next->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		//从slow处将链表进行反转
		myNode* pre = NULL;
		myNode* next = NULL;
		while (slow) {
			next = slow->next;
			slow->next = pre;

			pre = slow;
			slow = next;
		}

		myNode* right_head = pre;//保存右半边的头结点，由于之后的反转
		//比较,pre是后半部分的反转值
		while (pre) {
			if (pre->data != head->data)
			{
				//将链表反转回去
				pre = NULL;
				next = NULL;
				while (right_head) {
					next = right_head->next;
					right_head->next = pre;

					pre = right_head;
					right_head = next;

				}
				return false;
			}
			pre = pre->next;
			head = head->next;

		}
		pre = NULL;
		next = NULL;
		while (right_head) {
			next = right_head->next;
			right_head->next = pre;

			pre = right_head;
			right_head = next;
		}

		return true;
	}
	default:
		break;
	}
}

myNode* list_netherland(myNode* head, int pivot) {
	myNode* small_head = NULL;
	myNode* small_tail = NULL;
	myNode* equ_head = NULL;
	myNode* equ_tail = NULL;
	myNode* big_head = NULL;
	myNode* big_tail = NULL;

	while (head)
	{
		if (head->data < pivot) {
			if (small_head) {
				small_tail->next = head;
				small_tail = head;
			}
			else
			{
				small_head = head;
				small_tail = head;
			}
		}
		else if (head->data == pivot) {
			if (equ_head) {
				equ_tail->next = head;
				equ_tail = head;
			}
			else {
				equ_head = head;
				equ_tail = head;
			}
		}
		else {
			if (big_head) {
				big_tail->next = head;
				big_tail = head;
			}
			else {
				big_head = head;
				big_tail = head;
			}
		}
		head = head->next;
	}
	
	if (small_head) {
		if (equ_head) {
			small_tail->next = equ_head;
			if (big_head) {
				equ_tail->next = big_head;
				big_tail->next = NULL;
			} else 	equ_tail->next = NULL;
		}
		else {
			if (big_head) {
				small_tail->next = big_head;
				big_head->next = NULL;
			}
			else small_tail->next = NULL;
		}

		return small_head;
	}
	else if(equ_head){
		if (big_head) {
			equ_tail->next = big_head;
			big_tail->next = NULL;
		}else equ_tail->next = NULL;
		
		return equ_head;
	}else
	{
		big_tail->next = NULL;
		return big_head;
	}

}

void release_list(myNode* head) {
	while (head) {
		myNode* temp = head->next;
		delete head;
		head = temp;
	}
}

RandomNode::RandomNode()
{
}

RandomNode::~RandomNode()
{
}

RandomNode::RandomNode(int in_data) {
	data = in_data;
}


RandomNode* copy_list_with_random(RandomNode* head) {
	int solution = 1;
	switch (solution)
	{
	case 0: {//利用哈希表的求解方案
		RandomNode* cur = head;
		map<RandomNode*, RandomNode*> Node_map;

		while (cur) {
			RandomNode* temp;
			Node_map[cur] = new RandomNode(cur->data);
			if (cur->next) { //加判断， 稍微有点重复
				Node_map[cur->next] = new RandomNode(cur->next->data);
			}
			
			if (cur->random) {//加判断
				Node_map[cur->random] = new RandomNode(cur->random->data);
			}
			cur = cur->next;
		}

		cur = head;
		while (cur) {
			Node_map[cur]->next = Node_map[cur->next];
			if (cur->random) {
				Node_map[cur]->random = Node_map[cur->random];
			}
			else {
				Node_map[cur->random] = NULL;
			}
			
			cur = cur->next;
		}

		return Node_map[head];
	}
	case 1: {//不使用额外的数据结构
		RandomNode* cur = head;
		while (cur) {//将每个节点的复制节点添加到其后
			RandomNode* copy_node = new RandomNode(cur->data);
			RandomNode* next = cur->next;
			cur->next = copy_node;
			copy_node->next = next;

			cur = next;//老是忘记更新
		}
		cur = head;
		RandomNode* new_head = head->next;
		while (cur)
		{
			RandomNode* add_node = cur->next;
			if (cur->random) {
				add_node->random = cur->random->next;
			}
			else {
				add_node->random = NULL;
			}

			//分离
			cur->next = add_node->next; //这里已经将cur_next更新了
			if (add_node->next)
				add_node->next = add_node->next->next;
			cur = cur->next;
		}
		return new_head;
		break;
	}
	default:
		break;
	}
	
}

void print_randomNodelist(RandomNode* head) {
	if (!head) {
		cout << "没有数据" << endl;
		return;
	}

	cout << " Order: ";
	RandomNode* cur = head;
	while (cur) {
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << endl;

	cout << "Random: ";
	cur = head;
	while (cur) {
		if (cur->random) {
			cout << cur->random->data<<" ";
		}
		else {
			cout << "-" << " ";
		}
		cur = cur->next;
	}
	cout << endl;
}

myNode* get_first_loop_node(myNode* head) {//获取链表入环的第一个节点
	myNode* cur = head;
	if (cur == NULL || cur->next == NULL || cur->next->next == NULL) {
		return NULL;
	}

	myNode* slow = cur->next; //要保证每一个变量的值有效的
	myNode* fast = cur->next->next;// 定义快慢指针

	while (slow != fast) {
		if (fast->next == NULL || fast->next->next == NULL) {
			return NULL;
		}

		slow = slow->next;
		fast = fast->next->next;
	}
	//到这里说明有环
	fast = head; //快节点回到头节点，步长变为1
	while (fast != slow) {
		fast = fast->next;
		slow = slow->next;
	}
	return slow;

}

myNode* no_loop(myNode* head1, myNode* head2) {
	int length1 = 1;
	int length2 = 1;

	myNode* cur = head1;
	while (cur->next) {
		length1++;
		cur = cur->next;
	}

	myNode* cur2 = head2;
	while (cur2->next) {
		length2++;
		cur2 = cur2->next;
	}

	if (cur != cur2) {
		return NULL;
	}

	int  diff_length = length1 > length2 ? length1 - length2 : length2 - length1;
	cur = length1 > length2 ? head1 : head2;

	while (diff_length--) {//长的先走掉长的那部分
		cur = cur->next;
	}

	cur2 = length1 <= length2 ? head1 : head2;
	while (cur != cur2) {
		cur = cur->next;
		cur2 = cur2->next;
	}

	return cur;
}

myNode* both_loop(myNode* head1, myNode* loop_node1, myNode* head2, myNode* loop_node2) {
	
	if (loop_node1 == loop_node2) {//若果两个有环链表的入环节点为同一个
		int length1 = 1;
		int length2 = 1;

		myNode* cur1 = head1;
		myNode* cur2 = head2;
		while (cur1 != loop_node1) {
			cur1 = cur1->next;
			length1++;
		}

		while (cur2 != loop_node2)
		{
			cur2 = cur2->next;
			length2++;
		}

		int diff_length = length1 > length2 ? length1 - length2 : length2 - length1;
		cur1 = length1 > length2 ? head1 : head2;
		cur2 = length1 <= length2 ? head1 : head2;

		while (diff_length--) {
			cur1 = cur1->next;
		}

		while (cur1 != cur2) {
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return cur1;

	}
	else {//两个节点不同的话
		//判断它们是否相交
		myNode* cur = loop_node1->next;
		while (cur != loop_node1)
		{
			if (cur == loop_node2)
			{
				return loop_node1;
			}
			cur = cur->next;
		}
		return NULL;
	}
}

myNode* find_first_intersect_node(myNode* head1, myNode* head2) {
	if (head1 == NULL || head2 == NULL) {
		return NULL;
	}
	myNode* n1 = get_first_loop_node(head1);
	myNode* n2 = get_first_loop_node(head2);

	if (n1 != NULL && n2 != NULL) {//两个单链表都有环的情况
		return both_loop(head1, n1, head2, n2);
	}
	else if (n1 == NULL && n1 == NULL) {//两个单链表都为无环的情况
		return no_loop(head1, head2);
	}

}