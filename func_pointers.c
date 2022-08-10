// A simple C program to show function pointers as parameter
#include <stdio.h>

// Two simple functions
void fun1(int x) { printf("Fun1:    Put First %d\n", x); }
void fun2(int z) { printf("Fun2:    %d Put Next\n", z); }

// A function that receives a simple function
// as parameter and calls the function
void wrapper(void (*fun)(int))
{
    printf("[Exec passed callback]  ");
	fun(777);
}

int main()
{
	wrapper(fun1);
	wrapper(fun2);
	return 0;
}
