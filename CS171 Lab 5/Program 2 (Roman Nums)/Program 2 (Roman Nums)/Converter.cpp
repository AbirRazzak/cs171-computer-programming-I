#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string roman(int num, string one, string five, string ten)
{
	switch (num)
	{
	case 1:
		return one;
		break;

	case 2:
		return one + one;
		break;

	case 3:
		return one + one + one;
		break;

	case 4:
		return one + five;
		break;

	case 5:
		return five;
		break;

	case 6:
		return five + one;
		break;

	case 7:
		return five + one + one;
		break;

	case 8:
		return five + one + one + one;
		break;

	case 9:
		return one + ten;
		break;
	}
	return "";
}

string roman_num(int num)
{
	string output="";

	if (num > 1000)
	{
		int thousands = num / 1000;
		output += roman(thousands, "M", "v", "x");
		num -= thousands * 1000;
	}
	if (num > 99)
	{
		int hundreds = num / 100;
		output += roman(hundreds, "C", "D", "M");
		num -= hundreds * 100;
	}
	if (num > 9)
	{
		int tens = num / 10;
		output += roman(tens, "X", "L", "C");
		num -= tens * 10;
	}
	if (num > 0)
	{
		int ones = num / 1;
		output += roman(ones, "I", "V", "X");
		num -= ones * 1;
	}
	return output;
}

int main()
{
	int input;
	cout << "Roman Number gnerator. Enter 0 to quit." << endl;
	cout << "Enter a number between 1 and 3,999: " << endl;
	cin >> input;
	while (input != 0)
	{
		cout << "Roman Numerals: " << roman_num(input) << endl;
		cout << "Enter a number between 1 and 3,999: " << endl;
		cin >> input;
	}
	return 0;
}