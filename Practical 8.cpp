#include <iostream>
#include <stdio.h>
#include<math.h>


/*
	Part 1:

	Write a function that receives, as arguments, a pointer to a double array, as well as the number of elements in the array (int). The function must use pointer operations (no block notation such as arr[i]) and calculate the standard deviation of the elements in the array. The function returns the standard deviation to the calling statement. Due to possible rounding or floating-point arithmetic errors, round the result to 4 decimal places.

	Use the formula below. Each summation can be done with a for-loop. To calculate the square root you may use the <math.h> header file.

	You may use the following code:

	  float data[] = {11.2, 2.4, 3.13, 16.4, 5.8, 9.22, 4.9, 10.5, 6.5, 2.99};
	  int N = sizeof(data) / sizeof(float);



	Part 2:

	Write a function that receives, as arguments, a pointer to a double array, as well as the number of elements in the array (int). The function must use pointer operations (no block notation such as arr[i]) and must display each element in the array.

	 

	Part 3:

	Write a function that receives, as arguments, a pointer to a double array, as well as a pointer to the number of elements in the array. The function must use pointer operations (no block notation such as arr[i]) to remove a value from the array. The user must enter the index to remove. The number of elements in the array must be updated. The function must be of the void type and thus may not return a value. 

	Afterward, in the main function, display the array with the function from part 2 and calculate the new standard deviation with the function from part 1.

	Tip: to remove an element from an array, all the following elements are shifted up to replace the previous element. The number of ele

	 

	Template:

	double std_dev( ??? );
	void print_array( ??? );
	void remove_one( ??? );

	int main()
	{
	  double previous_std_dev;
	  double new_std_dev;

	  double data[] = {11.2, 2.4, 3.13, 16.4, 5.8, 9.22, 4.9, 10.5, 6.5, 2.99};
	  int N = sizeof(data) / sizeof(double);

	  previous_std_dev = std_dev( ??? );
	  print_array( ??? );
	  remove_one( ??? );
	  print_array( ??? );
	  new_std_dev = std_dev( ??? );
	}

	 

	Example Input and Output:

	11.20  2.40  3.13  16.40  5.80  9.22  4.90  10.50  6.50  2.99

	Enter an index to remove (0-9): 3

	Removed the value '16.40'.

	11.20  2.40  3.13  5.80  9.22  4.90  10.50  6.50  2.99

	The standard deviation of the array was: 4.249367
	It is now: 3.138312

*/
using namespace std;

//VARIABLES
double OldSD;
double NewSD;
int index;

double data[] = {11.2, 2.4, 3.13, 16.4, 5.8, 9.22, 4.9, 10.5, 6.5, 2.99};
int N = sizeof(data) / sizeof(double);

//PART 1
//FUNCTION PROTOTYPE
double SD_dev(double* p, int Num)
{
   double sum = 0;
   for(int i=0;i<Num;i++)
   {
       sum += *(p+i);
   }

   double mean = sum/Num;
   double SD = 0;

   for(int i=0;i<Num;i++)
   {
       SD+= (*(p+i)-mean)*(*(p+i)-mean);
   }
   //RETURN STATEMENT
   return sqrt(SD/Num);
}

//PART 2
//NO RETURN STATEMENT
void DisplayArr(double* p, int Num)
{
   for(int i=0;i<Num;i++)
    printf("%.2f ", *(p+i));
    printf("\n");
}
//PART 3
void Remove(double*p, int Num, int index )
{
   if(index<0 || index>=Num)
    //THIS RETURNS THE VALUE REMOVED
    return;
    printf("\nRemoved the value\'%.2f\.'\n\n",*(p+index));
    for(int i=index; i<Num-1; i++)
    *(p+i)=*(p+i+1);
    Num =Num - 1;
}

//FUNCTION DEFINITION
int main()
{
    //DISPLAY THE ARRAY
   DisplayArr(data, N);

   //PROMPTING THE USER TO ENTER A NUMBER
   printf("\nEnter an index to remove (0-9): ");
   scanf("%d",&index);

   OldSD = SD_dev(data, N);

   //REMOVES THE INDEX SELECTED
   Remove(data, N, index);

   //DISPLAYS THE NEW ARRAY - 1
   DisplayArr(data, N-1);

   //CALCULATES THE NEW STANDARD DEVIATION
   NewSD = SD_dev(data, N-1);

    //LAST OUTPUT
   printf("\nThe standard deviation of the array was: %.6f\n", OldSD);
   printf("It is now: %.6f\n", NewSD);
}
