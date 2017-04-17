//-------------------------------------------------
// Program Name: Programs 2-5 (Problem 4.16)
// Purpose: Takes an inputted 
//			
// Coder: Abir Razzak
// Date: 1/27/16
// Last Modified: Abir Razzak, 1/31/17
//-------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

//Global Constants
const string HALFBAR = ":";
const string FULLBAR = "|";
const string ONEBAR = "00011";
const string TWOBAR = "00101";
const string THREEBAR = "00110";
const string FOURBAR = "01001";
const string FIVEBAR = "01010";
const string SIXBAR = "01100";
const string SEVENBAR = "10001";
const string EIGHTBAR = "10010";
const string NINEBAR = "10100";
const string ZEROBAR = "11000";
const int NUMBER_OF_DIGITS_IN_A_ZIP_CODE = 5;
const char ZERO_DIGIT = '0';
const char ONE_DIGIT = '1';
/**
	Computes the distance away that the sum of the digits in a zipcode is from the nearest multipule of 10.
	@param zipcode any 5 digit positive integer
	@return distance from the nearest multipule of 10 of the sum of the digits of the zipcode
*/
int makeDigitCheck(int zipcode)
{
	//Storing the inputted int
	int storedZipcode = zipcode;
	//Varible used to calculate the sum of the digits in the zipcode
	int sum = 0;
	//Loops through all digits in the number and adds them to the sum
	for (int i=1; i<=NUMBER_OF_DIGITS_IN_A_ZIP_CODE; i++)
	{
		sum += storedZipcode % 10;
		storedZipcode /= 10;
	}

	//If the sum is already a multipule of 10, then return 0
	if (sum % 10 == 0)
	{
		return 0;
	}
	//If not, return the distance away for the sum to reach the next multipule of 10
	else
	{
		return 10 - (sum % 10);
	}
}
/**
	Converts a digit into its barcode equivelent
	@param value any 1 digit positive integer
	@return string that represents the integer's barcode
*/
string convertDigit(int value)
{
	//Fail condition
	if (value < 0 || value > 9) { return "Not a valid digit. "; }

	//Determines the binary code for inputted value
	string binary;
	if (value == 0) { binary = ZEROBAR; }
	if (value == 1) { binary = ONEBAR; }
	if (value == 2) { binary = TWOBAR; }
	if (value == 3) { binary = THREEBAR; }
	if (value == 4) { binary = FOURBAR; }
	if (value == 5) { binary = FIVEBAR; }
	if (value == 6) { binary = SIXBAR; }
	if (value == 7) { binary = SEVENBAR; }
	if (value == 8) { binary = EIGHTBAR; }
	if (value == 9) { binary = NINEBAR; }

	//Creates a string "barcode" and adds to it by checking the digits in binary
	string barcode;
	for (char a : binary) 
	{
		//'0' will result in ":"
		if (a == ZERO_DIGIT)
		{
			barcode.append(HALFBAR);
		}
		//'1' will result in "|"
		if (a == ONE_DIGIT)
		{
			barcode.append(FULLBAR);
		}
	}

	return barcode;
}
/**
	Converts a zipcode into a barcode
	@param zipcode any 5 digit positive integer
	@return final barcode that is to be used by mail service
*/
string barcode(int zipcode)
{
	//Storing the inputted int
	int storedZipcode = zipcode;
	//Used to store the final barcode printout
	string finalBarcode = "";
	//Inserts the barcode for the digit check to finalBarcode
	finalBarcode.insert( 0, convertDigit( makeDigitCheck(zipcode) ) );
	//Inserts the barcodes for the digits of the zipcode backwards to the front of the string
	for (int i = 1; i <= NUMBER_OF_DIGITS_IN_A_ZIP_CODE; i++)
	{
		finalBarcode.insert( 0,convertDigit(storedZipcode % 10) );
		storedZipcode /= 10;
	}

	//Put a fullbar at the beginning of finalBarcode
	finalBarcode.insert(0, FULLBAR);
	//Put a fullbar at the end of finalBarcode
	finalBarcode.append(FULLBAR);
	//return finalBarcode
	return finalBarcode;
}

int main()
{
	//asks user for a zipcode
	int input;
	cout << "Enter a 5 digit zipcode to create a barcode for: " << endl;
	cin >> input;

	//if the zipcode is positive, then print out the barcode for it
	if (input >= 0)
	{
		cout << barcode(input) << endl;
		return 0;
	}
	//if the zipcode is negative, print out an error message
	else
	{
		cout << "ERROR! Please enter a positive number kind Sir/Ma'am. " << endl;
		return 1;
	}
}