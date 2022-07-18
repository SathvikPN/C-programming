#include<stdio.h>
#include "euclid.h"

/* Global state variables */
int x,y;

/* Helpers */
void swap(int*, int*);

/* greatest common divisor ---------------------------------------------*/
int gcd(int a, int b)
{
    if (a<b)
        swap(&a, &b);
    while (b)
    {
        int R = a%b;
        a = b;
        b = R;
    }
    return a;
}

/* Extended Euclidean Algorithm -------------------------------------
 * For given (a,b)
 * Returns (g,x,y) where 
 *      g = gcd(a,b)
 *  ax+by = g
 */

int extended_euclid(int a, int b)
{
    if (b==0)
    {
        x = 1;
        y = 0;
        return a;
    }

    int g1 = extended_euclid(b, a%b);
    int s1=x, t1=y;
    int g = g1;
    x = t1;
    y = s1 - (a/b) * t1;

    return g;
}
/* https://www.csee.umbc.edu/~chang/cs203.s09/exteuclid.shtml#:~:text=Here's%20the%20pseudo%2Dcode%20for,%2Ct)%20%3B%20%7D%20Note%20that */




/* HELPERS --------------------------*/
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

