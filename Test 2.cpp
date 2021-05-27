#include <iostream>
#include <stdio.h>
#include <ctype.h> //FOR TOUPPER
#include <time.h>
#include <stdlib.h>
#include <string.h>

/*
	1. Create a struct called Booking that consists of a 3 digit flight number (e.g. 234), type of seat (E or B), the price of a seat in economic class and the number of seats booked.
	   Declare an array to store at least 30 Booking structs. (4)
	2. The user must be able to enter the information for a number of bookings from the keyboard. Ask whether a booking must be made (Y or N). If a booking must be made, a random 3 digit flight number must be generated. 
	   The user must be asked to enter the type of seat, the price per seat and the number of seats to book.
	3. Write code to display a numbered list with all the information of all the bookings. The price per ticket must be displayed with 2 decimal places.
	4. Write code to calculate and display the income earned per booking. Display headings and subheadings.
	   Also count and display the number of business seats and economics seats booked as well as the income earned from each of these types of bookings. Calculate and display the total income.
	5. The user must be able to remove a booking from the list. Ask whether the user wants to remove a booking. If the user wants to remove a booking, the user must enter the number of the booking to be removed from the list.
	   Use a do … while loop to validate the number that is entered. The number that was entered must be in the range of numbers displayed on the numbered list. In this example the number must be in the range of 1 to 5. If the number that was entered is not in the correct range, display an error message and ask the user to enter another number until a valid number has been entered. The validation must work for any number of bookings as displayed on the numbered list.
	   Write code to display the numbered list again to see whether the booking has been removed.

*/


using namespace std;

//STRUCTURE

struct Bookings
{
    int fnumber;
    int nseats;
    float price;
    char seat;
};


int main()
{

  //VARIABLES
  int scount = 1;
  int ecount = 0;
  int bcount = 0;
  float eincome = 0;
  float bincome = 0;
  float tot;

  struct Bookings booked[30];   //LEAST BOOKING STRUCTS

  //MY NESTED FIRST FOR LOOP
  for (int i=1; i<= 30; i++)
  {
      char book;

      //WHETHER THE USER WANTS TO BOOK OR NOT
      printf_s("Make a booking (Y or N)? :");
      scanf (" %c", &book);

      //IF THE USER ENTERS Y IT EXECUTES
      if(toupper(book) == 'Y')
      {
          srand(time(0));

          //SECOND  FOR LOOP
          //i - THE MONEY YOU CAN ORDER WITH

          for (int j = 100; j<1000; j++)
          {
              booked[i].fnumber = (1 + (rand()%999));  //WHERE IT MUST ENDS

          }
            //DISPLAYING THE SEAT
            printf("Type of seat (E or B): ");
            scanf (" %c", &booked[i].seat);

            //DISPLAYING THE PRICE
            printf_s("Price per seat: ");
            scanf("%f", &booked[i].price);

            //DISPLAYING THE NUMBER OF SEATS
            printf_s("Number of seats: ");
            scanf("%d", &booked[i].nseats);

            //IF THE USER SELECTS ECONOMY
            if(toupper(booked[i].seat) == 'E')
            {
                ecount += booked[i].nseats;
                eincome += (booked[i].price*booked[i].nseats);
            }
            else
            {
                bcount += booked[i].nseats;
                bincome += (booked[i].price*booked[i].nseats);
            }
                scount += 1;
                tot     = (bincome + eincome);
            }
            else
            {
                break;
            }
        }
            printf_s("\nList of Bookings\n");
            printf_s("\tFlight Number\t Type \tPrice per ticket \tNumber of seats");
    for(int i = 1; i <=scount-1; i++)
    {
      printf_s("\n%d\t%d \t\t %c\t\t%.2f \t\t %d", i, booked[i].fnumber,
                toupper(booked[i].seat), booked[i].price, booked[i].nseats);
    }

  printf_s("\n\n");
  printf_s("List of Incomes");
  printf_s("\n");
  printf_s("\tFlight Number\t Type\t Amount(R.c)");

  //FOURTH FOR LOOP
  for(int i = 1; i<=scount-1; i++)
  {
     printf_s("\n");
      printf_s("%d\t%d \t\t %c\t\t%.2f \t\t %d", i, booked[i].fnumber,
                toupper(booked[i].seat), (booked[i].price*booked[i].nseats));
  }


  printf_s("\nTotal number of economic seats booked:    %d",ecount);
  printf_s("\nIncome from economic seat bookings:       R %.2f", eincome);
  printf_s("\nTotal number of business seats booked:    %d", bcount);
  printf_s("\nIncome from business bookings:            R %.2f", bincome);
  printf_s("\nTotal income:                             R %.2f", tot);

    return 0;
}
