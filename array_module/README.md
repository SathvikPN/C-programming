If included header with path `"array_module/helpers.h"` in the file `program.c`

[RUN]
```bash
gcc -Wall -c -g array_module/helpers.c program.c
gcc -Wall helpers.o program.o -o run
./run
```

[CLEAN] (windows) remove all files with matching extension
```bash
DEL *.o
DEL *.exe
```

`-Wall`
- optional but is strongly encouraged.
- it tells C to produce all possible warning messages
-  A warning message will usually lead you to a bug in your program

`-c`
- produce an object file with name same as source code filename
- `main.c` --> `main.o`

`-g`
- include information needed by the debugger.


`-o`
- what to name the executable

`-lm`
- tells C to link in the math libraries
- optional if no functions from math madule is used
