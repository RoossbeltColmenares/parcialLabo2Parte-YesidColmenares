/*
 * print.h
 *
 *  Created on: 13 may. 2021
 *      Author: Yesid
 */

#include "../eAuxiliary/eAuxiliary.h"
#include "../eDate/eDate.h"
#include "../eJob/eJob.h"
#include "../eService/eService.h"
#include "../nexo/nexo.h"

#ifndef PRINT_PRINT_H_
#define PRINT_PRINT_H_

/**
 * @brief print current jobs
 *
 * @param listJ struct name
 * @param sizeJ struct size
 * @param listS struct name
 * @param date struct name
 * @param auxiliary struct name
 * @param listBB
 */
void printJobs(eJob listJ[], int sizeJ, eService listS[], eDate date[], eBicycleBrand listBB[]);

/**
 * @brief print total money for services
 *
 * @param totalMoney
 */
void printTotalMoneyServices(int totalMoney);

/**
 * @brief print modifications menu
 *
 * @param listJ struct name
 * @param listS struct name
 * @param listBB struct name
 * @param date struct name
 * @param id, id of the job to modify
 */
void printModificationsMenu(eJob listJ[], eService listS[], eBicycleBrand listBB[], eDate date[], int id);

/**
 * @brief print main menu
 *
 */
void printMainMenu(void);

void printReportsMenu(void);

#endif /* PRINT_PRINT_H_ */
