/*
 * eJob.c
 *
 *  Created on: 13 may. 2021
 *      Author: Yesid
 */

#include "eJob.h"
#include "../nexo/nexo.h"
#define FALSE 0
#define TRUE 1
#define OCCUPIED 1

void initialitationJob(eJob listJ[], int sizeJ)
{
	int i;
	for (i = 0; i < sizeJ; i++)
	{
		listJ[i].isEmpty = VOID;
	}
}

int searchIsEmptyJob(eJob listJ[], int sizeJ, int *freePosition)
{
	int returnValue;
	int i;

	returnValue = FALSE;

	for (i = 0; i < sizeJ; i++)
	{
		if (listJ[i].isEmpty == VOID)
		{
			*freePosition = i;
			returnValue = TRUE;
			break;
		}
	}
	return returnValue;
}

int thereAreJobs(eJob listJ[], int sizeJ)
{
	int returnValue;
	int i;

	returnValue = FALSE;

	for (i = 0; i < sizeJ; i++)
	{
		if (listJ[i].isEmpty == OCCUPIED)
		{
			returnValue = TRUE;
			break;
		}
	}
	return returnValue;
}

int findAJobById(eJob listJ[], int sizeJ, int *position, int id)
{
	int returnValue;
	int i;
	int sizeA;
	eAuxiliary auxiliary[sizeJ];

	returnValue = FALSE;

	if (activeJobsPosition(listJ, sizeJ, auxiliary, &sizeA) == TRUE)
	{
		for (i = 0; i < sizeA; i++)
		{
			if (listJ[auxiliary[i].id].idJob == id)
			{
				*position = i;
				returnValue = TRUE;
				break;
			}
		}
	}

	return returnValue;
}

int removeJob(eJob listJ[], int sizeJ, int id)
{
	int returnValue;
	int position;

	returnValue = FALSE;
	if (findAJobById(listJ, sizeJ, &position, id) == TRUE)
	{
		listJ[position].isEmpty = VOID;
		listJ[position].idJob = VOID;
		returnValue = TRUE;
	}
	return returnValue;
}

int sortByYear(eJob listJ[], int sizeJ, eDate date[], int sizeD, eBicycleBrand listBB[])
{
	int returnValue;
	int i;
	int j;
	int sizeA;
	eDate dateCpy;
	eAuxiliary auxiliary[sizeJ];
	eJob cpy;

	activeJobsPosition(listJ, sizeJ, auxiliary, &sizeA);

	returnValue = FALSE;

	for (i = 0; i < sizeA - 1; i++)
	{
		for (j = i + 1; j < sizeA; j++)
		{
			if (date[auxiliary[i].id].year > date[auxiliary[j].id].year)
			{
				cpy = listJ[auxiliary[j].id];
				listJ[auxiliary[j].id] = listJ[auxiliary[i].id];
				listJ[auxiliary[i].id] = cpy;

				dateCpy = date[auxiliary[j].id];
				date[auxiliary[j].id] = date[auxiliary[i].id];
				date[auxiliary[i].id] = dateCpy;

				returnValue = TRUE;
			}
			else
			{
				if (date[auxiliary[i].id].year == date[auxiliary[j].id].year)
				{
					sortByBicycleBrand(listJ, date, listBB, auxiliary[i].id, auxiliary[j].id);
				}
			}
		}
	}
	return returnValue;
}

int originalOrderJob(eJob listJ[], int sizeJ, eDate date[])
{
	int returnValue;
	int i;
	int j;
	int sizeA;
	eAuxiliary auxiliary[sizeJ];
	eJob cpy;
	eDate dateCpy;

	activeJobsPosition(listJ, sizeJ, auxiliary, &sizeA);

	returnValue = FALSE;

	for (i = 0; i < sizeA - 1; i++)
	{
		for (j = i + 1; j < sizeA; j++)
		{
			if (listJ[auxiliary[i].id].idJob > listJ[auxiliary[j].id].idJob)
			{
				cpy = listJ[auxiliary[j].id];
				listJ[auxiliary[j].id] = listJ[auxiliary[i].id];
				listJ[auxiliary[i].id] = cpy;

				dateCpy = date[auxiliary[j].id];
				date[auxiliary[j].id] = date[auxiliary[i].id];
				date[auxiliary[i].id] = dateCpy;

				returnValue = TRUE;
			}
		}
	}
	return returnValue;
}

