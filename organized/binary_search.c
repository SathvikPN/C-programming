/* --------------------------------------------
[run]
gcc -Wall -c -g lib/helpers.c binary_search.c
gcc -Wall helpers.o binary_search.o -o run
./run

[clean] (WINDOWS system)
DEL *.o
DEL *.exe

*/

#include"lib/helpers.h"
#include<stdio.h>
#include<stdlib.h>

void binary_search(int key, int *array, int array_len);
int main()
{
    int array[] = {1,3,2,4,6,5,7,9,8};
    int len = array_len(array);
    qsort(array, len, sizeof(array[0]), comparator_func);
    show_array(array, len);
    binary_search(37, array, len);
}

void binary_search(int key, int *array, int len)
{
    /* iterative */
    int left=0, right=len-1;
    int mid;
    while(left<=right)
    {
        mid = left + ((right-left)/2);
        if (array[mid]==key)
        {
            printf("[FOUND] key:%d  idx:%d\n", key, mid);
            return;
        }

        if (key<array[mid])
            right = mid-1;
        else
            left = mid+1;
    }
    printf("[NOT_FOUND] key:%d\n", key);
}