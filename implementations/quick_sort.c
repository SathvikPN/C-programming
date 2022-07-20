#include <stdio.h>
#define alen(array) (sizeof(array)==0) ? (0):(sizeof(array)/sizeof(array[0]))

void show_array(int *array, int len);
void quick_sort(int*array, int from, int to);
void swap(int *a, int *b);

int main()
{
    int array[] = {5,3,4,1,9,7,2};
    show_array(array, alen(array));
    quick_sort(array, 0, alen(array)-1);
    show_array(array, alen(array));
}

/* pivot selection. Either always low or high or random */
int select_pivot(int*array, int from, int to)
{
    return from;
}

void quick_sort(int* array, int left, int right)
{
    if (left>=right)   
        return;
    
    int pivot_idx = select_pivot(array, left, right);
    swap(&array[left], &array[pivot_idx]); /* move pivot element to leftmost */
    int pivot = left;
    int leftwall = left; 

    for (int i=leftwall+1; i<=right; i++)
    {
        if(array[i]<array[pivot])
        {
            /* from left until and including leftwall, all elements less than pivot element */
            leftwall++;
            swap(&array[i], &array[leftwall]);
        }
    }
    swap(&array[pivot], &array[leftwall]);

    /* sort two halves around pivot */
    quick_sort(array, 0, pivot-1);
    quick_sort(array, pivot+1, right);
    return;

}


/* HELPERS ------------------------------------------------*/
void show_array(int *array, int len)
{
    for(int i=0; i<len; i++)   
        printf("%4d ", *(array+i));
    puts("");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}