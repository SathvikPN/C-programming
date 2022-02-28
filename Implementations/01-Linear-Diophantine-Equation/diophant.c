/* Design a program to solve linear Diophantine equation 

ax + by = c  (x, y: integers)
*/
#include<stdio.h>
#include "euclid.h"

int main()
{
    /* get a,b,c for eqn */
    int a = 10, b = 20, c = 30;

    /* compute g = gcd(a,b) */
    int g = gcd(a,b);

    if (c%g!=0)
    {
        puts("c is not multiple of gcd");
        puts("exit algo");
        return 0;
    }

    /* compute x,y using Extended Euclidean Algorithm */
    g = ext_euclid(a,b); // results in global x and y//

    /* Rescale so ax + by = c */
    int grow = c/g;
    x = x * grow;
    y = y * grow;

    printf("(%d*%d) + (%d*%d) = %d", a,x,b,y,c);

    return 0;
}



/* Appendix --------------------------------------------------------------------

1] Linear diophantine eqn 
ax + by = c  (x, y: integers)

Pseudocode:
get a, b, c from command line
compute g = gcd(a,b)
if (c is not a multiple of the gcd)
    no solutions exist; 
    exit;
run Extended Euclidean algorithm on a, b
rescale x and y output by (c/g)
print solution

2] Extended Euclidean Algorithm
Find integer x,y such that 
ax + by = gcd(a, b)

Pseudocode:
Initialize state variables (x,y)
if (a < b)
    swap(a,b)
while (b > 0) {
    compute quotient, remainder
    update state variables (x,y)
}
return gcd and state variables (x,y)
*/
