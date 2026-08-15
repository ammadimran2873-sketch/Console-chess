#pragma once
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>

#include "Board.h"
#include "Player1.h"
#include "Player2.h"
#include"SpecialRules.h"

using namespace std;
class Game
{
	Player1 player1;
	Player2 player2;
	Board board;

	char srcColumn, destColumn;
	int srcRow, destRow;
	char playerTurn;
	bool check;
	bool moveUnderCheck;
	bool checkmate;
	string player1Name;
	string player2Name;

private:
	void makeMove();
public:
	Game();
	void initialize();
	void initialText();
	void start();

};

