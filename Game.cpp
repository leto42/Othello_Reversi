/*****************************************************************************/
/*                                                                           */
/* File: Game.cpp                                                            */
/* Project: Reversi/Othello                                                  */
/* Author: Tommy Le                                                          */
/* Date: Fall 2018                                                           */ 
/* Description: This program contains the implementations of the functions   */
/*              defined in Game.h for the Game class and Cell struct.        */
/*****************************************************************************/

#include "Game.h"
#include <iomanip>

/*****************************************************************************/
/*                                                                           */
/* Function: Cell                                                            */ 
/* Input parameters: none                                                    */ 
/* Return value: none                                                        */ 
/* Description: This function will set the owner of the cell to none.        */
/*                                                                           */
/*****************************************************************************/

Game::Cell::Cell ()
{
	owner = NONE;
}

/*****************************************************************************/
/*                                                                           */
/* Function: Display                                                         */ 
/* Input parameters: output stream                                           */ 
/* Return value: none (void)                                                 */ 
/* Description: This function holds the 3 different symbols/pieces           */
/*              that are in the game.                                        */
/*****************************************************************************/

void Game::Cell::Display (ostream & outs)
{

  char symbols [] {' ', 'X', 'O'};
  outs << symbols[owner];
}

/*****************************************************************************/
/*                                                                           */
/* Function: Constructor                                                     */ 
/* Input parameters: none                                                    */ 
/* Return value: none                                                        */ 
/* Description: This function will initialize scores to 0.                   */
/*                                                                           */
/*****************************************************************************/

Game::Game ()
{
	score[0] = 0;
	score[HUMAN] = 0;
	score[COMPUTER] = 0;
}

/*****************************************************************************/
/*                                                                           */
/* Function: Instructions                                                    */ 
/* Input parameters: output stream                                           */ 
/* Return value: none (void)                                                 */ 
/* Description: This function will print the instructions of the game.       */
/*              and how to read the board.                                   */
/*****************************************************************************/

void Game::Instructions (ostream & outs)
{
  outs << setw(40) << right << ":RULES:\n\n";
  outs << "1: The only valid move in the game is to outflank or sandwich your opponent's piece.\n" 
       << "This means that two of your own pieces must surround your opponent's pieces whether it\n" 
       << "be horizontally, vertically, or diagonally. "
       << "If outflanking an opponent is possible,\nthen the player must do it, even if it may be disadvantageous to do so.\n\n";
  outs << "2: Each player takes turns as long as they have a valid move. " 
       << "If there is no valid move,\nthe same player keeps placing pieces until the other player can make a move.\n\n";
  outs << "3: The game is over when there are no valid moves for either player\n"
       << "The player who has the most pieces at the end of the game is the winner.\n\n";
  outs << setw(50) << right <<  ":HOW TO READ THE BOARD:\n\n";
  outs << "The board is divided into eight columns and eight rows.\n"
       << "To place a piece in a space, call the row and column such as 1A or 1a.\n\n"
       << "You are the X symbol!\n\n"
       << "Good Luck!\n\n"; 
  
}

/*****************************************************************************/
/*                                                                           */
/* Function: Init                                                            */ 
/* Input parameters: none                                                    */ 
/* Return value: none (void)                                                 */ 
/* Description: This function initializes the size of the board as well as   */
/*              sets the 4 pieces in the starting position and gives         */
/*              ownership of 2 of the pieces to each player.                 */
/*****************************************************************************/

void Game::Init ()
{
	Cell cell;
	for (int r = 1; r <= ROWS; r++)
		for (int c = 1; c <= COLS; c++)
			board[r][c] = cell;
	//	board[ROWS/2][COLS/2].owner = HUMAN;
	board[ROWS/2][COLS/2].owner = COMPUTER;
	board[ROWS/2][COLS/2+1].owner = HUMAN;
	board[ROWS/2+1][COLS/2].owner = HUMAN;
	//	board[ROWS/2+1][COLS/2+1].owner = HUMAN;
	board[ROWS/2+1][COLS/2+1].owner = COMPUTER;
	score[HUMAN] = 2;
	score[COMPUTER] = 2;

}

/*****************************************************************************/
/*                                                                           */
/* Function: Display                                                         */ 
/* Input parameters: output stream, playerType                               */ 
/* Return value: none (void)                                                 */ 
/* Description: This function displays the current state of the board        */
/*              as well as the current score of the two players.             */
/*****************************************************************************/

