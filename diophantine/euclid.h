#ifndef EUCLID_H
#define EUCLID_H

/* global variables (declared in euclid.c) */
extern int x, y;

/* GCD of two numbers */
int gcd(int, int);

/* Returns GCD and updates state variables (x,y) */
int extended_euclid(int, int);

#endif