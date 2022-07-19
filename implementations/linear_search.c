#include <stdio.h>
#include <stdlib.h>
#define array_length(arr) ((sizeof(arr)==0) ? (0): (sizeof(arr)/sizeof(arr[0])))
int array[] = {99,1,2,38,24,5,6,7,32,9};

void show_array(int *array, int length);
void insertion_sort(int *array, int length);
void shift_element(int *array, int curr);
void swap(int *x, int *y);

int main()
{
    int n = array_length(array);
    show_array(array, n);
    insertion_sort(array, n);
    show_array(array, n);
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

void swap(int* x, int* y)
{
    int temp = *y;
    *y = *x;
    *x = temp;
}


void show_array(int *array, int array_size)
{
    for(int i=0; i<array_size; i++)   
    {
        printf("%d ", *(array+i));
    }
    puts("");
}
