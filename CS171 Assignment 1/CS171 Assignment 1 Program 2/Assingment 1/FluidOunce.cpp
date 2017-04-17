//-------------------------------------------------
// Program Name: Program 2 (Fluid Ounce input)
// Purpose: Converts an inputted amount of
//			fluid ounces and converts that
//			amount into various units.
// Coder: Abir Razzak
// Date: 1/16/16
// Last Modified: Abir Razzak, 1/18/17
//-------------------------------------------------

#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{
	// int input - the number of fluid ounces the user will input
	int input;
	// int remaining - the number of fluid ounces remaining upon subtracting one conversion
	int remaining;

	//asks the user how many fluid ounces he/she wants to convert
	cout << "How many fluid ounces do you have? ";
	cin >> input;

	//sets the remaining fluid ounces to the inputted (max) fluid ounces
	remaining = input;

	cout << input << " fluid ounces can be divided into:";
	cout << endl;

	//conversion factors:
	const int FLUID_OUNCE_IN_BARREL = 5376;
	const int FLUID_OUNCE_IN_GALLON = 128;
	const int FLUID_OUNCE_IN_QUART = 32;
	const int FLUID_OUNCE_IN_PINT = 16;
	const int FLUID_OUNCE_IN_CUP = 8;
	const int FLUID_OUNCE_IN_GILL = 4;
	const int TABLESPOONS_IN_FLUID_OUNCE = 2;

	//checks how many units can be factored into the remaining fluid ounces
	input = remaining / FLUID_OUNCE_IN_BARREL;
	//subtracts the amount of fluid ounces that can be converted into a unit
	remaining -= input * FLUID_OUNCE_IN_BARREL;
	//prints the number of units out
	cout << setw(1) << setfill('0') << input << " barrel(s)";
	cout << endl;

	//rinse and repeat
	input = remaining / FLUID_OUNCE_IN_GALLON;
	remaining -= input * FLUID_OUNCE_IN_GALLON;
	cout << input << " gallon(s)";
	cout << endl;

	input = remaining / FLUID_OUNCE_IN_QUART;
	remaining -= input * FLUID_OUNCE_IN_QUART;
	cout << setw(1) << setfill('0') << input << " quart(s)";
	cout << endl;

	input = remaining / FLUID_OUNCE_IN_PINT;
	remaining -= input * FLUID_OUNCE_IN_PINT;
	cout << setw(1) << setfill('0') << input << " pint(s)";
	cout << endl;

	input = remaining / FLUID_OUNCE_IN_CUP;
	remaining -= input * FLUID_OUNCE_IN_CUP;
	cout << setw(1) << setfill('0') << input << " cups(s)";
	cout << endl;

	input = remaining / FLUID_OUNCE_IN_GILL;
	remaining -= input * FLUID_OUNCE_IN_GILL;
	cout << setw(1) << setfill('0') << input << " gill(s)";
	cout << endl;

	//takes remaining fluid ounces and converts them into tablespoons
	input = remaining * TABLESPOONS_IN_FLUID_OUNCE;
	//prints the amount of tablespoons remaining
	cout << setw(1) << setfill('0') << input << " tablespoons";
	cout << endl;

	//fin
	return 0;
}