[RUN]

gcc -Wall -c -g main.c diophant.c euclid.c
gcc -Wall -o run main.o diophant.o euclid.o
./run