void Game::Display (ostream & outs)
{
  outs << "\nScores\tHUMAN: " << score[HUMAN] << ";\tCOMPUTER: " << score[COMPUTER] << endl;
	// Prints letters above the columns using ASCII values
	// to determine how many letters are needed.
	for(int i = 0; i < ROWS; i++)
	  {
	    if (i == 0)
	      {
		outs << setw(7) << right <<  char(i+'A');
	      }
	    else
	      {
		outs << setw(4) << right << char(i+'A');
	      }
	  }
	outs << endl;

	// Creates the first 8 lines of the board.
	for (int r = 1; r <= ROWS; r++)
	{
	  for (int i = 1; i <= ROWS; i++)
	    {
	      if (i == 1)
		{
		  outs << "    +---+";
		}
	      else
		{
		  outs << "---+";
		}
	    }
	  // Print numbers to the left of the rows as well
	  // as the bars between each cell.
	  outs << endl << setw(3) << right  << r << ' ';
	  for (int c = 1; c <= COLS; c++)
	    {
	      outs << "| ";
	      board[r][c].Display(outs);
	      outs << " ";
	      if (c == COLS)
		{
		  outs << '|';
		}
	    }
	  // Print numbers to the right of the rows.
	  outs << ' ' << r << endl;
	}
	
	// Prints the last row of the board outline.
	for (int i = 1; i <= ROWS; i++)
	  {
	    if (i == 1)
	      {
		outs << "    +---+";
	      }
	    else
	      {
		outs << "---+";
	      }
	  }
	outs << endl;
	
	// Prints letters below the columns.
	for(int i = 0; i < ROWS; i++)
	  {
	    if (i == 0)
	      {
		outs << setw(7) << right <<  char(i+'A');
	      }
	    else
	      {
		outs << setw(4) << right << char(i+'A');
	      }
	  }
	outs << endl;
}

/*****************************************************************************/
/*                                                                           */
/* Function: CheckBoard                                                      */ 
/* Input parameters: object                                                  */ 
/* Return value: bool                                                        */ 
/* Description: This function checks to see if the current player            */
/*              has any valid moves left on the board.                       */
/*****************************************************************************/

bool Game::CheckBoard (playerType Who)
{
  int num_valid = 0;

  // Go through each cell on the board to see if any
  // of the positions result in a valid move.
  for (int r = 1; r <= ROWS; r++)
    {
      for (int c = 1; c <= COLS; c++)
	{
	  // If a valid move is found, the number of valid
	  // moves will be incremented.
	  if (ValidMove(Who, r, c) == true)
	    {
	      num_valid++;
	    }
	}
    }
  // If the number of valid moves is greater than 0,
  // that means that the player has a cell that they can
  // place their piece into.
  if (num_valid > 0)
    {
      return true;
    }

  // If the number of valid moves isn't greater than 0,
  // that means that the player does not have a cell that they can
  // place their piece into.
  return false;
}


/*****************************************************************************/
/*                                                                           */
/* Function: ValidMove                                                       */ 
/* Input parameters: object, int, int                                        */ 
/* Return value: bool                                                        */ 
/* Description: This function will check whether or not a player's move      */
/*              is valid (i.e follows the game's rules).                     */
/*****************************************************************************/

