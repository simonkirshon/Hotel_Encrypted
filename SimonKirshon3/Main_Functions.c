#pragma warning(disable: 4996 4710)

#include "Main_Functions.h"
#include <stdio.h>
/*Prints menu*/
void displayMenu()
{
	printf("\nDisplaying functions:\n[1]: Show hotel status.\n[2]: Check room's feature.\n[3]: Check feature in all empty rooms.\n[4]: Check feature in specific hotel rooms.\n[5]: \n[6]: . \n[7]: \n[-1]: Exit.\nPlease choose a function: ");
	getchar();
}

void showChooseFeatures()
{
	printf("Showing features menu: \n");
	printf("   [1]: Check if room has a pool view.\n");
	printf("   [2]: Check if room has a balcony.\n");
	printf("   [3]: Check if room has a kettle.\n");
	printf("   [4]: Check if room has Wi-Fi.\n");
	printf("   [5]: Check if room has a foldable couch.\n");
	printf("   [6]: Check if room has a tv.\n");
	printf("   [7]: Check if room is empty.\n");
	printf("Please choose a feature:  ");
}

void selectFeature(int* feature)
{
	do {
		scanf("%d", feature);
		if (*feature < 1 || *feature > 7)
			printf("invalid feature number. Please try again: ");

	} while (*feature < 1 || *feature > 7);
}