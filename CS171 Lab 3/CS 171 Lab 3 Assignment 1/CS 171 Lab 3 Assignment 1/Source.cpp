#include <iostream>
using namespace std;

int main()
{
	cout << "Write a month. " << endl;
	int month;
	cin >> month;

	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		cout << "That month has 31 days.";
		return 0;
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		cout << "That month has 30 days.";
		return 0;
	}
	else {
		cout << "That month has 28 or 29 days.";
		return 0;
	}

	return 1;
}