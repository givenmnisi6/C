#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
	Create a LookupNames project.

	In the main function:
	Ask the user to enter a number of names, X to quit input.
	Store the names in an array.
	Also use a counter variable to count the number of names entered.

	Write a function displayNames to display the names.
	The function must receive the array and the counter as parameters.

	Write a function called lookupNames.
	The function must receive the array and the counter as parameters.
	Ask the user to enter a letter.
	Display all the names with the letter that was entered as the first letter of the name.

	Call the displayNames and lookupNames functions from the main function.


	Tip: declare your functions above the main() function:

	void displayNames(char array[][60], int count)
	{
	  // function code here
	}

	int main()
	{
	  // main code here
	  displayNames(names, number);
	  // possible more code here
	}

	Tip2: make sure your function parameter matches the data type you send as an argument to that function.
	In the above example, names and array should have the same data type, and number and count should have the same data type.


	Enter name (X to quit input): John Peterson
	Enter name (X to quit input): Diane Lee
	Enter name (X to quit input): James Smith
	Enter name (X to quit input): Frank Xaba
	Enter name (X to quit input): Jacky Mokabe
	Enter name (X to quit input): x 


	List of Names

	John Peterson
	Diane Lee
	James Smith
	Frank Xaba
	Jacky Mokabe

	Enter a letter: J 

	Names starting with the letter J

	John Peterson
	James Smith
	Jacky Mokabe
*/

using namespace std;

//MORE OF CONSTANTS IN MY CODE
 #define SIZE_NAME 100 //LENGTH OF THE NAMES
 #define NUMB_NAME 50 //NUMBER OF NAMES INPUTTED CAN BE UP TO 50

int main()
{
    char names[NUMB_NAME][SIZE_NAME] = {""}; //INITIALIZING MY ARRAY AS A BLANK STRING (INPUT FULL NAME)
    char digit;                             //LETTER INPUTTED
    int SIZE;
    int i;

    for (i=0; i<NUMB_NAME; i++)
    {
    printf("Enter name (X to quit input): ");
    gets(names[i]);

    if((strcmp(names[i], "X") == 0) || strcmp(names[i], "x") == 0)
    {
        break;
    }
    SIZE++;
    }

    printf("\nList of names\n\n");
    for(i=0; i<SIZE; i++)
    {
     puts(names[i]);
    }

    printf("\nEnter a letter: ");
    scanf("%c", &digit);

    printf("\nNames starting with the letter %c\n\n", digit);

    for (int i=0; i<SIZE_NAME; i++)
    {
        if(digit==names[i][0])
        {
            cout<<names[i]<<endl;
        }
    }
}
