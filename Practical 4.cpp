#include <iostream>
#include <stdio.h>

/*
	Write a program in C/C++ that receives a series of integer values from the user. The user nominates the number of values to be saved (n) and then enters the values one at a time. This set of values must be stored in an array. After the values are saved in the array, it must be displayed again on the screen as output.

	The user then nominates an element that has to be removed from the array (n-th element) . The program must ensure that the value for n is valid. After the value has been deleted, the array must be displayed to the user again.

	Tip: To erase an element, the elements are moved to overwrite the nth element. Note that the array can now save one more position than there are elements. The number of "active" elements in the array must be updated every time.

	See example input and output below:

	 
	Enter the number of values to enter: 5

	Enter the value for array value 0: 1
	Enter the value for array value 1: 2
	Enter the value for array value 2: 3
	Enter the value for array value 3: 4
	Enter the value for array value 4: 5

	Value 0 is 1
	Value 1 is 2
	Value 2 is 3
	Value 3 is 4
	Value 4 is 5

	Enter the index of the value you wish to remove: 2

	Value 0 is 1
	Value 1 is 2
	Value 2 is 4
	Value 3 is 5
*/

using namespace std;

int main()
{
    int values;
    printf("Enter the number of values to enter: ");
    scanf("%d", &values);
    printf("\n");

    int array[values];
    for(int i=0; i<values; ++i)
    {
        cout<<"Enter the value for array value "<<i<<": ";
        cin>>array[i];
    }

        for(int i=0; i<values; ++i)
        {
            printf("\nValue %2i is%3d",i , array[i]);
        }

        int del = 0;
        printf("\n\nEnter the index of value you wish to remove: ");
        scanf("%d", &del);

        for(int i=del; i<values-1; ++i)
        {
            array[i] = array[i+1];
        }
        for(int i=0; i<values-1; i++)
        {
            printf("\nValue %2i is%3d", i, array[i]);
        }
    return 0;
}
