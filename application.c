#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <\Users\Carlos S\Documents\IE\calculoNumerico.h>

int main(){

    double a = 1.0;
    double b = 2.0;
    double erro = 0.05;
 
    printf("\nResultado: %.2lf\n", bisectionMethod(a, b, erro));
    printf("\nResultado: %.2lf\n", falsePosition(a, b, erro));

    return 0;
}