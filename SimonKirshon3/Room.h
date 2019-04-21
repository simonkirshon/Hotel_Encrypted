#ifndef  __ROOM_H
#define  __ROOM_H

#define MAX_ROOMS_PER_FLOOR 99
#define MAX_NUMBER_OF_PROPERTIES 7
#define EMPTY_FEATURE 7

typedef struct {
	int numOfBeds;
	unsigned char roomDetails;
}room_t;

void enterRoomDetails(room_t* theRoom);
void printRoomDetails(room_t theRoom);
void setBitFromRight(unsigned char* ch, int index, int value);
int getBitFromRight(unsigned char ch, int index);
void printHasView(int num);
void printHasBalcony(int num);
void printHasKettle(int num);
void printHasWifi(int num);
void printHasCouch(int num);
void printHasTV(int num);
void printIsEmpty(int num);

#endif // ! __ROOM_H
