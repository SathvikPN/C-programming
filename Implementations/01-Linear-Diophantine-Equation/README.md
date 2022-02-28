### Execution Tips

First you need to compile each of the `.c` files separately. 
You can do this by using the -c option of the compiler from a Unix shell window:
```console
gcc -Wall -g -c diophant.c
gcc -Wall -g -c euclid.c
```

Next you need to link the two resulting `.o` files into a single executable program. 
You can do this by using the -o option of the compiler:
```console
gcc -o demo diophant.o euclid.o -lm
```
This results in an executable called `demo`.

Finally you need to run the resulting executable. You do this by:
```console
./demo
```

### Algorithms
```
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
```
