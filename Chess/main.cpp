#include<iostream>
#include<iomanip>
#include<vector>

#include "Board.h"
#include "Player1.h"
#include "Player2.h"
#include"SpecialRules.h"
#include"Game.h"

using namespace std;
int main()
{
	Game game;
	game.initialize();
	game.start();
	return 0;
}