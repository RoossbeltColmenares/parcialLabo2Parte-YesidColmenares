/*
 * realizarValidacion.c
 *
 *  Created on: 10 abr. 2021
 *      Author: Yesid
 */
#include "realizarValidacion.h"

int validarDouble(char cadenaTexto[], double *numeroDoubleIngresado)
{
	double valorIngresado;
	int valorRetorno;

	printf("%s", cadenaTexto);
	fflush(stdin);
	valorRetorno = scanf("%lf", &valorIngresado);

	if (valorRetorno == 1)
	{
		*numeroDoubleIngresado = valorIngresado;
	}

	return valorRetorno;
}

int validarEntero(char cadenaTexto[], int *numeroIntIngresado)
{
	int valorIngresado;
	int valorRetorno;

	printf("%s", cadenaTexto);
	fflush(stdin);
	valorRetorno = scanf("%d", &valorIngresado);

	if (valorRetorno == 1)
	{
		*numeroIntIngresado = valorIngresado;
	}

	return valorRetorno;
}

int validarRangoDoubleEntero(double valor, double minimo, double maximo)
{
	int valorRetorno;

	valorRetorno = 0;

	if (valor < minimo || valor > maximo)
	{
		valorRetorno = 1;
	}

	return valorRetorno;
}
