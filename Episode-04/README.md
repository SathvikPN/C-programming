Lookout

User defined datatype,
Structures,
Unions,
Bitfields,
Data structure,
Memory allocation,
Linked lists,
Binary trees,

---
> [Great Explanation on Structures](https://www.microforum.cc/blogs/entry/21-how-to-struct-lessons-on-structures-in-c/) [webpage]

A structure is a collection of related variables (of possibly different types) grouped together under a single name.
```
struct [structure tag] {
   member definition;
   member definition;
   ...
} [one or more structure variables];
```

```c
struct point
{
   int x;
   int y;
};

/* notice ";" at end */
```

• struct defines a new datatype.

• The name of the structure is optional.
struct {...} x,y,z;

• The variables declared within a structure are called its
members

• Variables can be declared like any other built in data-type.
struct point ptA;

• Initialization is done by specifying values of every member.
struct point ptA={10,20};

• Assignment operator copies every member of the structure
(be careful with pointers). 

```c
/* Members can be structures */
struct triangle
{
   struct point ptA;
   struct point ptB;
   struct point ptC;
};

/* Members can be self referential */
struct chain_element
{
   int data;
   struct chain_element *next;
};
```

• Individual members can be accessed using ’.’ operator.
```c
struct point pt={10,20}; 
int x=pt.x; 
int y=pt.y;
```

• If structure is nested, multiple ’.’ are required
```c
struct rectangle
{
  struct point tl; /∗ top left ∗/
  struct point br; /∗ bottom right ∗/
};

struct rectangle rect;

int tlx = rect.tl.x ; /∗ nested ∗/
int tly = rect.tl.y;
```

---

For large structures it is more efficient to pass pointers.
```c
void foo(struct point ∗ pp); // declaration
struct point pt;  // instantiation
foo(&pt); // function call

struct point p = {10 ,20};
struct point ∗pp = &p;
pp−>x = 10; /∗ changes p.x ∗ /
int y = pp−>y ; /∗ same as y = p.y ∗/
```
Other ways to access structure members?
```c
(∗pp).x = 10; /∗ changes p.x ∗ /
int y= (∗pp).y; /∗ same as y=p.y ∗/
/* why is the () required? */
```

Array of structures
```c
// array declaration
int x[10];
struct point p[10];

// Initialisation
int x[3] = {7,5,8};
struct point p[3] = { {1,8}, {2,9}, {3,5} };
```

**The size of a structure is greater than or equal to the sum
of the sizes of its members.**

---

A union is a variable that may hold objects of different
types/sizes in the same memory location. Example:
```c
union data
{
   int idata ;
   float fdata ;
   char∗ sdata ;
} d1,d2,d3;

d1.idata = 10;
d1.fdata = 3.14F;
d1.sdata = "hello world"; 
```

• The size of the union variable is equal to the size of its
largest element.

• Important: The compiler does not test if the data is being
read in the correct format.

union data d; d.idata=10; float f=d.fdata; /∗ will give junk∗/

• A common solution is to maintain a separate variable.
```c
enum dtype { INT ,FLOAT,CHAR} ;
struct variant
{
   union data d ;
   enum dtype t ;
};
```

// Read about Bitfields.

---

**DYNAMIC MEMORY ALLOCATION**

```c 
void∗ malloc(size_t n)
```
• `malloc()` allocates blocks of memory

• returns a pointer to unitialized block of memory on
success

• returns `NULL` on failure.

• the returned value should be cast to appropriate type using (). 
```c
int∗ ip=(int∗)malloc(sizeof(int)∗100) 
```

```c
void∗ calloc(size_t n,size_t size)
```
• allocates an array of n elements each of which is ’size’ bytes.

• initializes memory to 0

```c
void free(void∗)
```
• Frees memory allocated by malloc()

• Common error: accessing memory after calling free

