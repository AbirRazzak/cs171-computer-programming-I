//-----------------------------------------------------
// Program Name: Blood Alcohol Concentration Calculator
// Purpose: Takes an inputted weight, gender, and time
//			since last drink and calculates BAC.
// Coder: Abir Razzak
// Date: 2/15/17
// Last Modified: Abir Razzak, 2/16/17
//-----------------------------------------------------
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const double FEMALE_BAC_CONSTANT = 4.5;
const double MALE_BAC_CONSTANT = 3.8;
const double TIME_TO_LOWER_BAC = 40.0;
const double DECREASE_IN_BAC = 0.01;

const double safe = 0.00;
const double someImpairment = 0.04;
const double significantAffected = 0.08;
const double someCriminalPenalties = 0.10;
const double deathPossible = 0.30;
const string SAFE = "Safe To Drive";
const string SOMEIMPAIR = "Some Impairment";
const string SIGNIFICANT = "Driving Skills Significantly Affected";
const string MOST_STATES = "Criminal Penalties in Most US States";
const string ALL_STATES = "Legally Intoxicated - Criminal Penalties in All US States";
const string YOURE_DEAD = "Death is Possible!";
/*
	Computes the BAC for both a male and female based on given number of drinks, weight, and time since last drink.
	@param numDrinks- number of drinks person had
	@param weight- weight of person drinking
	@param duration- how long it has been since last drink
	@param &maleBAC- BAC for a male given those parameters
	@param &femaleBAC- BAC for a female given those parameters
*/
void computeBloodAlcoholConcentration(int numDrinks, int weight, int duration, double &maleBAC, double &femaleBAC)
{
	femaleBAC = (double) numDrinks / (double) weight  * FEMALE_BAC_CONSTANT  - DECREASE_IN_BAC * ( (double) duration / TIME_TO_LOWER_BAC);
	maleBAC = ( (double) numDrinks * MALE_BAC_CONSTANT / (double) weight ) - DECREASE_IN_BAC * ( (double) duration / TIME_TO_LOWER_BAC);

	if (femaleBAC < 0.0) femaleBAC = 0.0;
	if (maleBAC < 0.0) maleBAC = 0.0;
}

/*
	Determines the level of impairment for a person given thier BAC
	@param bac- BAC of person
	@return- String describing the level of impairment of person
*/
string impairment(double bac)
{
	if (bac == safe) return SAFE;
	if (bac > deathPossible) return YOURE_DEAD;
	if (bac >= someCriminalPenalties) return ALL_STATES;
	if (bac >= significantAffected) return MOST_STATES;
	if (bac >= someImpairment) return SIGNIFICANT;
	if (bac > safe) return SOMEIMPAIR;
	//if (bac < safe) return "NEGATIVE BAC IS IMPOSSIBLE";
}
/*
	Asks the user for an integer, and keeps asking until you recieve an interger within a certain bound
	@param &message- String used to ask the user to enter an integer
	@param lower- the lower bound for the int
	@param upper- the upper bound for the int
	@return- the integer that the user inputs (within bounds)
*/
int promptForInteger(const string &message, int lower, int upper)
{
	//gets input
	int input;
	cout << message;
	cin >> input;

	if (input >= lower && input <= upper) return input; //if input is within bounds, return input
	else promptForInteger(message, lower, upper); //if not, ask again
}
/*
	Asks the user for M or F, used for detmining gender for BAC
	@param message- The message used for asking the user for their gender
	@return- M or F, based on user input
*/
char promptForMorF(const string &message)
{
	//gets input
	char input;
	cout << message;
	cin >> input;

	if (input == 'M' || input == 'F') return input; //if input is M or F, then return input
	else promptForMorF(message); //if not, ask again
}
/*
	Prints out a chart for BAC for up to 10 drinks
	@param weight- weight of person
	@param duration- time since last drink
	@param isMale- whether tester is male or not
*/
void showImpairmentChart(int weight, int duration, bool isMale)
{
	//	Because of the level of accuracy of the parameters, with both weight and duration being rounded to the nearest int,
	//	I felt it was innapropriate to determine BAC over a significant figure of 2 as both weight and duration will only
	//	have a signifcant figure of 2 or less.

	double Male_BAC; //Stores male BAC
	double Female_BAC; // Stores female BAC
	for (int i = 0; i <= 10; i++)
	{
		double currBAC; //Stores BAC for current num of drinks
		cout << setfill(' ') << setw(8);
		cout << i; //Prints out number of drinks
		cout << " " << fixed << setprecision(2);
		computeBloodAlcoholConcentration(i, weight, duration, Male_BAC, Female_BAC); //Calculates BAC for current num of drinks
		if (isMale) currBAC = Male_BAC; //if male, use Male_BAC as display
		else currBAC = Female_BAC; //if female, use Female_BAC as display
		cout << currBAC; //Displays BAC for current drink num
		cout << " " << setfill('x') << setw(3);
		cout << impairment(currBAC); //Displays the impairment level for current BAC
		cout << endl;

	}
}
int main()
{
	//ask for weight
	const int WEIGHT_OF_FATTEST_MAN_ALIVE = 812;
	int weight = promptForInteger("Enter your weight (in lbs): ", 1, WEIGHT_OF_FATTEST_MAN_ALIVE);
	//ask how long since last drink
	const int MINUTES_IN_A_DAY = 1440;
	int duration = promptForInteger("How many minutes since your last drink? ", 0, MINUTES_IN_A_DAY);
	//ask if M or F
	bool isMale;
	char gender = promptForMorF("Is you a male or female? ");
	//if male, use maleBAC
	if (gender == 'M') isMale = true;
	//if not, use femaleBAC
	else isMale = false;
	//print person summary
	cout << weight << " pounds, " << gender << ", " << duration << " since last drink." << endl;
	//prints out table headings
	cout << "# drinks  BAC Status" << endl;
	//print out chart
	showImpairmentChart(weight, duration, isMale);
}