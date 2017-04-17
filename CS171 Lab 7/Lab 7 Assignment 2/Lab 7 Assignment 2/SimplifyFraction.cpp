#include <iostream>
#include <cmath>
using namespace std;

/*
	Calculates the greatest common denominator (GCD) of two integers
	@param a - first integer
	@param b - second integer
	@return - greatest common denominator/factor between the two integers
*/
int gcd(int a, int b)
{
	//GCD is usually a positive number, so let's make both integers positive for simplicity
	a = abs(a);
	b = abs(b);

	//if the second integer is larger than the first integer, then switch the order
	if (a < b) return gcd(a, b);

	//if the second integer can divide evenly into the first intger, then the second integer is the GCD!
	if (a % b == 0)	return b;
	//if not, run the function again, but instead using the remainder as the second integer
	else return gcd(a, a % b);
}

int main()
{
	//prompts user to enter the numerator
	cout << "Enter your numerator: ";
	int numerator;
	cin >> numerator;

	//prompts the user to enter the denominator
	cout << "Enter your denominator: ";
	int denominator;
	cin >> denominator;

	//calculates the GCD between them
	int GCD = gcd(numerator, denominator);
	
	//calculates the simplified numerator and denominator
	int newNumerator = numerator / GCD;
	int newDenominator = denominator / GCD;

	//prints out the simplfied fraction along with the original fraction
	cout << "Simplified form: " << endl;
	cout << numerator << "/" << denominator << " = " << newNumerator << "/" << newDenominator << endl;

	// Note that if the user enters negative numbers for both numerator and denominator, then the final
	// final form will also have a negative numerator and denominator.

	return 0;
}