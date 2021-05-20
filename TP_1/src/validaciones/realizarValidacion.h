/*
 * realizarValidacion.h
 *
 *  Created on: 10 abr. 2021
 *      Author: Yesid
 */
#include <stdio.h>
#include <ctype.h>
#ifndef VALIDACIONES_REALIZARVALIDACION_H_
#define VALIDACIONES_REALIZARVALIDACION_H_

/**
 * @brief recibe un puntero como parametro para retornar el numero validado solo si es posible
 *
 * @param cadenaTexto, es el mensaje-instruccion que recibe el usuario
 * @param numeroDoubleIngresado, es el puntero que nos va a permitir pasar el valor por referencia,
 * solo si se cumple la validacion.
 * @return retorna 0 si el tipo de dato no es Double, de los contrario retorna 1
 */
int validarDouble(char cadenaTexto[], double *numeroDoubleIngresado);

/**
 * @brief recibe un puntero como parametro para retornar el numero validado solo si es posible
 *
 * @param cadenaTexto, es el mensaje-instruccion que recibe el usuario
 * @param numeroIntIngresado, es el puntero que nos va a permitir pasar el valor por referencia,
 * solo si se cumple la validacion.
 * @return retorna 0 si el tipo de dato no es Entero, de lo contrario retorna 1
 */
int validarEntero(char cadenaTexto[], int *numeroIntIngresado);

/**
 * @brief valida un numero Decimal o Entero y retorna un 0 o un 1 dependiendo si cumple la condicion
 *
 * @param valor, es el numero a validar el rango
 * @param minimo, es el valor minimo que se acepta
 * @param maximo, es el valor maximo que se acepta
 * @return retorna 1 si esta fuera del rango, de lo contrario retorna un 0
 */
int validarRangoDoubleEntero(double valor, double minimo, double maximo);

#endif /* VALIDACIONES_REALIZARVALIDACION_H_ */
