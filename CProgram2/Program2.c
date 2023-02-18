#include <stdio.h> //Include base libraries

int main() //main function
{
    int score; //Variable to hold the score
    int total = 0; //Variable to hold the calculated totals
    printf("Enter the NFL score: "); //Ask user to enter a score
    fflush(stdout); //Flush the print to allow correct order to be maintained
    scanf("%d", &score); //Obtain user input

        for(int two = 0; two <= score/2; two++) //Loop through the amount possibilities of 2 points
			for (int three = 0; three <=(score - two*2)/3; three++) //Loop through the possibilities of scores given from the remainder of the score - 2s
				for(int six = 0; six <= (score - two*2 - three*3)/6; six++) //Loop through the possibilities of scores given from the remainder of the score - 2s and 3s
					for(int seven = 0; seven <= (score - two*2 - three*3 - six*6)/7; seven++) //Loop through the possibilities of scores given from the remainder of the score - 2s, 3s and 6s
						for(int eight = 0; eight <= (score - two*2 - three*3 - six*6 - seven*7)/8; eight++) //Loop through the possibilities of scores given from the remainder of the score - 2s, 3s, 6s and 7s
						{
							total = two*2+three*3+six*6+seven*7+eight*8; //After each loop concludes, add all obtained combos of the numbers into the total variable
							if(total == score) //If statement to check if the user input score is equal to the total
							{
								printf("\tSafeties: %d, FG: %d, TD: %d, TD + Conversion: %d, TD + FG: %d\n",two, three, six, seven, eight); //If so, print the combinations
							}
						}
}
