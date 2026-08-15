#include "Game.h"
#include"Color.h"

#include<ctime>

Game::Game()
{
	srcColumn = 0;
	destColumn = 0;
	srcRow = 0; 
	destRow = 0;
	playerTurn = 0;
	check = 0;
	moveUnderCheck = 0;
	checkmate = 0;
}

void Game::initialText()
{
	cout << "==================================================\n";
	cout << "              CHESS GAME - 2 PLAYER               \n";
	cout << "==================================================\n\n";

	cout << "Welcome to Console Chess!\n\n";

	cout << "HOW TO PLAY\n";
	cout << "--------------------------------------------------\n";
	cout << "- Player 1 plays as Dark Grey.\n";
	cout << "- Player 2 plays as White.\n";
	cout << "- Players take turns making legal moves.\n";
	cout << "- The game follows standard chess rules.\n\n";

	cout << "MOVE INPUT\n";
	cout << "--------------------------------------------------\n";
	cout << "Enter the starting and destination squares.\n";
	cout << "Example: e2 e4\n\n";
	cout << "e2 = Starting square\n";
	cout << "e4 = Destination square\n\n";

	cout << "Other examples:\n";
	cout << "g1 f3\n";
	cout << "e7 e5\n";
	cout << "e1 g1\n\n";

	cout << "IMPORTANT\n";
	cout << "--------------------------------------------------\n";
	cout << "- Use coordinates from a1 to h8.\n";
	cout << "- Enter the starting square first.\n";
	cout << "- Enter the destination square second.\n";
	cout << "- Only legal moves will be accepted.\n\n";

	cout << "SPECIAL RULES\n";
	cout << "--------------------------------------------------\n";
	cout << "- Castling is supported.\n";
	cout << "- En passant is supported.\n";
	cout << "- Pawn promotion is supported.\n";
	cout << "- Check and Checkmate are detected.\n\n";

	cout << "==================================================\n";
	Color::setColor(3);
	cout << '\n' << "Press Enter to start the game...";
	Color::setColor(7);
	char start;
	cin.get(start);
	cout << '\n';
}


void Game::initialize()
{
	initialText();

	cout << "Enter the name of player 1 (Lower Pieces): ";
	Color::setColor(11);
	getline(cin, player1Name, '\n');
	Color::setColor(7);
	cout << "Enter the name of player 2 (Upper Pieces): ";
	Color::setColor(11);
	getline(cin, player2Name, '\n');
	Color::setColor(7);
	cout << '\n';

	player1.initialize();
	player2.initialize();


	srand(time(0));
	int choice = rand() % 2 + 1;
	if (choice == 1)
		playerTurn = '1';
	else
		playerTurn = '2';
}

void Game::start()
{
	// chess board
	cout << setw(40) << setfill('-') << '-' << '\n';
	board.draw(player1.piece, player2.piece);
	cout << setw(40) << setfill('-') << '-' << '\n';

	while (!checkmate)
	{
		makeMove();

		cout << setw(40) << setfill('-') << '-' << '\n';
		board.draw(player1.piece, player2.piece);
		cout << setw(40) << setfill('-') << '-' << '\n';
	}
	cout << '\n' << "Checkmate!" << '\n';
	if (playerTurn == '1')
	{
		Color::setColor(2);
		cout << player2Name << " Wins" << '\n';
		Color::setColor(7);
	}
	else
	{
		Color::setColor(2);
		cout << player1Name << " Wins" << '\n';
		Color::setColor(7);
	}
}

void Game::makeMove()
{
	if (playerTurn == '1')
	{
		Color::setColor(11);
		cout << '\n' << ".........." << player1Name << "'s Turn.........." << '\n';
		Color::setColor(7);

		if (!check)
			check = SpecialRules::isCheck(player1.piece, player2.piece);
		if (check)
		{
			checkmate = SpecialRules::isCheckmate(player1.piece, player2.piece);
			if (!checkmate)
			{
				if (moveUnderCheck)
				{
					Color::setColor(4);
					cout << '\n' << "Can't Move!";
					cout << '\n' << "Your King will be in Check!" << '\n';
					Color::setColor(7);
				}
				else
				{
					Color::setColor(4);
					cout << '\n' << "Your King is in Check!" << '\n';
					Color::setColor(7);
				}
				moveUnderCheck = 1;
			}

		}
		else
		{
			moveUnderCheck = 0;
			playerTurn = '2';
		}
		if (!checkmate)
		{
			cout << '\n' << "Enter the source piece location: ";
			cin >> srcColumn >> srcRow;
			int i = player1.findPiece(srcColumn, srcRow);
			while (i == -1)
			{
				cout << '\n' << "Enter the source piece location: ";
				cin >> srcColumn >> srcRow;
				i = player1.findPiece(srcColumn, srcRow);
			}
			cout << "Enter the destination piece location: ";
			cin >> destColumn >> destRow;


			while (!(player1.isValideMove(destColumn, destRow, i, player2.piece)))
			{
				cout << '\n' << "Enter the source piece location: ";
				cin >> srcColumn >> srcRow;
				i = player1.findPiece(srcColumn, srcRow);
				while (i == -1)
				{
					cout << '\n' << "Enter the source piece location: ";
					cin >> srcColumn >> srcRow;
					i = player1.findPiece(srcColumn, srcRow);
				}

				cout << "Enter the destination piece location: ";
				cin >> destColumn >> destRow;
			}
			player1.update(destColumn, destRow, i, player2.piece, playerTurn, moveUnderCheck, check);
		}

	}
	else
	{
		Color::setColor(11);
		cout << '\n' << ".........." << player2Name << "'s Turn.........." << '\n';
		Color::setColor(7);
		if (!check)
			check = SpecialRules::isCheck(player2.piece, player1.piece);
		if (check)
		{
			checkmate = SpecialRules::isCheckmate(player2.piece, player1.piece);
			if (!checkmate)
			{
				if (moveUnderCheck)
				{
					Color::setColor(4);
					cout << '\n' << "Can't Move!";
					cout << '\n' << "Your King will be in Check!" << '\n';
					Color::setColor(7);

				}
				else
				{
					Color::setColor(4);
					cout << '\n' << "Your King is in Check!" << '\n';
					Color::setColor(7);
				}
				moveUnderCheck = 1;
			}

		}
		else
		{
			moveUnderCheck = 0;
			playerTurn = '1';
		}
		if (!checkmate)
		{
			cout << '\n' << "Enter the souce piece location: ";
			cin >> srcColumn >> srcRow;
			int i = player2.findPiece(srcColumn, srcRow);
			while (i == -1)
			{
				cout << '\n' << "Enter the source piece location: ";
				cin >> srcColumn >> srcRow;
				i = player2.findPiece(srcColumn, srcRow);
			}
			cout << "Enter the destination piece location: ";
			cin >> destColumn >> destRow;


			while (!(player2.isValideMove(destColumn, destRow, i, player1.piece)))
			{
				cout << '\n' << "Enter the source piece location: ";
				cin >> srcColumn >> srcRow;
				i = player2.findPiece(srcColumn, srcRow);
				while (i == -1)
				{
					cout << '\n' << "Enter the source piece location: ";
					cin >> srcColumn >> srcRow;
					i = player2.findPiece(srcColumn, srcRow);
				}
				cout << "Enter the destination piece location: ";
				cin >> destColumn >> destRow;
			}
			player2.update(destColumn, destRow, i, player1.piece, playerTurn, moveUnderCheck, check);
		}

	}
}
