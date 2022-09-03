#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include <string>

using namespace std;

class Battleship {

private:
	//The Gameboard for the Player
	int userGrid[5][5];

	//The Gameboard for the Computer
	int computerGrid[5][5];

public:
	//Ships
	void addUserShips(int x, int y); //ADDS A USER SHIP'S COORDINATES
	void addComputerShips(int x, int y); //ADDS A COMPUTER SHIP'S COORDNIATES

	//Hits
	void addUserHits(int x, int y); //ADDS A HITS COORDINATE TO COMPUTER GRID
	void addComputerHits(int x, int y); // ADDS A MISSES COORDINATE TO USER GRID

	//Misses
	void addUserMisses(int x, int y); //ADDS A MISSES COORDINATE TO COMPUTER GRID
	void addComputerMisses(int x, int y); // ADDS A MISSES COORDINATE TO USER GRID

	//Returns the Gameboards
	int getUserGrid(int x, int y); //RETURNS THE USER'S GRID
	int getComputerGrid(int x, int y); //RETURNS THE COMPUTER'S GRID
};
#endif