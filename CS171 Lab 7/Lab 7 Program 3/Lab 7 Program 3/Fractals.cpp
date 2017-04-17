#include <iostream>
#include <string>
using namespace std;


void printRepeat(string input, int times)
{
	while (times > 0)
	{
		cout << input;
		times--;
	}
	cout << endl;
}

void print(int length, int spaces) {
	if (spaces > 0) {
		cout << " ";
		print(length, spaces - 1);
	}
	else if (length > 0) {
		cout << "*";
		print(length - 1, spaces);
	}
}

void fractal(int length, int spaces)
{
	if (length == 1)
	{
		print(length, spaces);
		cout << endl;
	}
	else
	{
		fractal(length / 2, spaces);
		print(length, spaces);
		cout << endl;
		fractal((length / 2), (spaces + (length / 2)));
	}
}

int main()
{
	cout << "Fractal Generator" << endl << " Enter an integer > 0: ";
	int x;
	cin >> x;
	fractal(x, 0);

	return 0;
}