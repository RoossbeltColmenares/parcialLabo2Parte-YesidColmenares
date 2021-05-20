/*
 ============================================================================
 Name        : Examen-YesidColmenares.c
 Author      : Yesid Colmenares
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "nexo/nexo.h"

int main(void)
{
	setbuf(stdout, NULL);

	eJob listJ[SIZE_J];
	eDate date[SIZE_D];
	eService listS[SIZE_S];
	eBicycleBrand listBB[SIZE_BB];
	eAuxiliary auxiliary[SIZE_A];

	int optionEntered;
	int whileCondition;
	int returnValueId;
	int position;
	int totalMoney;

	hardcodedBicycleBrand(listBB);
	initialitationJob(listJ, SIZE_J);
	hardCodeService(listS);

	do
	{
		printMainMenu();
		inputIntR(&optionEntered, "\nEnter option: ", "\nError, enter option: ", 1, 8);

		switch (optionEntered)
		{
			case 1:
				system("cls");
				if (addJob(listJ, SIZE_J, listS, SIZE_S, date, listBB, SIZE_BB) == TRUE)
				{
					system("cls");
					printf("! DATA UPLOADED SUCCESSFULLY !\n");
				}
				else
				{
					system("cls");
					printf("! There is no space available to store more Jobs !\n");
				}
				break;

			case 2:
				system("cls");
				if (thereAreJobs(listJ, SIZE_J) == TRUE)
				{
					printJobs(listJ, SIZE_J, listS, date, listBB);
					inputInt(&returnValueId, "\nEnter the ID to modify: ", "\nError, enter the ID to modify: ");

					if (findAJobById(listJ, SIZE_J, &position, returnValueId) == TRUE)
					{
						if (modificationJob(listJ, SIZE_J, listS, SIZE_S, listBB, SIZE_BB, position, date, auxiliary) == TRUE)
						{
							system("cls");
							printf("! MODIFICATED SUCCESSFULLY !\n");
						}
					}
					else
					{
						system("cls");
						printf("! The specified ID does not exist !\n");
					}
				}
				else
				{
					printf("\n! There are no jobs in the database  !\n");
				}
				break;

			case 3:
				system("cls");
				if (thereAreJobs(listJ, SIZE_J) == TRUE)
				{
					printJobs(listJ, SIZE_J, listS, date, listBB);
					inputInt(&returnValueId, "\nEnter the ID to unsubscribe: ", "\nError, enter the ID to unsubscribe: ");

					if (removeJob(listJ, SIZE_J, returnValueId) == TRUE)
					{
						system("cls");
						printf("! DATA ELIMINATED SUCCESSFULLY !\n");
					}
					else
					{
						system("cls");
						printf("! The specified ID does not exist !\n");
					}
				}
				else
				{
					printf("\n! There are no jobs in the database  !\n");
				}
				break;

			case 4:
				system("cls");
				if (thereAreJobs(listJ, SIZE_J) == TRUE)
				{
					sortByYear(listJ, SIZE_J, date, SIZE_D, listBB);
					printJobs(listJ, SIZE_J, listS, date, listBB);
					originalOrderJob(listJ, SIZE_J, date);
				}
				else
				{
					printf("\n! There are no jobs in the database  !\n");
				}
				break;

			case 5:
				system("cls");
				printServices(listS, SIZE_S);
				break;

			case 6:
				system("cls");
				totalMoney = 0;

				if (thereAreJobs(listJ, SIZE_J) == TRUE)
				{
					totalMoneyServices(listJ, SIZE_J, listS, &totalMoney);
					printTotalMoneyServices(totalMoney);
				}
				else
				{
					printf("\n! There are no jobs in the database  !\n");
				}
				break;

			case 7:
				system("cls");

				if (thereAreJobs(listJ, SIZE_J))
				{
					reports(listJ, SIZE_J, listS, SIZE_S, listBB, date, SIZE_BB, auxiliary, SIZE_A);
				}
				else
				{
					printf("\n! There are no jobs in the database  !\n");
				}
				break;

			case 8:
				system("cls");
				whileCondition = 8;
				break;
		}
	} while (whileCondition != 8);
}

