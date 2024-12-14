#include <stdio.h>
#define INVALID_OP '\0'

/*
This program demonstrates a basic three-function calculator.
*/

int main ()
{
    int result, value, operation;
    result=0;
    /* Initialize operation to '+' so the first number gets added to zero. */
    operation = '+';
    while (operation != '='){

