#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*
	The rand() function generates a pseudo-random integer from 0 to RAND_MAX. This can be used to generate a random integer from 0 to N-1 by using the modulo operator %: rand() % N, where N is the desired number of possible values.

	Use this function to generate three statistics for a virtual character, such as Agility, Strength and Intellect. These stats should range in values from 0 up to and including 10.	 

	Your program should ask the user to pick from one of three character classes, such as a Rogue, Warrior or Mage.

	Each of these classes should correspond to one main statistic. (Ex: Rogue uses Agility, Warrior uses Strength, Mage uses Intellect). The program should then display the statistics with their random values to the user. Make use of a switch statement.	 

	Should the user's main statistic (ex. Agility if the user picked Rogue) be greater or equal to 6, the user is deemed to be strong enough to slay the dragon. 

	Display appropriate messages to the user during all steps. (String variables are not expected.)

	Read Generating Pseudo-Random Integers from Beginning C, p153 and adjust your program to display different values every time the program runs.
*/

using namespace std;

int main()
{
    int classes;
    int Agility;
    int Strength;
    int Intellect;
    int r = 0;
    int N = 10;
    srand(time(NULL));
    r = (rand()%N);


    printf("Choose your class:\n");
    printf("1 for Rogue\n");
    printf("2 for Warrior\n");
    printf("3 for Mage\n\n");

    printf("Enter the value: ");
    scanf ("%d", &classes);
    printf("\n");

    switch (classes){
    case 1:
        printf("Your stats are: ");
        printf("\nAgility: %d ",rand()%N);
        printf("\nStrength: %d ",rand()%N);
        printf("\nIntellect: %d ",rand()%N);
        printf("\n\nYou have picked a Rogue.");
        Agility = r;
        if (Agility >=6 )
            printf("\nYour agility is high enough to slay the dragon.");
        else
            printf("\nYour agility is low, you need more experience.");
        break;

    case 2:
        printf("Your stats are: ");
        printf("\nAgility: %d ",rand()%N);
        printf("\nStrength: %d ",rand()%N);
        printf("\nIntellect: %d ",rand()%N);
        printf("\n\nYou have picked a Warrior");
        Strength = r;
        if (Strength >= 6)
            printf("\nYour strength is high to slay the dragon.");
        else
            printf("\nYour strength is low, you need more experience.");
        break;

    case 3:
        printf("Your stats are: ");
        printf("\nAgility: %d ",rand()%N);
        printf("\nStrength: %d ",rand()%N);
        printf("\nIntellect: %d ",rand()%N);
        printf("\n\nYou have picked a Mage");
        Intellect = r;
        if (Intellect >= 6)
            printf("\nYour intellect is high to slay the dragon.");
        else
            printf("\nYour intellect is low, you need more experience.");
        break;
    default:
        printf("Error!");
        break;
    }
    return 0;
}
