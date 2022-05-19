#include "GamePlay.h"
#include "PlayerInstructions.h"

bool checkWin(Minesweeper& Board, Minesweeper* RBoard) {
	int x = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (Board.getBoardState(i, j) == 'X' && RBoard->getBoardState(i, j) != 'M') //Game continues as long as x is non-zero
			{
				x++;
			}
		}
	}
	if (x == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

GamePlay::GamePlay() { }

void GamePlay::Play()
{
	int x, y;

	cout << endl;

	PlayerInstructions p;

	Minesweeper** m = new Minesweeper * [3];
	m[0] = &Game; //frontend board with all X displayed to User
	m[1] = MineBoard; //backend board with all explored locations
	m[2] = &p; //Instructions for player

	while (1) {
		m[0]->print(); 
		//m[1]->print(); 
		m[2]->print();
		cin >> x >> y;
		
		while ((x < 0 || x > 4) || (y < 0 || y > 4)) //Validating Input Coordinates
		{
			cout << "Enter coordinates between 0 and 4 : ";
			cin >> x >> y;
		}

		if (MineBoard->getBoardState(x, y) == 'M') {
			cout << "\nYou Lost, Mine found at " << "(" << x << "," << y << ")";
			break;
		}
		else {
			reveal(x, y);
			if (checkWin(Game, MineBoard)) {
				cout << "\nYou have beaten the game\n\n";
				break;
			}
		}
	}
}

void GamePlay::reveal(int x, int y) {

	Game.setBoardState(x, y, MineBoard->getBoardState(x, y));
	
	if (Game.getBoardState(x, y) == '0')
	{
		revealMore(x, y);
	}
}

void GamePlay::revealMore(int x, int y) {
	int minx, miny, maxx, maxy;

	// Don't try to check beyond the edges of the board
	minx = (x <= 0 ? 0 : x - 1);
	miny = (y <= 0 ? 0 : y - 1);
	maxx = (x >= 5 - 1 ? 5 : x + 2);
	maxy = (y >= 5 - 1 ? 5 : y + 2);
	char** a = Game.getBoard();
	char** b = MineBoard->getBoard();

	//Loop over all surrounding cells
	for (int i = minx; i < maxx; i++) {
		for (int j = miny; j < maxy; j++) {
			if (b[i][j] != 'M' && a[i][j] == 'X') {
				reveal(i, j);
				if (b[i][j] == 0) { // Move to newly found zero location
					//recursive calling
					revealMore(i, j);
				}
			}
		}
	}
}