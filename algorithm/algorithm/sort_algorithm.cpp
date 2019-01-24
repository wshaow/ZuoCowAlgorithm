
#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stack>
#include <math.h>

#include "sort_algorithm.h"

void swap(int &a, int &b) {
	//a = a ^ b; //�����������ȵĻ�����Ҫ�����⣬������ ���ڲ��ȶ�������Ҫ�����ַ���
	//b = a ^ b;
	//a = a ^ b;
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void bubble_sort(vector<int> &arr, int lo, int hig) { //�±��0��ʼ
	if (hig - lo < 2) return; //����ӵ�

	for (int i = hig; i > lo; i--) {  // iָ���˴�����ź����λ��
		for (int j = lo; j < i; j++)
			if(arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);			
	}
}

void select_sort(vector<int> &arr, int lo, int hig) {
	if (hig - lo < 2) return;

	for (int i = hig; i > lo; i--) { // i ָ���˴�����ź����λ��
		int max_index = lo;
		for (int j = lo; j <= i; j++) {
			if (arr[max_index] < arr[j]) max_index = j;
		}
		swap(arr[i], arr[max_index]);
	}

}

void insert_sort(vector<int> &arr, int lo, int hig) {
	if (hig - lo < 2) return;

	for (int i = lo; i < hig; i++) { // ָ�������������λ��
		for (int j = i + 1; j > lo && arr[j] < arr[j - 1]; j--)
			swap(arr[j], arr[j - 1]);
	}
}

void merge(vector<int> &arr, int left, int mid, int right) {
	vector<int> help_vec(right - left + 1);
	int i, j;
	int count = 0;
	for (i = left, j = mid + 1; i <= mid && j <= right; ) { //������ && ������ || 
		if (arr[i] <= arr[j]) {							// ,��һ����left��ʼ�ڶ����� mid + 1 ��ʼ ˳���ܴ� ���磺4,5,7
			help_vec[count++] = arr[i++];
		}
		else {
			help_vec[count++] = arr[j++]; //��j++
		}
	}

	if (i > mid) { //˵����߲����Ѿ�û����
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
	if (lo == hig) return; //�ݹ��

	int mid = lo + ((hig - lo) >> 1); //����д�����Է�ֹ�������� ��΢��һ���м��ǼӺ�
	merge_sort(arr, lo, mid);  // ���ⲽʱ��һֱ�����������ֱ�����
	merge_sort(arr, mid + 1, hig);
	merge(arr, lo, mid, hig);
	//cout << lo << " " << "mid:" << mid << " " << hig << endl;
}


// �鲢��������棬˼�����Ե����ϣ� �ݹ���˼·���Զ����ºͷ���
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

// �����˼·�Ƚ�����һ�㣬�ؼ���ϸ�ڵĴ���
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
	int res = 0; //�洢��ǰ�������С�͵�ֵ
	vector<int> help_vec(hig - lo + 1);
	int count = 0;
	while ((cur1 <= mid) && cur2 <= hig) {
		if (arr[cur1] < arr[cur2]) {
			res += arr[cur1] * (hig - cur2 + 1); //��Ҫ�����������仰
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

// С������ĵݹ�汾
int small_sum(vector<int> &arr, int lo, int hig) {
	if (lo == hig) return 0;

	int mid = lo + (hig - lo >> 1);
	return small_sum(arr, lo, mid) + small_sum(arr, mid + 1, hig) + small_sum_merge(arr, lo, mid, hig);
}

//С����������汾
int small_sum_iter(vector<int> &arr, int lo, int hig) {
	int res = 0;
	int step = 1;
	while (step <= hig) { // ����Ҫȡ���Ⱥ� ������������Ļ�Ҫ������
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
		if (arr[cur1] <= arr[cur2]) {//������merge����Ҳ��Ҫ�ѵȺż��ϣ����������㷨�����ȶ���
			help_vec[count++] = arr[cur1++];
		}
		else {
			help_vec[count++] = arr[cur2++];
			res += mid - cur1 + 1; // ��ǰ���������������Եĸ���
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

// ���������ĵݹ�汾�� �����汾��΢��һ�¾Ϳ���
int inversion_pair(vector<int> &arr, int lo, int hig) {
	if (lo == hig) return 0; //�ݹ��

	int mid = lo + (hig - lo >> 1);
	return inversion_pair(arr, lo, mid) + inversion_pair(arr, mid + 1, hig) + inversion_pair_merge(arr, lo, mid, hig);
}

// ��С������
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

// ������������
vector<int> nether_lands_flag(vector<int> &arr, int lo, int hig, int num) {
	int le = lo - 1;
	int gre = hig + 1;
	int cur = lo;
	while (cur < gre) {
		if (arr[cur] < num) {
			swap(arr[++le], arr[cur++]); //����Ҳ��Ҫ�����������ʹ�С�����ⲻһ���ĵط�
		}
		else if (arr[cur] == num) {  // ��������˵Ӧ�ðѷ��������Ըߵ���ǰ�š������ø÷� > �����
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

	// ����һ��[lo, hig]֮��������
	srand((int)time(0));//ʹ��ϵͳʱ����Ϊʱ������ 0~65535

	int rand_index = rand()%(hig - lo + 1) + lo;//rand����0��32767֮��������,������ʽ�ӷ���[lo,hig]�������
	//cout << lo <<" "<< rand_index <<" "<< hig << endl;
	swap(arr[rand_index], arr[hig]); //���������ѡһ������Ϊ�Ƚ���num
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

			//������
			help_stack.push(le_gre[1]);
			help_stack.push(right);

			//������
			help_stack.push(left);
			help_stack.push(le_gre[0]);
		}
	}
}

void heapInsert(vector<int> &arr, int lo, int hig) { //�����ѵù��̣�ÿ�ζ����ӵ�index����������
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

	while (left_descen <= hig) {  //�������Ҫ�������ڵ����
		
		int next;
		if (left_descen < hig) {
			next = arr[left_descen] >= arr[left_descen + 1] ? left_descen : (left_descen + 1);
		}
		else { //ֻ�����ӵ����Ҫ����
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

// ��������
void count_sort(vector<int> &arr, int lo, int hig) {
	// �ҵ������������е����ֵ����Сֵ
	int min = arr[lo];
	int max = arr[lo];
	for (int i = lo; i <= hig; i++) {
		min = min < arr[i] ? min : arr[i];
		max = max > arr[i] ? max : arr[i];
	}

	//�½�����ͳ�Ƶ�����
	vector<int> count_bucket(max - min + 1, 0);

	// ͳ��
	for (int i = lo; i <= hig; i++) {
		count_bucket[arr[i] - min]++;
	}

	// �õ�������
	int idx = 0;
	for (int i = 0; i < count_bucket.size(); i++) {
		for (int j = 0; j < count_bucket[i]; j++) {
			arr[idx++] = min + i;
		}
	}

}

//Ͱ����
void bucket_sort(vector<int> &arr, int lo, int hig) {
	//����Ͱ
	int bucket_num = 10; //Ͱ����Ŀ
	vector<vector<int> > bucket(bucket_num);

	//�����ݷ��䵽Ͱ��
	for (int i = lo; i <= hig; i++) {
		bucket[arr[i] / (bucket_num + 1)].push_back(arr[i]); //����ķ��亯��Ҳ�н���,ÿ��֮�������Ҳ�д�С��ϵ
	}

	//��ÿ��Ͱ�е����ݽ�������
	for (int i = 0; i < bucket_num; i++) {
		if (!bucket[i].empty()) {
			quick_sort(bucket[i], 0, bucket[i].size() - 1);
		}
	}

	//������д��ԭ������
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

//��������
void radix_sort(vector<int> &arr, int lo, int hig) {
	if (hig - lo < 1) return;

	//�ҵ������������е����ֵ
	int max_value = arr[lo];
	for (int i = lo; i <= hig; i++) {
		if (max_value < arr[i]) max_value = arr[i];
	}

	//�������ֵ��λ��
	int count = 0;
	while (max_value) {
		max_value = max_value / 10;
		count++;
	}
	//cout<<"�����λ��Ϊ�� " << count << endl;

	//���л�������
	vector<vector<int> > temp_radix(10); //�洢0-9��Ͱ
	for (int i = 1; i <= count; i++) {
		//�����ÿһλʹ��Ͱ����
		for (int j = lo; j <= hig; j++) { //�������������λ�������ݷ��䵽Ͱ��
			temp_radix[getdigt(arr[j], i)].push_back(arr[j]);
		}

		//�������ź�������ݸ��ƻ�ԭ������
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
//����Ͱ˼���Ѱ�����������������֮������gapֵ
int get_max_gap(vector<int> &arr, int lo, int hig) {
	//�ҵ������е����ֵ����Сֵ
	int max = arr[lo];
	int min = arr[lo];
	for (int i = lo + 1; i <= hig; i++) {
		if (max < arr[i]) max = arr[i];
		if (min > arr[i]) min = arr[i];
	}

	//����N+1��Ͱ����֤һ�����ٴ���һ����Ͱ��������Ͱǰһ��Ͱ�е����ֵ���ͺ�һ��Ͱ�е���Сֵ�Ϳ�����������Ҫ��ֵ
	int len = arr.size()+1;
	vector<int> binmax(len + 1);
	vector<int> binmin(len + 1);
	vector<bool> binempty(len + 1, true);
	//�����ݷ��䵽Ͱ��
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

	//��������֮�����ֵ����Сֵ֮��Ĳ�ֵ
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
	//����һ,ֱ�ӱ���
	for (int i = 0; i < B.size(); i++) {
		bool flag_include = false;
		for (int j = 0; j < A.size(); j++) {
			if (B[i] == A[j]) flag_include = true;
		}
		if (!flag_include) cout << B[i] <<" ";
	}
	cout << endl;


	//���̶�����A�н��ж��ֲ���
	for (int i = 0; i < B.size(); i++) {
		if (bin_search(A, 0, A.size() - 1, B[i]) < 0) {
			cout << B[i] << " ";
		}
	}
	cout << endl;

	//�������������ŵķ�ʽ�����ԭ��͹鲢�����е�merge����һ��
	//cout << "������" << endl;
	//�����ȶ�B����
	quick_sort(B, 0, B.size() - 1);
	//�������ŵ�˼��
	int point_A = 0;
	int point_B = 0;
	while (point_A < A.size() && point_B < B.size()) {
		if (B[point_B] < A[point_A]) {
			cout << B[point_B++] << " ";
		}
		else if (B[point_B] > A[point_A]) {
			point_A++;
		}
		else { //��ȵ�ʱ��B��ֵҪ����
			//point_A++; ���ﲻ�ܼ������
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
		cout << "������û������!" << endl;
	}
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";

	cout << endl;
}

