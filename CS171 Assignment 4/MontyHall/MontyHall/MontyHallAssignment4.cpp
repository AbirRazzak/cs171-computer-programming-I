//-----------------------------------------------------
// Program Name: Legendary Monty Hall Problem
// Purpose: Runs 10,000 simulations of the popular game
//			show "Let's Make a Deal" and displays 
//			player statistics on chance of winning a car
// Coder: Abir Razzak
// Date: 3/1/17
// Last Modified: Abir Razzak, 3/3/17
//-----------------------------------------------------
#include <iostream>
#include <cmath>
#include <string>
#include <random>
using namespace std;

const char CAR = 'C';
const char GOAT = 'G';

/*
	Sets up the doors with a new set of goats and car
	@param &door1 - what lies behind the first door already
	@param &door2 - what lies behind the second door already
	@param &door3 - what lies behind the third door already
*/
void setupDoors(char &door1, char &door2, char &door3)
{
	//checks if there are 2 goats and 1 car present behind the doors already
	if ( (door1 == CAR) && (door2 == GOAT) && (door3 == GOAT) )
	{
		//Door 1 is car and the other two are goats
	}
	else if ( (door2 == CAR) && (door1 == GOAT) && (door3 == GOAT) )
	{
		//Door 2 is car and the other two are goats
	}
	else if ( (door3 == CAR) && (door1 == GOAT) && (door2 == GOAT) )
	{
		//Door 3 is car and the other two are goats
	}
	else
	{
		//error statement
		cout << "ERROR, THERE MUST BE A CAR AND 2 GOATS PRESENT";
		return;
	} 

	//randomizer:
	random_device rd;
	mt19937 rng(rd());
	uniform_int_distribution<int> uni(1, 3);
	auto random_integer = uni(rng);
		
	int carDoor = uni(rng); //Generate a random number to determine what door gets the car

	//the random number decides which door has the car, the other two have goats
	if (carDoor == 1)
	{
		door1 = CAR;
		door2 = GOAT;
		door3 = GOAT;
	}
	else if (carDoor == 2)
	{
		door1 = GOAT;
		door2 = CAR;
		door3 = GOAT;
	}
	else if (carDoor == 3)
	{
		door1 = GOAT;
		door2 = GOAT;
		door3 = CAR;
	}
	else
	{
		//error statement
		cout << "YOUR RNG WENT WRONG BUDDY";
		return;
	}

	return;
}

/*
	randomly picks a door for the player and for Monty Hall
	@param &door1 - what lies behind the first door already
	@param &door2 - what lies behind the second door already
	@param &door3 - what lies behind the third door already
	@param &doorPlayer - randomly picked door for player
	@param @doorMonty - door picked for Monty that is not player's
						door nor the door that has the car
*/
void pickDoorChoices(char door1, char door2, char door3, int &doorPlayer, int &doorMonty)
{
	//randomizer:
	random_device rd;
	mt19937 rng(rd());
	uniform_int_distribution<int> uni(1, 3);
	auto random_integer = uni(rng);

	doorPlayer = uni(rng); //assigns the player a random door, can be any door

	bool validDoor = false; //boolean to keep track of Monty's random door to check validity

	while (validDoor == false) //while the random door is false, keep generating random doors for Monty
	{
		doorMonty = uni(rng);
		
		//checks if Monty's Door is different than Player's Door
		if (doorMonty != doorPlayer) 
		{
			// checks if Monty's door does not have a car behind it
			if ( (doorMonty == 1) && (door1 != CAR) ) validDoor = true;
			else if ( (doorMonty == 2) && (door2 != CAR) ) validDoor = true;
			else if ( (doorMonty == 3) && (door3 != CAR) ) validDoor = true;
		}

		//if not, validDoor still is false
	}

}
int main()
{
	int stayRight = 0; //keeps track of when not switching doors worked
	int stayWrong = 0; //keeps track of when player should have switched doors
	char a = CAR; //door 1
	char b = GOAT; //door 2
	char c = GOAT; // door 3
	int playerChoice; //door player chooses
	int montyChoice; // door Monty reveals

	cout << "WELCOME TO LET'S MAKE A DEAL!" << endl << "STARRING MONTY HALL!" << endl << "----------------------------------------------" << endl;
	int i;
	//run simulation 10,000 times
	for (i= 1; i <= 10000; i++)
	{
		setupDoors(a, b, c); //sets up the doors
		pickDoorChoices(a, b, c, playerChoice, montyChoice); //gives monty and the player a door to pick

		//if the player's choice is correct, add one to stayRight count
		if (playerChoice == 1 && a == CAR) stayRight++; 
		else if (playerChoice == 2 && b == CAR) stayRight++;
		else if (playerChoice == 3 && c == CAR) stayRight++;
		else stayWrong++; //if it wasn't correct, add one to stayWrong count
	}
	i--; //number of experiments ran (subtract one because iterator is one over the number of experiements in order to stop loop)

	double percentRight = stayRight / (i * 1.0) * 100; //calculate the total percent of not switching doors was correct
	double percentWrong = stayWrong / (i * 1.0) * 100; //calculate the total percent of switching doors was correct

	//display stats
	cout << "Sticking to your original choice was correct: " << stayRight << "/" << i << " (" << percentRight << "%) times." << endl;
	cout << "Changing your mind on the choice was correct: " << stayWrong << "/" << i << " (" << percentWrong << "%) times." << endl;

	//conclusion
	if (stayWrong > stayRight) cout << "Therefore, it is to the player's advantage to switch doors!" << endl;
	if (stayRight > stayWrong) cout << "Therefore, it is to the player's advantage to stay with the original door!" << endl;
	if (stayRight == stayWrong) cout << "It doesn't matter what you decided to do!" << endl;
	return 0;
}