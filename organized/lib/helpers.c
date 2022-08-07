#include<stdio.h>
#include<stdlib.h>
#include"helpers.h"

#define array_len(arr) sizeof(arr)==0 ? 0 : sizeof(arr)/sizeof(arr[0]);

void show_array(int *array, int array_len)
{
    for(int i=0; i<array_len; i++)
        printf("%4d", array[i]);
    
    puts("[END]");
}


void swap(int *x, int *y)
{
    int temp = *y;
    *y = *x;
    *x = temp;
}

void copy_array(int *from_array, int *to_array, int len)
{
    for(int i=0; i<len; i++)
        to_array[i] = from_array[i];
}


/* defined for integers only */
int comparator_func(const void *a, const void *b)
{
    /* type casting */
    int *x = (int*)(a);
    int *y = (int*)(b); 
    return (*x - *y);
}

int compare_arrays(int*arrayA, int lenA, int*arrayB, int lenB)
{
    if(lenA!=lenB)
    {
        puts("MISMATCH LENGTH");
        return 0;
    }
        
    for(int i=0; i<lenA; i++)
    {
        if(arrayA[i]!=arrayB[i])
        {
            printf("MISMATCH ELEMENT at idx [%d]\n", i);
            return 0;
        }
    }
    puts("IDENTICAL ELEMENTS");
    return 1;
}