#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


/*
	1. Write a function called displayCodes to receive the pointer of the first element of the array and the number
	of elements in the array.
	Call the function displayCodes from the main function.

	2. Write a function called displayCodes to receive the pointer of the first element of the array and the number
	of elements in the array.
	Call the function displayCodes from the main function.

	3. Write a function called checkStock to receive a pointer to the address of the first element of the array and
	the number of elements in the array.
	The minimum number of each item that must be in stock is 100.
	Find the items with less than 100 in stock. For each of these items calculate the number that must be
	ordered so that the number in stock is 100.
	Display the number of the item, the number currently in stock and the number to order to have 100 of the
	item in stock. Display the values neatly in columns as shown in the example below.
	Also calculate the total number of items to order in the function and return this value to the main function.
	This value and a suitable label must be displayed from the main function.

*/

using namespace std;

#define SIZE 200

int read(char *);
void displayCodes(char *, int);
void displayLocations(char *, int);
void checkStock(char *, int);


int main()
{
    char Codes[SIZE];
    int count = read(Codes);
    displayCodes(Codes, count);
    displayLocations(Codes, count);
    checkStock(Codes, count);
}


int read (char *array)
{
    FILE *file;
    file = fopen("codes.txt", "r");
    printf("List of Codes \n");

    char c;
    int count = 0;

    int i;
    for(i = 0; i<SIZE; i++)
    {
     if(fscanf(file, "%c", &c) == EOF)
     {
               break;
     }
     else
     {
        *(array+i) = c;
        count++;
     }
    }
    return count;
}


void displayCodes (char *array, int count)
{
    int i;
    for(i = 0; i<count; i++)
    {
        printf("%c", *(array+ i));
    }
    printf("\n");
}


void displayLocations(char *array, int count)
{
    printf("\nLocation of items\n");
    printf("Item Nr\tSRoom\tSection\t   Shelf");
    for(int i = 0; i<count; i++)
     {
       if(*(array+i) == '_')
       {
           char word[3] = {*(array+i+1), *(array+i+2)};
           int item = atoi(word);

           if(item<10)
           {
                printf("\n0%d\t  %c\t   %c\t     %c", item, *(array+i+4),
                *(array+i+5), *(array+i+6));
           }
           else
            {
                printf("\n%d\t  %c\t   %c\t     %c", item, *(array+i+4),
                *(array+i+5), *(array+i+6));
            }
       }
     }
}


void checkStock(char *array, int count)
{
     printf("\n\nList of stock to order\n");
     printf("Item  Nr\tIn stock\tTo order");

 int Total = 0;
 for(int i = 0; i<count; i++)

     {
       if(*(array+i) == '_')
       {
           char word[3] = {*(array+i+1), *(array+i+2)};
           int item = atoi(word);

           char words[4] =  {*(array+i+8), *(array+i+9), *(array+i+10)};
           int stock = atoi(words);
           int ToOrder = 100 - stock;

            if(stock<100)
            {
                if(item<10)
                {
                    printf("\n0%d\t\t  %d\t\t   %d ", item, stock, ToOrder);
                }
                else
                {
                    printf("\n%d\t\t  %d\t\t    %d", item, stock, ToOrder);
                }
                Total += ToOrder;
            }
       }
     }
     printf("\n\nTotal number of items to order: %d", Total);
}



