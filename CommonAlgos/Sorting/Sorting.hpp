/**
 *
 * 1) Selection sort : The selection sort algorithm sorts an array by repeatedly finding the minimum element
                       (considering ascending order)from unsorted part and putting it at the beginning.
 * 2) Bubble sort
 * 3) Insertion sort
 * 4) Merge sort
 * 5) Quick sort
 * 6) Heap sort
 * 7) Radix sort
 *
 * */

#pragma once


#include "vector"

using namespace std;


class Sorting {
private:
    void swap_value(int from , int to, vector<int> &v);
    void shift_array(int from , int to, vector<int> &v);
    vector<int> sliceVector(vector<int> a, int start, int end);
    vector<int> merge_sort_recursion(vector<int> v);
    vector<int> merge_vectors(vector<int> vectorLeft, vector<int> vectorRight);
    int perform_quicksort(vector<int> &v, int start, int end);
    void quick_sort_recursion(vector<int> &v, int start, int end);
public:
    void print_vectors(vector<int> &v);
    void selection_sort(vector<int> &v);
    void bubble_sort(vector<int> &v);
    void insertion_sort(vector<int> &v);
    vector<int> merge_sort(vector<int> v);
    vector<int> quick_sort(vector<int> v);
};
