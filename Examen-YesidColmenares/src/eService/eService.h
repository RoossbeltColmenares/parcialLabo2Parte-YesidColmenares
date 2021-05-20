/*
 * eService.h
 *
 *  Created on: 13 may. 2021
 *      Author: Yesid
 */

#ifndef ESERVICE_ESERVICE_H_
#define ESERVICE_ESERVICE_H_
#define SIZE_S 4

typedef struct
{
	int idService;
	char description[25];
	int price;
} eService;

/**
 * @brief I manually enter the values of the structure fields
 *
 * @param service, struct name
 */
void hardCodeService(eService service[]);


/**
 * @brief print services
 *
 * @param listS struct name
 * @param sizeS struct size
 */
void printServices(eService listS[], int sizeS);

#endif /* ESERVICE_ESERVICE_H_ */
