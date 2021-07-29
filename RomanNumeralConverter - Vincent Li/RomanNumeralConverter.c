/*
Name:		Vincent Li
Date:       Jan 15, 2020
Purpose:    Converts a roman number to the equivalent arabic number or arabic number to the equivalent roman number
*/

// Importing classes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Used for converting lower case to uppercase, since 32 is the difference between lowercase and uppercase
// in the ASCII table
#define UPPER 32


/**
* \fn:          romanConvert
* \brief:       To convert from roman numerals to arabic
* \param:       char
* \return:      The arabic equivalent of the roman number (integer)
*/

double romanConvert(char c)
{
	// A switch statement that is used to convert the roman number equivalent of the arabic number
	switch (c)
	{

	case 'I':
		return 1;
	case 'V':
		return 5;
	case 'X':
		return 10;
	case 'L':
		return 50;
	case 'C':
		return 100;
	case 'D':
		return 500;
	case 'M':
		return 1000;

		// returns 0 for these cases or else it will default to -1
		// Vinculum
	case '-':
		return 0;
	case '_':
		return 0;

		// fraction cases
	case '.':
		return (1.0 / 12.0);
	case 'S':
		return 0.5;

		// The null case, returns 0 if there is nothing there
		// Also used to differentiate a valid roman number and invalid
	case '\0':
		return 0;

		// Returns -1 if it is not a roman number
		// The -1 is used for the if statement to vertify wheter or not it is a roman number
	default:
		return -1;
	} // end switch
} // end function


/**
* \fn:          arabicConvert
* \brief:       Converts the arabic number to the roman numeral equilvalent
* \param:       The address of a c string
* \return:      Nothing
*/

