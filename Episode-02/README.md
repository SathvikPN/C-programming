Lookout

- Functions and modular programming. Variable scope. Static and global variables.
- Input Output

Review
Blocks and Compound Statements, Control Flow, Conditional Statements, Loops, Functions, Modular Programming, Variable Scope
Standard I/O, String I/O, File I/O

---

variable: reference to a stored value (usually in memory)

Data type: determines the size of a variable in memory, what values it can take on, what operations are allowed 

Block compiled as a single unit

C99, bool type available (use stdbool.h) 

[Multiple Conditions inside a for loop](https://stackoverflow.com/questions/16859029/multiple-conditions-in-a-c-for-loop)

Available:
- switch
- goto (error handle use case)
- do-while
- break continue


Functions only return (up to) one value

For multiple return use case - global variables

• Break down problem into simpler sub-problems

• Consider iteration and recursion

• How can we implement gcd(a,b) recursively?

• Minimize transfer of state between functions

• Writing pseudocode first can help

Modular Programming :

• C programs do not need to be monolithic

• Module: interface and implementation

• interface: header files

• implementation: auxilliary source/object files

`extern` keyword: informs compiler that variable defined somewhere else 

`static` keyword has two meanings, depending on where the static variable is declared

Outside a function:
- static variables/functions only visible within that file, not globally (cannot be extern’ed)

Inside a function: static variables

- are still local to that function

- are initialized only during program initialization

- do not get reinitialized with each function call 



`register` 

• During execution, data processed in registers

• Explicitly store commonly used data in registers – minimize load/store overhead

• Can explicitly declare certain variables as registers using register keyword

• must be a simple type (implementation-dependent)

• only local variables and function arguments eligible

• excess/unallowed register declarations ignored, compiled as regular variables

• Registers do not reside in addressed memory; pointer of a register variable illegal 

`goto` sphagetti code

Any code that uses goto can be written without using one. 

goto provides a convenient way to exit from nested blocks.

I/O

`printf()` specification: %[flags][width][.precision][modifier]<type>

  
strings as character arrays
  
Declaration examples:
```c
char str []="hello"; /∗compiler takes care of size∗/  
char str[10]="hello"; /∗make sure the array is large enough∗/
char str []={'h','e','l','l',0};
```

Instead of writing to the standard output, the formatted data can be written to or read from character arrays.
```
int sprintf (char string [], char format[],arg1,arg2)
  
int sscanf(char str [], char format[],arg1,arg2)
```
  
  
C allows us to read data from text/binary files using fopen().
```c
FILE∗ fopen(char name[],char mode[])
```
• mode can be "r" (read only),"w" (write only),"a" (append)
among other options. "b" can be appended for binary files.
  
• fopen returns a pointer to the file stream if it exists or
NULL otherwise.

• We don’t need to know the details of the FILE data type.
  
• Important: The standard input and output are also FILE*
datatypes (stdin,stdout). 

  
**Command line input**
  
```c
  int main(int argc,char∗ argv[])
```
• argc: count of arguments.
  
• argv[]: an array of pointers to each of the arguments
  
• note: the arguments include the name of the program as well.
  
Examples:
- `./cat a.txt b.txt` (argc=3,  argv[0]="cat"  argv[1]="a.txt"  argv[2]="b.txt")

- `./cat` (argc=1,  argv[0]="cat") 
