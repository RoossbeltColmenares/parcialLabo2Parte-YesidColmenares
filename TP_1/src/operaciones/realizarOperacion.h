/*
 * realizarOperacion.h
 *
 *  Created on: 10 abr. 2021
 *      Author: Yesid
 */
#include <stdio.h>
#include <ctype.h>
#ifndef OPERACIONES_REALIZAROPERACION_H_
#define OPERACIONES_REALIZAROPERACION_H_

/**
 * @brief realiza la suma de dos numeros decimales o enteros pasados como parametros
 *
 * @param primerValor, primer numero sumando
 * @param segundoValor, segundo numero sumando
 * @param resultadoSuma, es el puntero que nos va a permitir pasar el valor por referencia,
 * el resultado de la suma en tipo de dato double
 *
 * @return retorna 1 si no se pudo sumar, de lo contrario retorna 0
 */
int sumar(double primerValor, double segundoValor, double *resultadoSuma);

/**
 * @brief realiza la resta de dos numeros decimales o enteros pasados como parametros
 *
 * @param primerValor, primer numero es el minuendo
 * @param segundoValor, segundo numero es el substraendo
 * @param resultadoResta, es el puntero que nos va a permitir pasar el valor por referncia,
 * la diferencia de la resta en tipo de dato double
 * @return retorna 1 si no se pudo restar, de lo contrario retorna 0
 */
int restar(double primerValor, double segundoValor, double *resultadoResta);

/**
 * @brief realiza la multiplicacion de dos numeros decimales o enteros pasados como parametros
 *
 * @param primerValor, primer numero es el multiplicando
 * @param segundoValor, segundo numero es el multiplicador
 * @param resultadoMultiplicacion, es el puntero que nos va a permitir pasar el valor por referncia,
 * el producto de la multiplicacion en tipo de dato double
 * @return
 */
int multiplicar(double primerValor, double segundoValor, double *resultadoMultiplicacion);

/**
 * @brief realiza la division de dos numeros decimales o enteros pasados como parametros solo si
 * es posible realizar la operacion
 *
 * @param primerValor, primer numero es el dividiendo
 * @param segundoValor, segundo numero es el divisor
 * @param resultadoDivision, es el puntero que nos va a permitir pasar el valor por referencia,
 * el cociente de la division en tipo de dato double
 * @return retorna 1 si no se pudo dividir, de lo contrario retorna 0
 */
int dividir(double primerValor, double segundoValor, double *resultadoDivision);

/**
 * @brief valida y realiza el factorial del numero ingresado solo si se cumple la condicion
 *
 * @param valor, es el numero al cual se le realiza el factorial
 * @param minimo, es el valor minimo a calcular
 * @param maximo, es el valor maximo a calcular
 * @param resultadoFactorial, es el puntero que nos va a permitir pasar el valor por referencia,
 * el factorial en tipo de dato double
 * @return retorna 1 si no se pudo realizar el factorial, de lo contrario retorna 0
 */
int factorial(double valor, double minimo, double maximo, double *resultadoFactorial);


#endif /* OPERACIONES_REALIZAROPERACION_H_ */
