#include <iostream>
using namespace std;

int main()
{
	cout << "How many hours did you work this week? (decimal)? ";
	double hours;
	cin >> hours;

	cout << "How much do you get paid? (decimal) ";
	double pay;
	cin >> pay;

	double OT=0;
	if (hours > 40)
	{
		OT = hours - 40.0;
		hours = hours - OT;
	}
	cout << (hours*pay + OT*1.5*pay) << endl;
}