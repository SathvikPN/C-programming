/*
• A simple insertion sort: O(n2)
• iterate through array until an out-of-order element found
• insert out-of-order element into correct location
• repeat until end of array reached
• Split into two functions for ease-of-use 
*/
#include<stdio.h>

#define array_length(arr) ( (sizeof(arr)==0)? (0):( sizeof(arr)/sizeof(arr[0]) ) )

int arr[] = {1,3,6,2,5,4,7,9,8};
void shift_element(unsigned int i); 
void insertion_sort();
void print_array();

int main()
{
   print_array();
   insertion_sort();
   print_array();
   return 0;
}

void shift_element(unsigned int i)
{
   int ivalue;

   for(ivalue = arr[i]; (i && arr[i-1]>ivalue); i--)
   {
      arr[i] = arr[i-1];
      // bring up previous element
      // ivalue is saved throughout the loop
   }
   
   arr[i] = ivalue;
}

void insertion_sort()
{
   unsigned int i;
   unsigned int len = array_length(arr);
   for (i=1; i<len; i++)
   {
        if (arr[i-1]>arr[i])
            shift_element(i);
   }
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
