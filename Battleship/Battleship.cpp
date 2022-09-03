#include "Battleship.h"
#include <string>
#include <iostream>

using namespace std;

void Battleship::addUserShips(int x, int y) {

	userGrid[x][y] = 1;

}

void Battleship::addComputerShips(int x, int y) {

	computerGrid[x][y] = 1;

}

void Battleship::addUserMisses(int x, int y) {

	computerGrid[x][y] = 3;

}

void Battleship::addUserHits(int x, int y) {

	computerGrid[x][y] = 2;

}

void Battleship::addComputerHits(int x, int y) {

	userGrid[x][y] = 2;

}

void Battleship::addComputerMisses(int x, int y) {

	userGrid[x][y] = 3;

}

int Battleship::getUserGrid(int x, int y) {

	return userGrid[x][y];

}

int Battleship::getComputerGrid(int x, int y) {

	return computerGrid[x][y];

}