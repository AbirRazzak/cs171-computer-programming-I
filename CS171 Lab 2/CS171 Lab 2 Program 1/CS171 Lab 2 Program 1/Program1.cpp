#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int num1;
	int num2;

	cout << "What is your first number? ";
	cin >> num1;

	cout << "What is your second number? ";
	cin >> num2;

	cout << "The sum is: " << num1 + num2;
	cout << endl;

	cout << "The difference is: " << num1 - num2;
	cout << endl;

	cout << "The product is: " << num1*num2;
	cout << endl;

	cout << "The average is: " << (double)(num1 + num2) / 2.0;
	cout << endl;

	cout << "The distance is: " << abs(num1 - num2);
	cout << endl;

	cout << "The max is: " << max(num1, num2);
	cout << endl;

	cout << "The min is: " << min(num1, num2);
	cout << endl;
}