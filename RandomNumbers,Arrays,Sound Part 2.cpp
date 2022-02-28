// RandomNumbers,Arrays,Sound-P2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
//Creator Information:
/*
Name: Eric Phelps
Professor: Juan Rodriguez
Date Completed: 20220212
Project Name: Random Numbers,Arrays,Sound P2
*/

/*
Part 1 Goals:
	Create an array of "Rebels"
	create an array of "Locations"
	Add user input
	Add sound for the end of the game

Part 2 Goals:
	add "movement" to the rebels = change the output of the random number after each guess.
	Add the logic: some sort of score system
	Add the logic:correct guess, score goes up; incorrect guess score goes down.
	create a Beep sound.
	Display score, after each turn.
	Play again feature.
*/

//Libraries
#include <iostream> //iostream creates console readout.
#include <algorithm> // allows the use of the shuffle function.
#include <string> // allows for the string variables.
#include <windows.h>// library containing the Beep Sound.

using namespace std;

// Variables
int UserIn;
int Guess = 0;
int GradeStart = 2;  //had to use 2 because it starts at interval 0 and goes through 4
const char Grades[] = {'A', 'B', 'C', 'D', 'F'}; //use const char, instead of char for characters that can never be modified
char CurrGrade = Grades[GradeStart]; //sets current grade to grades start, allows the user to start at a C grade
bool RebelElim;
bool GameOver = false;
void InputCheck(int); 

string TryAgain;

// String Arrays
string Rebels [20] = { "Kyle Reese", "Sarah Connor", "John Connor", "Detectove O'brien", "Arnold Schwarzenegger", "Kate Brewster ","Ed Traxler", "Peter Silberman", "Hal Vukovich", "Miles Dyson", "Empty", "Empty", "Empty", "Empty", "Empty","Empty", "Empty", "Empty", "Empty", "Empty"};
string Hideouts[20] = { "1350","1018","1027","1063","2354","2354","2326","2371","2582","2593","2405","2144","2207","2306","2408","2505","2063","2702","2804","2091" };
string Occupied[20]; // Empty array used to pair the previous 2 arrays


// made function to check input results.
void InputCheck(int UserIn)
{
	cout << "\nMissle has been fired, lets check to after action.\n";
	if (Occupied[UserIn].length() > 11) { // compares and validates input to char length.
		Beep(450, 1000);
		// Correct prediction output.

		cout << "\nDirect hit, HVT eliminated. Letter Grade has increased\n";
		RebelElim = true;
		CurrGrade = Grades[--GradeStart];
		cout << "\nAfer Action Report: \n";
		for (int j = 0; j < 20; j++)
		{
			Occupied[j] = Hideouts[j] + ": " + Rebels[j];
			cout << "\n" << j << ". ) " << Hideouts[j] << ", " << Rebels[j];
		}
		cout << "\n\n";
		cout << "Your grade is now a " << CurrGrade << ".\n\n";
		system("pause");
	}
	else {
		Beep(450, 1000);
		// Incorrect Prediction Output.
		cout << "\nIncorrect, wasted fire.\n\n";
		RebelElim = false;
		CurrGrade = Grades[++GradeStart];
		cout << "\nAfter Action Report: \n";
		for (int j = 0; j < 20; j++) {
			Occupied[j] = Hideouts[j] + ": " + Rebels[j];
			cout << "\n" << j << ". ) " << Hideouts[j] << ", " << Rebels[j];
		}
		cout << "\n\n";
		cout << "Your grade is now a " << CurrGrade << ".\n\n";
		system("pause");
	}

	// Compares the new current grade with an A or an F to decide if the game will end.
	if (CurrGrade == 'A' || CurrGrade == 'F') {
		GameOver = true;
	}
	return;
}


int main() {
GameStart: // Creates a local variable to Anchor TryAgain

	// Opening Narrative //
	cout << "\n\t\t\t\t\t Welcome to Skynet, Cadet.\n\n";
	cout << "As our search for John Conner and the resistance has continued,We have an ever growing need for Pilots.\n\n";
	cout << "Today you will be using our new training simulation program.\n\n";
	cout << "This simulation will give you, 20 Grid Locations of well known rebel hideouts.\n\n";
	cout << "Within these 10 locations there are 10 HVTs that lead the resistance.\n\n";
	cout << "Your task is to predict which Hideout is currently housing a HVT.\n\n";
	cout << "You will Start this simulation with a C letter grade.\n\n";
	cout << "If you terminate a HVT, your grade will increase one letter.\n\n";
	cout << "If you predict incorrectly, your grade will decrease one letter.\n\n";
	cout << "Upon recieving your final grade, will determine your fate; \n if you recieve an A, you will graduate to Pilot, \n if you recieve an F, you will be terminated.\n\n";
	cout << "May you choose wisely, Cadet.\n\n";
	cout << "\n\t\t\t\t SkyNet Training Simulation Initalizing...\n\n";
	system("pause"); 

	do {
		cout << "\nThese are the grid locations all well known rebel hideouts:\n";
		random_shuffle(&Rebels[0], &Rebels[19]); // This mixes up the rebel names.
		for (int j = 0; j < 20; j++) {
			Occupied[j] = Hideouts[j] + ": " + Rebels[j]; // This assigns a rebel to a specific hideout.
			cout << "\n" << j << ". ) " << Hideouts[j]; // This will print out the list of hideouts.
		}
		cout << "\n\nMake your prediction of which hideout you belive a Rebel HVT to be hiding.\n\n";
		cin >> UserIn; // User Input .
		InputCheck(UserIn);
	}

	// Loop to set win/lose conditions.
	while (GameOver == false);
	if (CurrGrade == 'A' || CurrGrade == 'F') {
		if (CurrGrade == 'A') {
			cout << "\nCongrats, you have been promoted to Pilot, Serve SkyNet well!!\n";
		}
		else {
			cout << "\nYou have failed the training program, termination has been scheduled.\n";
		}

		// Closing Narritive
	Restart: // anchor for if user inputs the wrong characters.
		cout << "Would you like to tray again?";
		cout << "\nTo try again, type [yes]. To accept termination, type [no].\n\n";
		cin >> TryAgain; //user input
		if (TryAgain == "yes" || TryAgain == "Yes") { 
			cout << "\n\n\n";
			goto GameStart; // if user selects yes, goes to anchor GameStart.
		}
		if (TryAgain == "no" || TryAgain == "No") { 
			return 0; // if user selects no, end program.
		}
		else { // Otherwise restate the choices. 
			goto Restart;
		}
	}
}





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
