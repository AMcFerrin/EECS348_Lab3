#include <stdio.h> //include standard libraries


const char* monthIn(int i) //Function to output the proper month associated with a given index
{
	char *month; //variable to hold the month string
	switch(i) //switch case to pick the right month
	{
		case 0: //case when the month is January
			month = "Jan"; //set the month variable so
			break; //break the statement
		case 1: //case when the month is February
			month = "Feb"; //set the month variable so
			break; //break the statement
		case 2: //case when the month is March
			month = "Mar"; //set the month variable so
			break; //break the statement
		case 3: //case when the month is April
			month = "Apr"; //set the month variable so
			break; //break the statement
		case 4: //case when the month is May
			month = "May"; //set the month variable so
			break; //break the statement
		case 5: //case when the month is June
			month = "Jun"; //set the month variable so
			break;  //break the statement
		case 6: //case when the month is July
			month = "Jul"; //set the month variable so
			break; //break the statement
		case 7: //case when the month is August
			month = "Aug"; //set the month variable so
			break; //break the statement
		case 8: //case when the month is September
			month = "Sep"; //set the month variable so
			break; //break the statement
		case 9: //case when the month is October
			month = "Oct"; //set the month variable so
			break; //break the statement
		case 10: //case when the month is November
			month = "Nov"; //set the month variable so
			break; //break the statement
		case 11: //case when the month is December
			month = "Dec"; //set the month variable so
			break; //break the statement
	}
	return month; //return the received string
}

int main() //main function that prints all required operations
{

	FILE *input; //Create a file instance of 'input'
	char fileName[100]; //Create the file name string
	float earnings[12]; //Create the list of values that will be in the file


	printf("Enter a file: "); //Print to the user what to input
	fflush(stdout); //Flush the print so that the scan goes in the proper order
	scanf("%s", fileName); //Get the file name from the user

	input = fopen(fileName, "r"); //Open the file the user provided
	if (input == NULL) //Check if the file exists
	{
		printf("File name not recognized; check if you typed it in correctly"); //Print to the user so
	}
	else //If the file does exist, continue
	{
		for (int i = 0; i < 12; i++) //Loop 12 times to obtain all 12 values for each month
		{
			fscanf(input, "%f", &earnings[i]); //Add each item to the array 'earnings'
		}
//--------------------------------------------------------------------------
		printf("\nMonthly sales report for 2022:\n\nMonth\t  Sales\n"); //Print the meaning of the following prints
		for (int i = 0; i < 12; i++) //Loop through the list of values
		{
			printf("%s: \t$%f\n", monthIn(i), earnings[i]); //Print each value, along with the corresponding month
		}
//--------------------------------------------------------------------------
		printf("\nSales summary:\n"); //Print the meaning of the following prints
		float max = earnings[0], min = earnings[0], average; //set the following variables to floats
		int maxMonth, minMonth; //Set the following variables to ints

		for (int i = 0; i < 12; i++) //Loop through all values
		{
			if (earnings[i] > max) //Check if the current index's item is greater than the previous
			{
				max = earnings[i]; //If so, set the new 'max' to the current index's value
				maxMonth = i; //Set it's month to the current index
			}
			if (earnings[i] < min) //Check if the current index's item is less than the previous
			{
				min = earnings[i]; //If so, set the new 'min' to the current index's value
				minMonth = i; //SEt it's month to the current index
			}

			average += earnings[i]; //Set the average to the sum of all value
		}
		average /= 12; //Divide the average by 12

		printf("Minimum Sales:\t$%f   (%s)\n",min,monthIn(minMonth)); //Print the min value and it's month
		printf("Maximum Sales:\t$%f   (%s)\n",max,monthIn(maxMonth)); //Print the max value and it's month
		printf("Average Sales:\t$%f\n\n", average); //Print the average value

//--------------------------------------------------------------------------
		printf("Six-Month Moving Average Report:\n"); //Print what the following information will be
		{
			for (int i = 0; i < 7; i++) //Set a for loop to loop 7 times
			{
				float sixMonthSum = 0; //Create a variable to hold the values of 6 month intervals
				for (int j = 0; j < 6; j++) //Loop through 6 more times
				{
					sixMonthSum = sixMonthSum + earnings[j+i]; //Sum the given 6 months' values
				}
				printf("%s  -  %s:\t$%f\n",monthIn(i),monthIn(i+5),sixMonthSum); //Print the months and their total values
			}
		}
//---------------------------------------------------------------------------
		printf("\nSales Report (Highest to Lowest):\nMonth\t  Sales\n"); //Print what the following prints will be
		int a; //Create temp variable a
		float newArr[12]; //Create a copy array

		for (int i = 0; i < 12; i++) //Loop 12 times over the array
		{
			newArr[i] = earnings[i]; //Add each item from earnings to the new array to preserve their location in the array
		}


		   for (int i = 0; i < 12; i++) //Loop 12 times
		   {
		      for (int j = 0; j < 12; j++) //Loop another 12 times
		      {
		         if (earnings[i] > earnings[j]) //Check if the value from the first loop is greater than the second loop
		         {
		            a = earnings[i]; //If so, set a to the first loops' value
		            earnings[i] = earnings[j]; //Move the second loop's value to its place
		            earnings[j] = a; //Set the old value to the second values' position
		         }
		      }
		   }
		for (int i = 0; i < 12; i++) //Loop 12 times
		{
			for (int j = 0; j < 12; j++) //Loop 12 times again
			{
				if (earnings[i] == newArr[j]) //Check if the value from 'earnings' matches the one in the new array
				{
					printf("%s:\t$%f\n", monthIn(j),earnings[i]); //Print out the correct month and value pair
				}
			}
		}
	}


	fclose(input); //Close the file
	return 0; //Return 0
}
