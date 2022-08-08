[RUN]
gcc -Wall -c -g lib/helpers.c {program.c}
gcc -Wall helpers.o {program.o} -o {run} 
./{run}

[Windows] Remove files with given ext
DEL *.o
DEL *.exe

[custom run]
gcc -Wall -c -g lib/helpers.c insertion_sort.c
gcc -Wall helpers.o insertion_sort.o -o run
./run
