/*
 * eService.c
 *
 *  Created on: 13 may. 2021
 *      Author: Yesid
 */

#include "eService.h"
#include <stdio.h>
#include <String.h>

void hardCodeService(eService listS[])
{
	listS[0].idService = 20000;
	strcpy(listS[0].description, "CLEANING");
	listS[0].price = 250;

	listS[1].idService = 20001;
	strcpy(listS[1].description, "PATCH");
	listS[1].price = 300;

	listS[2].idService = 20002;
	strcpy(listS[2].description, "CENTERING");
	listS[2].price = 400;

	listS[3].idService = 20003;
	strcpy(listS[3].description, "CHAIN");
	listS[3].price = 350;
}

void printServices(eService listS[], int sizeS)
{
	int i;
	printf("\nID            SERVICE      PRICE");
	for (i = 0; i < sizeS; i++)
	{
		printf("\n%5d %15s %10d", listS[i].idService, listS[i].description, listS[i].price);
	}
}

