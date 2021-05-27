#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Part 2

	Write a C/C++ program that prompts the user to enter N integer values and stores it in an array. Display the array’s elements in reverse order.
*/


using namespace std;

#define MAX 1000
int main()
{
    //VARIABLES
    int values;
    int Range;
    //MY CODE
    printf("How many elements should be stored in the array?\t ");
    scanf("%d", &values);
    int arr[MAX];
    int *parr = arr;

    //FOR LOOP FOR VALUES
    for (int i = 0; i<values; i++)
    {
        printf("Enter a value for element at index %d:\t", i);
        cin>>*(parr+i);
        parr[i] = arr[i];
    }

    //REVERSE FOR LOOP
    printf("Reversed array: ");
    for(int j = values-1; j>=0; j--)
    {
        printf("%d ", *(parr+j));
    }
    return 0;
}