bool Game::ValidMove (playerType Who, int Row, int Col)
{
  playerType other;
  // Checking to see if the current player is the
  // HUMAN or COMPUTER. After finding out the current
  // player.
  if(Who == HUMAN)
    {
      other = COMPUTER;
    }
  else
    {
      other = HUMAN;
    }

  // If the cell position is already owned, then it will not result in a valid move.
  // If the cell position is out of the board, it is not a valid move.
  if(board[Row][Col].owner != NONE || (Row < 1) || (Row > ROWS) || (Col < 1) || (Col > COLS))
    {
      return false;
    }

    // Checking up direction.
  int totalcount = 0, count = 0, r = Row-1, c = Col;
    while(board[r][c].owner == other)
      {
	count++;
	r--;
      }
    
    if(count > 0 && board[r][c].owner == Who)
      {
	totalcount += count;
      }

   
    // Checking down direction.
    count = 0, r = Row+1, c = Col;
    while(board[r][c].owner == other)
      {
	count++;
	r++;
      }
    if(count > 0 && board[r][c].owner == Who)
      {
	totalcount += count;
      }
    
    // Checking horizontal left direction.
    count = 0, r = Row, c = Col-1;
    while(board[r][c].owner == other)
      {
	count++;
	c--;
      }
    
    if(count > 0 && board[r][c].owner == Who)
      {
	totalcount += count;
      }

    
    // Checking horizontal right direction.
    count = 0, r = Row, c = Col+1;
    while(board[r][c].owner == other)
      {
	count++;
        c++;
      }
    
    if(count > 0 && board[r][c].owner == Who)
      {
	totalcount += count;
      }

    // Checking left to right upwards diagonal direction.
    count = 0, r = Row-1, c = Col+1;
    while(board[r][c].owner == other)
      {
	count++;
	r--;
	c++;
      }
    
    if(count > 0 && board[r][c].owner == Who)
      {
	totalcount += count;
      }


    // Checking right to left upwards diagonal direction.
    count = 0, r = Row-1, c = Col-1;
    while(board[r][c].owner == other)
      {
	count++;
	r--;
	c--;
      }
    
    if (count > 0 && board[r][c].owner == Who)
      {
	totalcount += count;
      }

    // Checking left to right downwards diagonal  direction.
    count = 0, r = Row+1, c = Col+1;
    while(board[r][c].owner == other)
      {
	count++;
	r++;
	c++;
      }
    
    if(count > 0 && board[r][c].owner == Who)
      {
	totalcount += count;
      }

    // Checking right to left downwards diagonal direction.
    count = 0, r = Row+1, c = Col-1;
    while(board[r][c].owner == other)
      {
	count++;
	r++;
	c--;
      }
    
    if(count > 0 && board[r][c].owner == Who)
      {
	totalcount += count;
      }

    // If the totalcount is greater than 0, that means
    // that there is a valid move in at least one of
    // the 8 directions of the cell that was chosen.
    if (totalcount > 0)
      {
	return true;
      }
    return false;
}


/*****************************************************************************/
/*                                                                           */
/* Function: CompBestMove                                                    */ 
/* Input parameters: playerType object                                       */ 
/* Return value: vector containing ints                                      */ 
/* Description: This function checks the board for each valid move,          */
/*              looks for the move with the highest priority, and then       */
/*              returns the coordinates of that move.                        */
/*****************************************************************************/

vector<int> Game::CompBestMove(playerType Who)
{
  int temp, priority = 0, chosen_priority;
  // This vector will hold row positions of all of the available moves.  
  vector<int> row_list;
  // This vector will hold column positions of all of the available moves.
  vector<int> col_list;
  // This vector will hold row positions of moves that have the highest priority.
  vector<int> best_move_row;
  // This vector will hold column positions of moves that have the highest priority.
  vector<int> best_move_col;
  // This vector will hold the final row and column that are randomly chosen
  // from the lists that contain the highest priority row and column positions.
  vector<int> final_move;
  
  // Checking entire board for valid moves.
  for (int r = 1; r <= ROWS; r++)
    {
      for (int c = 1; c <= COLS; c++)
	{
	  // If a valid move is found, the row position will be pushed back
	  // into one vector, and the column position in another.
	  if (ValidMove(Who, r, c))
	    {
	      row_list.push_back(r);
	      col_list.push_back(c);
	    }
	}
    }

  // If there are no valid moves in the first place,
  // return the empty vector.
  if(row_list.size() == 0)
    {
      return row_list;
    }

  // Going through the rows and columns list to
  // find the greatest priority value.
  for(int i = 0; i < row_list.size(); i++)
    {
      temp = CheckPriority(row_list[i], col_list[i]);

      // If a new highest priority was found, the previous
      // will be replaced.
      if (temp > priority)
	{
	  priority = temp;
	}
    }
   
  // Going through the rows and columns list to check
  // if they match the greatest priority value.
  for(int i = 0; i < row_list.size(); i++)
    {
      temp = CheckPriority(row_list[i], col_list[i]);

      // The row and column of the moves with the highest priorities
      // will be stored into the next 2 vectors.
      if (temp == priority)
	{
	  best_move_row.push_back(row_list[i]);
	  best_move_col.push_back(col_list[i]);
	}
    }

      // Choose a random number between 0 and the number of elements in
      // the vector-1.
  srand(time(NULL));
  chosen_priority = rand() % best_move_row.size();

  // After a random position is chosen, the row and column
  // containing that position will be push backed into
  // the final vector.
  final_move.push_back(best_move_row[chosen_priority]);
  final_move.push_back(best_move_col[chosen_priority]);

  // Return the vector containing the move the COMPUTER will make.
  return final_move;
}


