/*
 * nexo.c
 *
 *  Created on: 13 may. 2021
 *      Author: Yesid
 */

#include "nexo.h"
#include "../eJob/eJob.h"
#define OCCUPIED 1
#define FALSE 0
#define TRUE 1

int addJob(eJob listJ[], int sizeJ, eService listS[], int sizeS, eDate date[], eBicycleBrand listBB[], int sizeBB)
{
	int returnValue;
	int freePosition;

	returnValue = FALSE;
	if (searchIsEmptyJob(listJ, sizeJ, &freePosition) == TRUE)
	{
		fillJob(listJ, listS, sizeS, date, listBB, sizeBB, freePosition);
		returnValue = TRUE;
	}

	return returnValue;
}

void fillJob(eJob listJ[], eService listS[], int sizeS, eDate date[], eBicycleBrand listBB[], int sizeBB, int freePosition)
{
	listJ[freePosition].isEmpty = OCCUPIED;
	listJ[freePosition].idJob = freePosition;

	printBicycleBrand(listBB, sizeBB);
	inputIntR(&listJ[freePosition].idBicycleBrand, "\n\nEnter bicycle ID: ", "Error, enter bicycle ID: ", listBB[0].idBicycleBrand, listBB[sizeBB - 1].idBicycleBrand);
	listJ[freePosition].idBicycleBrand = listJ[freePosition].idBicycleBrand - 25;

	printServices(listS, sizeS);
	inputIntR(&listJ[freePosition].idService, "\n\nEnter Service ID: ", "Error, enter Service ID: ", listS[0].idService, listS[sizeS - 1].idService);
	listJ[freePosition].idService = listJ[freePosition].idService - 20000;

	inputIntR(&date[freePosition].day, "Enter day: ", "\nError, enter day:", 1, 31);
	inputIntR(&date[freePosition].month, "Enter month: ", "\nError, enter month:", 1, 12);
	inputIntR(&date[freePosition].year, "Enter year: ", "\nError, enter year:", 2000, 3000);
}

int activeJobsPosition(eJob listJ[], int sizeJ, eAuxiliary auxiliary[], int *sizeA)
{
	int returnValue;
	int i;
	int j;

	returnValue = FALSE;

	j = 0;
	for (i = 0; i < sizeJ; i++)
	{
		if (listJ[i].isEmpty == OCCUPIED)
		{
			auxiliary[j].id = i;
			j++;
			returnValue = TRUE;
		}
	}
	*sizeA = j;
	return returnValue;
}

int modificationJob(eJob listJ[], int sizeJ, eService listS[], int sizeS, eBicycleBrand listBB[], int sizeBB, int position, eDate date[], eAuxiliary auxiliary[])
{
	int returnValue;
	int option;
	int whileCondition;

	returnValue = FALSE;
	do
	{
		system("cls");
		printModificationsMenu(listJ, listS, listBB, date, position);
		inputIntR(&option, "\nEnter option: ", "\nError, enter option: ", 1, 3);
		switch (option)
		{
			case 1:
				system("cls");
				printBicycleBrand(listBB, sizeBB);
				inputIntR(&listJ[position].idBicycleBrand, "\n\nEnter bicycle ID: ", "Error, enter bicycle ID: ", listBB[0].idBicycleBrand, listBB[sizeBB - 1].idBicycleBrand);
				listJ[position].idBicycleBrand = listJ[position].idBicycleBrand - 25;
				returnValue = TRUE;
				break;

			case 2:
				system("cls");
				printServices(listS, sizeS);
				inputIntR(&listJ[position].idService, "\n\nEnter Service ID: ", "Error, enter Service ID: ", listS[0].idService, listS[sizeS - 1].idService);
				listJ[position].idService = listJ[position].idService - 20000;
				returnValue = TRUE;
				break;

			case 3:
				system("cls");
				whileCondition = 3;
				break;
		}
	} while (whileCondition != 3);

	return returnValue;
}

void totalMoneyServices(eJob listJ[], int sizeJ, eService listS[], int *totalMoney)
{
	int i;
	int sizeA;
	eAuxiliary auxiliary[SIZE_J];

	activeJobsPosition(listJ, sizeJ, auxiliary, &sizeA);

	for (i = 0; i < sizeA; i++)
	{
		*totalMoney += listS[listJ[auxiliary[i].id].idService].price;
	}
}

int sortByBicycleBrand(eJob listJ[], eDate date[], eBicycleBrand listBB[], int i, int j)
{
	int returnValue;
	eJob jobCpy;
	eDate dateCpy;

	returnValue = FALSE;
	if (strcmp(listBB[listJ[i].idBicycleBrand].bicycleBrand, listBB[listJ[j].idBicycleBrand].bicycleBrand) > 0)
	{
		jobCpy = listJ[j];
		listJ[j] = listJ[i];
		listJ[i] = jobCpy;

		dateCpy = date[j];
		date[j] = date[i];
		date[i] = dateCpy;
		returnValue = TRUE;
	}

	return returnValue;
}

