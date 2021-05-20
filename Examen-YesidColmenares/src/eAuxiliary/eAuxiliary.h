/*
 * eAuxiliary.h
 *
 *  Created on: 13 may. 2021
 *      Author: Yesid
 */

#ifndef EAUXILIARY_EAUXILIARY_H_
#define EAUXILIARY_EAUXILIARY_H_
#define SIZE_A SIZE_J

typedef struct
{
	int id;
	int accountant;
	int isEmpty;

} eAuxiliary;

void initializeStatusAuxiliary(eAuxiliary auxiliary[], int sizeA);

#endif /* EAUXILIARY_EAUXILIARY_H_ */
