#include <iostream>
#include <cmath>
#include <string>
using namespace std;

const double MOON_GRAVITY = -1.63;

void landing(double a, double v, int time)
{
	int f = -1;
	while (f < 0)
	{
		cout << "How many fuel units do you want to burn? ";
		cin >> f;
	}
	v += ( MOON_GRAVITY + (0.1)*f ) ;
	a += v;
	if (a < 0.00) a = 0.00;
	cout << "After " << time << " seconds, Altitude: " << a << " Velocity: " << v << endl;
	if (a > 0) landing(a, v, time+1);
	if (a == 0)
	{
		if (v < -2.00) cout << "HE CRASH LANDED!!! \n";
		if (v >= -2.00) cout << "HE STUCK THE LANDING! \n";
	}
}
int main()
{
	cout << "Initial altitude? ";// << endl;
	double alt;
	cin >> alt;

	cout << "Initial velocity? ";// << endl;
	double vel;
	cin >> vel;

	landing(alt, vel, 1);
}