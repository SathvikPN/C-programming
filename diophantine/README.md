[RUN]
```Bash
gcc -Wall -c -g main.c diophant.c euclid.c
gcc -Wall -o run main.o diophant.o euclid.o -lm
./run
```

`-Wall`
- optional but is strongly encouraged.
- it tells C to produce all possible warning messages
-  A warning message will usually lead you to a bug in your program

`-c'
- produce an object file with name same as source code filename
- `main.c` --> `main.o`

`-g`
- include information needed by the debugger.


`-o`
- what to name the executable

`-lm`
- tells C to link in the math libraries
- optional if no functions from math madule is used
