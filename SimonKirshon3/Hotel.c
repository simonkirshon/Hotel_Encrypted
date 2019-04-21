#pragma warning(disable: 4996 4710)

#include "Hotel.h"
#include "Room.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void initHotel(hotel_t*  emptyHotel)
{
	int i, j;
	printf("Please choose number of floors: ");
	scanf("%d", &emptyHotel->numFloors);
	printf("Please choose number of rooms each floor (1-99): ");
	while ((emptyHotel->numRooms < 1) || (emptyHotel->numRooms >= MAX_ROOMS_PER_FLOOR)) {
		scanf("%d", &emptyHotel->numRooms);
		if (emptyHotel->numRooms < 1 || emptyHotel->numRooms >MAX_ROOMS_PER_FLOOR)
			printf("Number of rooms entered is not between 1 and 99. Try again: ");
	}
	emptyHotel->roomMatrix = (room_t**)malloc(sizeof(room_t*)*emptyHotel->numFloors);
	if (!(emptyHotel->roomMatrix)) // (arr == NULL) --> allocaton didn't succeed
	{
		printf("ERROR! Out of memory!\n");
		exit(1);
	}
	for (i = 0; i < emptyHotel->numFloors; i++) {
		emptyHotel->roomMatrix[i] = (room_t*)malloc(sizeof(room_t)*emptyHotel->numRooms);
		for (j = 0; j < emptyHotel->numRooms; j++)
		{
			enterRoomDetails(&(emptyHotel->roomMatrix)[i][j]);
		}
	}
}

void showHotelStatus(hotel_t hotel)
{
	int i, j;
	for (i = 0; i < hotel.numFloors; i++)
	{
		for (j = 0; j < hotel.numRooms; j++)
		{
			if (j%hotel.numRooms == 0)
			{
				printf("Floor %3d:\n", i + 1);
			}
			if (j + 1 < 10)
				printf("   -Room %d0%d: ", i + 1, j + 1);
			else
				printf("   -Room %d%d: ", i + 1, j + 1);
			printRoomDetails(hotel.roomMatrix[i][j]);
			printf("\n");
		}
	}
}

int checkRoomfeature(room_t theRoom, int featureNum)
{
	return getBitFromRight(theRoom.roomDetails, featureNum);
}

room_t getRoomByNumber(hotel_t hotel, int roomNum)
{
	int floors = (roomNum - 1) / MAX_ROOMS_PER_FLOOR ;
	int rooms = (roomNum - 1) % (MAX_ROOMS_PER_FLOOR + 1) + 1;
	while (floors > hotel.numFloors || floors < 1 || rooms > hotel.numRooms || rooms < 1)
	{
	printf("Invalid number of room. Try again: ");
	scanf("%d", &roomNum);
	floors = (roomNum - 1) / MAX_ROOMS_PER_FLOOR;
	rooms = (roomNum - 1) % (MAX_ROOMS_PER_FLOOR + 1) + 1;
	}
	return hotel.roomMatrix[((roomNum - 1) / MAX_ROOMS_PER_FLOOR) - 1][(roomNum - 1) % (MAX_ROOMS_PER_FLOOR + 1)];

}

void checkFeatureInHotelRooms(hotel_t hotel, int feature)
{
	int bool,i,j;
	for (i = 0; i < hotel.numFloors; i++)
	{
		for (j = 0; j < hotel.numRooms; j++)
		{
		
			bool = checkRoomfeature(hotel.roomMatrix[i][j], EMPTY_FEATURE);
			if (bool)
			{
				bool = checkRoomfeature(hotel.roomMatrix[i][j], feature);
				if (bool) 
				{
				printf("Feature exists in room %d0%d.\n", i + 1, j + 1);
				printRoomDetails(hotel.roomMatrix[i][j]);
				printf("\n");
				}
			}
		}
	}
	
}

void checkFeatureInSpecificRooms(int feature, room_t* room, ...)
{
	printf("Checking if feature exists in specific rooms: \n");
	int bool;
	va_list   allRooms;
	room_t* currentRoom;
	va_start(allRooms, room);
	currentRoom = room;
	while (currentRoom != NULL) {
		bool = checkRoomfeature(*currentRoom, feature);
		if (bool)
		{
			printRoomDetails(*currentRoom);
			printf("\n");
		}
		currentRoom = va_arg(allRooms, room_t*);
	}
	va_end(allRooms);
}
