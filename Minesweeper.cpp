#include "Minesweeper.h"

Minesweeper::Minesweeper() {
	Matrix = new char* [5];
	for (int i = 0; i < 5; i++)
	{
		Matrix[i] = new char[5];
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			Matrix[i][j] = 'X';
		}
	}
}

char** Minesweeper::getBoard() {
	return Matrix;
}

char Minesweeper::getBoardState(int x, int y) {
	return Matrix[x][y];
}

void Minesweeper::setBoardState(int x, int y, char CH) {
	Matrix[x][y] = CH;
}

void Minesweeper::print() {
	cout << "The Board at this state is \n";
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << Matrix[i][j] << " ";
		}
		cout << endl;
	}
}

Minesweeper::~Minesweeper() {
	for (int i = 0; i < 5; i++)
	{
		delete[] Matrix[i];
	}
	delete[] Matrix;
	Matrix = NULL;
}
