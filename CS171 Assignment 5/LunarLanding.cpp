//-----------------------------------------------------
// Program Name: Moon Landing Game
// Purpose: Simulate an astronaut attempting to land on
//			the moon from 1000 feet above its surface 
// Coder: Abir Razzak
// Date: 3/15/17
// Last Modified: Abir Razzak, 3/17/17
//-----------------------------------------------------
#include <iostream>
#include <cmath>
#include <string>
#include <ostream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

const double MOON_GRAVITY = 5.0; //-5ft/sec, assume positive velocity is downward

void reportStatus(ostream &os, double time, double height, double velocity, double fuel, string name) {
	//construct line 1 (status line)
	string line1 = "Status of your " + name + " spacecraft: \n";
	os << line1;
	cout << line1;

	//contruct line 2 (time)
	string line2 = "Time  :" + to_string(time) + " seconds \n";
	os << line2;
	cout << line2;

	//construct line 3 (height)
	string line3 = "Height:" + to_string(height) + " feet \n";
	os << line3;
	cout << line3;

	//construct line 4 (veloctiy)
	string line4 = "Speed :" + to_string(velocity) + " feet/second \n";
	os << line4;
	cout << line4;

	//construct line 5 (fuel)
	string line5 = "Fuel  :" + to_string(fuel) + "\n";
	os << line5;
	cout << line5;
}

/*
	updateStatus - 	uses the current values	of velocity, burnAmount, fuelRemaining and height to compute the values	one	second later
	@param velocity - velocity of spaceship
	@param burnAmount - amount of fuel units user is burning for this second
	@param fuelRemaining - fuel remaining for the spaceship
	@param height - altitude of spaceship relative to moon's surface
*/
void updateStatus(double &velocity, double burnAmount, double &fuelRemaining, double &height) {
	fuelRemaining -= burnAmount; //burn fuel and compute fuel left

	double oldVelocity = velocity; //store old velocity
	velocity += (MOON_GRAVITY - burnAmount); //calculate new velocity

	double avgVelocity = (velocity + oldVelocity) / 2.0; //calculate average velocity from old velocity to new velocity
	height -= avgVelocity; //calculate new height
}

/*
	introduction - gets instructions via some input stream is, and output those instructions to some output stream os
	@param is - input file that contains the instructions
	@param os - output file writing everything to
	@param target - string that is to be replaced when writing to os
	@param replacement - string that is to replace target
*/
void introduction(istream &is, ostream &os, string target, string replacement) {
	string line;
	while (getline(is, line)) {
		string currentWord;
		for (int i = 0; i < line.length(); i++) {

			//if the next character is a space
			if (line[i] == ' ' || line[i + 1] == NULL) {
				if (currentWord == target) { //if the currentword that was processed is the target word
					os << replacement << " "; //print out the replacement word instead
					cout << replacement << " ";
				}
				else { //if not, then just print out the actual word
					os << currentWord << " ";
					cout << currentWord << " ";
				}
				currentWord = ""; //now reset the currentword
			}


			else {
				currentWord += line[i]; //contruct the word you are reading by adding the current character you are reading and storing it in currentword
			}
		}
		//when the line is finished, indent to the next line
		os << "\n";
		cout << "\n";
	}
}

/*
	touchdown - updates parameters correctly to analyze impact on moon
	@param elapsedTime - time rounded up of spacecraft impact
	@param velocity - velocity of spacecraft at elapsedtime
	@param burnAmount - amount of fuel user burned during the second
	@param height - height of spacecraft at elapsedtime (will be either negative or zero)
*/
void touchdown(double &elapsedTime, double &velocity, double &burnAmount, double &height) {

	//undo last update
	double timeBeforeImpact = elapsedTime - 1.0; //oldtime
	double velocityBeforeImpact = velocity - (MOON_GRAVITY - burnAmount); //oldvelocity
	double avgVelocityBeforeImpact = (velocity + velocityBeforeImpact) / 2.0;
	double heightBeforeImpact = height + avgVelocityBeforeImpact; //oldheight

	//calculate delta
	double delta;
	if (burnAmount == 5) delta = heightBeforeImpact / velocityBeforeImpact;
	else {
		delta = sqrt(velocityBeforeImpact*velocityBeforeImpact + heightBeforeImpact*(10.0 - 2.0*burnAmount) );
		delta -= velocityBeforeImpact;
		delta /= (5 - burnAmount);	
	}

	//finally, compute
	elapsedTime = (elapsedTime - 1.0) + delta;
	velocity = velocityBeforeImpact + (5 - burnAmount)*delta;
	height = 0.00;
}

