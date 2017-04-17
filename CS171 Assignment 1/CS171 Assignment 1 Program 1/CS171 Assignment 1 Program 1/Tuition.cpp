//-------------------------------------------------
// Program Name: Program 1 (Tuition Calculator)
// Purpose: Takes an inputted initial tuition cost
//			and rate and gives the tuition of each
//			year and total amount for all 5 years.
// Coder: Abir Razzak
// Date: 1/17/16
// Last Modified: Abir Razzak, 1/19/17
//-------------------------------------------------

#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{
	//long integer used for storing initial tuition cost
	long int tuition;
	//doubled used for storing tuition rate
	double rate;
	//long used to calculate total tuition aftr 5 years
	long int total;

	//prompts user for intial tuition amount
	cout << "Enter the initial tuition amount: ";
	cin >> tuition;
	tuition = tuition * 100;

	//prompts user for tuition rate
	cout << "Enter the yearly tuition increase (as a percentage) : ";
	cin >> rate;
	rate = (rate / 100) + 1;

	//starting total should be $0.00
	const int STARTING_TOTAL = 0;
	total = STARTING_TOTAL;

	//prints out tuition for current year
	cout << "Tuition of Year 1 is: $" << tuition / 100 << "." << setw(2) << setfill('0') << tuition % 100;
	//adds current year tuition to total
	total += tuition;
	//calculates tuition for next year
	tuition = tuition*rate;
	cout << endl;

	//rinse and repeat
	cout << "Tuition of Year 2 is: $" << tuition / 100 << "." << setw(2) << setfill('0') << tuition % 100;
	total += tuition;
	tuition = tuition*rate;
	cout << endl;

	cout << "Tuition of Year 3 is: $" << tuition / 100 << "." << setw(2) << setfill('0') << tuition % 100;
	total += tuition;
	tuition = tuition*rate;
	cout << endl;

	cout << "Tuition of Year 4 is: $" << tuition / 100 << "." << setw(2) << setfill('0') << tuition % 100;
	total += tuition;
	tuition = tuition*rate;
	cout << endl;

	cout << "Tuition of Year 5 is: $" << tuition / 100 << "." << setw(2) << setfill('0') << tuition % 100;
	total += tuition;
	tuition = tuition*rate;
	cout << endl;

	//prints total tuition cost over the 5 years
	cout << "Total Tuition Cost is: $" << total / 100 << "." << setw(2) << setfill('0') << tuition % 100;
	cout << endl;

	//fin :)
	return 0;
}