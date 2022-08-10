/* -----------------------------------------------------------------------
[Compile-RUN instructions] "array_module/README.md"
*/

#include"array_module/helpers.h"
#include<stdio.h>
#include<stdlib.h>

int array[] = {7,4,1,8,5,2,9,6,3};
int len = array_len(array);

void shift_element(int idx);
void insertion_sort();

int main()
{
    show_array(array, len);
    insertion_sort();
    show_array(array, len);
}

void insertion_sort()
{
    if (len<=1) return;
    
    for (int i=1; i<len; i++)
    {
        if(array[i]<array[i-1])
            shift_element(i);
    }
}

void shift_element(int idx)
{
    int hold = array[idx];
    while(idx && (array[idx-1] > hold))
    {
        array[idx] = array[idx-1];
        idx--;
    }
    array[idx] = hold;

}

/*
• A simple insertion sort: O(n2)
• iterate through array until an out-of-order element found
• insert out-of-order element into correct location
• repeat until end of array reached
• Split into two functions for ease-of-use 
*/