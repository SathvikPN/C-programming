/* GCD Computation [Knuth, D. E. The Art of Computer Programming, Volume 1: Fundamental Algorithms. 3rd ed. Addison-Wesley, 1997.] 

Algorithm relies on gcd(a, b) = gcd(b, a mod b), for natural numbers a > b. 
*/

int gcd(int a, int b)
{
    /* if (a<b) performs swap */
    while (b)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

/* Global Variables x,y */
int x,y;

/*Extended Euclidean Algorithm 
Returns: g,x,y such that 
g = gcd(a,b)
g = ax + by
*/
int ext_euclid(int a, int b)
{
    if (b==0)
    {
        x = 1;
        y = 0;
        return a;
    }

    int g1 = ext_euclid(b, a%b);
    int s1=x, t1=y;
    int g = g1;
    x = t1;
    y = s1 - (a/b) * t1;

    return g;

}
/* src: https://www.csee.umbc.edu/~chang/cs203.s09/exteuclid.shtml#:~:text=Here's%20the%20pseudo%2Dcode%20for,%2Ct)%20%3B%20%7D%20Note%20that */


/* Extended Euclidean Algorithm
Initialize state variables (x,y)
if (a < b)
    swap(a,b)
while (b > 0) {
    compute quotient, remainder
    update state variables (x,y)
}
return gcd and state variables (x,y)
*/
