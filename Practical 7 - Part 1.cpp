#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Part 1

	The range of a set of values is the difference between the highest value and the lowest value in the set. Write a C/C++ program that prompts the user to enter N integer values and stores it in an array. Calculate and display the range of the values, as well as the largest and smallest values in the set.

	TIP: you can declare an array of size N by declaring the array after the user enters a value for N!
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

    //FOR LOOP FOR MIN AND MAX

    int Max = *parr;
    int Min = *parr;

    for(int j = 0; j<values; j++)
    {
        if(*(parr+j)>Max)
        {
            Max = *(parr+j);
        }
        if(*(parr+j)<Min)
        {
            Min = *(parr+j);
        }
    }
            Range = Max - Min;
            printf("Max:\t%d",Max);
            printf("\nMin:\t%d",Min);
            printf("\nRange:  %d",Range);

    return 0;
}
