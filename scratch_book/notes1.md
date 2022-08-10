Compile programs - walkthrough [[webpage]](https://www.cs.utah.edu/~zachary/isp/tutorials/separate/separate.html#tex2html1)

```c
int main(int argc, char ∗∗argv);  
// identifiers {argc, argv} can be any user wish identifier.
// 1st argument argv[0] == location of the executable.
```

Pointer variables: `int *p, *q` (* associated with identifier)

```c
/* '\0' Not written explicitly in string literals */
char msg[] = "Hi";      // modifiable string
char *msg = "Hi";       // string cannot be modified. (segmentation fault)
const char msg[] = "Hi" // constant string. cannot modify
```

Inline: Request to compiler to place function inline without call-stack setup. (type-checked)

Macro: Exact replacement of text by preprocessor

```c
#define m_square(x) x*x               // m_square(3+1) ==> 3+1*3+1 = 7 
inline int i_square(x) {return x*x;}  // i_square(3+1) ==> 4*4 = 16
```

`Little Endian` LSB at lower-address       

`Big Endian` MSB at lower-address.

`Hexadecimal`: `0xFA`--> `11111010` where `F=1111` `A=1010`

/* ----------------------------------------------------------------------------------------------------------*/

variable --> reference to stored value.

pointer --> memory address of stored value.

datatype --> determines the size of a variable in memory, what values it can take on, what operations are allowed

> functions can only return (upto) one value. [multiple value return, use global variables]


