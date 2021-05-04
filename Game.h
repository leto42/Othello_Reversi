/*****************************************************************************/
/*                                                                           */
/* File: Game.h                                                              */
/* Project: Reversi/Othello                                                  */
/* Author: Tommy Le                                                          */
/* Date: Fall 2018                                                           */ 
/* Description: This header contains the description of the Game class.      */
/*                                                                           */
/*****************************************************************************/
 
#pragma once
#include <iostream>
// Include for srand and rand.
#include <stdlib.h>
// Include to use a random seed for the time.
#include <time.h>
// Positions of rows and columns will be stored in multiple vectors
#include <vector>

using namespace std;

/*****************************************************************************/
/*                                                                           */
/* Constants: ROWS and COLS                                                  */ 
/* Description: These variables will store the number of rows and            */
/* columns that the gameboard contains.                                      */
/*****************************************************************************/

const int ROWS = 8;
const int COLS = 8;

/*****************************************************************************/
/*                                                                           */
/* Type: playerType                                                          */ 
/* Description: This enumerated type defines the different players in the    */
/* game. NONE is used to identify a cell that has not been claimed and a     */
/* tied game.                                                                */
/*                                                                           */
/*****************************************************************************/

#ifndef PLAYER_TYPE
#define PLAYER_TYPE
enum playerType {NONE, HUMAN, COMPUTER};
#endif

/*****************************************************************************/
/*                                                                           */
/* Class: Game                                                               */ 
/* Description: Holds the functions that will check if a move that was       */
/*              chosen is valid, check the entire board to see if the game   */
/*              is done, display the instructions, initialize the positions  */
/*              of the board and owners of the pieces, update the score,     */
/*              print the final score. It will hold the functions that       */
/*              allows the COMPUTER to determine what move it will make.     */
/*              It tell who won the game based on how many pieces each       */
/*              player has compared with one another.                        */
/*                                                                           */
/*****************************************************************************/

class Game
{
	private:
		struct Cell
		{
		  Cell ();
		  void Display (ostream & outs);
		  playerType owner;
		};
		Cell board [ROWS+2][COLS+2];
		int score[3];
		bool ValidMove (playerType Who, int Row, int Col);
		bool CheckBoard (playerType Who);
	public:
		Game ();
		void Instructions (ostream & outs);
		void Init ();
  void Display (ostream & outs);
		void UpdateScore();
		void PrintFinalScore(ostream & outs);
		int TotalofTurn(playerType Who, int Old);
		vector<int> CompBestMove(playerType Who);
		int CheckPriority(int  Row, int Col);
		void MakeMove (playerType Who, int  Row, int Col);
		bool ChooseMove (playerType Who, int & Row, int & Col, istream & In, ostream & Out);
		bool ChooseMove (playerType Who, int & Row, int & Col);
		bool Done ();
		playerType Winner (ostream & outs);
};
