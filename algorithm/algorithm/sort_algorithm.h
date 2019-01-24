#pragma once

#include <vector>
using namespace std;

void bubble_sort(vector<int> &arr, int lo, int hig);

void select_sort(vector<int> &arr, int lo, int hig);

void insert_sort(vector<int> &arr, int lo, int hig);

void merge_sort(vector<int> &arr, int lo, int hig);

void merge_sort_iter(vector<int> &arr, int lo, int hig);

int small_sum(vector<int> &arr, int lo, int hig);

int small_sum_iter(vector<int> &arr, int lo, int hig);

int inversion_pair(vector<int> &arr, int lo, int hig);

int small_big_data(vector<int> &arr, int lo, int hig, int num);

vector<int> nether_lands_flag(vector<int> &arr, int lo, int hig, int num);

void quick_sort(vector<int> &arr, int lo, int hig);

void quick_sort_iter(vector<int> &arr, int lo, int hig);

void heap_sort(vector<int> &arr, int lo, int hig);

void count_sort(vector<int> &arr, int lo, int hig);

void bucket_sort(vector<int> &arr, int lo, int hig);

void radix_sort(vector<int> &arr, int lo, int hig);

int get_max_gap(vector<int> &arr, int lo, int hig);

void get_all_not_include(vector<int> &A, vector<int> &B);

void print_vector(vector<int> &arr);