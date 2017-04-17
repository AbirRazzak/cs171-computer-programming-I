#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double radius;
	const double  PI = atan(1) * 4;

	cout << "What is the radius? ";
	cin >> radius;

	cout << "Area of a circle with radius " << radius << " units is " << PI * radius *radius << " units^2 and circumference of " << 2.0 * PI * radius << "units";
	cout << endl;

	cout << "Volume of a sphere with radius " << radius << "units is " << 4.0 / 3.0 * PI * radius * radius * radius << "units^3 and surface area of " << 4.0 * PI * radius * radius << "units^2";
	cout << endl;
}