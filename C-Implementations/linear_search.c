#include <stdio.h>
#include <stdlib.h>

int array[] = {0,1,2,3,4,5,6,7,32,9};

void show_array(int*, int);
int linear_search(int, int*, int);

int main()
{
    int val = 32;
    int array_size = (sizeof(array)==0) ? 0:(sizeof(array)/sizeof(array[0]));
    show_array(array, array_size);
    int pos = linear_search(val, array, array_size);
    printf("%d at [%d]", val, pos);
}

int linear_search(int val, int* array, int size)
{
    if (size==0)
        return -1;

    for (int i=0; i<size; i++)
    {
        if(*(array+i)==val)
            return i;
    }
    return -1;
}


void show_array(int *array, int array_size)
{
    for(int i=0; i<array_size; i++)   
    {
        printf("%d ", *(array+i));
    }
    puts("");
}
