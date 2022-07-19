#include<stdio.h>
#include<stdlib.h>
#include"sorting.h"

void show_array(int *array, int array_size)
{
    for(int i=0; i<array_size; i++)   
    {
        printf("%4d ", *(array+i));
    }
    puts("");
}

void swap(int* x, int* y)
{
    int temp = *y;
    *y = *x;
    *x = temp;
}

void array_copy(int* from_array, int* to_array, int length)
{
    for(int i=0; i<length; i++)
        to_array[i] = from_array[i];
    return; 
}

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
    puts("SAME ELEMENTS");
    return 1;
}