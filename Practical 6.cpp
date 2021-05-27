#include <iostream>
#include <stdio.h>
#include <ctype.h>


/*
	The Durban July is an annual horse race that has been presented every year since 1897. Write a C/C++ program to handle registrations for the race. The program must meet the following specifications:

	Create a structure (struct) to save the following information for each horse in the race:
	Name - up to 20 characters;
	Age - Age in years (integer);
	Height - The height of the horse in hands (integer); and
	Time that the horse achieved in the last race in seconds (real value).
	Create an array of structures (structs) that are used to save the information for four horses. The user types in the information for each horse.
	After the horse's information is stored in the array, the schedule for the race must be displayed based on the contents of the array. Iterate through the array and display the information on one line for each horse.
	The horse with the best time for the previous race is named as the favorite. Iterate through the array, identify the horse with the best time and show it at the bottom of the schedule. Assume that each horse's time will be unique.
*/

using namespace std;


//STRUCTURE TYPE - HORSE
struct Horse
{
    char name[20] = "";
    int age;
    int height;
    float time;
};



int main()
{
    struct Horse Race[4];      //NUMBER OF HORSES IN RACE
    int rcount = 0;            //RACE COUNT
    float Favourite = 0;
    string sName;

    //MY CODE
    printf("\t-=Welcome to the Durban July=-\n");

    //INTRODUCING MY FOR LOOOP
    for(rcount = 0; rcount<sizeof(Race)/sizeof(Horse); ++rcount)
    {
        printf_s("=====================================\n");
        printf_s("Enter details for horse #%d\n", rcount+1);  //rcount+1, SO THAT IT CAN START FROM ONE
        printf_s("=====================================\n");

        //DISPLAYING THE NAME
        printf_s("Horse #%d - Name: ",rcount+1);
        scanf   ("%s", &Race[rcount].name);

        //DISPLAYING THE AGE
        printf_s("Horse #%d - Age: ",rcount+1);
        scanf   ("%d", &Race[rcount].age);

        //DISPLAYING HEIGHT
        printf_s("Horse #%d - Height: ",rcount+1);
        scanf   ("%d", &Race[rcount].height);

        //DISPLAYING TIME
        printf_s("Horse #%d - Time for last race: ",rcount+1);
        scanf   ("%f", &Race[rcount].time);

        if(rcount == 0)
        {
            Favourite = Race[rcount].time;
            sName = Race[rcount].name;
        }
        else
        {
            if(Race[rcount].time<Favourite)
            {
                Favourite = Race[rcount].time;
                sName = Race[rcount].name;
            }
        }
    }//CLOSING MY FIRST FOR LOOP

        printf_s("\n\n******************************************************************\n");
        printf_s("\t\t\tRoster for next race");
        printf_s("\n******************************************************************");


        //MY SECOND FOOR LOOP
        for(rcount = 0; rcount<sizeof(Race)/sizeof(Horse); ++rcount)
        {
            printf("\n%d.\tName: %s\tAge: %d years \tHeight: %d hands \tLast run: %.2f seconds", rcount+1, Race[rcount].name, Race[rcount].age, Race[rcount].height, Race[rcount].time);

        }
            printf_s("\n******************************************************************");
            cout<<"\nRace favourite: " <<sName<<", with a time of: "<<Favourite <<endl;
            printf_s("\n******************************************************************");
     return 0;
    }


