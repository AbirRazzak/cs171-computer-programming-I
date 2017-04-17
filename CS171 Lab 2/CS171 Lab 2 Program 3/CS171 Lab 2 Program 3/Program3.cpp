#include <iostream>
using namespace std;

int main()
{
	int side1;
	int side2;

	cout << "Enter side 1 ";
	cin >> side1;

	cout << "Enter side 2 ";
	cin >> side2;

	cout << "Area of rectangle is " << side1*side2 << " and perimeter is " << 2 * side1 + 2 * side2 << endl;
	cout << "Diagonal of rectangle is " << sqrt(side1*side1 + side2*side2) << endl;
}