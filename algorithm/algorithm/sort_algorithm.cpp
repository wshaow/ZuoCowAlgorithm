
#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stack>
#include <math.h>

#include "sort_algorithm.h"

void swap(int &a, int &b) {
	//a = a ^ b; //如果两个数相等的话交换要出问题，清零了 对于不稳定的排序不要用这种方法
	//b = a ^ b;
	//a = a ^ b;
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void bubble_sort(vector<int> &arr, int lo, int hig) { //下标从0开始
	if (hig - lo < 2) return; //后面加的

	for (int i = hig; i > lo; i--) {  // i指明了大端已排好序的位置
		for (int j = lo; j < i; j++)
			if(arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);			
	}
}

void select_sort(vector<int> &arr, int lo, int hig) {
	if (hig - lo < 2) return;

	for (int i = hig; i > lo; i--) { // i 指明了大端已排好序的位置
		int max_index = lo;
		for (int j = lo; j <= i; j++) {
			if (arr[max_index] < arr[j]) max_index = j;
		}
		swap(arr[i], arr[max_index]);
	}

}

void insert_sort(vector<int> &arr, int lo, int hig) {
	if (hig - lo < 2) return;

	for (int i = lo; i < hig; i++) { // 指明了排序区域的位置
		for (int j = i + 1; j > lo && arr[j] < arr[j - 1]; j--)
			swap(arr[j], arr[j - 1]);
	}
}

void merge(vector<int> &arr, int left, int mid, int right) {
	vector<int> help_vec(right - left + 1);
	int i, j;
	int count = 0;
	for (i = left, j = mid + 1; i <= mid && j <= right; ) { //这里是 && 而不是 || 
		if (arr[i] <= arr[j]) {							// ,第一个从left开始第二个从 mid + 1 开始 顺序不能错 例如：4,5,7
			help_vec[count++] = arr[i++];
		}
		else {
			help_vec[count++] = arr[j++]; //是j++
		}
	}

	if (i > mid) { //说明左边部分已经没有了
		while (j <= right) {
			help_vec[count++] = arr[j++];
		}
	}
	else {
		while (i <= mid) {
			help_vec[count++] = arr[i++];
		}
	}

	count = 0;
	for (i = left; i <= right; i++)
	{
		arr[i] = help_vec[count++];
	}
}

void merge_sort(vector<int> &arr, int lo, int hig) {
	if (lo == hig) return; //递归基

	int mid = lo + ((hig - lo) >> 1); //这种写法可以防止相加溢出， 稍微记一下中间是加号
	merge_sort(arr, lo, mid);  // 在这步时会一直王者里面进行直到完成
	merge_sort(arr, mid + 1, hig);
	merge(arr, lo, mid, hig);
	//cout << lo << " " << "mid:" << mid << " " << hig << endl;
}


// 归并排序迭代版，思想是自底向上； 递归版的思路是自顶向下和分治
//void merge_sort_iter(vector<int> &arr, int lo, int hig) {
//	int step = 1;
//	while (step <= 2*hig) {
//		for (int i = lo; i <= hig; i += step + 1 ) {
//			merge(arr, i, i + (step >> 1) > hig? (i + hig)>>1:i+(step>>1), i + step > hig ? hig : i + step);
//			cout << i << endl;
//		}
//		print_vector(arr);
//		step = 2*step + 1;
//		cout << step << endl;
//	}
//
//}

// 这个的思路比较清晰一点，关键是细节的处理
void merge_sort_iter(vector<int> &arr, int lo, int hig) {
	int step = 1;
	while (step <= hig) {
		for (int i = lo; i <= hig; i += 2*step) {
			int left = i;
			int mid = i + step -1;
			int right = i + 2 * step - 1;
			merge(arr, left,mid < hig ? mid:hig, right<hig ? right:hig );
		}
		step = 2 * step;
	}
}

int small_sum_merge(vector<int> &arr, int lo, int mid, int hig) {
	int cur1 = lo;
	int cur2 = mid + 1;
	int res = 0; //存储当前区间的最小和的值
	vector<int> help_vec(hig - lo + 1);
	int count = 0;
	while ((cur1 <= mid) && cur2 <= hig) {
		if (arr[cur1] < arr[cur2]) {
			res += arr[cur1] * (hig - cur2 + 1); //主要就是添加了这句话
			help_vec[count++] = arr[cur1++];
		}
		else {
			help_vec[count++] = arr[cur2++];
		}
	}

	while (cur1 <= mid) {
		help_vec[count++] = arr[cur1++];
	}

	while (cur2 <= hig) {
		help_vec[count++] = arr[cur2++];
	}

	count = 0;
	for (cur1 = lo; cur1 <= hig;) {
		arr[cur1++] = help_vec[count++];
	}

	return res;
}

// 小数问题的递归版本
int small_sum(vector<int> &arr, int lo, int hig) {
	if (lo == hig) return 0;

	int mid = lo + (hig - lo >> 1);
	return small_sum(arr, lo, mid) + small_sum(arr, mid + 1, hig) + small_sum_merge(arr, lo, mid, hig);
}

//小数问题迭代版本
int small_sum_iter(vector<int> &arr, int lo, int hig) {
	int res = 0;
	int step = 1;
	while (step <= hig) { // 这里要取到等号 例如有五个数的话要出问题
		for (int i = lo; i < hig; i += 2 * step) {
			int left = i;
			int mid = i + step - 1;
			int right = i + 2 * step - 1;
			res += small_sum_merge(arr, left, mid < hig ? mid : hig, right < hig ? right : hig);
		}
		step *= 2;
	}
	return res;
}

int inversion_pair_merge(vector<int> &arr, int left, int mid, int right) {
	int res = 0;
	int cur1 = left;
	int cur2 = mid + 1;
	vector<int> help_vec(right - left + 1);
	int count = 0;
	while (cur1 <= mid && cur2 <= right) {
		if (arr[cur1] <= arr[cur2]) {//其它的merge过程也需要把等号加上，这样排序算法才是稳定的
			help_vec[count++] = arr[cur1++];
		}
		else {
			help_vec[count++] = arr[cur2++];
			res += mid - cur1 + 1; // 当前数在左边区域逆序对的个数
			for (int i = cur1; i <= mid; i++) {
				cout << arr[i] << " " << arr[cur2-1] << endl;
			}
		}
	}

	while (cur1 <= mid) {
		help_vec[count++] = arr[cur1++];
	}

	while (cur2 <= right) {
		help_vec[count++] = arr[cur2++];
	}

	count = 0;
	for (cur1 = left; cur1 <= right;) {
		arr[cur1++] = help_vec[count++];
	}

	return res;
}

// 逆序对问题的递归版本， 迭代版本稍微改一下就可以
int inversion_pair(vector<int> &arr, int lo, int hig) {
	if (lo == hig) return 0; //递归基

	int mid = lo + (hig - lo >> 1);
	return inversion_pair(arr, lo, mid) + inversion_pair(arr, mid + 1, hig) + inversion_pair_merge(arr, lo, mid, hig);
}

// 大小数问题
int small_big_data(vector<int> &arr, int lo, int hig, int num) {
	int gre = hig + 1;
	int cur = lo;
	while (cur < gre) {
		if (arr[cur] <= num) {
			cur++;
		}
		else {
			swap(arr[cur], arr[--gre]);
		}
	}
	return cur;
}

// 荷兰国旗问题
vector<int> nether_lands_flag(vector<int> &arr, int lo, int hig, int num) {
	int le = lo - 1;
	int gre = hig + 1;
	int cur = lo;
	while (cur < gre) {
		if (arr[cur] < num) {
			swap(arr[++le], arr[cur++]); //这里也需要交换！！！和大小数问题不一样的地方
		}
		else if (arr[cur] == num) {  // 理论上来说应该把发生可能性高的往前放。这里用该放 > 的情况
			cur++;
		}
		else {
			swap(arr[cur], arr[--gre]);
		}
	}
	vector<int> res;
	res.push_back(le>lo? le:lo);
	res.push_back(gre < hig? gre: hig);
	return res;
}

void quick_sort(vector<int> &arr, int lo, int hig) {
	if (lo >= hig) return;

	// 产生一个[lo, hig]之间的随机数
	srand((int)time(0));//使用系统时间作为时间种子 0~65535

	int rand_index = rand()%(hig - lo + 1) + lo;//rand返回0到32767之间的随机数,因此这个式子返回[lo,hig]的随机数
	//cout << lo <<" "<< rand_index <<" "<< hig << endl;
	swap(arr[rand_index], arr[hig]); //这里随机的选一个数作为比较数num
	vector<int>le_gre = nether_lands_flag(arr, lo, hig, arr[hig]);
	
	quick_sort(arr, lo, le_gre[0]);
	quick_sort(arr, le_gre[1], hig);
}


void quick_sort_iter(vector<int> &arr, int lo, int hig) {
	if (hig - lo < 1) return;

	stack<int> help_stack;
	help_stack.push(lo);
	help_stack.push(hig);
	srand((int)time(0));

	while (!help_stack.empty()) {
		int right = help_stack.top(); help_stack.pop();
		int left = help_stack.top(); help_stack.pop();
		if (left < right) {
			int rand_index = rand() % (right - left + 1) + left;
			swap(arr[rand_index], arr[right]);
			vector<int> le_gre = nether_lands_flag(arr, left, right, arr[right]);

			//右区间
			help_stack.push(le_gre[1]);
			help_stack.push(right);

			//左区间
			help_stack.push(left);
			help_stack.push(le_gre[0]);
		}
	}
}

void heapInsert(vector<int> &arr, int lo, int hig) { //构建堆得过程，每次都增加第index个数到堆中
	if (hig == lo) return;

	int parent_index = hig - 1 >> 1;
	while (parent_index >= lo && arr[parent_index] < arr[hig]) {
		swap(arr[parent_index], arr[hig]);
		hig = parent_index;
		parent_index = parent_index - 1 >> 1;
	}
}

void heapfy(vector<int> &arr, int lo, int hig) {
	if (lo == hig) return;

	int left_descen = (lo << 1) + 1;

	while (left_descen <= hig) {  //这里必须要包含等于的情况
		
		int next;
		if (left_descen < hig) {
			next = arr[left_descen] >= arr[left_descen + 1] ? left_descen : (left_descen + 1);
		}
		else { //只有左孩子的情况要考虑
			next = left_descen;
		}

		if (arr[next] <= arr[lo]) break;

		swap(arr[lo], arr[next]);

		lo = next;
		left_descen = (next << 1) + 1;
	}
}

void heap_sort(vector<int> &arr, int lo, int hig) {
	for (int i = lo; i <= hig; i++) {
		heapInsert(arr, lo, i);
	}

	
	for (int i = hig; i >= lo;) {
		swap(arr[lo], arr[i]);
		heapfy(arr, lo,--i);
		print_vector(arr);
	}
}

// 计数排序
void count_sort(vector<int> &arr, int lo, int hig) {
	// 找到待排序数组中的最大值和最小值
	int min = arr[lo];
	int max = arr[lo];
	for (int i = lo; i <= hig; i++) {
		min = min < arr[i] ? min : arr[i];
		max = max > arr[i] ? max : arr[i];
	}

	//新建用于统计的篮子
	vector<int> count_bucket(max - min + 1, 0);

	// 统计
	for (int i = lo; i <= hig; i++) {
		count_bucket[arr[i] - min]++;
	}

	// 得到排序结果
	int idx = 0;
	for (int i = 0; i < count_bucket.size(); i++) {
		for (int j = 0; j < count_bucket[i]; j++) {
			arr[idx++] = min + i;
		}
	}

}

//桶排序
void bucket_sort(vector<int> &arr, int lo, int hig) {
	//构建桶
	int bucket_num = 10; //桶的数目
	vector<vector<int> > bucket(bucket_num);

	//将数据分配到桶中
	for (int i = lo; i <= hig; i++) {
		bucket[arr[i] / (bucket_num + 1)].push_back(arr[i]); //这里的分配函数也有讲究,每个之间的数据也有大小关系
	}

	//对每个桶中的数据进行排序
	for (int i = 0; i < bucket_num; i++) {
		if (!bucket[i].empty()) {
			quick_sort(bucket[i], 0, bucket[i].size() - 1);
		}
	}

	//将数据写回原数组中
	int idx = 0;
	for (int i = 0; i < bucket_num; i++) {
		if (!bucket[i].empty()) {
			for (int j = 0; j < bucket[i].size(); j++)
				arr[idx++] = bucket[i][j];
		}
	}

}


int getdigt(int num, int d) {
	return (num / (int)(pow(10, d - 1)) ) % 10;
}

//基数排序
void radix_sort(vector<int> &arr, int lo, int hig) {
	if (hig - lo < 1) return;

	//找到待排序数组中的最大值
	int max_value = arr[lo];
	for (int i = lo; i <= hig; i++) {
		if (max_value < arr[i]) max_value = arr[i];
	}

	//计算最大值的位数
	int count = 0;
	while (max_value) {
		max_value = max_value / 10;
		count++;
	}
	//cout<<"最大数位数为： " << count << endl;

	//进行基数排序
	vector<vector<int> > temp_radix(10); //存储0-9的桶
	for (int i = 1; i <= count; i++) {
		//这里对每一位使用桶排序
		for (int j = lo; j <= hig; j++) { //按照现在排序的位，将数据分配到桶中
			temp_radix[getdigt(arr[j], i)].push_back(arr[j]);
		}

		//将上面排好序的数据复制回原数数组
		int index = lo;
		for (int j = 0; j < 10; j++) {
			if (!temp_radix[j].empty()) {
				for (int k = 0; k < temp_radix[j].size(); k++) {
					arr[index++] = temp_radix[j][k];
				}
				temp_radix[j].clear();
			}
		}
		print_vector(arr);
	}
	
}


int get_bucket_num(int num, int max, int min, int len) {
	return (int)(num - min)*len / (max - min);
}
//基于桶思想的寻找排序后，两相邻数据之间的最大gap值
int get_max_gap(vector<int> &arr, int lo, int hig) {
	//找到数组中的最大值和最小值
	int max = arr[lo];
	int min = arr[lo];
	for (int i = lo + 1; i <= hig; i++) {
		if (max < arr[i]) max = arr[i];
		if (min > arr[i]) min = arr[i];
	}

	//构建N+1个桶，保证一定至少存在一个空桶，这样空桶前一个桶中的最大值，和后一个桶中的最小值就可能是我们需要的值
	int len = arr.size()+1;
	vector<int> binmax(len + 1);
	vector<int> binmin(len + 1);
	vector<bool> binempty(len + 1, true);
	//将数据分配到桶中
	for (int i = lo; i <= hig; i++) {
		int bid = get_bucket_num(arr[i], max, min, len);
		if (binempty[bid]) {
			binmin[bid] = arr[i];
			binmax[bid] = arr[i];
			binempty[bid] = false;
		}
		else {
			binmin[bid] = binmin[bid] < arr[i] ? binmin[bid] : arr[i];
			binmax[bid] = binmax[bid] > arr[i] ? binmax[bid] : arr[i];
		}
	}

	//计算相邻之间最大值和最小值之间的差值
	int max_gap = 0;
	int last_max = binmax[0];
	for (int i = 1; i <= len; i++) {
		if (!binempty[i]) {
			max_gap = max_gap > (binmin[i] - last_max) ? max_gap : (binmin[i] - last_max);
			last_max = binmax[i];
		}
	}
	cout << max_gap << endl;
	return max_gap;
}

int bin_search(vector<int> &arr, int lo, int hig, int num) {
	if (lo == hig) return -1;

	int mid = lo + (hig - lo >> 1);
	int res = -1;
	if (arr[mid] > num) {
		res = bin_search(arr, lo, mid, num);
	}
	else if (arr[mid] < num) {
		res = bin_search(arr, mid + 1, hig, num);
	}
	else {
		return mid;
	}
	return res;

}

void get_all_not_include(vector<int> &A, vector<int> &B) {
	//流程一,直接遍历
	for (int i = 0; i < B.size(); i++) {
		bool flag_include = false;
		for (int j = 0; j < A.size(); j++) {
			if (B[i] == A[j]) flag_include = true;
		}
		if (!flag_include) cout << B[i] <<" ";
	}
	cout << endl;


	//流程二：在A中进行二分查找
	for (int i = 0; i < B.size(); i++) {
		if (bin_search(A, 0, A.size() - 1, B[i]) < 0) {
			cout << B[i] << " ";
		}
	}
	cout << endl;

	//流程三采用外排的方式，这个原理和归并排序中的merge过程一样
	//cout << "流程三" << endl;
	//首先先对B排序
	quick_sort(B, 0, B.size() - 1);
	//利用外排的思想
	int point_A = 0;
	int point_B = 0;
	while (point_A < A.size() && point_B < B.size()) {
		if (B[point_B] < A[point_A]) {
			cout << B[point_B++] << " ";
		}
		else if (B[point_B] > A[point_A]) {
			point_A++;
		}
		else { //相等的时候B的值要跳过
			//point_A++; 这里不能加上这个
			point_B++;
		}
	}

	while (point_B < B.size()) {
		cout << B[point_B++] << " ";
	}

	cout << endl;

}

void print_vector(vector<int> &arr) {
	if (arr.empty()) {
		cout << "向量中没有数据!" << endl;
	}
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";

	cout << endl;
}

