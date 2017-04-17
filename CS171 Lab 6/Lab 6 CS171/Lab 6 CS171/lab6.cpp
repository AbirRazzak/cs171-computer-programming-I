#include <iostream>
#include <fstream>
#include <string>
#include "lab6.h"
using namespace std;

int starts_with_letter(string filename, char letter)
{
	char uppercase;
	char lowercase; 

	if (isupper(letter)) 
	{
		uppercase = letter;
		lowercase = tolower(letter);
	}
	else
	{
		uppercase = toupper(letter);
		lowercase = letter;
	}

	ifstream infile;
	string inputfilename = filename;
	inputfilename += ".txt";
	infile.open(inputfilename);

	ofstream outfile;
	string outputfilename = "result_";
	outputfilename +=letter;
	outputfilename += ".txt";
	outfile.open(outputfilename);

	string word;

	int numwords = 0;
	while (infile >> word)
	{
		if (word[0] == uppercase || word[0] == lowercase)
		{
			outfile << word << endl;
			numwords++;
		}
	}

	infile.close();
	outfile.close();

	return numwords;
}

int main()
{
	cout << "Enter a filename" << endl;
	string filename;
	cin >> filename;
	
	char letters[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H','I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

	for (int i = 0; i < 26; i++)
	{
		cout << "Count of Words that start with " << letters[i] << " is " << starts_with_letter(filename, letters[i]) << endl;
	}
}