/*****************************************************************************/
/*                                                                           */
/* Function: CheckPriority                                                   */ 
/* Input parameters: int, int                                                */ 
/* Return value: int                                                         */ 
/* Description: This function checks for the priority of the move.           */
/*              The priorities are based on different locations on           */
/*              the board.                                                   */
/*****************************************************************************/

int Game::CheckPriority(int Row, int Col)
{
  // Corners are highest priority.
  if ((Row == 1 && Col == 1) || (Row == 1 && Col == COLS) || (Row == ROWS && Col == 1) || (Row == ROWS && Col == COLS))
    {
      return 4;
    }
  // Edges are 2nd highest priority.
  else if(Col == 1 || Col == COLS || Row == 1 || Row == ROWS)
    {
      return 3;
    }
  // Places that are in between rows 3 to 6 and columns
  // C-F are 3rd highest priority.
  else if ((Row > 2) && (Row < ROWS-1) && (Col > 2) && (Col < COLS-1))
    {
      return 2;
    }
  // Rows and columns next to the edges are the lowest priority.
  else
    {
      return 1;
    }
  
   
}

/*****************************************************************************/
/*                                                                           */
/* Function: MakeMove                                                        */ 
/* Input parameters: object, int, int                                        */ 
/* Return value: none (void)                                                 */ 
/* Description: This function will give ownership of the chosen cell         */
/*              to the current player and flip all of the opponent's         */
/*              pieces that were outflanked/sandwiched.                      */
/*****************************************************************************/

void Game::MakeMove (playerType Who, int Row, int Col)
{
  // Check to see who is the current player.
  // Set other to the second player.
  playerType other;
  if(Who == HUMAN)
    {
      other = COMPUTER;
    }
  else
    {
      other = HUMAN;
    }
  if(ValidMove(Who, Row, Col) == true)
    {
      // Give ownership of the cell that was called by the player.
      board[Row][Col].owner = Who;
      // Checking up direction.
  int count = 0, r = Row-1, c = Col;
    while(board[r][c].owner == other)
      {
	count++;
	r--;
      }

    
    if(count > 0 && board[r][c].owner == Who)
      {
	while(count != 0)
	  {
	    // At this point, the program is in the cell that was
	    // found to be part of the outflank of the opponent's piece.
	    // Reverse the direction that was being looked at and 
	    // start replacing ownership of the pieces that are outflanked.
	    r++;
	    // Change the ownership of the cell.
	    board[r][c].owner = Who;	    
	    count--;
	  }
      }

   
    // Checking down direction.
    count = 0, r = Row+1, c = Col;
    while(board[r][c].owner == other)
      {
	count++;
	r++;
      }
    if(count > 0 && board[r][c].owner == Who)
      {
	while(count != 0)
	  {
	    // Reverse direction.
	    r--;
	    // Change the ownership of the cell.
	    board[r][c].owner = Who;
	    count--;
	  }
      }
    
    // Checking horizontal left direction.
    count = 0, r = Row, c = Col-1;
    while(board[r][c].owner == other)
      {
	count++;
	c--;
      }
    
    if(count > 0 && board[r][c].owner == Who)
      {
	while (count != 0)
	  {
	    // Reverse direction.
	    c++;
	    // Change the ownership of the cell.
	    board[r][c].owner = Who;
	    count--;
	  }
      }

    
    // Checking horizontal right direction.
    count = 0, r = Row, c = Col+1;
    while(board[r][c].owner == other)
      {
	count++;
        c++;
      }
    
    if(count > 0 && board[r][c].owner == Who)
      {
	while (count != 0)
	  {
	    // Reverse direction.
	    c--;
	    // Change the ownership of the cell.
	    board[r][c].owner = Who;
	    count--;
	  }
      }

    // Checking left to right upwards diagonal direction.
    count = 0, r = Row-1, c = Col+1;
    while(board[r][c].owner == other)
      {
	count++;
	r--;
	c++;
      }
    
    if(count > 0 && board[r][c].owner == Who)
      {
	while(count != 0)
	  {
	    // Reverse direction.
	    r++;
	    c--;
	    // Change ownership of the cell.
	    board[r][c].owner = Who;
	    count--;
	  }
      }


    // Checking right to left upwards diagonal direction.
    count = 0, r = Row-1, c = Col-1;
    while(board[r][c].owner == other)
      {
	count++;
	r--;
	c--;
      }
    
    if (count > 0 && board[r][c].owner == Who)
      {
	while(count != 0)
	  {
	    // Reverse direction.
	    r++;
	    c++;
	    // Change ownership of the cell.
	    board[r][c].owner = Who;
	    count--;
	  }
      }

    // Checking left to right downwards diagonal  direction.
    count = 0, r = Row+1, c = Col+1;
    while(board[r][c].owner == other)
      {
	count++;
	r++;
	c++;
      }
    
    if(count > 0 && board[r][c].owner == Who)
      {
	while(count != 0)
	  {
	    // Reverse direction/
	    r--;
	    c--;
	    // Change ownership of the cell.
	    board[r][c].owner = Who;
	    count--;
	  }
      }

    // Checking right to left downwards diagonal direction.
    count = 0, r = Row+1, c = Col-1;
    while(board[r][c].owner == other)
      {
	count++;
	r++;
	c--;
      }
    
    if(count > 0 && board[r][c].owner == Who)
      {
	while (count != 0)
	  {
	    // Reverse direction.
	    r--;
	    c++;
	    // Change ownership of the cell.
	    board[r][c].owner = Who;
	    count--;
	  }
      }
    }
  // Update the current state of the board.
  UpdateScore();
}

