// Birthdays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define PEOPLE 25
#define DAYS 365
#define TESTSIZE 1000000.0

bool BDay()
{
	int Birthdays[PEOPLE];
	int i;

	srand(GetTickCount());
	
	for(i = 0; i < PEOPLE; i++)
	{
		int ThisBDay = (rand() % 365) + 1;
		//printf("This Birthday: %d\n", ThisBDay);
		for(int j = 0; j < i; j++)
		{
			if(Birthdays[j] == ThisBDay)
			{
				//printf("Match found: %d\n", ThisBDay);
				return true;
			}
			else
			{
				//printf("%d doesn't match %d\n", Birthdays[j], ThisBDay);
			}
		}
		Birthdays[i] = ThisBDay;
	}
	return false;
}

void main()
{
	int Num = 0;
	srand(GetTickCount());
	for(int i = 0; i < TESTSIZE; i++)
	{
		if(BDay())
			Num++;
	}

	printf("In %.0f groups of %d people, %d of the groups had at least one shared birthday\n", TESTSIZE, PEOPLE, Num);
	printf("(%.2f%%)\n\n\n", Num/(TESTSIZE / 100.0));


	system("pause");
}
