#include <stdio.h>
#include <stdlib.h>
#include "Files.h"
#include "Room.h"
#pragma warning(disable: 4996 4710)

void encryptionFunction(void* variable, int sizeOfVar)
{
	int i;
	int encryptionNum = -1;
	FILE* f = fopen(TXT_FILE_NAME, "r");
	checkIfFileOpeningSucceeded(f);
	fscanf(f, "%d", &encryptionNum);
	
	for (i = 0; i < sizeOfVar; i++)
	{
		unsigned char* tempVariable = (unsigned char*)variable + i;
		swapBits(tempVariable, encryptionNum);
		encryptXOR(tempVariable);
		encryptByShiftRight(tempVariable, encryptionNum);
		/*test decryptByShiftLeft(tempVariable, encryptionNum); */
	}

}

/*Keren explained that we can do the random number once*/
void createRandomNumberInTextFlie()
{
	int rnd = rand() % 8;
	FILE* f = fopen(TXT_FILE_NAME, "w");
	checkIfFileOpeningSucceeded(f);

	fprintf(f, "%d", rnd);
	fclose(f);
}

void checkIfFileOpeningSucceeded(FILE* f)
{
	if (f == NULL)
	{
		printf("Failed opening the file. Exiting!\n");
		system("pause");
		exit(1);
	}
}

void swapBits(unsigned char* tempVariable, int encryptionNum1)
{
	int encryptionNum2 = 0, bit1=0, bit2=0;
	if (encryptionNum1 != 7)
		encryptionNum2 = encryptionNum1 + 1;
	bit1 = getBitFromRight(*tempVariable, encryptionNum1);
	bit2 = getBitFromRight(*tempVariable, encryptionNum2);
	setBitFromRight(tempVariable, encryptionNum1, bit2);
	setBitFromRight(tempVariable, encryptionNum2, bit1);

}

void encryptXOR(unsigned char* tempVariable)
{
	*tempVariable ^= 255;
}

void encryptByShiftRight(unsigned char* tempVariable, int encryptionNum)
{
	int i;
	unsigned char bit;
	for (i = 0; i < encryptionNum; i++)
	{
		bit = getBitFromRight(*tempVariable, 0);
		*tempVariable = *tempVariable >> 1;
		bit = bit << 7;
		*tempVariable = *tempVariable | bit;
	}
}
void decryptByShiftLeft(unsigned char* tempVariable, int encryptionNum)
{
	int i;
	unsigned char bit;
	for (i = 0; i < encryptionNum; i++)
	{
		bit = getBitFromRight(*tempVariable, 7);
		*tempVariable = *tempVariable << 1;
		*tempVariable = *tempVariable | bit;
	}
}
