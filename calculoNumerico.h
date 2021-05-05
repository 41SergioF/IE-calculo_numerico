#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//------------------------------------------//
//Nesse trecho de código devemos implementar a função a ser encontrada o x  
double function(double x){
    return ((x*x*x)-7);
}
//------------------------------------------//

//  Funções base para o cálculo 
//modulo 
float module (float value){
    return (value < 0) ? value*(-1) : value;
}
//calculo de x
double calculateX(double a, double b) {
    double f = a * function(b) - b *function(a);
    f = f / (function(b) - function(a));
    return f;
}

//Métodos de calculo numerico 
//Método da Bisseção
float bisectionMethod(double a, double b, double erro) {
    bool aIsPositive = (function(a) < 0) ? 0 : 1;    /*se a for positivo mas como verdadeiro. aIsPositive = false a é negativo*/
    double x = (a + b) / 2.0;
    double result;

    int i = 1;
    while ((b-a) > erro){    //para quando (b-a) < erro 
        result = function(x);            //f(x)
        //printf("%fl %lf", x, result);   
        
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
        x = (a + b) / 2.0;              //suposto valor do x para esse passo
    }       
    return x; //retorna x sendo f(x) próximo a 0
}

//Falsa Posição
double falsePosition(double a, double b, double erro) {
    bool aIsPositive = (function(a) < 0) ? 0 : 1;
    double x = calculateX(a, b);
    double result;

    while ((b-a) > erro){     //para quando (b-a) < erro
        result = function(x);
        
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
         x = calculateX(a, b);
    }
    return x;   //retorna x sendo f(x) próximo a 0
}
//Ponto fixo
/*
double fixedPoint() {
		
}*/