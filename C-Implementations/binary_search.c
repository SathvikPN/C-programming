/* 
Binary Search
• Worst case: logarithmic time
• Requires random access to array memory
• on sequential data, like hard drive, can be slow
• seeking back and forth in sequential memory is wasteful
• better off doing linear search in some cases
• Implemented in C standard library as bsearch() in stdlib.h
*/

#include<stdio.h>
#define array_length(arr) ( (sizeof(arr)==0)? (0):( sizeof(arr)/sizeof(arr[0]) ) )

int binary_search(int);
void print_array();

int arr[] = {13,26,39,52,65,78};

int main()
{
   print_array();
   printf("%d at idx %d", 26, binary_search(26));
   return 0;
}


void print_array()
{
   int len = array_length(arr);
   for(int i=0; i<len; i++)
   {
      printf("%d ", arr[i]);
   }
   puts("");
}

int binary_search(int val)
{
   int left = 0;
   int right = array_length(arr)-1;

   while(left<=right)
   {
      int mid = (left+right)/2;

      if (arr[mid]==val)
         return mid;

      if (arr[mid]<val)
         left = mid+1;
      
      else  
         right = mid-1;
   }

   return -1;
}
