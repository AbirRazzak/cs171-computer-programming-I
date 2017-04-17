#include <iostream>
using namespace std;

int main()
{
	int input;
	int min = 100;
	cout << "Enter a number between 1 and 100. Enter 0 or a number > 100 to quit: " << endl;
	cin >> input;
	while (input != 0 && input < 100)
	{
		if (input < min) min = input;
		cout << "The smallest number you have entered in : " << min << endl;
		cout << "Enter a number between 1 and 100. Enter 0 or a number > 100 to quit: " << endl;
		cin >> input;
		
	}
	cout << "Bye." << endl;
	return 0;
}