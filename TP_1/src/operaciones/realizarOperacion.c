/*
 * realizarOperacion.c
 *
 *  Created on: 10 abr. 2021
 *      Author: Yesid
 */
#include "realizarOperacion.h"
#include "../validaciones/realizarValidacion.h"

int sumar(double primerValor, double segundoValor, double *resultadoSuma)
{
	int valorRetorno;

	valorRetorno = 1;

	if (isdigit(primerValor) == 0 && isdigit(segundoValor) == 0)
	{
		*resultadoSuma = primerValor + segundoValor;
		valorRetorno = 0;
	}
	return valorRetorno;
}

int restar(double primerValor, double segundoValor, double *resultadoResta)
{
	int valorRetorno;

	valorRetorno = 1;

	if (isdigit(primerValor) == 0 && isdigit(segundoValor) == 0)
	{
		*resultadoResta = primerValor - segundoValor;
		valorRetorno = 0;
	}
	return valorRetorno;
}

int multiplicar(double primerValor, double segundoValor, double *resultadoMultiplicacion)
{
	int valorRetorno;

	valorRetorno = 1;

	if (isdigit(primerValor) == 0 && isdigit(segundoValor) == 0)
	{
		*resultadoMultiplicacion = primerValor * segundoValor;
		valorRetorno = 0;
	}
	return valorRetorno;
}

int dividir(double primerValor, double segundoValor, double *resultadoDivision)
{
	int valorRetorno;

	valorRetorno = 1;

	if (isdigit(primerValor) == 0 && isdigit(segundoValor) == 0)
	{
		if (segundoValor != (double) 0)
		{
			*resultadoDivision = primerValor / segundoValor;
			valorRetorno = 0;
		}
	}
	return valorRetorno;
}

int factorial(double valor, double minimo, double maximo, double *resultadoFactorial)
{
	int valorRetorno;
	double valorFactorial;
	int i;

	valorFactorial = 1;
	valorRetorno = 1;

	if (isdigit(valor) == 0 && isdigit(minimo) == 0 && isdigit(maximo) == 0)
	{
		if (validarRangoDoubleEntero(valor, minimo, maximo) == 0)
		{
			for (i = (int) valor; i > 1; i--)
			{
				valorFactorial *= i;
				valorRetorno = 0;
			}
			*resultadoFactorial = valorFactorial;
			valorRetorno = 0;
		}
	}
	return valorRetorno;
}

