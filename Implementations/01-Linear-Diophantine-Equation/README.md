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
