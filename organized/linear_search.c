/* --------------------------------------------
[run]
gcc -Wall -c -g lib/helpers.c linear_search.c
gcc -Wall helpers.o linear_search.o -o run
./run

[clean] (WINDOWS system)
DEL *.o
DEL *.exe

*/

#include"lib/helpers.h"
#include<stdio.h>
#include<stdlib.h>

void linear_search(int key, int *array, int array_len);

int main()
{
    int array[] = {1,2,3,4,5};
    int len = array_len(array);
    show_array(array, len);
    linear_search(2, array, len);
    linear_search(99, array, len);
    return 0;
}

void linear_search(int key, int *array, int len)
{
    for(int i=0; i<len; i++)
        if (array[i]==key)
        {
            printf("[FOUND]  %d at idx %d\n", key, i);
            return;
        }
    printf("[NOT_FOUND] %d", key);
}