/*
	finalAnalysis - displays damage of impact on spacecraft depending on velocity of impact
	@param os - output file that results will be printing out to
	@param velocity - velocity of spacecraft impact to the moon
*/
void finalAnalysis(ostream &os, double velocity) {
	if (velocity == 0) {
		const string velocity0 = "Congratulations! A perfect landing!! \n Your license will	be renewed...later. \n";
		os << velocity0;
		cout << velocity0;
	}
	if (velocity > 0 && velocity < 2) {
		const string velocity2 = "A	little bumpy. \n";
		os << velocity2;
		cout << velocity2;
	}
	const string family = "\n Your family will be notified... by post. \n";
	if (velocity >= 2 && velocity < 5) {
		const string velocity5 = "You blew it!!!!! \n Your family will be notified... by post. \n";
		os << velocity5;
		cout << velocity5;
	}
	if (velocity >= 5 && velocity < 10) {
		const string velocity10 = "Your ship is a heap of junk!!!!! \n Your family will be notified... by post. \n";
		os << velocity10;
		cout << velocity10;
	}
	if (velocity >= 10 && velocity < 30) {
		const string velocity30 = "You blasted a huge crater!!!!! \n Your family will be notified... by post. \n";
		os << velocity30;
		cout << velocity30;
	}
	if (velocity >= 30 && velocity < 50) {
		const string velocity50 = "Your ship is a wreak!!!!! \n Your family will be notified... by post. \n";
		os << velocity50;
		cout << velocity50;
	}
	if (velocity >= 50) {
		const string velocity51 = "You totaled an entire mountain!!!!! \n Your family will be notified... by post. \n";
		os << velocity51;
		cout << velocity51;
	}

	if (velocity < 0) {
		cout << "Something went wrong with your velocity... \n";
	}
}
int main(){
	cout << "What do you want to name your output file? (Type .txt at the end pls): ";
	string outputFile;
	cin >> outputFile;
	ofstream output; //create an output file
	output.open(outputFile);

	const string shipName = "APOLLO"; //change this if you want to change the name of the ship

	// *** Ask the user if he/she needs to read the directions
	cout << "Do you want instructions(y / n) ?  "; 
	output << "Do you want instructions(y / n) ?  ";
	char dirAnswer; //stores answer to question
	cin >> dirAnswer;
	output << dirAnswer << "\n";
	if (dirAnswer == 'y' || dirAnswer == 'Y') { //if the user answers yes then run the introduction function
		ifstream directions("input.txt"); //open the directions text file
		introduction(directions, output, "$SPACECRAFT", shipName);
		directions.close(); //close a file when you're down with it! :D
	}
	
	//Inital Conditions:
	double alt = 1000.00; //1000 ft
	double vel = 50.00; //50 ft/sec
	double fuel = 150; //150 fuel units
	double time = 0.0; //starting time is 0s
	double burnAmount = -1; //fuel burning variable

	while (alt > 0) {
		reportStatus(output, time, alt, vel, fuel, shipName); //print out current status of ship
		burnAmount = -1; //reset burnAmount
		//if there is fuel left to burn
		if (fuel > 0) {
			//ask for fuel to burn
			while (burnAmount < 0 || burnAmount > 30) {
				cout << "How many fuel units do you want to burn? ";
				output << "How many fuel units do you want to burn? ";
				cin >> burnAmount;
				if (burnAmount >= fuel) {
					burnAmount = fuel;
				}
				output << burnAmount << "\n";
			}
		}
		//if no fuel left output that user is out of fuel
		else {
			cout << "****OUT OF FUEL**** \n";
			output << "****OUT OF FUEL**** \n";
			burnAmount = 0;
		}
		updateStatus(vel, burnAmount, fuel, alt); //update new values
		time += 1.0; //time goes forward 1s
	}

	touchdown(time, vel, burnAmount, alt);

	//display touchdown stats
	cout << "Touchdown at " << time << " seconds. \n";
	output << "Touchdown at " << time << " seconds. \n";
	cout << "Landing velocity= " << vel << " feet/second. \n";
	output << "Landing velocity= " << vel << " feet/second. \n";
	cout << "Fuel remaining: " << fuel << " \n";
	output << "Fuel remaining: " << fuel << " \n";
	finalAnalysis(output, vel);
	output.close(); //close output file
	return 0;
}