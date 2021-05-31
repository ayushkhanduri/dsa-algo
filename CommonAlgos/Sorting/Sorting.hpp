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
public:
    void print_vectors(vector<int> &v);
    void selection_sort(vector<int> &v);
    void bubble_sort(vector<int> &v);
    void insertion_sort(vector<int> &v);
    void merge_sort(vector<int> &v);
};
