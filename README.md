Script started on 2018-11-13 10:56:09-0800
]0;tle@blue:~/cs215f18/Project2[tle@blue Project2]$ ./P2.out
                               :RULES:

1: The only valid move in the game is to outflank or sandwich your opponent's piece.
This means that two of your own pieces must surround your opponent's pieces whether it
be horizontally, vertically, or diagonally. If outflanking an opponent is possible,
then the player must do it, even if it may be disadvantageous to do so.

2: Each player takes turns as long as they have a valid move. If there is no valid move,
the same player keeps placing pieces until the other player can make a move.

3: The game is over when there are no valid moves for either player
The player who has the most pieces at the end of the game is the winner.

                         :HOW TO READ THE BOARD:

The game can be played on a board of any size. This example shows a game with
a 4x4 size board.

To place a piece in a space, write the row number and column letter such as 1A or 1a.

The human player is the X symbol.

Here is a sample of a game being played between a human and a computer.


Scores	HUMAN: 2;	COMPUTER: 2
      A   B   C   D
    +---+---+---+---+
  1 |   |   |   |   | 1
    +---+---+---+---+
  2 |   | O | X |   | 2
    +---+---+---+---+
  3 |   | X | O |   | 3
    +---+---+---+---+
  4 |   |   |   |   | 4
    +---+---+---+---+
      A   B   C   D
Enter row and col for your move: 1b

Scores	HUMAN: 4;	COMPUTER: 1
      A   B   C   D
    +---+---+---+---+
  1 |   | X |   |   | 1
    +---+---+---+---+
  2 |   | X | X |   | 2
    +---+---+---+---+
  3 |   | X | O |   | 3
    +---+---+---+---+
  4 |   |   |   |   | 4
    +---+---+---+---+
      A   B   C   D
Player 2 choosing 1,A Total =  1

Scores	HUMAN: 3;	COMPUTER: 3
      A   B   C   D
    +---+---+---+---+
  1 | O | X |   |   | 1
    +---+---+---+---+
  2 |   | O | X |   | 2
    +---+---+---+---+
  3 |   | X | O |   | 3
    +---+---+---+---+
  4 |   |   |   |   | 4
    +---+---+---+---+
      A   B   C   D
Enter row and col for your move: 4c

Scores	HUMAN: 5;	COMPUTER: 2
      A   B   C   D
    +---+---+---+---+
  1 | O | X |   |   | 1
    +---+---+---+---+
  2 |   | O | X |   | 2
    +---+---+---+---+
  3 |   | X | X |   | 3
    +---+---+---+---+
  4 |   |   | X |   | 4
    +---+---+---+---+
      A   B   C   D
Player 2 choosing 4,D Total =  1

Scores	HUMAN: 4;	COMPUTER: 4
      A   B   C   D
    +---+---+---+---+
  1 | O | X |   |   | 1
    +---+---+---+---+
  2 |   | O | X |   | 2
    +---+---+---+---+
  3 |   | X | O |   | 3
    +---+---+---+---+
  4 |   |   | X | O | 4
    +---+---+---+---+
      A   B   C   D
Enter row and col for your move: 2a

Scores	HUMAN: 6;	COMPUTER: 3
      A   B   C   D
    +---+---+---+---+
  1 | O | X |   |   | 1
    +---+---+---+---+
  2 | X | X | X |   | 2
    +---+---+---+---+
  3 |   | X | O |   | 3
    +---+---+---+---+
  4 |   |   | X | O | 4
    +---+---+---+---+
      A   B   C   D
Player 2 choosing 1,C Total =  2

Scores	HUMAN: 4;	COMPUTER: 6
      A   B   C   D
    +---+---+---+---+
  1 | O | O | O |   | 1
    +---+---+---+---+
  2 | X | X | O |   | 2
    +---+---+---+---+
  3 |   | X | O |   | 3
    +---+---+---+---+
  4 |   |   | X | O | 4
    +---+---+---+---+
      A   B   C   D
Enter row and col for your move: 3d

Scores	HUMAN: 6;	COMPUTER: 5
      A   B   C   D
    +---+---+---+---+
  1 | O | O | O |   | 1
    +---+---+---+---+
  2 | X | X | O |   | 2
    +---+---+---+---+
  3 |   | X | X | X | 3
    +---+---+---+---+
  4 |   |   | X | O | 4
    +---+---+---+---+
      A   B   C   D
Player 2 choosing 4,A Total =  1

Scores	HUMAN: 5;	COMPUTER: 7
      A   B   C   D
    +---+---+---+---+
  1 | O | O | O |   | 1
    +---+---+---+---+
  2 | X | X | O |   | 2
    +---+---+---+---+
  3 |   | O | X | X | 3
    +---+---+---+---+
  4 | O |   | X | O | 4
    +---+---+---+---+
      A   B   C   D
Enter row and col for your move: 3a

Scores	HUMAN: 7;	COMPUTER: 6
      A   B   C   D
    +---+---+---+---+
  1 | O | O | O |   | 1
    +---+---+---+---+
  2 | X | X | O |   | 2
    +---+---+---+---+
  3 | X | X | X | X | 3
    +---+---+---+---+
  4 | O |   | X | O | 4
    +---+---+---+---+
      A   B   C   D
Player 2 choosing 2,D Total =  1

Scores	HUMAN: 6;	COMPUTER: 8
      A   B   C   D
    +---+---+---+---+
  1 | O | O | O |   | 1
    +---+---+---+---+
  2 | X | X | O | O | 2
    +---+---+---+---+
  3 | X | X | X | O | 3
    +---+---+---+---+
  4 | O |   | X | O | 4
    +---+---+---+---+
      A   B   C   D
Enter row and col for your move: 1d

Scores	HUMAN: 8;	COMPUTER: 7
      A   B   C   D
    +---+---+---+---+
  1 | O | O | O | X | 1
    +---+---+---+---+
  2 | X | X | X | O | 2
    +---+---+---+---+
  3 | X | X | X | O | 3
    +---+---+---+---+
  4 | O |   | X | O | 4
    +---+---+---+---+
      A   B   C   D
Player 2 choosing 4,B Total =  4

Scores	HUMAN: 4;	COMPUTER: 12
      A   B   C   D
    +---+---+---+---+
  1 | O | O | O | X | 1
    +---+---+---+---+
  2 | X | O | X | O | 2
    +---+---+---+---+
  3 | X | O | O | O | 3
    +---+---+---+---+
  4 | O | O | O | O | 4
    +---+---+---+---+
      A   B   C   D
GameOver! 
The winner is COMPUTER!
The final score is: HUMAN: 4;	COMPUTER: 12