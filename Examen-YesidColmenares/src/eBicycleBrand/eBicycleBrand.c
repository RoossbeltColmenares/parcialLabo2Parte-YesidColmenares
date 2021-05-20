#include "eBicycleBrand.h"
#include <string.h>
#include <stdio.h>

void hardcodedBicycleBrand(eBicycleBrand listBB[])
{
	listBB[0].idBicycleBrand = 25;
	strcpy(listBB[0].bicycleBrand, "TOP MEGA");
	listBB[0].wheelSize = 29;
	strcpy(listBB[0].colour, "YELLOW");

	listBB[1].idBicycleBrand = 26;
	strcpy(listBB[1].bicycleBrand, "VAIRO");
	listBB[1].wheelSize = 27;
	strcpy(listBB[1].colour, "GREEN");

	listBB[2].idBicycleBrand = 27;
	strcpy(listBB[2].bicycleBrand, "VENZO");
	listBB[2].wheelSize = 26;
	strcpy(listBB[2].colour, "RED");

	listBB[3].idBicycleBrand = 28;
	strcpy(listBB[3].bicycleBrand, "RALEIGH");
	listBB[3].wheelSize = 26;
	strcpy(listBB[3].colour, "GRAY");

	listBB[4].idBicycleBrand = 29;
	strcpy(listBB[4].bicycleBrand, "OLMO");
	listBB[4].wheelSize = 27;
	strcpy(listBB[4].colour, "BLACK");

	listBB[5].idBicycleBrand = 30;
	strcpy(listBB[5].bicycleBrand, "TRINX");
	listBB[5].wheelSize = 29;
	strcpy(listBB[5].colour, "ORANGE");
}

void printBicycleBrand(eBicycleBrand listBB[], int sizeBB)
{
	int i;

	printf("\n ID      BICYCLE BRAND    INCH WHEEL       COLOUR");
	for (i = 0; i < sizeBB; i++)
	{
		printf("\n%3d %18s %13d %12s", listBB[i].idBicycleBrand, listBB[i].bicycleBrand, listBB[i].wheelSize, listBB[i].colour);
	}
}
