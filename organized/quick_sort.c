/* --------------------------------------------
[run]
gcc -Wall -c -g lib/helpers.c quick_sort.c
gcc -Wall helpers.o quick_sort.o -o run
./run

[clean] (WINDOWS system)
DEL *.o
DEL *.exe

*/

/* -----------------------------------------------
Quicksort: 
O(n log n) average; O(n2) worst case
• choose a pivot element
• move all elements less than pivot to one side, all elements
greater than pivot to other
• sort sides individually (recursive algorithm) 
Implemented in C standard library as qsort() in stdlib.h
void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
*/

#include"lib/helpers.h"
#include<stdio.h>
#include<stdlib.h>

void quick_sort(int start_idx, int end_idx, int *array, int array_len);
int choose_pivot_idx(int start_idx, int end_idx);

int main()
{
    int base_array[] = {1,3,2,4,6,5,7,9,8};
    int len = array_len(base_array);

    int copyA[len]; /* for inbuilt sort method */
    copy_array(base_array, copyA, len);
    qsort(copyA, len, sizeof(int), comparator_func);

    int copyB[len];
    copy_array(base_array, copyB, len);
    quick_sort(0, len-1, copyB, len);

    compare_arrays(copyA, len, copyB, len);
    show_array(copyB, len);
}

int choose_pivot_idx(int start_idx, int end_idx)
{
    return start_idx;
}

void quick_sort(int start_idx, int end_idx, int *array, int len)
{
    if (start_idx>=end_idx)
        return;

    int pivot_idx = choose_pivot_idx(start_idx, end_idx);
    int pivot_elem = array[pivot_idx];
    swap(&array[start_idx], &array[pivot_idx]);

    int mid_idx = start_idx;
    for (int i=start_idx+1; i<=end_idx; i++)
    {
        if(array[i]<=pivot_elem)
        {
            mid_idx++;
            swap(&array[mid_idx], &array[i]);
        }
    }

    /* RESTORE PIVOT (correct place in sorted form) */
    swap(&array[start_idx], &array[mid_idx]);

    /* recursive sort sides
    * leftside of pivot. [excluding pivot]
    * rightside of pivot. [excluding pivot]
    */
    quick_sort(start_idx, mid_idx-1, array, len);
    quick_sort(mid_idx+1, end_idx, array, len);
}