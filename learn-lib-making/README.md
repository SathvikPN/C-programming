```powershell
gcc -Wall -c .\sort_lib\sorting.c insertion_sort.c
gcc -Wall -o run sorting.o insertion_sort.o
.\run
```

OR

```
gcc -Wall .\sort_lib\sorting.c insertion_sort.c
.\a
```
