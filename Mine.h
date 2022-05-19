#pragma once
#include "Minesweeper.h"
class Mine : public Minesweeper
{
private:
	int MineX;
	int MineY;
protected:
	Minesweeper* MineBoard; //Backend Board
public:
	Mine();
	void MineAdd(Minesweeper* M);
};