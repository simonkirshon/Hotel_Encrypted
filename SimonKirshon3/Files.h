#include <stdio.h>
#ifndef __FILES_H
#define __FILES_H
#define TXT_FILE_NAME "myTxtFile.txt"
#define BINARY_FILE_NAME "myBinaryFile.bin"


void createRandomNumberInTextFlie();
void encryptionFunction(void* variable, int sizeOfVar);
void checkIfFileOpeningSucceeded(FILE* f);
void swapBits(unsigned char* tempVariable, int encryptionNum1);
void encryptXOR(unsigned char* tempVariable);
void encryptByShiftRight(unsigned char* tempVariable, int encryptionNum);
void decryptByShiftLeft(unsigned char* tempVariable, int encryptionNum);
#endif //!__FILES_H