#include <stdio.h>

int main()
{
    int score;
    int total = 0;
    printf("Enter the NFL score: ");
    fflush(stdout);
    scanf("%d", &score);

        for(int two = 0; two <= score/2; two++)
			for (int three = 0; three <=(score - two*2)/3; three++)
				for(int six = 0; six <= (score - two*2 - three*3)/6; six++)
					for(int seven = 0; seven <= (score - two*2 - three*3 - six*6)/7; seven++)
						for(int eight = 0; eight <= (score - two*2 - three*3 - six*6 - seven*7)/8; eight++)
						{
							total = two*2+three*3+six*6+seven*7+eight*8;
							if(total == score)
							{
								printf("\tSafeties: %d, FG: %d, TD: %d, TD + Conversion: %d, TD + FG: %d\n",two, three, six, seven, eight);
							}
						}
}
