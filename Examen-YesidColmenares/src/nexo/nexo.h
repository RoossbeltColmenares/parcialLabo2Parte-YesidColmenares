/*
 * nexo.h
 *
 *  Created on: 13 may. 2021
 *      Author: Yesid
 */

#ifndef NEXO_NEXO_H_
#define NEXO_NEXO_H_

#define TRUE 1
#define FALSE 0
#include "../eBicycleBrand/eBicycleBrand.h"
#include "../dataEntry/input.h"
#include "../print/print.h"
#include "../dataValidation/charString.h"

/**
 * @brief add a job to the array
 *
 * @param listJ struct name
 * @param sizeJ struct size
 * @param listS struct name
 * @param sizeS struct size
 * @param date struct name
 * @param listBB struct name
 * @param sizeBB struct size
 * @return, 1 if it is correct or 2 if there is an error
 */
int addJob(eJob listJ[], int sizeJ, eService listS[], int sizeS, eDate date[], eBicycleBrand listBB[], int sizeBB);

/**
 * @brief fill array fields in free position
 *
 * @param listJ struct name
 * @param listS struct name
 * @param sizeS struct size
 * @param date struct name
 * @param listBB struct name
 * @param sizeBB struct size
 * @param freePosition, position where the new job will be entered
 */
void fillJob(eJob listJ[], eService listS[], int sizeS, eDate date[], eBicycleBrand listBB[], int sizeBB, int freePosition);

/**
 * @brief traverses the matrix in search of the positions that are occupied
 *
 * @param listJ struct name
 * @param sizeJ struct size
 * @param auxiliary, returns occupied positions to work only with occupied spaces
 * @param sizeA struct size
 * @return, 1 if it is correct or 2 if there is an error
 */
int activeJobsPosition(eJob listJ[], int sizeJ, eAuxiliary auxiliary[], int *sizeA);

/**
 * @brief
 *
 * @param listJ struct name
 * @param sizeJ struct size
 * @param listS struct name
 * @param sizeS struct size
 * @param listBB struct name
 * @param sizeBB struct size
 * @param position, position id to modify
 * @param date struct name
 * @param auxiliary struct name
 * @return, 1 if it is correct or 2 if there is an error
 */
int modificationJob(eJob listJ[], int sizeJ, eService listS[], int sizeS, eBicycleBrand listBB[], int sizeBB, int position, eDate date[], eAuxiliary auxiliary[]);

/**
 * @brief calculate the total money for services
 *
 * @param listJ struct name
 * @param sizeJ struct size
 * @param listS struct name
 * @param totalMoney, pointer that returns the total money
 */
void totalMoneyServices(eJob listJ[], int sizeJ, eService listS[], int *totalMoney);

/**
 * @brief arranges the array according to the positions it receives as a parameter
 *
 * @param listJ struct name
 * @param sizeJ struct size
 * @param date struct name
 * @param sizeD struct size
 * @param listBB struct name
 * @param i, position i
 * @param j, position j
 * @return, 1 if it is correct or 2 if there is an error
 */
int sortByBicycleBrand(eJob listJ[], eDate date[], eBicycleBrand listBB[], int i, int j);

int listJobsOrderedByBicycleBrand(eJob listJ[], int sizeJ, eBicycleBrand listBB[], int sizeBB, eDate date[]);

int servicesWithTheMostWorkPerformed(eJob listJ[], int sizeJ, eService listS[], int sizeS, eAuxiliary auxiliary[], int sizeA);

int totalServices(eJob listJ[], int sizeJ, eService listS[], int sizeS, eAuxiliary auxiliary[], int sizeA);

int mostRepeatedService(eAuxiliary auxiliary[], int sizeA, int *moreRepeated);

int repeatedService(eAuxiliary auxiliary[], int sizeA, int moreRepeated);

void printServicesWithTheMostWorkPerformed(eService listS[], eAuxiliary auxiliary[], int sizeA);

int printServicesWithDataOfTheBicyclesPerformed(eJob listJ[], int sizeJ, eService listS[], int sizeS, eBicycleBrand listBB[], eDate date[]);






#endif /* NEXO_NEXO_H_ */
