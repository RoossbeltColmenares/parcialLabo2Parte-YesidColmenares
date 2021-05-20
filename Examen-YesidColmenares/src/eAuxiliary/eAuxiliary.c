/*
 * eAuxiliary.c
 *
 *  Created on: 13 may. 2021
 *      Author: Yesid
 */
# include "eAuxiliary.h"
#define VOID -1

void initializeStatusAuxiliary(eAuxiliary auxiliary[], int sizeA)
{
	int i;
	for (i = 0; i < sizeA; i++)
	{
		auxiliary[i].id = 0;
		auxiliary[i].isEmpty = VOID;
		auxiliary[i].accountant = 0;
	}
}
