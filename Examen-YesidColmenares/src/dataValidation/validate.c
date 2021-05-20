/*
 * validate.c
 *
 *  Created on: 18 abr. 2021
 *      Author: Yesid
 */

#include "validate.h"

#include "charString.h"
#define TRUE 1
#define FALSE 0

int validateRangeDouble(double value, double min, double max)
{
	int returnValue;

	returnValue = FALSE;

	if (value < min || value > max)
	{
		returnValue = TRUE;
	}

	return returnValue;
}

int validateRangeInt(int value, int min, int max)
{
	int returnValue;

	returnValue = FALSE;

	if (value < min || value > max)
	{
		returnValue = TRUE;
	}

	return returnValue;
}

int validateRangeFloat(float value, float min, float max)
{
	int returnValue;

	returnValue = FALSE;

	if (value < min || value > max)
	{
		returnValue = TRUE;
	}

	return returnValue;
}

int validationString(char *charStringEntered)
{
	int returnValue;
	int i;

	returnValue = TRUE;
	for (i = 0; charStringEntered[i] != '\0'; i++)
	{
		if (isSymbol_Number(charStringEntered[i]) == TRUE)
		{
			returnValue = FALSE;
			break;
		}
	}

	return returnValue;
}

