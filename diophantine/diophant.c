#include <stdio.h>
#include "euclid.h"
#include "diophant.h"

void display_diophantine()
{
    puts("ax + by = c");
    puts("  where a,b,c (integers) --> diophantine parameters");
}

void solve_diophantine(int a, int b, int c)
{
    int g = gcd(a,b);
    if (c%g)
    {
        puts("c is not multiple of gcd(a,b)");
        return;
    }

    g = extended_euclid(a,b);

    /* get g,x,y from extended_euclid */
    g = extended_euclid(a,b);


    /* Rescale so ax + by = c */
    int grow = c/g;
    x = x * grow;
    y = y * grow;
    puts("------------------------------------------------");
    printf("%dx + %dy = %d  \n", a,b,c);
    printf("x=[%d]  y=[%d]", x,y);
    puts("");
    return;
}