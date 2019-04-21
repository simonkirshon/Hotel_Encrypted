#ifndef __HOTEL_H
#define __HOTEL_H
#include "Room.h"


typedef struct
{
	int numFloors;
	int numRooms;
	room_t** roomMatrix;
} hotel_t;

void initHotel(hotel_t*  emptyHotel);
void showHotelStatus(hotel_t hotel);
int checkRoomfeature(room_t theRoom, int featureNum);
room_t getRoomByNumber(hotel_t hotel, int roomNum);
void checkFeatureInHotelRooms(hotel_t hotel, int feature);
void checkFeatureInSpecificRooms(int feature, room_t* room, ...);
#endif //!__HOTEL_H