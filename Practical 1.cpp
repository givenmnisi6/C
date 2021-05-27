#include <iostream>
#include <stdio.h> //to use printf


/*
	Write a program that receives the weight and length of a person as input from the user. The program should start by asking if the user would like to enter the weight and length in kilograms and meters or in pounds and inches by entering either a 1 or a 2.

	After the person entered the information the program should write a report that summarises the weight, length, BMI and the result of the BMI “underweight, normal overweight, obese”.

	The calculations for the BMI are as follows:

	a.    For kilograms and meters: The formula is BMI = kg/m2 where kg is a person's weight in kilograms and m2 is their height in metres squared, round to one decimal place.
	b.    For pounds and inches:  The formula is weight (lb) / [height (in)]2 x 703, divide weight (lb) by height (in) squared, multiply by 703, round to one decimal place.

	Lastly the results are depended on the BMI and are as follows:
	a.    BMI larger or equal to 30: Obese
	b.    BMI between 29 and 25: Overweight
	c.    BMI between 25 and 18.5: Normal
	d.    BMI smaller than 18.5: Underweight

*/



using namespace std;

int main()
{
    printf("BMI Calculator\n\n");
    printf("1. Weight in pounds, height in inches\n");
    printf("2. Height in kilograms, height in meters\n\n");

    float Choice;
    printf("Choice: ");
    scanf("%f",&Choice);
    printf("\n");

    float BMI = 0.0;
    float W   = 0.0;
    float H   = 0.0;

   if (Choice==1){
        printf("Weight in pounds?: ");
    scanf("%f", &W);
        printf("\nHeight in inches?: ");
    scanf("%f",&H);
    BMI = (W*703)/(H*H);
    printf("\n");

    printf("Results...........\n\n");
    printf("Weight:\t\t"      "%.2f"  " pounds\n",W);       //2.f means two decimal places
    printf("Height:\t\t"      "%.4f"  " inches\n",H);       //4.f means two decimal places
    printf("BMI:\t\t"            "%.1f" ,BMI);
}
    else if (Choice == 2){
        printf("Weight in kilograms?: ");
    scanf("%f", &W);
        printf("\nHeight in meters?: ");
    scanf("%f",&H);
    BMI = (W)/(H*H);
    printf("\n\n");

    printf("Results...........\n\n");
    printf("Weight:\t\t"          "%.1f" " kilograms\n",W);  //.1f means one decimal place
    printf("Height:\t\t"          "%.1f"  " meters\n",H);
    printf("BMI:\t\t"       "%.1f",BMI);
}
    printf("\n");
    if(BMI>=30)
        printf("Status:\t\t"       "Obese");
    else if (BMI<30 & BMI>=25)
         printf("Status:\t\t"      "Overweight");
    else if (BMI<25 & BMI>=18.5)
         printf("Status:\t\t"      "Normal");
    else
         printf("Status:\t\t"      "Underweight");

    return 0;
}

