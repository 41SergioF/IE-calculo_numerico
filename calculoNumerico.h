#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
/*
-> Exemplos para ser usados como teste.
    -> Bissecção
        f(x) = x³ - 9 * x + 3  
        a    =  0
        b    =  1  
    -> Falsa Posição
        f(x) = x³ - 9 * x + 3  
        a    =  0
        b    =  1  
    -> Ponto Fixo
        f(x) = x² + x - 6
        g(x) = 6 - x²
        xo   = 1.5
    -> Newton-Raphson
        f(x)  = x² + x - 6
        f'(x) = 2x + 1
        xo    = 1.5
    -> Secante
        f(x)  = x² + x - 6
        xo    = 1.5
        x1    = 1.7
        erro = 0.001        
*/
//------------------------------------------//
//Nesse trecho de código devemos implementar a função a ser encontrada o x  
double function_(double x){
   return (x*x*x) - (9 * x) + 3;
}

double function(double x){
   return (x*x)+x-6;
}

double functionDerived(double x){
    return (2*x) + 1;//vc implementa
}

//------------------------------------------//

//  Funções base para o cálculo 
//modulo 
double module (double value){
    return (value < 0) ? value*(-1) : value;
}
//calculo de x
double calculateX_bisection(double a, double b){
    return ((a+b)/2);
}

double calculateX_falsePosition(double a, double b) {
    double f = a * function_(b) - b *function_(a);
    f = f / (function_(b) - function_(a));
    return f;
}

double calculateX_fixedPoint(double x){
    return pow(6 - x, 0.5);
}

double calculateX_newtonRaphson(double x){
    return x - (function(x) / functionDerived(x));
}

double calculateX_secant(double x_k, double x_kMenosUm, double error){
    return x_k - ((function(x_k)*(x_k-x_kMenosUm)))/(function(x_k)-function(x_kMenosUm));
}

//Métodos de calculo numerico 
//Método da Bisseção
double bisectionMethod(double a, double b, double error) {
    bool aIsPositive = (function_(a) < 0) ? 0 : 1;    /*se a for positivo mas como verdadeiro. aIsPositive = false a é negativo*/
    double x = calculateX_bisection(a, b);
    double result;

    int i = 1;
    while ((b-a) > error){    //para quando (b-a) < error 
        result = function_(x);            //f(x)
        printf("\tx = %lfl : f(x) = %lf\n", x, result);   
        
        if (aIsPositive) { //se o 'a' for positivo
            if (result >= 0.0) { 
                a = x;      //sendo 'a' POSITIVO e f(x) POSITIVO
            }else {
                b = x;      //sendo 'a' POSITIVO e f(x) NEGATIVO
            }
        }else {
            if (result >= 0.0) {
                b = x;      //sendo 'a' NEGATIVO e f(x) POSITIVO    
            }else {
                a = x;      //sendo 'a' NEGATIVO e f(x) NEGATIVO
            }
        }
        x = calculateX_bisection(a, b);            //suposto valor do x para esse passo
    }       
    return x; //retorna x sendo f(x) próximo a 0
}

//Falsa Posição
double falsePositionMethod(double a, double b, double error) {
    bool aIsPositive = (function_(a) < 0) ? 0 : 1;
    double x = calculateX_falsePosition(a, b);
    double result;

    while ((b-a) > error){     //para quando (b-a) < error
        result = function_(x);
        printf("\tx = %lfl : f(x) = %lf\n", x, result);   
        
        if (aIsPositive) { //se o a for positivo
            if (result >= 0.0) {
                a = x;      //sendo 'a' POSITIVO e f(x) POSITIVO
            }else {
                b = x;      //sendo 'a' POSITIVO e f(x) NEGATIVO   
            }
        }else {
            if (result >= 0.0) {
                b = x;      //sendo 'a' NEGATIVO e f(x) POSITIVO
            }else {
                a = x;      //sendo 'a' NEGATIVO e f(x) NEGATIVO
            }
        }
         x = calculateX_falsePosition(a, b);
    }
    return x;   //retorna x sendo f(x) próximo a 0
} 

//Ponto Fixo
//O erro e o start(condição de parada) é dado na questão
double fixedPointMethod(double start, double error) {
    double x = calculateX_fixedPoint(start); //chute inicial usando o "start"

    // |f(x)| > erro
    while(module(function(x)) > error){
        printf("\tx = %lf : f(x) = %lf\n", x, function(x));   
        x = calculateX_fixedPoint(x); //outro chute com o "x"
    }

    return x; // retorna o 'x'. Esse "x" usado em f(x) = y = próximo a zero
}

//Newton-Raphson
double newtonRaphsonMethod(double start, double error){
    double x = calculateX_newtonRaphson(start);
    
    while (module(function(x)) > error){
        printf("\tx = %lf : f(x) = %lf\n", x, function(x));   
        x = calculateX_newtonRaphson(x);
    }

    return x;
}

//Secante
double secanteMethod(double x_k, double x_kMenosUm, double error){
    double x_kMaisUm = calculateX_secant(x_k, x_kMenosUm, error);
    
    while (module(function(x_kMaisUm)) > error){
        printf("\tx = %lf : f(x) = %lf\n", x_kMenosUm, function(x_kMaisUm));   
        x_kMaisUm = calculateX_secant(x_kMaisUm, x_k, error);
    }

    return x_kMaisUm;
}