/*****************************************************************************/
/*                                                                           */
/* Function: ChooseMove                                                      */ 
/* Input parameters: object, int, int, input stream, and output stream       */
/* Return value: bool                                                        */ 
/* Description:  Prompt user for location of move.                            */
/*                                                                           */
/*****************************************************************************/

bool Game::ChooseMove (playerType Who, int & Row, int & Col, istream & In, ostream & Out)
{
  // If the player has a valid move, then ask where the player
  // wants to place their piece.
  if(CheckBoard(Who) == true)
    {
      int r;
      char c;
      Out << "Enter row and col for your move: ";
      
      In >> r >> c;
      // If char c isn't part of the alphabet or if int r 
      // isn't a digit, the move is invalid.
      while (!(isalpha(c) >  0) && !isdigit(r))
	{
	  // Clear the fail flag.
	  cin.clear();
	  // Ignore up to 100 characters that were on the same line and
	  // skips to the next newline.
	  cin.ignore(100, '\n');
	  Out << "Not a valid move" << endl;
	  In >> r >> c;
	}
      
      // Convert r and c to Rows and Columns.
      Row = r;
      Col = toupper(c) - 'A'+1;
      
      while( !ValidMove(Who, Row, Col))
	{
	  Out << "Not a valid move" << endl;
	  In >> r >> c;
	  Row = r;
	  Col = toupper(c) - 'A'+1;
	}
      return true;
    }
  else
    {
      return false;
    }
}

/*****************************************************************************/
/*                                                                           */
/* Function: ChooseMove                                                      */ 
/* Input parameters: object, int, int                                        */ 
/* Return value: bool                                                        */ 
/* Description: AI determines desired location of move and places its        */
/*              piece in that location.                                      */
/*****************************************************************************/

bool Game::ChooseMove (playerType Who, int & Row, int & Col)
{
  int OldScore = score[Who];

  // Get vector that contains the move that the COMPUTER
  // will make.
  vector<int> chosen_move = CompBestMove(Who);
  // If the size of the vector is empty, that means that
  // COMPUTER doesn't have any valid moves.
  if(chosen_move.size() == 0)
    {
      return false;
    }
  // Set Row and Col to their corresponding position in the vector.
  Row = chosen_move[0];
  Col = chosen_move[1];
  
  // Make the move if the COMPUTER has a valid move.
  MakeMove(Who, Row, Col);
  
  // Print the row and column COMPUTER placed its piece
  // as well the number of enemy pieces it took over.
  if (Who == HUMAN)
    {
      cout << "Player 1 choosing " << chosen_move[0] << ','
	   << char(chosen_move[1]+'A'-1) << ' ' << "Total =  "
	   << TotalofTurn(Who, OldScore) << endl;
    }
  else
    {      
      cout << "Player 2 choosing " << chosen_move[0] << ','
	   << char(chosen_move[1]+'A'-1) << ' ' << "Total =  "
	   << TotalofTurn(Who, OldScore) << endl;
    }
  return true;
}

