#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include </home/carlossergio/Documentos/IE/calculoNumerico.h>

int main(){
    const float error = 0.001;
    //bissecção e falsa posição
    const float a = 0.0;
    const float b = 1.0;
    //Os demais métodos  
    const float start_0 = 1.5;
    const float start_1 = 1.7;

    printf("Método Bissecção\n");
    //printf("\tResultado: %.4lf\n\n", bisectionMethod(a, b, error));
    
    printf("Método Falsa Posição\n");
    //printf("\tResultado: %.4lf\n\n", falsePositionMethod(a, b, error));
    
    printf("Método Ponto Fixo\n");
    printf("\tResultado: %.4lf\n\n", fixedPointMethod(start_0, error));
    
    printf("Método Newton Raphson\n");
    //printf("\tResultado: %.4lf\n\n", newtonRaphsonMethod(start_0, error));
    
    printf("Método Secante\n");
    //printf("\tResultado: %.4lf\n\n", secanteMethod(start_0, start_1, error));

    return 0;
}