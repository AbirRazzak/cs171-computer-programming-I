#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "Let's play a guessing game." << endl << "Pick a number between 0 and 100." << endl << "I will make guesses.Tell me if your number is higher or lower." << endl;
	int guess = 50;
	int min = 0;
	int max = 100;
	string answer;
	while (1==2)
	{
		cout << "Is your secret number " << guess << "?" << endl << "y for yes, l for lower or h for higher" << endl;
		cin >> answer;

		if (answer == "l")
		{
			max = guess - 1;
			guess = (min + max) / 2;
		}

		if (answer == "h")
		{
			min = guess + 1;
			guess = (min + max) / 2;
		}

		if (answer == "y")
		{
			break;
		}
	}
	cout << "Your secret number was " << guess << "!" << endl;
	return 0;
}