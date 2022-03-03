/* 
Quicksort: O(n log n) average; O(n2) worst case
• choose a pivot element
• move all elements less than pivot to one side, all elements
greater than pivot to other
• sort sides individually (recursive algorithm) 

Implemented in C standard library as qsort() in stdlib.h
*/

#include<stdio.h>
#define array_length(arr) ( (sizeof(arr)==0)? (0):( sizeof(arr)/sizeof(arr[0]) ) )

void swap(int*, int*);
void quick_sort(unsigned int left_idx, unsigned int right_idx);
void print_array();

int arr[] = {7,4,1,2,5,8,9,6,3};

int main()
{
   print_array();
   quick_sort(0, array_length(arr)-1);
   print_array();
   return 0;
}

void swap(int *x, int *y)
{
   int temp = *x;
   *x = *y;
   *y = temp;
}

void print_array()
{
   int len = array_length(arr);
   
   for(int i=0; i<len; i++)
      printf("%d ", arr[i]);

   puts("");
}

void quick_sort(unsigned int left, unsigned int right)
{
   unsigned int i;
   unsigned int mid;
   int pivot;

   if (left>=right)
      return; // nothing to sort

   /* pivot is midpoint. Move to left side */
   swap(arr+left, arr+(left+right)/2);
   pivot = arr[mid=left];

/* separate into 
side<pivot(left+1 to mid)
side>=pivot(mid+1 to right)*/

   for(i=left+1; i<=right; i++)
   {
      if(arr[i]<pivot)
         swap(arr + (++mid), arr+i);
   }

   /* Restore pivot */
   swap(arr+left, arr+mid);

   /* sort two sides */
   if (mid>left)
      quick_sort(left, mid-1);

   if (mid<right)
      quick_sort(mid+1, right);


}

/* Discussion ----------------------------------------------
• Not stable (equal-valued elements can get switched) in
present form
• Can sort in-place – especially desirable for low-memory
environments
• Choice of pivot influences performance; can use random
pivot
• Divide and conquer algorithm; easily parallelizeable
• Recursive; in worst case, can cause stack overflow on
large array 

*/
