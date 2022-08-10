#ifndef HELPERS_H
#define HELPERS_H

#define array_len(arr) sizeof(arr)==0 ? 0 : sizeof(arr)/sizeof(arr[0]);

void show_array(int *array, int len);
void swap(int *x, int *y);
void copy_array(int *from_array, int *to_array, int len);

int comparator_func(const void *a, const void *b);
int compare_arrays(int *arrayA, int lenA, int *arrayB, int lenB);
#endif