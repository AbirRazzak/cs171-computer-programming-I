#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int promptForInteger(const string &message, int lower, int upper)
{
	//gets input
	int input;
	cout << message;
	cin >> input;

	if (input >= lower && input <= upper) return input; //if input is within bounds, return input
	else promptForInteger(message, lower, upper); //if not, ask again
}

void calculate(int v[10], int minAge, int maxAge)
{
	ifstream infile;
	infile.open("alcohol.txt");
	string line;
	while (getline(infile, line))
	{
		//cout << "IS WHILE A WORKIN";
		if (line[2] * 10 + line[3] >= minAge + 48 + 480 && line[2] * 10 + line[3] <= maxAge + 48 + 480)
		{
			//cout << "IS FIRST IF WORKIN";
			int frequency = line[5] - 48;
			int position;
			if (line[0] == 'M')
			{
				position = frequency * 2 - 2;
				v[position] = v[position] + 1;
				//cout << v[position] << "TEST";
			}
			if (line[0] == 'F')
			{
				position = frequency * 2 - 1;
				v[position] = v[position] + 1;
			}
		}
	}
	infile.close();
}

void bargraph(int v[10])
{
	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
		{
			cout << "M Freq. " << (i / 2) + 1 << " ";
		}
		else
		{
			cout << "F Freq. " << (i / 2) + 1 << " ";
		}
		int tens = v[i] / 10;
		int ones = v[i] % 10;
		
		while (tens > 0)
		{
			cout << "X";
			tens--;
		}

		cout << ones << endl;
	}
}

int main()
{	
	int v[10];
	int minAge;
	int maxAge;
	bool stop = false;
	string answer = "y";
	while (answer == "y")
	{
		int v[10] = { 0,0,0,0,0,0,0,0,0,0 };
		minAge = promptForInteger("Enter Minimum Age as integer ", 15, 21);
		maxAge = promptForInteger("Enter Maximum Age as integer ", 16, 22);
		calculate(v, minAge, maxAge);
		bargraph(v);

		cout << "Create a new table? y/n: ";
		
		cin >> answer;
		//if (answer == "n") stop == true;
	}
	/*for (int i = 0; i < 10; i++)
	{
		cout << v[i] << endl;
	} */
	return 0;
}