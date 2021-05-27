#include <iostream>

/*
	Part 1

	Write a function that will receive a pointer to the address of the first element of the array. Read the ID numbers contained in idnumbers.txt into the array. Display a message which indicates that data is being read from the file. Return the number of elements saved in the array.

	Part 2

	Write a function that will receive the pointer of the first element of an array, as well as the number of elements in the array. Display the contents of the array.

	Part 3

	Write a function that will receive the pointer of the first element of an array, as well as the number of elements in the array. The function should display the birth date of each person. Assume valid years are from 1921-2020.

	Tip: The underscore character serves as the first locator character for each ID number, you can use this as a landmark to identify the indexes of each ID number.

	 
	 -----------------------------------------------------------------------------------------------------------------
	 id numbers txt
	 _7803045678087
	_8904050876092
	_9002017896054
	_9408072345087
	_8703083456098
	_7812120867087
	_0108068675087
	_1012239687087
	_0801090675086
	_9911220768082
	-----------------------------------------------------------------------------------------------------------------
	 

	EXAMPLE OUTPUT

	List of ID numbers:
	_7803045678087
	_8904050876092
	_9002017896054
	_9408072345087
	_8703083456098
	_7812120867087
	_0108068675087
	_1012239687087
	_0801090675086
	_9911220768082

	Date born: 1978/03/04
	Date born: 1989/04/05
	Date born: 1990/02/01
	Date born: 1994/08/07
	Date born: 1987/03/08
	Date born: 1978/12/12
	Date born: 2001/08/06
	Date born: 2010/12/23
	Date born: 2008/01/09
	Date born: 1999/11/22
	
*/

using namespace std;

#define MAX 400

int read(char *);
void display(char *, int);
void displayBirthday(char *, int);


int main()
{
    char ID[MAX];
    int rcount = read(ID);
    display(ID, rcount);
    displayBirthday(ID, rcount);
    return 0;
}

int read (char *array)
{
    FILE *file;
    file = fopen("idnumbers.txt", "r");
    printf("List of ID numbers: \n");

    char c;
    int rcount = 0;

    int i;
    for(i = 0; i<MAX; i++)
    {
     if(fscanf(file, "%c", &c) == EOF)
     {
               break;
     }
     else
     {
        *(array+i) = c;
        rcount++;
     }
    }
    return rcount;
}

void display (char *array, int rcount)
{
    int i;
    for(i = 0; i<rcount; i++)
    {
        printf("%c", *(array+ i));
    }
    printf("\n");
}

void displayBirthday(char *array, int rcount)
{
   for(int i = 0; i<rcount; i++)
   {
       if(*(array+i) == '_')
       {
           char word[3] = {*(array+i+1), *(array+i+2)};
           int year = atoi(word);

           if(year<= 20)
           {
               year += 2000;
           }
           else
           {
              year += 1900;
           }
           printf("\nDate of born: %d/%c%c/%c%c", year, *(array+i+3), *(array+i+4),
                   *(array+i+5), *(array+i+6));
       }
   }
}
