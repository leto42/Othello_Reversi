/*****************************************************************************/
/*                                                                           */
/* File: othello.cpp                                                         */
/* Project: Reversi/Othello                                                  */
/* Date: September 24, 2018                                                  */ 
/* Description: This is the driver file for a Human vs Computer game of	     */
/* Reversi/Othello. It will instantiate and use an object of the Game class. */
/*                                                                           */
/*****************************************************************************/

#include <iostream>
#include "Game.h"

using namespace std;

/*****************************************************************************/
/*                                                                           */
/* Function: main                                                            */ 
/* Input parameters: none                                                    */ 
/* Return value: int                                                         */ 
/* Description: This will play a game of Othello/Reversi. The game           */
/*              will be between a human and a computer.                      */
/*****************************************************************************/

int main ()
{
	Game game;
	// Display the instructions on how to play the game.
	game.Instructions (cout);
	game.Init();
	string playerNames [] = {"NONE", "HUMAN", "COMPUTER"};
	playerType player = HUMAN;
	// Display the current board and score.
	game.Display (cout);
	// While the game isn't finished...
	while (!game.Done())
	{
		int row, col;
		bool moveAvailable = false;
		if (player == HUMAN) // Human Player
		  moveAvailable = game.ChooseMove(player, row, col, cin, cout);
		else
		  moveAvailable = game.ChooseMove(player, row, col);
		if (moveAvailable)
		{
		  game.MakeMove(player, row, col);
		  game.Display(cout);
		}
		else
			cout << "No move available for " << playerNames[player] << " Player.\n";
		// If the current player doesn't have an available move, it becomes
		// the next player's turn.
		if (player == HUMAN)
		  player = COMPUTER;
		else
		  player = HUMAN;
	}
	cout << "GameOver! " << endl;
	// Announce the winner of the game.
	int winner = game.Winner(cout);

	return 0;
}
