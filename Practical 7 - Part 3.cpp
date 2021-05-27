#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Part 3

	Write a C/C++ program that prompts the user to enter N integer values and stores it in an array. Sort the elements of the array in ascending order. You may use any sorting algorithm.
*/

using namespace std;

#define MAX 1000
int main()
{
    //VARIABLES
    int arr[MAX];
    int values;
    int *parr = arr;
    int temp;
    int j;

    //MY CODE
    printf("How many elements should be stored in the array?\t ");
    cin>>(values);

    //FOR LOOP FOR VALUES
    for (int i = 0; i<values; i++)
    {
        printf("Enter a value for element at index %d:\t", i);
        cin>>*(parr+i);
    }

    //FOR LOOP FOR SORTING
    for (int i = 0; i < values - i; i++)
    {
        for (int j = 0; j < values - i - 1; j++)
        {
            if(*(parr + j)<*(parr+j+1))
           {
               temp = *(parr + j);
               *(parr + j) = *(parr + j + 1);
               *(parr + j + 1) = temp;
           }
        }
    }
    printf("Sorted array: ");
    for(int i = values - 1; i >= 0; i--)
    {
        printf("%d ", *(parr + i));
    }
    return 0;
}
