#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "Write three words" << endl;
	string a;
	string b;
	string c;

	cin >> a >> b >> c;

	string holder;
	if (b > c)
	{
		holder = b;
		b = c;
		c = holder;
	}

	if (a > b)
	{
		holder = a;
		a = b;
		b = holder;
	}

	if (b > c)
	{
		holder = b;
		b = c;
		c = holder;
	}
	cout << a << " " << b << " " << c << endl;
}