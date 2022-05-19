#pragma once
#include "Mine.h"
class GamePlay : public Mine
{
private:
	Mine Game; //Frontend Board
public:
	GamePlay();
	void reveal(int x, int y);
	void revealMore(int x, int y);
	void Play();
};