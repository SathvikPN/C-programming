#include <stdio.h>
#include <stdlib.h>
#define array_length(arr) ((sizeof(arr)==0) ? (0): (sizeof(arr)/sizeof(arr[0])))
int array[] = {99,1,2,38,24,5,6,7,32,9};

void show_array(int *array, int length);
void insertion_sort(int *array, int length);
void shift_element(int *array, int curr);
void swap(int *x, int *y);
void array_copy(int* from_array, int* to_array, int length);
int comparator_func(const void *a, const void *b)
{
    /* type casting */
    int *x = (int*)(a);
    int *y = (int*)(b); 
    return (*x - *y);
}

void compare_array(int* a, int alen, int* b, int blen)
{
    if (alen!=blen)
        puts("NOT IDENTICAL");
    for (int i=0; i<alen; i++)
    {
        if (a[i]!=b[i])
            puts("NOT IDENTICAL");
    }
    puts("IDENTICAL");
}

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
    compare_array(array, array_length(array), new_array, array_length(new_array));
}

void array_copy(int* from_array, int* to_array, int length)
{
    for(int i=0; i<length; i++)
        to_array[i] = from_array[i];
    return; 
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
