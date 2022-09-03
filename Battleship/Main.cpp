#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <Windows.h>

#include "Battleship.h"

using namespace std;

Battleship b = Battleship();

//Outputs the Game Menu
void startGame() {

	clock_t t = clock();

	cout << "Welcome to Battleship\n";
	cout << "\n";
	Sleep(2000);

	cout << "Rules:\n";
	Sleep(1500);

	cout << "You and the computer will each have 5 ships to place.\n";
	Sleep(2000);

	cout << "The play area is 5 x 5. You cannot place ships outside these bounds or fire shots beyond these bounds.\n";
	Sleep(3000);

	cout << "If you can find and shoot the computer's ships before it finds and destroys yours, you win.\n";
	Sleep(3000);

	cout << "If you cannot find and shoot the computer's ships before it finds and destroys yours, you lose.\n";
	Sleep(3000);

	cout << "To input coordinates, enter the x value on one line and the y value on the next.\n";
	Sleep(2000);

	system("pause");

}

//Inputs User and Computer Ships to the Battleship Class
void inputShips() {

	int x;
	int y;
	
	cout << "Please place your 5 battleships:\n";

	//Inputs User Ships
	for (int i = 0; i < 5; ++i) {

		cout << "Input the coordinates of ship " << i + 1 << endl;
		cin >> x;
		cin >> y;

		//will run if the inputed coordinates are not valid
		while (b.getComputerGrid(x, y) == 1 || x > 5 || y > 5 || x < 1 || y < 1) {

			cout << "Not a valid position, try placing it somewhere else.\n";

			cin >> x;
			cin >> y;

		}

		b.addUserShips(x, y);

	}

	//Generates Computer Ships

	srand(time(NULL));

	for (int i = 0; i < 5; ++i) {

		x = rand() % 5 + 1;
		y = rand() % 5 + 1;

		//will run if the randomly generated coordinates are invalid
		while (b.getComputerGrid(x, y) == 1) {
		
			x = rand() % 5 + 1;
			y = rand() % 5 + 1;
		
		}

		b.addComputerShips(x, y);

	}

}

//Outputs the Play Area
void setUpGrid() {

	cout << endl;

	//double for loop creates a 5 x 5 grid
	for (int x = 1; x <= 5; ++x) {
	
		for (int y = 1; y <= 5; ++y) {
		
			cout << " O ";
		
		}

		cout << endl;
	
	}

	cout << endl;

}

//Prints the grid after every round with hits as X and misses as M
void printGrid() {

	for (int y = 1; y <= 5; ++y) {
	
		for (int x = 1; x <= 5; ++x) {
		
			if (b.getComputerGrid(x, y) == 2) {
			
				cout << " X ";
			
			}
			else if (b.getComputerGrid(x, y) == 3) {
			
				cout << " M ";
			
			}
			else {
			
				cout << " O ";
			
			}
		
		}

		cout << endl;
	
	}

	cout << endl;

}

/*
Core Game Loop:
Asks the user for coordinates to fire at and tells if it was a hit or miss.
Computer randomly generates coordinates to fire at and will alert the user if ships were sunk.
*/
void playRound() {

	int x; //x input
	int y; //y input
	int h = 0; //the number of ships hit
	int s = 5; //the amount of user ships left

	//The loop will run until either the player or the computer wins
	while (h < 5 || s == 0) {

		/*
		---------------------------------------------------------------------------------

		Player's turn

		---------------------------------------------------------------------------------
		*/

		printGrid();

		cout << "\nEnter the coordinates to fire at:\n";

		cin >> x;
		cin >> y;

		//will run if the coordinates inputed are at a hit or miss input or outside the play area
		while (b.getComputerGrid(x, y) == 2 || b.getComputerGrid(x, y) == 3 || x > 5 || y > 5 || x < 1 || y < 1) {

			cout << "Not a valid location, try again\n";

			cout << "Enter coordinates to fire at:\n";
			cin >> x;
			cin >> y;

			cin.ignore();

		}

		if (b.getComputerGrid(x, y)) {

			b.addUserHits(x, y);
			h++;
			cout << "You sunk the computer's ship!";

			Sleep(1000);

			if (h == 5) {
			
				cout << "\nCongrats, you won!\n";
				break;
			
			}

		}
		else {

			b.addUserMisses(x, y);

			cout << "You missed the computer's ship...";

		}

		Sleep(2500);

		/*
		---------------------------------------------------------------------------------

		Computer's turn

		---------------------------------------------------------------------------------
		*/

		srand(time(NULL));

		x = rand() % 5 + 0;
		y = rand() % 5 + 0;

		//will run if the randomly generated coordinates are invalid
		while (b.getUserGrid(x, y) == 2 || b.getUserGrid(x, y) == 3) {

			x = rand() % 5 + 0;
			y = rand() % 5 + 0;

		}

		if (b.getUserGrid(x, y) == 1) {

			s--;
			b.addComputerHits(x, y);

			if (s == 0) {
			
				cout << "The computer won...\n";
				break;
			
			}
			else {
			
				cout << "The computer sunk one of your ships...\n";
			
			}

		}
		else {
		
			cout << "The computer missed!\n";
			b.addComputerMisses(x, y);
		
		}

		Sleep(1500);

	}

}

int main() {

	startGame(); //Puts the game name and rules on the screen. then asks for key input to start the game.

	setUpGrid(); //gives a visual of the empty play area

	inputShips(); //prompts the user to place their 5 ships, computer randomly generates positions for its ships

	playRound(); //core loop of the game

}