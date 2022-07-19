#include <stdio.h>
#include <stdlib.h>
#include "sort_lib/sorting.h"

#define array_length(arr) ((sizeof(arr)==0) ? (0): (sizeof(arr)/sizeof(arr[0])))
int array[] = {99,1,2,38,24,5,6,7,32,9};


void insertion_sort(int *array, int length);
void shift_element(int *array, int curr);


int main()
{
    int n = array_length(array);
    show_array(array, n);
    int new_array[n];
    array_copy(array, new_array, n);

    insertion_sort(array, n);
    qsort(new_array, n, sizeof(new_array[0]), comparator_func);
    show_array(array, n);
    puts("Comparing custom_sort-ed and inbuilt_qsort-ed: ");
    compare_arrays(array, array_length(array), new_array, array_length(new_array));
}


void insertion_sort(int* array, int length)
{
    for(int i=0; i<length; i++)
    {
        shift_element(array, i);
    }
    puts("Insertion Sort-ed");
}

void shift_element(int *array, int curr)
{
    while((curr>0) && (array[curr-1]>array[curr]))
    {
        swap(&array[curr-1], &array[curr]);
        curr = curr-1;
    }
}