/*****************************************************************************/
/*                                                                           */
/* Function: Done                                                            */ 
/* Input parameters: none                                                    */ 
/* Return value: bool                                                        */ 
/* Description: This function will tell whether or not the game is           */
/*              finished.                                                    */
/*****************************************************************************/

bool Game::Done ()
{
  // If no players have a valid move, then the game is done.
  if(!CheckBoard(HUMAN) && !CheckBoard(COMPUTER))
    {
      return true;
    }
  return false;
  
}

/*****************************************************************************/
/*                                                                           */
/* Function: Winner                                                          */ 
/* Input parameters: output stream                                           */ 
/* Return value: playerType object                                           */ 
/* Description: This function will determine the winner of the game.         */
/*                                                                           */
/*****************************************************************************/

playerType Game::Winner (ostream & outs)
{
	playerType winner = NONE;

	// If HUMAN's score is greater than COMPUTER's score,
	// HUMAN is the winner.
	if(score[HUMAN] > score[COMPUTER])
	  {
	    winner = HUMAN;
	    outs << "The winner is HUMAN!" << endl;
	  }
	// If HUMAN's score is less than COMPUTER's score,
	// COMPUTER is the winner.
	else if(score[HUMAN] < score[COMPUTER])
	  {
	    winner = COMPUTER;
	    outs << "The winner is COMPUTER!" << endl;
	  }
	// Otherwise, the game was a tie.
	else
	  {
	    winner = NONE;
	    outs << "The game ended in a tie!" << endl;
	  }

	// Print the final score of the game.
	PrintFinalScore(cout);
	return winner;
}

/*******************************************************************************/
/*                                                                             */
/* Function: PrintFinalScore                                                   */
/* Input parameters: output stream                                             */
/* Return value: none (void)                                                   */
/* Description : This function will print the final score of the game.         */
/*                                                                             */
/*******************************************************************************/

void Game::PrintFinalScore(ostream & outs)
{
  outs << "The final score is: HUMAN: " << score[HUMAN] << ";\tCOMPUTER: "
       << score[COMPUTER] << endl;
}


/*******************************************************************************/
/*                                                                             */
/* Function: UpdateScore                                                       */
/* Input parameters: none                                                      */
/* Return value: none (void)                                                   */
/* Description : This function will update the scores of the game.             */
/*                                                                             */
/*******************************************************************************/

void Game::UpdateScore()
{
  // Go through each cell of the board and increment
  // the player's respective counter to see the total
  // number of pieces they own.
  int human_score = 0, computer_score = 0;
  for(int r = 1; r <= ROWS; r++)
    {
      for (int c = 1; c <= COLS; c++)
	{
	  if (board[r][c].owner == HUMAN)
	    {
	      human_score++;
	    }
	  else if (board[r][c].owner == COMPUTER)
	    {
	      computer_score++;
	    }
	}
    }
  // The the scores to the amount of pieces that
  // the players own.
  score[HUMAN] = human_score;
  score[COMPUTER] = computer_score;
}


/*******************************************************************************/
/*                                                                             */
/* Function: TotalofTurn                                                       */
/* Input parameters: playerType object                                         */
/* Return value: int                                                           */
/* Description : This function return the total amount of symbols that         */
/*               COMPUTER obtained during it's move.                           */
/*******************************************************************************/

int Game::TotalofTurn(playerType Who, int Old)
{
  // Goes through the board to find the player's (current score -1),
  // and substracts the old score to it to get the
  // number of enemy pieces that was flipped over.
  int total_score = 0;
  for(int r = 1; r <= ROWS; r++)
    {
      for (int c = 1; c <= COLS; c++)
	{
	  if (board[r][c].owner == Who)
	    {
	      total_score++;
	    }
	}
    }
  // The -1 is there because the cell that the piece
  // was placed in doesn't count as flipping an enemy piece.
  return ((total_score - 1) - Old);

}  
