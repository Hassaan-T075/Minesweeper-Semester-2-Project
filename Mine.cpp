#include "Mine.h"

int mineHere(char** Board, int x, int y) { //Checking a location for mine
	if (Board[x][y] == 'M')
		return 1;
	else return 0;
}

int CheckSurroundings(char** Board, int x, int y);

Mine::Mine() {

	Minesweeper* M = new Minesweeper;
	MineAdd(M);

	for (int i = 0; i < 5; i++) //Setting Up Mines
	{
		srand(time(0));
		MineX = rand() % 5;
		MineY = rand() % 5;
		if (MineBoard->getBoardState(MineX, MineY) == 'M' || (MineX == 0 && MineY == 0))
		{
			i--;
		}
		else
		{
			MineBoard->setBoardState(MineX, MineY, 'M');
		}
	}

	char CHA;
	int temp;
	for (int i = 0; i < 5; i++) //Filling Rest of Backend Board
	{
		for (int j = 0; j < 5; j++)
		{
			temp = CheckSurroundings(MineBoard->getBoard(), i, j);
			CHA = char(temp + 48);
			MineBoard->setBoardState(i, j, CHA);
		}
	}
}

void Mine::MineAdd(Minesweeper* M)
{
	MineBoard = M;
}

int CheckSurroundings(char** Board, int x, int y) {
	if (Board[x][y] == 'M')
		return 29;
	int totalMinesSurrounding = 0;
	/*
	1   2   3
	8   0   4   for currentstate
	7	6	5
	*/
	int currentState;

	if (x == 0 && y == 0)
		currentState = 1;
	else if (x > 0 && x < 4 && y == 0)
		currentState = 2;
	else if (x == 4 && y == 0)
		currentState = 3;
	else if (x == 4 && y > 0 && y < 4)
		currentState = 4;
	else if (x == 4 && y == 4)
		currentState = 5;
	else if (x > 0 && x < 4 && y == 4)
		currentState = 6;
	else if (x == 0 && y == 4)
		currentState = 7;
	else if (x == 0 && y > 0 && y < 4)
		currentState = 8;
	else currentState = 0;

	if (currentState == 1)
	{
		totalMinesSurrounding = totalMinesSurrounding + mineHere(Board, x + 1, y);
		totalMinesSurrounding = totalMinesSurrounding + mineHere(Board, x + 1, y + 1);
		totalMinesSurrounding = totalMinesSurrounding + mineHere(Board, x, y + 1);
		return totalMinesSurrounding;
	}
	if (currentState == 2)
	{
		totalMinesSurrounding = totalMinesSurrounding + mineHere(Board, x + 1, y);
		totalMinesSurrounding = totalMinesSurrounding + mineHere(Board, x + 1, y + 1);
		totalMinesSurrounding = totalMinesSurrounding + mineHere(Board, x, y + 1);
		totalMinesSurrounding = totalMinesSurrounding + mineHere(Board, x - 1, y + 1);
		totalMinesSurrounding = totalMinesSurrounding + mineHere(Board, x - 1, y);
		return totalMinesSurrounding;
	}
	if (currentState == 3)
	{
		totalMinesSurrounding = totalMinesSurrounding + mineHere(Board, x - 1, y);
		totalMinesSurrounding = totalMinesSurrounding + mineHere(Board, x - 1, y + 1);
		totalMinesSurrounding = totalMinesSurrounding + mineHere(Board, x, y + 1);
		return totalMinesSurrounding;
	}
	if (currentState == 4)
	{
		totalMinesSurrounding = totalMinesSurrounding + mineHere(Board, x, y - 1);
		totalMinesSurrounding = totalMinesSurrounding + mineHere(Board, x - 1, y - 1);
		totalMinesSurrounding = totalMinesSurrounding + mineHere(Board, x - 1, y);
		totalMinesSurrounding = totalMinesSurrounding + mineHere(Board, x - 1, y + 1);
		totalMinesSurrounding = totalMinesSurrounding + mineHere(Board, x, y + 1);
		return totalMinesSurrounding;
	}
	if (currentState == 5)
	{
		totalMinesSurrounding = totalMinesSurrounding + mineHere(Board, x, y - 1);
		totalMinesSurrounding = totalMinesSurrounding + mineHere(Board, x - 1, y - 1);
		totalMinesSurrounding = totalMinesSurrounding + mineHere(Board, x - 1, y);
		return totalMinesSurrounding;
	}
	if (currentState == 6)
	{
		totalMinesSurrounding = totalMinesSurrounding + mineHere(Board, x + 1, y);
		totalMinesSurrounding = totalMinesSurrounding + mineHere(Board, x + 1, y - 1);
		totalMinesSurrounding = totalMinesSurrounding + mineHere(Board, x, y - 1);
		totalMinesSurrounding = totalMinesSurrounding + mineHere(Board, x - 1, y - 1);
		totalMinesSurrounding = totalMinesSurrounding + mineHere(Board, x - 1, y);
		return totalMinesSurrounding;
	}
	if (currentState == 7) {
		totalMinesSurrounding = totalMinesSurrounding + mineHere(Board, x + 1, y);
		totalMinesSurrounding = totalMinesSurrounding + mineHere(Board, x + 1, y - 1);
		totalMinesSurrounding = totalMinesSurrounding + mineHere(Board, x, y - 1);
		return totalMinesSurrounding;
	}
	if (currentState == 8)
	{
		totalMinesSurrounding = totalMinesSurrounding + mineHere(Board, x, y + 1);
		totalMinesSurrounding = totalMinesSurrounding + mineHere(Board, x + 1, y + 1);
		totalMinesSurrounding = totalMinesSurrounding + mineHere(Board, x + 1, y);
		totalMinesSurrounding = totalMinesSurrounding + mineHere(Board, x + 1, y - 1);
		totalMinesSurrounding = totalMinesSurrounding + mineHere(Board, x, y - 1);
		return totalMinesSurrounding;
	}
	if (currentState == 0)
	{
		totalMinesSurrounding = totalMinesSurrounding + mineHere(Board, x, y + 1);
		totalMinesSurrounding = totalMinesSurrounding + mineHere(Board, x + 1, y + 1);
		totalMinesSurrounding = totalMinesSurrounding + mineHere(Board, x + 1, y);
		totalMinesSurrounding = totalMinesSurrounding + mineHere(Board, x + 1, y - 1);
		totalMinesSurrounding = totalMinesSurrounding + mineHere(Board, x, y - 1);
		totalMinesSurrounding = totalMinesSurrounding + mineHere(Board, x - 1, y - 1);
		totalMinesSurrounding = totalMinesSurrounding + mineHere(Board, x - 1, y);
		totalMinesSurrounding = totalMinesSurrounding + mineHere(Board, x - 1, y + 1);
		return totalMinesSurrounding;
	}
}