int reports(eJob listJ[], int sizeJ, eService listS[], int sizeS, eBicycleBrand listBB[], eDate date[], int sizeBB, eAuxiliary auxiliary[], int sizeA)
{
	int returnValue;
	int conditionWhile;
	int option;
	int quantityRedBicycles;

	quantityRedBicycles = 0;
	returnValue = FALSE;
	do
	{
		initializeStatusAuxiliary(auxiliary, SIZE_A);
		printReportsMenu();
		inputIntR(&option, "\nEnter option: ", "\nError, enter option: ", 1, 5);
		switch (option)
		{
			case 1:
				system("cls");
				listJobsOrderedByBicycleBrand(listJ, sizeJ, listBB, sizeBB, date);
				printJobs(listJ, sizeJ, listS, date, listBB);
				returnValue = TRUE;
				break;

			case 2:
				system("cls");
				servicesWithTheMostWorkPerformed(listJ, sizeJ, listS, sizeS, auxiliary, sizeA);
				printServicesWithTheMostWorkPerformed(listS, auxiliary, sizeA);
				returnValue = TRUE;
				break;

			case 3:
				system("cls");
				printServicesWithDataOfTheBicyclesPerformed(listJ, sizeJ, listS, sizeS, listBB, date);
				returnValue = TRUE;
				break;

			case 4:
				system("cls");
				redBicyclesThatWereProvidedSomeService(listJ, sizeJ, listBB, &quantityRedBicycles);
				printBicyclesThatWereProvidedSomeService(quantityRedBicycles);
				returnValue = TRUE;
				break;

			case 5:
				system("cls");
				conditionWhile = 5;
				break;
		}
	} while (conditionWhile != 5);

	return returnValue;
}

int redBicyclesThatWereProvidedSomeService(eJob listJ[], int sizeJ, eBicycleBrand listBB[], int *quantityRedBicycles)
{
	int i;
	int sizeA;
	int returnValue;
	int accountant;

	accountant = 0;
	returnValue = FALSE;
	eAuxiliary auxiliary[sizeJ];

	activeJobsPosition(listJ, sizeJ, auxiliary, &sizeA);

	for (i = 0; i < sizeA; i++)
	{
		if (strcmp(listBB[listJ[auxiliary[i].id].idBicycleBrand].colour, "RED") == 0)
		{
			accountant++;
			*quantityRedBicycles = accountant;
			returnValue = TRUE;
		}
	}
	return returnValue;
}

int listJobsOrderedByBicycleBrand(eJob listJ[], int sizeJ, eBicycleBrand listBB[], int sizeBB, eDate date[])
{
	int returnValue;
	int i;
	int j;
	int sizeA;
	eAuxiliary auxiliary[sizeJ];

	activeJobsPosition(listJ, sizeJ, auxiliary, &sizeA);

	returnValue = FALSE;

	for (i = 0; i < sizeA - 1; i++)
	{
		for (j = i + 1; j < sizeA; j++)
		{
			sortByBicycleBrand(listJ, date, listBB, auxiliary[i].id, auxiliary[j].id);
		}
	}
	return returnValue;
}

int servicesWithTheMostWorkPerformed(eJob listJ[], int sizeJ, eService listS[], int sizeS, eAuxiliary auxiliary[], int sizeA)
{
	int returnValue;
	int moreRepeated;

	if (totalServices(listJ, sizeJ, listS, sizeS, auxiliary, sizeA) == TRUE)
	{
		mostRepeatedService(auxiliary, sizeA, &moreRepeated);
		repeatedService(auxiliary, sizeA, moreRepeated);
		returnValue = TRUE;
	}

	return returnValue;
}

int totalServices(eJob listJ[], int sizeJ, eService listS[], int sizeS, eAuxiliary auxiliary[], int sizeA)
{
	int i;
	int j;
	int returnValue;

	if (activeJobsPosition(listJ, sizeJ, auxiliary, &sizeA) == TRUE)
	{
		for (i = 0; i < sizeA; i++)
		{
			for (j = 0; j < sizeS; j++)
			{
				if (listJ[auxiliary[i].id].idService + 20000 == listS[j].idService)
				{
					auxiliary[j].accountant++;
					returnValue = TRUE;
				}
			}
		}
	}
	return returnValue;
}

int mostRepeatedService(eAuxiliary auxiliary[], int sizeA, int *moreRepeated)
{
	int i;
	int returnValue;

	returnValue = FALSE;

	for (i = 0; i < sizeA; i++)
	{
		if (*moreRepeated < auxiliary[i].accountant || returnValue == 0)
		{
			*moreRepeated = auxiliary[i].accountant;
			returnValue = TRUE;
		}
	}
	return returnValue;
}

int repeatedService(eAuxiliary auxiliary[], int sizeA, int moreRepeated)
{
	int returnValue;
	int i;

	returnValue = FALSE;
	for (i = 0; i < sizeA; i++)
	{
		if (moreRepeated == auxiliary[i].accountant)
		{
			moreRepeated = auxiliary[i].accountant;
			auxiliary[i].id = i;
			auxiliary[i].isEmpty = OCCUPIED;
			returnValue = TRUE;
		}
	}
	return returnValue;
}