void arabicConvert(char* arabic, char* tempNum)
{
	// declaring variables used for the conversion
	char romanValue[100]; // holds the converted arabic number
	int counter = 0; // counter for the c string

	// checks if it contains a period so it can perform the fractions
	if (strchr(arabic, '.'))
	{
		// using the atof function to convert from c string to float/decimals
		double arabicFraction = atof(arabic);
		double tempNumber = atof(tempNum);

		// since it can be impossible for the user input to equal 0 completely, the lowest number of 1.0/12.0 is used
		if (arabicFraction >= (1.0 / 12.0) && arabicFraction < 4000)
		{
			while (arabicFraction >= (1.0 / 12.0))
			{
				// Basically, say if the number is 1000 or greater, then it would return M first
				if (arabicFraction >= 1000)
				{
					arabicFraction -= 1000;
					romanValue[counter++] = 'M';
				}
				else if (arabicFraction >= 900)
				{
					arabicFraction -= 900;
					romanValue[counter++] = 'C';
					romanValue[counter++] = 'M';
				}
				else if (arabicFraction >= 500)
				{
					arabicFraction -= 500;
					romanValue[counter++] = 'D';
				}
				else if (arabicFraction >= 400)
				{
					arabicFraction -= 400;
					romanValue[counter++] = 'C';
					romanValue[counter++] = 'D';
				}
				else if (arabicFraction >= 100)
				{
					arabicFraction -= 100;
					romanValue[counter++] = 'C';
				}
				else if (arabicFraction >= 90)
				{
					arabicFraction -= 90;
					romanValue[counter++] = 'X';
					romanValue[counter++] = 'C';
				}
				else if (arabicFraction >= 50)
				{
					arabicFraction -= 50;
					romanValue[counter++] = 'L';
				}
				else if (arabicFraction >= 40)
				{
					arabicFraction -= 40;
					romanValue[counter++] = 'X';
					romanValue[counter++] = 'L';
				}
				else if (arabicFraction >= 10)
				{
					arabicFraction -= 10;
					romanValue[counter++] = 'X';
				}
				else if (arabicFraction >= 9)
				{
					arabicFraction -= 9;
					romanValue[counter++] = 'I';
					romanValue[counter++] = 'X';
				}
				else if (arabicFraction >= 5)
				{
					arabicFraction -= 5;
					romanValue[counter++] = 'V';
				}
				else if (arabicFraction >= 4)
				{
					arabicFraction -= 4;
					romanValue[counter++] = 'I';
					romanValue[counter++] = 'V';
				}
				else if (arabicFraction >= 1)
				{
					arabicFraction -= 1;
					romanValue[counter++] = 'I';
				}
				else if (arabicFraction >= 0.5)
				{
					arabicFraction -= 0.5f;
					romanValue[counter++] = 'S';
				}
				else if (arabicFraction >= (1.0 / 12.0))
				{
					arabicFraction -= (1.0 / 12.0);
					romanValue[counter++] = '.';
				}
			} // end while

			// Adds the null character so it does not print the 'garbage' data
			romanValue[counter++] = '\0';
		} // end if 


		// So basically multiply the numbers by 1000, if it is > then the original, divide by 1000 to get back to the normal number
		// Vinculum
		else if (arabicFraction >= 4000.0)
		{
			// divide the number by 1000 and store it in a temp variable
			int temp = arabicFraction / 1000;
			double temp2 = arabicFraction / 1000.0; // holds the numbers less than 4000
			arabicFraction = (arabicFraction - (temp * 1000)) + temp2 - temp; // the calculation that removes the numbers over 4000 and leaves only the numbers less than it

			// Used for the vinculum part for numbers over 4000
			while (temp >= (1.0 / 12.0))
			{
				// Basically, say if the number is 1000 or greater, then it would return M first
				if (temp >= 1000)
				{
					temp -= 1000;
					romanValue[counter++] = 'M';
				}
				else if (temp >= 900)
				{
					temp -= 900;
					romanValue[counter++] = 'C';
					romanValue[counter++] = 'M';
				}
				else if (temp >= 500)
				{
					temp -= 500;
					romanValue[counter++] = 'D';
				}
				else if (temp >= 400)
				{
					temp -= 400;
					romanValue[counter++] = 'C';
					romanValue[counter++] = 'D';
				}
				else if (temp >= 100)
				{
					temp -= 100;
					romanValue[counter++] = 'C';
				}
				else if (temp >= 90)
				{
					temp -= 90;
					romanValue[counter++] = 'X';
					romanValue[counter++] = 'C';
				}
				else if (temp >= 50)
				{
					temp -= 50;
					romanValue[counter++] = 'L';
				}
				else if (temp >= 40)
				{
					temp -= 40;
					romanValue[counter++] = 'X';
					romanValue[counter++] = 'L';
				}
				else if (temp >= 10)
				{
					temp -= 10;
					romanValue[counter++] = 'X';
				}
				else if (temp >= 9)
				{
					temp -= 9;
					romanValue[counter++] = 'I';
					romanValue[counter++] = 'X';
				}
				else if (temp >= 5)
				{
					temp -= 5;
					romanValue[counter++] = 'V';
				}
				else if (temp >= 4)
				{
					temp -= 4;
					romanValue[counter++] = 'I';
					romanValue[counter++] = 'V';
				}
				else if (temp >= 1)
				{
					temp -= 1;
					romanValue[counter++] = 'I';
				}
				else if (temp >= 0.5)
				{
					temp -= 0.5f;
					romanValue[counter++] = 'S';
				}
				else if (temp >= (1.0 / 12.0))
				{
					temp -= (1.0 / 12.0);
					romanValue[counter++] = '.';
				}

			}

			// adds the underscore to indicate it is vinculum and \0 to remove the 'garbage data'
			romanValue[counter++] = '_';

			// to get the numbers after the vinculum
			while (arabicFraction >= (1.0 / 12.0))
			{
				// Basically, say if the number is 1000 or greater, then it would return M first
				if (arabicFraction >= 1000)
				{
					arabicFraction -= 1000;
					romanValue[counter++] = 'M';
				}
				else if (arabicFraction >= 900)
				{
					arabicFraction -= 900;
					romanValue[counter++] = 'C';
					romanValue[counter++] = 'M';
				}
				else if (arabicFraction >= 500)
				{
					arabicFraction -= 500;
					romanValue[counter++] = 'D';
				}
				else if (arabicFraction >= 400)
				{
					arabicFraction -= 400;
					romanValue[counter++] = 'C';
					romanValue[counter++] = 'D';
				}
				else if (arabicFraction >= 100)
				{
					arabicFraction -= 100;
					romanValue[counter++] = 'C';
				}
				else if (arabicFraction >= 90)
				{
					arabicFraction -= 90;
					romanValue[counter++] = 'X';
					romanValue[counter++] = 'C';
				}
				else if (arabicFraction >= 50)
				{
					arabicFraction -= 50;
					romanValue[counter++] = 'L';
				}
				else if (arabicFraction >= 40)
				{
					arabicFraction -= 40;
					romanValue[counter++] = 'X';
					romanValue[counter++] = 'L';
				}
				else if (arabicFraction >= 10)
				{
					arabicFraction -= 10;
					romanValue[counter++] = 'X';
				}
				else if (arabicFraction >= 9)
				{
					arabicFraction -= 9;
					romanValue[counter++] = 'I';
					romanValue[counter++] = 'X';
				}
				else if (arabicFraction >= 5)
				{
					arabicFraction -= 5;
					romanValue[counter++] = 'V';
				}
				else if (arabicFraction >= 4)
				{
					arabicFraction -= 4;
					romanValue[counter++] = 'I';
					romanValue[counter++] = 'V';
				}
				else if (arabicFraction >= 1)
				{
					arabicFraction -= 1;
					romanValue[counter++] = 'I';
				}
				else if (arabicFraction >= 0.5)
				{
					arabicFraction -= 0.5f;
					romanValue[counter++] = 'S';
				}
				else if (arabicFraction >= (1.0 / 12.0))
				{
					arabicFraction -= (1.0 / 12.0);
					romanValue[counter++] = '.';
				}
			} // end while

			// Gets rid of the 'garbage' values after its finished converting
			romanValue[counter++] = '\0';

		} // end else if

		// invalid numbers
		else
		{
			printf("Invalid roman number...\n");
		} // end else

		// printing the result
		printf("%.2lf is %s\n", tempNumber, romanValue);
	} // end if 

	// if it is not a decimal, then convert normally
	else
	{
		// makes the c-string into an integer
		int num = atoi(arabic);
		int tempNumber = atoi(tempNum); // holds the original number

		// since roman numbers cannot be negative and roman numbers go to 4000
		if (num >= 1 && num < 4000)
		{
			// as long as the number is not 0, it will keep subtracting and creating a roman number
			while (num != 0)
			{

				// Basically, say if the number is 1000 or greater, then it would return M first
				if (num >= 1000)
				{
					num -= 1000;
					romanValue[counter++] = 'M';
				}
				else if (num >= 900)
				{
					num -= 900;
					romanValue[counter++] = 'C';
					romanValue[counter++] = 'M';
				}
				else if (num >= 500)
				{
					num -= 500;
					romanValue[counter++] = 'D';
				}
				else if (num >= 400)
				{
					num -= 400;
					romanValue[counter++] = 'C';
					romanValue[counter++] = 'D';
				}
				else if (num >= 100)
				{
					num -= 100;
					romanValue[counter++] = 'C';
				}
				else if (num >= 90)
				{
					num -= 90;
					romanValue[counter++] = 'X';
					romanValue[counter++] = 'C';
				}
				else if (num >= 50)
				{
					num -= 50;
					romanValue[counter++] = 'L';
				}
				else if (num >= 40)
				{
					num -= 40;
					romanValue[counter++] = 'X';
					romanValue[counter++] = 'L';
				}
				else if (num >= 10)
				{
					num -= 10;
					romanValue[counter++] = 'X';
				}
				else if (num >= 9)
				{
					num -= 9;
					romanValue[counter++] = 'I';
					romanValue[counter++] = 'X';
				}
				else if (num >= 5)
				{
					num -= 5;
					romanValue[counter++] = 'V';
				}
				else if (num >= 4)
				{
					num -= 4;
					romanValue[counter++] = 'I';
					romanValue[counter++] = 'V';
				}
				else if (num >= 1)
				{
					num -= 1;
					romanValue[counter++] = 'I';
				}
			} // end loop

			// Once it is done converting, a null character is added so it does not print the 'garbage' data
			romanValue[counter++] = '\0';


		} // end if 

		// Vinculum
		else if (num >= 4000)
		{
			// this is to get the big numbers that is over 4000
			int temp = num / 1000;
			double temp2 = num / 1000.0; // this is for the numbers less than 4000 also after the _
			int num2 = (num - (temp * 1000)) + temp2 - temp; // The calculation to only get the numbers after _

			// as long as the number is not 0, it will keep subtracting and creating a roman number
			while (temp != 0)
			{

				// Basically, say if the number is 1000 or greater, then it would return M first
				if (temp >= 1000)
				{
					temp -= 1000;
					romanValue[counter++] = 'M';
				}
				else if (temp >= 900)
				{
					temp -= 900;
					romanValue[counter++] = 'C';
					romanValue[counter++] = 'M';
				}
				else if (temp >= 500)
				{
					temp -= 500;
					romanValue[counter++] = 'D';
				}
				else if (temp >= 400)
				{
					temp -= 400;
					romanValue[counter++] = 'C';
					romanValue[counter++] = 'D';
				}
				else if (temp >= 100)
				{
					temp -= 100;
					romanValue[counter++] = 'C';
				}
				else if (temp >= 90)
				{
					temp -= 90;
					romanValue[counter++] = 'X';
					romanValue[counter++] = 'C';
				}
				else if (temp >= 50)
				{
					temp -= 50;
					romanValue[counter++] = 'L';
				}
				else if (temp >= 40)
				{
					temp -= 40;
					romanValue[counter++] = 'X';
					romanValue[counter++] = 'L';
				}
				else if (temp >= 10)
				{
					temp -= 10;
					romanValue[counter++] = 'X';
				}
				else if (temp >= 9)
				{
					temp -= 9;
					romanValue[counter++] = 'I';
					romanValue[counter++] = 'X';
				}
				else if (temp >= 5)
				{
					temp -= 5;
					romanValue[counter++] = 'V';
				}
				else if (temp >= 4)
				{
					temp -= 4;
					romanValue[counter++] = 'I';
					romanValue[counter++] = 'V';
				}
				else if (temp >= 1)
				{
					temp -= 1;
					romanValue[counter++] = 'I';
				}
			} // end loop

			// Once it is done converting, a null character is added so it does not print the 'garbage' data
			romanValue[counter++] = '_'; // also add the _ to indicate it is vinculum

			// To calculate for the values after _
			while (num2 != 0)
			{

				// Basically, say if the number is 1000 or greater, then it would return M first
				if (num2 >= 1000)
				{
					num2 -= 1000;
					romanValue[counter++] = 'M';
				}
				else if (num2 >= 900)
				{
					num2 -= 900;
					romanValue[counter++] = 'C';
					romanValue[counter++] = 'M';
				}
				else if (num2 >= 500)
				{
					num2 -= 500;
					romanValue[counter++] = 'D';
				}
				else if (num2 >= 400)
				{
					num2 -= 400;
					romanValue[counter++] = 'C';
					romanValue[counter++] = 'D';
				}
				else if (num2 >= 100)
				{
					num2 -= 100;
					romanValue[counter++] = 'C';
				}
				else if (num2 >= 90)
				{
					num2 -= 90;
					romanValue[counter++] = 'X';
					romanValue[counter++] = 'C';
				}
				else if (num2 >= 50)
				{
					num2 -= 50;
					romanValue[counter++] = 'L';
				}
				else if (num2 >= 40)
				{
					num2 -= 40;
					romanValue[counter++] = 'X';
					romanValue[counter++] = 'L';
				}
				else if (num2 >= 10)
				{
					num2 -= 10;
					romanValue[counter++] = 'X';
				}
				else if (num2 >= 9)
				{
					num2 -= 9;
					romanValue[counter++] = 'I';
					romanValue[counter++] = 'X';
				}
				else if (num2 >= 5)
				{
					num2 -= 5;
					romanValue[counter++] = 'V';
				}
				else if (num2 >= 4)
				{
					num2 -= 4;
					romanValue[counter++] = 'I';
					romanValue[counter++] = 'V';
				}
				else if (num >= 1)
				{
					num2 -= 1;
					romanValue[counter++] = 'I';
				}
			} // end loop

			// gets rid of the garbage values
			romanValue[counter++] = '\0';


		} // end else if

		// invalid data
		else
		{
			printf("\nInvalid Roman Number\n");
		} // end else

		// prints the roman version of the arabic number
		printf("%d is %s\n", tempNumber, romanValue);
	} // end else

} // end function


