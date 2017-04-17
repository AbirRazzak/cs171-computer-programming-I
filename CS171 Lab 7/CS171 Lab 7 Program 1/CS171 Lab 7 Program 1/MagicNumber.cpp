#include <iostream>
#include <string>
using namespace std;

void calculateMagicNum(int &A, int B)
{
	A *= 2;
	A += 2;
	A *= 5;
	A -= (10 - B);
}

int secondDigit(int i)
{
	return i % 10;
}

int promptForInteger(const string &message, int lower, int upper)
{
	//gets input
	int input;
	cout << message;
	cin >> input;

	if (input >= lower && input <= upper) return input; //if input is within bounds, return input
	else promptForInteger(message, lower, upper); //if not, ask again
}

int main()
{
	cout << "WELCOME TO THE MAGICAL GAME!" << endl << "PERSON A AND B, THINK OF A NUMBER BETWEEN 1 AND 9!" << endl;
	int a = promptForInteger("PERSON A, TYPE IN YOUR NUMBER!: ", 1, 9);
	int b = promptForInteger("PERSON B, TYPE IN YOUR NUMBER!: ", 1, 9);
	cout << "PERSON A TURN AWAY SO PERSON B CAN SHOW THEIR NUMBER!" << endl << "PERSON B'S NUMBER IS " << b << "!!!" << endl;
	calculateMagicNum(a, b);
	int newA = secondDigit(a);
	cout << "Person A: 'The second digit of my super secret number is " << newA << "!' ";
	cout << endl << "THATS ALL FOLKS!" << endl;

	return 0;
}