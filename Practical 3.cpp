#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

/*


	Your program should have the following two input validations:

	Should the user enter "yy" when asked to register, the second 'y' will be used indicate that the user is a member, which is not what we wish to happen in this case. 
	To get around this, you should clear the standard input buffer (information can be found in Beginning C, page 179) after the user input.
	If the user enters a value other than expected, that entry should be considered invalid and should not count toward any totals.
	The program should then make use of the 'goto' statement to return to the start of the while loop.
	This program will have a lot of variables, make sure to keep their declarations tidy, group ones that are similar and separate groups with an empty line.

	Design a program to do the administration for a fun run competition. Participants can run a distance of 5 kilometers, 10 kilometers or 15 kilometers.

	Ask the user if they wish to register a participant (Y or N). 
	Ask whether the person is a member (Y or N)
	Ask the distance that the person wishes to run (5, 10, 15).

	Information on using a switch statement for Y or N questions can be found in Beginning C, page 119.
	You may choose whether to use switch statements, if statements, or both for this practical.

	 

	Registration fees for club members are as follows:
	5km   = R  65.00
	10km = R 100.00
	15km = R 150.00

	Non-members:
	For the 5 and 10 kilometers distances, the participation fees must be increased by 25%
	For the 15 kilometer distance the registration fee is double that of club members.

	 

	Use the given criteria and input information to calculate the registration fee.

	The program must keep track of the total number of participants per distance category, the total amount received per distance category and total amount received.
	The program must also calculate the total number of participants and the total number of club members who registered.
	The program must identify the category with the highest income in terms of registration fees.
*/



using namespace std;

int main()
{
    //CONSTANTS
    const float km_5 = 65.0f;
    const float km_10 = 100.0f;
    const float km_15 = 150.0f;
    const float km_increase = 1.25f; //125% (1 + 25%)

    //VARIABLES
    int n5km = 0;  //NUMBER OF 5KM
    int n10km = 0;  //NUMBER OF 10KM
    int n15km = 0;  //NUMBER OF 15KM

    //SUM OF THE KMS INSERTED
    float s5km = 0;
    float s10km = 0;
    float s15km = 0;
    float total = (s5km + s10km + s15km);

    //NUMBER OF PARTICIPANT || REGISTERED AS A MEMBER
    int nregistered = 0;
    int nparticipant = 0;

    char register_;
    char member;
    int distance;

    //BOOLEAN
    bool is_member;
    bool register_flag = true; //TRUE = 1, FALSE = 0

    //MY CODE
    while(register_flag)
    {
        printf("Do you wish to register a new participant? (Y or N): ");
        scanf ("%c", &register_);

        switch(toupper(register_))  // CONVERT TO UPPERCASE
        {
        case 'Y': case 'y':
            printf("Is the participant a club member? (Y or N): ");
            scanf ("%c", &member);

            is_member = toupper(member) == 'Y';

            printf("\nEnter distance ( 5 / 10 / 15 ): ");
            scanf("%d", &distance);

            switch(distance)
            {
            case 5:
                n5km ++;
                nparticipant++;

                if(is_member)
                {
                    nregistered++;
                    s5km += km_5;
                }
                else
                    s5km += km_5 * km_increase;

            case 10:
                n10km ++;
                nparticipant++;

                if(is_member)
                {
                    nregistered++;
                    s10km += km_10;
                }
                else
                    s10km += km_10 * km_increase;

            case 15:
                n15km ++;
                nparticipant++;

                if(is_member)
                {
                    nregistered++;
                    s15km += km_15;
                }
                else
                    break;
            }
              case 'N' : case 'n':
                register_flag = false;
                printf("Total number: ");
                break;
        }
        break;
    break;

    }
    while(is_member)
    {
        printf("\nTotal number of participants: ", nparticipant);
        printf("Total number of members registered: ", is_member);

        printf("\nThe total number of participants per distance:");
        printf("5km:\t\t %d\t\tR%1fn5km",s5km);
        printf("10km:\t\t %d\t\tR%1fn10km",s10km);
        printf("15km:\t\t %d\t\tR%1fn15km",s15km);

        printf("\nTotal Income:\t\t",total);
        printf("Category with Highest Income: ", distance);
        break;
    }
    return 0;
}
