#include <stdio.h>
#include "diophant.h"

int a,b,c;
void get_diophantine_parameters();
int main()
{
    get_diophantine_parameters();
    solve_diophantine(a,b,c);
    return 0;
}

void get_diophantine_parameters()
{
    display_diophantine();
    printf("a b c: ");
    scanf("%d %d %d", &a, &b, &c);
}