int main()
{
	// Declaring variables
	int count = 0; // counts through the C String
	int value = 0; // holds the converted roman number
	double valueFraction = 0; // holds the converted roman number when a fraction is involved
	char number[100] = { '\0' }; // Stores the roman number or arabic number
	bool running = 1; // The thing that keeps the loop running

	// Used for vinculum
	int index;  // stores the index of where - or _ is located
	char* ptr;  // stores the address of - or _

	// A loop that will keep running until quit or QUIT is typed
	while (running)
	{
		// Asks the user for a roman or arabic number
		printf("Enter a roman or arabic number, type \"quit\" to exit: ");
		scanf_s("%s", number, sizeof(number));

		// If the C-String[0] is in the alphabet, chances are that it might be a roman number
		if (isalpha(number[count]) != 0)
		{
			// If the user types 'quit', the program ends
			if (strcmp(number, "quit") == 0)
			{
				running = 0;
			} // end if
			// Used to convert from lower case to uppercase
			for (size_t x = 0; x < strlen(number); x++)
			{
				// if it is lower case a-z, subtract 32 to go to upper case A-Z
				if ((number[x] >= 'a') && (number[x] <= 'z'))
				{
					number[x] -= UPPER;
				} // end if
			} // end for

			// runs through the C String to convert from roman to arabic
			while (number[count])
			{


				// The if statements that check if the C string entered is a valid roman number
				// If something like B, A, Q, etc... was entered, in the conversion function, it would return -1 for each case
				// Therefore they are invalid
				// Even if A is added to something like XI, this loop goes through all characters 1 by 1
				if (romanConvert(number[count]) < 0)
				{
					// exits loop if it is not a roman number
					break;
				} // end if

				// Basically if the initial number is greater than the second one, it would just add it normally
				// For example, if you had VI, since 5 > 1, it would just add normally to 6
				if (romanConvert(number[count]) >= romanConvert(number[count + 1]))
				{
					// for the . cases
					if (romanConvert(number[count]) == (1.0 / 12.0))
					{
						valueFraction += (1.0 / 12.0);
					}
					else
					{
						value += romanConvert(number[count]);

						// for when the S or . is involved
						valueFraction += romanConvert(number[count]);
					}



				} // end if

				// This is used for cases such as IV, IX, etc... 
				// So basically since the initial number before is less than the next number in the C-String
				// that would mean it would be IV or IX because 1 < 4 and 1 < 10
				else
				{
					// for the . cases
					if (romanConvert(number[count]) == (1.0 / 12.0))
					{
						valueFraction += (1.0 / 12.0);
					}
					else
					{
						// This takes the bigger number, for example in IX, it would take X and 
						// subtract it by I to get IX which is 10
						value += (romanConvert(number[count + 1]) - romanConvert(number[count]));

						// for when the S or . is involved
						valueFraction += (romanConvert(number[count + 1]) - romanConvert(number[count]));
					}

					// Increments count for the next roman number, if not added, it will duplicate the last number
					count++;
				} // end else

				// Increments count for the next roman number
				count++;

			} // end loop

			// Vinculum:
			// Basically if _ or - is found, it will find it then subtract the numbers after _ or - is found
			// Then it will multiply by 1000 (which is everything before _ or -
			// Then it will re-add then numbers subtracted
			if (strstr(number, "_") != NULL)
			{

				ptr = strchr(number, '_'); // stores the address of the underscore
				index = (int)(ptr - number); // stores the location of the string 

				// Uses the location of _ to subtract the the numbers after _
				for (int i = index; i < strlen(number); i++)
				{
					value -= romanConvert(number[count]);
					valueFraction -= romanConvert(number[count]);

					count--;
				}

				// multiply by 1000 for the fraction and normal version for vinculum
				value *= 1000;
				valueFraction *= 1000;
				count++;

				// add back the numbers that were subtracted
				while (number[count])
				{
					// Basically if the initial number is greater than the second one, it would just add it normally
					// For example, if you had VI, since 5 > 1, it would just add normally to 6
					if (romanConvert(number[count]) >= romanConvert(number[count + 1]))
					{
						// for the . cases
						if (romanConvert(number[count]) == (1.0 / 12.0))
						{
							valueFraction += (1.0 / 12.0);
						}
						else
						{
							value += romanConvert(number[count]);

							// for when the S or . is involved
							valueFraction += romanConvert(number[count]);
						}

					} // end if

					// This is used for cases such as IV, IX, etc... 
					// So basically since the initial number before is less than the next number in the C-String
					// that would mean it would be IV or IX because 1 < 4 and 1 < 10
					else
					{
						// for the . cases
						if (romanConvert(number[count]) == (1.0 / 12.0))
						{
							valueFraction += (1.0 / 12.0);
						}
						else
						{
							// This takes the bigger number, for example in IX, it would take X and 
							// subtract it by I to get IX which is 10
							value += (romanConvert(number[count + 1]) - romanConvert(number[count]));

							// for when the S or . is involved
							valueFraction += (romanConvert(number[count + 1]) - romanConvert(number[count]));
						}

						// Increments count for the next roman number, if not added, it will duplicate the last number
						count++;
					}
					count++;
				}
			}
			else if (strstr(number, "-") != NULL)
			{
				ptr = strchr(number, '-'); // stores the address of the underscore
				index = (int)(ptr - number); // stores the location of the string 

				// Uses the location of _ to subtract the the numbers after _
				for (int i = index; i < strlen(number); i++)
				{
					value -= romanConvert(number[count]);
					valueFraction -= romanConvert(number[count]);

					count--;
				}

				// multiply by 1000 for the fraction and normal version for vinculum
				value *= 1000;
				valueFraction *= 1000;
				count++;

				// add back the numbers that were subtracted
				while (number[count])
				{
					// Basically if the initial number is greater than the second one, it would just add it normally
					// For example, if you had VI, since 5 > 1, it would just add normally to 6
					if (romanConvert(number[count]) >= romanConvert(number[count + 1]))
					{
						// for the . cases
						if (romanConvert(number[count]) == (1.0 / 12.0))
						{
							valueFraction += (1.0 / 12.0);
						}
						else
						{
							value += romanConvert(number[count]);

							// for when the S or . is involved
							valueFraction += romanConvert(number[count]);
						}

					} // end if

					// This is used for cases such as IV, IX, etc... 
					// So basically since the initial number before is less than the next number in the C-String
					// that would mean it would be IV or IX because 1 < 4 and 1 < 10
					else
					{
						// for the . cases
						if (romanConvert(number[count]) == (1.0 / 12.0))
						{
							valueFraction += (1.0 / 12.0);
						}
						else
						{
							// This takes the bigger number, for example in IX, it would take X and 
							// subtract it by I to get IX which is 10
							value += (romanConvert(number[count + 1]) - romanConvert(number[count]));

							// for when the S or . is involved
							valueFraction += (romanConvert(number[count + 1]) - romanConvert(number[count]));
						}

						// Increments count for the next roman number, if not added, it will duplicate the last number
						count++;
					}
					count++;
				}
			}

			// This would mean that the decimals were added
			if (valueFraction > value)
			{
				// Prints out the roman conversion
				printf("%s is %.2lf\n", number, valueFraction);
			}
			// If it is not greater, it means that there was no S or . involved
			// Condition set to != quit so quit is not placed after the user types it 
			else if (strcmp(number, "QUIT") != 0)
			{
				// Prints out the roman conversion
				printf("%s is %d\n", number, value);
			}

		} // end if

		// if it is not in the alphabet, it is a number
		else if (isdigit(number[count]) != 0)
		{
			// activates the function
			arabicConvert(number, number);

		} // end if


		// Reseting values for the next roman number or integer
		count = 0;
		value = 0;
		valueFraction = 0;
	} // end loop

	// using the exit function from stdlib.h to exit the program 
	exit(0);
} // end main