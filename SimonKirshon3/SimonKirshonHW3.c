#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Room.h"
#include "Hotel.h"
#include "Main_Functions.h"
#include "Files.h"

#pragma warning(disable: 4996 4710)

void main() {
	int i, input;
	hotel_t hotel;

	srand((unsigned int)time(NULL));

	printf("Creating hotel:\n");
	initHotel(&hotel);
	printf("Hotel has been created. \n\n");
	createRandomNumberInTextFlie();

	if (hotel.numRooms > 2)
	{
		checkFeatureInSpecificRooms(BALCONY_FEATURE, &hotel.roomMatrix[0][0], &hotel.roomMatrix[0][1], &hotel.roomMatrix[0][2],NULL);
		printf("\n");
	}
	do
	{
		displayMenu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			showHotelStatus(hotel);
			break;
		case 2:
		{
			/*I am not sure if this is supposed to be in the main, or just used in 2.d. Added it anyways, just in case I might be wrong.*/
			int roomNum = 0, feature = 0, bool = 0;
			printf("Enter a room number: ");
			scanf("%d", &roomNum);
			room_t theRoom = getRoomByNumber(hotel, roomNum);
			showChooseFeatures();
			selectFeature(&feature);
			bool = checkRoomfeature(theRoom, feature - 1);
			if (bool)
				printf("Feature exists in room %d.\n", roomNum);
			else
				printf("Feature doesn't exist in room %d.\n", roomNum);
		}
		break;
		case 3:
		{
			
			int feature = 0;
			showChooseFeatures();
			selectFeature(&feature);
			checkFeatureInHotelRooms(hotel, feature - 1);
		}
		break;
		case 4:
		{
			int roomNum = 0, feature = 0, bool = 0;
			showChooseFeatures();
			selectFeature(&feature);

			break;
		}
		case 5:
			/*After keren's explanation, seems like it's allowed to make a function that does the random number once. So I created a function that does that.*/
			encryptionFunction(&hotel.roomMatrix[0][0], sizeof(room_t));
			printRoomDetails(hotel.roomMatrix[0][0]);
			break;
		case 6:
	
			break;
		case 7:
		{

		}
		break;
		case -1:
			break;
		default:
			printf("Invalid option selected. Please try again.\n");
			break;
		}
	} while (input != -1);


	



	for (i = 0; i < hotel.numFloors; i++)
		free(hotel.roomMatrix[i]);
	free(hotel.roomMatrix);
	system("pause");
}