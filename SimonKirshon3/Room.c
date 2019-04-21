#include <stdio.h>
#include <stdlib.h>
#include "Room.h"
#pragma warning(disable: 4996 4710)


void enterRoomDetails(room_t* theRoom)
{
	
	int i = 0;
	int rnd = 0;

	rnd = rand() % 4 + 1;
	(*theRoom).numOfBeds = rnd;
	while (i < MAX_NUMBER_OF_PROPERTIES) 
	{
		rnd = rand() % 2;
		setBitFromRight(&theRoom->roomDetails, i, rnd);
		i++;
	}
}

void printRoomDetails(room_t theRoom)
{
	printf("Printing room's unique properties: \n");
	printf("\t-Number of beds: %d.\n", theRoom.numOfBeds);
	int i, size;
	int num;
	void(*printProperties[])(num) = { printHasView, printHasBalcony, printHasKettle, printHasWifi, printHasCouch, printHasTV, printIsEmpty };
	size = sizeof(printProperties) / sizeof(printProperties[0]);
	for (i = 0; i < size; i++)
	{
		num = getBitFromRight(theRoom.roomDetails, i);
		printProperties[i](num);
	}
}

void setBitFromRight(unsigned char *ch, int index, int value)
{
	unsigned char mask = 1; // 00000001
	mask <<= index;

	if (value == 1)
		*ch = *ch | mask;
	else
	{
		mask = ~mask;
		*ch = *ch & mask;
	}
}

int getBitFromRight(unsigned char ch, int index)
{
	unsigned char mask = 1; // 00000001
	mask = mask << index;

	if ((ch & mask) == 0)
		return 0;
	else
		return 1;
}

void printHasView(int num)
{
	if(num)
		printf("\t-Room has a pool view.\n");
}

void printHasBalcony(int num)
{
	if(num)
		printf("\t-Room has a balcony.\n");
}

void printHasKettle(int num)
{
	if(num)
		printf("\t-Room has a kettle.\n");
}

void printHasWifi(int num)
{
	if(num)
		printf("\t-Room has Wi-Fi.\n");

}

void printHasCouch(int num)
{
	if(num)
		printf("\t-Room has a folding couch.\n");
}

void printHasTV(int num)
{
	if(num)
		printf("\t-Room has a TV.\n");
}

void printIsEmpty(int num)
{
	if(num)
		printf("\t-Room isn't Empty\n");
}

