Lookout

Pointers and Memory Addresses,
Physical and Virtual Memory,
Addressing and Indirection,
Functions with Multiple Outputs,
Arrays and Pointer Arithmetic,
Strings,
String Utility Functions,

---


• Pointer: memory address of a variable

• Address can be used to access/modify a variable from
anywhere 

• Physical memory: physical resources where data can be
stored and accessed by your computer. (cache, RAM, hard disk, removable storage)

• Virtual memory: abstraction by OS, addressable space
accessible by your code 

• Virtual memory maps to different parts of physical memory

• Usable parts of virtual memory: stack and heap

• stack: where declared variables go
• heap: where dynamic memory goes 

• Every variable residing in memory has an address!

• What doesn’t have an address?

• register variables
• constants/literals/preprocessor defines
• expressions (unless result is a variable) 

• Address of a variable of type t has type t *

address of a variable? The `&` operator 

dereferencing/indirection operator `*`

```c
/* pointer casting */
ppi = (double ∗)pn; // pn originally of type ( int *) 
```

---

• Primitive arrays implemented in C using pointer to block of
contiguous memory 

Consider array of 8 ints:
```int arr [8];```

• Accessing arr using array entry operator:
```int a = arr [0];```

• arr is like a pointer to element 0 of the array: 

```c
int ∗pa = arr;     ⇔     int ∗pa = &arr[0];
```

```
BYTES = sizeof(<data type>)

int arr [8]; /∗ sizeof(arr) == 32 ∗/ (64-bit OS)
long arr [5]; /∗ sizeof(arr) == 40 ∗/ (64-bit OS) 

#define array_length(arr) ( sizeof(arr)==0 ? 0 : sizeof(arr) / sizeof(arr[0]) )
```

• Suppose int ∗pa = arr;

• Pointer not an int, but can add or subtract an int from a
pointer:
pa + i points to arr[i]

• Address value increments by i times size of data type
Suppose arr[0] has address 100. Then arr[3] has
address 112.

• Suppose ```char ∗ pc = (char ∗)pa;```
What value of i satisfies
```(int ∗)(pc+i) == pa + 3```?

(ans) `i = 12`

---

**Strings as Arrays**

Strings stored as null-terminated character arrays (last
character == ’\0’)

• Suppose 
`char str [] = "This is a string.";` and
`char ∗ pc = str ;`

• Manipulate string as you would an array
```∗(pc+10) = ’S’;```

`puts( str ); /∗ prints "This is a String ." ∗/ `

---

**String Utility Functions**

String functions in standard header string.h
• Copy functions: strcpy(), strncpy()
```
char ∗ strcpy( strto ,strfrom ); – copy strfrom to strto
char ∗ strncpy( strto ,strfrom,n); – copy n chars from strfrom to strto
```
• Comparison functions: strcmp(), strncmp()
```
int strcmp(str1, str2 ); – compare str1, str2; return 0 if equal, positive if str1>str2, negative if str1<str2
int strncmp(str1,str2 ,n); – compare first n chars of str1 and str2
```
• String length: strlen()
```
int strlen ( str ); – get length of str
```

• Concatenation functions: strcat(), strncat()
```
char ∗ strcat ( strto ,strfrom ); – add strfrom to end of strto
char ∗ strncat( strto ,strfrom,n); – add n chars from strfrom to end of strto
```
• Search functions: strchr(), strrchr()
```
char ∗ strchr( str ,c); – find char c in str, return pointer to first occurrence, or NULL if not found
char ∗ strrchr ( str ,c); – find char c in str, return pointer to last occurrence, or NULL if not found
```
• Many other utility functions exist. . . 


REVIEW
---
Review: pointers

• Pointers: memory address of variables
• ’&’ (address of) operator.
• Declaring: int x=10; int ∗ px= &x;
• Dereferencing: ∗px=20;
• Pointer arithmetic:
• sizeof()
• incrementing/decrementing
• absolute value after operation depends on pointer datatype.
 
Review: string.h

• String copy: strcpy(),strncpy()
• Comparison: strcmp(),strncmp()
• Length: strlen()
• Concatenation: strcat()
• Search: strchr(),strstr()

Searching and sorting

Searching
• Linear search: O(n)
• Binary search: O(logn). The array has to be sorted first.
Sorting
• Insertion sort: O(n2)
• Quick sort: O(n log n)
