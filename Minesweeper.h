#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Minesweeper
{
private:
	char** Matrix;
public:
	Minesweeper();
	char getBoardState(int, int);
	char** getBoard();
	void setBoardState(int, int, char);
	virtual void print();
	~Minesweeper();
};