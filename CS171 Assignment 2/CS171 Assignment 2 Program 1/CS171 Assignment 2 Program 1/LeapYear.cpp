//-------------------------------------------------
// Program Name: Program 1 (Leap Year Calculator)
// Purpose: Takes an inputted year and determines
//			if the year is a leap year or not.
// Coder: Abir Razzak
// Date: 1/27/16
// Last Modified: Abir Razzak, 1/27/17
//-------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
	//Asks user for an inputted year
	int year;
	cout << "What year are you curious about?" << endl;
	cin >> year;

	//Every four years is a leap year
	const int LEAP_YEAR = 4;
	//If the year is divisble by 100, then an exception is made and is not a leap year
	const int NOT_LEAP_YEAR = 100;
	//Special case: If the year is divisible by 400, then it definetely is a leap year
	const int LEAP_YEAR_EXCEPTION = 400;

	cout << "---------------------------------" << endl;
	cout << "RESULTS: " << endl;

	//If input is divisble by 400, then input is a leap year
	if (year % LEAP_YEAR_EXCEPTION == 0)
	{
		cout << year << " is a leap year!" << endl;
		return 0;
	}
	
	//If input is divible by 100 then input is not a leap year
	else if (year % NOT_LEAP_YEAR == 0)
	{		
		cout << year << " is NOT a leap year :(" << endl;
		return 1;
	}

	//If input is not divisible by 100, but is divisible by 4, then input is leap year
	else if (year % LEAP_YEAR == 0)
	{
		cout << year << " is a leap year!" << endl;
		return 0;
	}
	
	//If all fails, the input is not a leap year
	cout << year << " is NOT a leap year :(" << endl;
	return 1;
}