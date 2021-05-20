
#ifndef EBICYCLEBRAND_EBICYCLEBRAND_H_
#define EBICYCLEBRAND_EBICYCLEBRAND_H_
#define SIZE_BB 6

typedef struct
{
	int idBicycleBrand;
	char bicycleBrand[50];
	int wheelSize;
	char colour[50];

} eBicycleBrand;

/**
 * @brief I manually enter the values of the structure fields
 *
 * @param listBB, struct name
 */
void hardcodedBicycleBrand(eBicycleBrand listBB[]);

/**
 * @brief print bike brands
 *
 * @param listBB, struct name
 * @param sizeBB, struct size
 */
void printBicycleBrand(eBicycleBrand listBB[], int sizeBB);

#endif /* EBICYCLEBRAND_EBICYCLEBRAND_H_ */
