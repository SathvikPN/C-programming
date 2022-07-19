#ifndef SORTING_H
#define SORTING_H

void show_array(int *array, int length);
void swap(int *x, int *y);
void array_copy(int* from_array, int* to_array, int length);
int comparator_func(const void *a, const void *b);
int compare_arrays(int*arrayA, int lenA, int*arrayB, int lenB);
#endif