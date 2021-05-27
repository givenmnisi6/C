#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

/*
		A bank in your town updates its customers’ accounts at the end of each month. The bank offers two types of accounts:
		savings and cheque. Every customer must maintain a minimum balance.
		Minimum balances for the accounts are:
		 Savings : R 1000.00
		 Cheque: R 1500.00
		If a customer’s balance falls below the minimum balance, there is a service charge of R50.00 for savings accounts and
		R100.00 for cheque accounts. If the balance at the end of the month is at least the minimum balance, the client
		receives interest as follows:
		 Savings accounts receive 4% interest on the balance.
		 Cheque accounts with balances of up to R 5000.00 more than the minimum balance receive 3% interest;
		otherwise, accounts with balances more than R 5000.00 more than the minimum balance receive 5% interest.
		Write a program that requests the user to enter a customer’s account number (int type), account type (char type - S
		for savings, C for checking) and current balance. The updated balance must be displayed.
		The program should continue updating accounts until the value 999 is entered as an account number.
		The number of savings and cheque account updated determined and must be displayed – see example output.
		Note:
		 The minimum balance amount for savings and cheque accounts must be declared as constants.
		 The program must accept capital or small letters as account types.
		 The updated balance displayed must be formatted to two decimal places.
		Test data:
		123 S 2700
		878 C 7689
		789 S 800
		Example run using the test data (next page):
		2
		Updating bank accounts
		Enter your account number (999 to exit): 123
		Enter account type (S for savings, C for cheque): s
		Enter your current balance: 2700
		Updated balance: R 2808.00

		Enter your account number (999 to exit): 878
		Enter account type (S for savings, C for cheque): C
		Enter your current balance: 7689
		Updated balance: R 8073.45

		Enter your account number (999 to exit): 789
		Enter account type (S for savings, C for cheque): s
		Enter your current balance: 800
		Updated balance: R 750.00

		Enter your account number (999 to exit): 999
		Number of clients with savings accounts: 2
		Number of clients with cheque accounts: 1
*/



int main(void)
{
    //CONSTANTS
    const float savings = 1000.0f;
    const float cheque = 1500.0f;

    //VARIABLES
    int account_number = 0;
    int current_balance = 0.0;
    int updated_balance = 0.0;
    int sclients = 0;
    int cclients = 0;
    char account_type;  //CHARACTER - SAVINGS OR CHEQUE

    //BOOLEAN
    bool account_flag = true;

    //MY CODE
    printf("Updating bank accounts");

    //WHILE LOOP, MAKE IT REPEAT
    while(account_flag)     //WHILE ACCOUNT FLAG IS TRUE,EXECUTE THE FOLLOWING
        {
        printf("\n\nEnter your account number (999 to exit): ");
        scanf("%d", &account_number);


        if (account_number == 999)    //IF 999 IS SELECTED IT MUST STOP
            {
            account_flag = false;
            printf("\n\nNumber of clients with savings accounts: %d", sclients);
            printf("\nNumber of clients with cheque accounts: %d", cclients);
            break;
        }
        else
            printf("Enter account type (S for savings, C for cheque): ");
            scanf("%c", & account_type);

            printf("Enter your current balance: ");
            scanf("%d", & current_balance);

            if (toupper(account_type) == 'S')
                {
                sclients++;
                if (savings > current_balance)
                    {
                    updated_balance = (current_balance - 50.00);
                    printf("Updated balance: %.2f", updated_balance);
                }
                else
                    {
                    updated_balance = (current_balance*1.04);
                    printf("Updated balance: %.2f", updated_balance);
                }
                }

            else if (toupper(account_type) == 'C')
                {
                float minuss = (current_balance - cheque);
                cclients++;

                if (cheque > current_balance){
                    updated_balance = (current_balance - 100.00);
                    printf("Updated balance: %.2f", updated_balance);}

                else if (minuss >=0 && 5000.00 >= minuss)
                    {
                    updated_balance = current_balance*1.03;
                    printf("Updated balance: %.2f", updated_balance);
                }
                else
                    {
                    updated_balance = current_balance*1.05;
                    printf("Updated balance: %.f", updated_balance);
                }
            }
            return 0;
            }
}
