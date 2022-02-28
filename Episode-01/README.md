Lookout:
- Write-Compile-Debug C programs
- Variables Datatypes Operators
---


C - Features: Few keywords, compound data types (`struct` `union`), Compiles to native code, pointers (Memory), Macro Preprocessors

C Lacks: Exception handling, range checking, Object oriented programming, Garbage collection (memory)


[Compile programs - walkthrough](https://www.cs.utah.edu/~zachary/isp/tutorials/separate/separate.html#tex2html1) [webpage]

Two-argument form of `main()`: access command-line arguments. [Read more](https://www.tutorialspoint.com/What-does-int-argc-char-argv-mean-in-C-Cplusplus)
```c
int main(int argc, char ∗∗argv);  
```

Use `int *p` over `int* p` [Discussion](https://stackoverflow.com/a/2660650)

`puts()` put_string only.    

`printf()` print_formatted. [string, variables]

```c
const char msg[] = "Hello world";
// Constant array of characters
// '\0' Not written explicitly in string literals
```

**Inline functions** parsed by the compiler  -  evaluated only once

**Macros** expanded by preprocessor  -  arguments are evaluated every time whenever macro is used


```c
#define squared(x) x*x  //MACRO : Inline replacement

double ans = 18.0/squared(2+1);

// Answer: 18.0/2 + 1 ∗ 2 + 1 = 9 + 2 + 1 = 12
```

Big endian: the most significant bits (MSBs) occupy the lower address.

Little endian : the least signficant bits (LSBs) occupy the lower address.
[Wikipedia](https://en.wikipedia.org/wiki/Endianness)


 `0xFA` --> `11111010`
 
 F=`1111`
 A=`1010`
 
a Hexadecimal digt = 4bit

Datatypes: int, float, char, string, [enum](https://www.geeksforgeeks.org/enumeration-enum-c/)

```c
y=x++ //y=x;  x=x+1;
y=++x //x=x+1;  y=x;
```

```c
scanf("%[^\n]%*c", s); // Reading Sentence
```
[] is the scanset character. ^\n stands for taking input until a newline isn't encountered. Then, with this %*c, it reads the newline character and here, the used * indicates that this newline character is discarded.
