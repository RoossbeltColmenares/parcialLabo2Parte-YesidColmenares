/*
 * eJob.h
 *
 *  Created on: 13 may. 2021
 *      Author: Yesid
 */

#ifndef EJOB_EJOB_H_
#define EJOB_EJOB_H_
#define SIZE_J 500
#define VOID -1
#include "../eDate/eDate.h"
#include "../eBicycleBrand/eBicycleBrand.h"
#include "../eService/eService.h"
#include "../eAuxiliary/eAuxiliary.h"

typedef struct
{
	int idJob;
    int isEmpty;
	int idBicycleBrand;
	int idService;
	eDate date;
} eJob;

/**
 * @brief initialize the isEmpty field to -1
 *
 * @param listJ, struct name
 * @param sizeJ, struct size
 */
void initialitationJob(eJob listJ[], int sizeJ);

/**
 * @brief look for an empty space in the array
 *
 * @param listJ, struct name
 * @param sizeJ, struct size
 * @param freePosition, pointer that returns the free position
 * @return, 1 if it is correct or 2 if there is an error
 */
int searchIsEmptyJob(eJob listJ[], int sizeJ, int *freePosition);

/**
 * @brief check for registered jobs
 *
 * @param listJ, struct name
 * @param sizeJ, struct size
 * @return, 1 if it is correct or 2 if there is an error
 */
int thereAreJobs(eJob listJ[], int sizeJ);

/**
 * @brief find a job by id in array
 *
 * @param listJ, struct name
 * @param sizeJ, struct size
 * @param position, pointer that returns position
 * @param id, position to find
 * @return, 1 if it is correct or 2 if there is an error
 */
int findAJobById(eJob listJ[], int sizeJ, int *position, int id);

/**
 * @brief delete a job using an ID entered
 *
 * @param listJ, struct name
 * @param sizeJ, struct size
 * @param id, position to find
 * @return, 1 if it is correct or 2 if there is an error
 */
int removeJob(eJob listJ[], int sizeJ, int id);

/**
 * @brief organize jobs by year
 *
 * @param listJ, struct name
 * @param sizeJ, struct size
 * @param date, struct name
 * @param sizeD, struct size
 * @param listBB, struct name
 * @return, 1 if it is correct or 2 if there is an error
 */
int sortByYear(eJob listJ[], int sizeJ, eDate date[], int sizeD, eBicycleBrand listBB[]);

/**
 * @brief organize jobs in order of id
 *
 * @param listJ, struct name
 * @param sizeJ, struct size
 * @param date, struct name
 * @return, 1 if it is correct or 2 if there is an error
 */
int originalOrderJob(eJob listJ[], int sizeJ, eDate date[]);

int reports(eJob listJ[], int sizeJ, eService listS[], int sizeS, eBicycleBrand listBB[], eDate date[], int sizeBB, eAuxiliary auxiliary[], int sizeA);
#endif /* EJOB_EJOB_H_ */
