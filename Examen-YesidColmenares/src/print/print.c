/*
 * print.c
 *
 *  Created on: 13 may. 2021
 *      Author: Yesid
 */

#include "print.h"

void printJobs(eJob listJ[], int sizeJ, eService listS[], eDate date[], eBicycleBrand listBB[])
{
	int i;
	int sizeJobOccupied;
	eAuxiliary auxiliary[sizeJ];

	activeJobsPosition(listJ, sizeJ, auxiliary, &sizeJobOccupied);

	printf("\n ID      BICYCLE BRAND    INCH WHEEL          COLOUR       SERVICE               DATE");
	for (i = 0; i < sizeJobOccupied; i++)
	{
		printf("\n%3d %18s %13d %15s %13s %10d/%d/%d", listJ[auxiliary[i].id].idJob, listBB[listJ[auxiliary[i].id].idBicycleBrand].bicycleBrand, listBB[listJ[auxiliary[i].id].idBicycleBrand].wheelSize,
				listBB[listJ[auxiliary[i].id].idBicycleBrand].colour, listS[listJ[auxiliary[i].id].idService].description, date[auxiliary[i].id].day, date[auxiliary[i].id].month, date[auxiliary[i].id].year);
	}
}

void printTotalMoneyServices(int totalMoney)
{
	printf("\nTotal money for services rendered: %d", totalMoney);
}

void printModificationsMenu(eJob listJ[], eService listS[], eBicycleBrand listBB[], eDate date[], int id)
{
	printf("--------------------------------------------------------------------------------------");
	printf("\n ID      BICYCLE BRAND    INCH WHEEL          COLOUR       SERVICE               DATE");
	printf("\n%3d %18s %12d %15s %13s %10d/%d/%d", listJ[id].idJob, listBB[listJ[id].idBicycleBrand].bicycleBrand, listBB[listJ[id].idBicycleBrand].wheelSize, listBB[listJ[id].idBicycleBrand].colour, listS[listJ[id].idService].description,
			date[id].day, date[id].month, date[id].year);
	printf("\n-------------------------------------------------------------------------------------");
	printf("\n-----------------------------------MODIFICATIONS-------------------------------------");
	printf("\n1. Modify bicycle brand");
	printf("\n2. Modify the service");
	printf("\n3. Exit");

}

void printMainMenu(void)
{
	printf("\n-----------------------------WELCOM TO OUR DATA SYSTEM-------------------------------");
	printf("\n1. Add job");
	printf("\n2. Modify job");
	printf("\n3. Remove job");
	printf("\n4. Job list");
	printf("\n5. List of services");
	printf("\n6. Total");
	printf("\n7. Reports");
	printf("\n8. Exit");
}

void printReportsMenu(void)
{
	printf("\n--------------------------------------REPORTS----------------------------------------");
	printf("\n1. List of all jobs ordered by bicycle brand");
	printf("\n2. The service(s) with the most work performed");
	printf("\n3. List of services with the data of the bicycles that were performed");
	printf("\n4. The number of Red bicycles that performed a service chosen by the user");
	printf("\n5. Exit");
}
