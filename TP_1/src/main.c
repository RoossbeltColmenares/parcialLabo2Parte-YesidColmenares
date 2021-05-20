/*
 ============================================================================
 Name        : TP1.c
 Author      : Roossbelt Yesid Colmenares Moreno
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Calculadora_TP1
 ============================================================================
 */
#include <stdlib.h>
#include <unistd.h>
#include "operaciones/realizarOperacion.h"
#include "entradaDatos/entradaDatos.h"

int main(void)
{
	setbuf(stdout, NULL);

	int banderaDelPrimero; //Valor: -1 (El cliente ya realizo el calculo 3), Valor: 0 (El cliente ingreso un nuevo dato) // Mientras no ingrese otro valor se mantiene en -1
	int opcionIngresadaMenu;
	int retornoPrimerFactorial;
	int retornoSegundoFactorial;
	int retornoDivision;

	//variables que guardan los operandos
	double primerOperandoIngresado;
	double segundoOperandoIngresado;

	//variables que guardan el resultado de las operaciones
	double resultadoSuma;
	double resultadoResta;
	double resultadoDivision;
	double resultadoMultiplicacion;
	double resultadoPrimerFactorial;
	double resultadoSegundoFactorial;

	//inicializacion variable
	banderaDelPrimero = 1;
	primerOperandoIngresado = 0;
	segundoOperandoIngresado = 0;

	do
	{
		printf("\n**************************************************************************");
		printf("\n                           Bienvenido Al Sistema                          ");
		printf("\n**************************************************************************");
		printf("\n1. Ingresar 1er operando (A = %.2lf)", primerOperandoIngresado);
		printf("\n2. Ingresar 2do operando (B = %.2lf)", segundoOperandoIngresado);
		printf("\n3. Calcular todas las operaciones");
		printf("\n4. Informar resultados");
		printf("\n5. Salir");
		printf("\n--------------------------------------------------------------------------");
		opcionIngresadaMenu = pedirEntero("\nIngresa la Opcion: ", "Error, Ingresa la Opcion: ", 1, 5);

		switch (opcionIngresadaMenu)
		{
			case 1:
				primerOperandoIngresado = pedirDouble("\n1. Ingresar 1er operando (A = X): ", "1. Error Fuera de rango, Ingresar 1er operando (A = X): ", -9999999999999.99, 9999999999999.99);

				banderaDelPrimero = 0;
				system("cls");
				break;

			case 2:
				segundoOperandoIngresado = pedirDouble("\n2. Ingresar 2do operando (B = X): ", "2. Error Fuera de rango, Ingresar 2do operando (B = X): ", -9999999999999.99, 9999999999999.99);

				banderaDelPrimero = 0;
				system("cls");
				break;

			case 3:
				system("cls");

				//validamos que primero haya ingresado algun dato
				if (banderaDelPrimero < 1)
				{
					printf("\n--------------------------------------------------------------------------");
					printf("\n3. Calcular todas las operaciones");
					printf("\n    A. Calcular la suma (%.2lf + %.2lf)", primerOperandoIngresado, segundoOperandoIngresado);
					printf("\n    B. Calcular la resta (%.2lf - %.2lf)", primerOperandoIngresado, segundoOperandoIngresado);
					printf("\n    C. Calcular la division (%.2lf / %.2lf)", primerOperandoIngresado, segundoOperandoIngresado);
					printf("\n    D. Calcular la multiplicacion (%.2lf * %.2lf)", primerOperandoIngresado, segundoOperandoIngresado);
					printf("\n    E. Calcular el factorial (%d!) y (%d!)", (int) primerOperandoIngresado, (int) segundoOperandoIngresado);

					//Realizamos las operaciones
					sumar(primerOperandoIngresado, segundoOperandoIngresado, &resultadoSuma);
					restar(primerOperandoIngresado, segundoOperandoIngresado, &resultadoResta);
					retornoDivision = dividir(primerOperandoIngresado, segundoOperandoIngresado, &resultadoDivision);
					multiplicar(primerOperandoIngresado, segundoOperandoIngresado, &resultadoMultiplicacion);
					retornoPrimerFactorial = factorial(primerOperandoIngresado, 0, 170, &resultadoPrimerFactorial);
					retornoSegundoFactorial = factorial(segundoOperandoIngresado, 0, 170, &resultadoSegundoFactorial);
					banderaDelPrimero = -1;
					printf("\n--------------------------------------------------------------------------\n");
				}
				else
				{
					printf("\n--------------------------------------------------------------------------");
					printf("\n!! No se puede calcular las operaciones sin haber ingresado los operandos !!");
					printf("\n--------------------------------------------------------------------------\n");
				}
				break;

			case 4:
				system("cls");

				//validamos que haya realizado el calculo primero
				if (banderaDelPrimero == -1)
				{
					printf("\n--------------------------------------------------------------------------");
					printf("\n4. Informar resultados");
					printf("\n    A. El resultado de (%.2lf + %.2lf) es: %.2lf", primerOperandoIngresado, segundoOperandoIngresado, resultadoSuma);
					printf("\n    B. El resultado de (%.2lf - %.2lf) es: %.2lf", primerOperandoIngresado, segundoOperandoIngresado, resultadoResta);

					//validando para saber cual enunciado mostrarle al usuario
					if (retornoDivision != 1)
					{
						printf("\n    C. El resultado de (%.2lf / %.2lf) es: %.2lf", primerOperandoIngresado, segundoOperandoIngresado, resultadoDivision);
					}
					else
					{
						printf("\n    C. !! No es posible dividir por cero !!");
					}

					printf("\n    D. El resultado de (%.2lf * %.2lf) es: %.2lf", primerOperandoIngresado, segundoOperandoIngresado, resultadoMultiplicacion);

					//validando para saber cual enunciado mostrarle al usuario
					if (retornoPrimerFactorial != 1)
					{
						if (primerOperandoIngresado > 13)
						{
							printf("\n    E. El factorial de (%d!) es: %e", (int) primerOperandoIngresado, resultadoPrimerFactorial);
						}
						else
						{
							printf("\n    E. El factorial de (%d!) es: %.0lf", (int) primerOperandoIngresado, resultadoPrimerFactorial);
						}
					}
					else
					{
						printf("\n    E. No es posible realizar el factorial de: (%.2lf!)", primerOperandoIngresado);
					}

					if (retornoSegundoFactorial != 1)
					{
						if (segundoOperandoIngresado > 13)
						{
							printf("\n       y el factorial de (%d!) es: %e", (int) segundoOperandoIngresado, resultadoSegundoFactorial);
						}
						else
						{
							printf("\n       y el factorial de (%d!) es: %.0lf", (int) segundoOperandoIngresado, resultadoSegundoFactorial);
						}
					}
					else
					{
						printf("\n       No es posible realizar el factorial de: (%.2lf!)", segundoOperandoIngresado);
					}

					printf("\n--------------------------------------------------------------------------\n");
				}
				else
				{
					printf("\n--------------------------------------------------------------------------");
					printf("\n!! No se pueden mostrar los resultados sin haber calculado las operaciones !!");
					printf("\n--------------------------------------------------------------------------\n");
				}
				break;

			case 5:
				printf("\n**************************************************************************");
				printf("\n                !! Gracias por preferir nuestro sistema !!                ");
				printf("\n**************************************************************************");
				opcionIngresadaMenu = 5;
				sleep(1);
				break;
		}
	} while (opcionIngresadaMenu != 5);
}

