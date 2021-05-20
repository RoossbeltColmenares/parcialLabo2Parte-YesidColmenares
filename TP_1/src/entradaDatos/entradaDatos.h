/*
 * entradaDatos.h
 *
 *  Created on: 10 abr. 2021
 *      Author: Yesid
 */
#ifndef ENTRADADATOS_ENTRADADATOS_H_
#define ENTRADADATOS_ENTRADADATOS_H_

/**
 * @brief imprime en pantalla la instruccion, guarda el dato ingresado por el usuario, lo valida y en caso
 * que este bien lo retornar por valor, de lo contrario pide de nuevo al usuario ingresar el dato
 *
 * @param cadenaTexto, es el mensaje-instruccion que recibe el usuario
 * @param cadenaError, es el mensaje de error, por si el ususario se equivoca
 * @param minimo, es el valor minimo que el usuario puede ingresar
 * @param maximo, es el valor maximo que el usuario puede ingresar
 * @return retorna el numero ingresado por valor, luego de ya estar validado en tipo de dato int
 */
int pedirEntero(char cadenaTexto[], char cadenaError[], int minimo, int maximo);

/**
 * @brief imprime en pantalla la instruccion, guarda el dato ingresado por el usuario, lo valida y en caso
 * que este bien lo retornar por valor, de lo contrario pide de nuevo al usuario ingresar el dato
 *
 * @param cadenaTexto, es el mensaje-instruccion que recibe el usuario
 * @param cadenaError, es el mensaje de error, por si el ususario se equivoca
 * @param minimo, es el valor minimo que el usuario puede ingresar
 * @param maximo, es el valor maximo que el usuario puede ingresar
 * @return retorna el numero ingresado por valor, luego de ya estar validado en tipo de dato double
 */
double pedirDouble(char cadenaTexto[], char cadenaError[], double minimo, double maximo);

#endif /* ENTRADADATOS_ENTRADADATOS_H_ */
