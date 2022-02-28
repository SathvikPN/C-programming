Lookout

More about Pointers,
Pointers to Pointers,
Pointer Arrays,
Multidimensional Arrays

---

```c
// What does this function do?
void swap ( int ∗∗a , int ∗∗b ) {
int ∗temp = ∗a ;
∗a = ∗b ;
∗b = temp ;
}
// How does it compare to the familiar version of swap?
void swap ( int ∗a , int ∗b ) {
int temp = ∗a ;
∗a = ∗b ;
∗b = temp ;
} 
```

```c
int n = 3;
int ∗pn = &n; /∗ pointer to n ∗/
int ∗∗ppn = &pn; /∗ pointer to address of n ∗/
```
```c
char ∗arr[10]; – an array of pointers to char’s
// Pointers in array can point to arrays themselves
char ∗strs [10]; – an array of char arrays (or strings) 
```

• Have an array int arr [100]; that contains some numbers

• Want to have a sorted version of the array, but not modify
arr

• Can declare a pointer array int ∗ sorted_array[100]; containing
pointers to elements of arr and sort the pointers instead
of the numbers themselves

• Good approach for sorting arrays whose elements are very
large (like strings) 
