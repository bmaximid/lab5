/*
 * minimax.c
 *
 *  Created on: Oct 15, 2018
 *      Author: bmaximid
 */


#include "minimax.h"


// this is the "brain" of the program.
// it will look at every possible move and chose the one that is most likely
// to win, or the fastest to win
// board: the current tic tac toe board being played on
// player: who's turn is it? true is player's turn, false is computer's turn
// current_player_is_x == true means X, current_player_is_x == false means O
int minimax(board, bool current_player_is_x)
{
  if (game is over)   // Recursion base case, there has been a win or a draw.
    // If game is over, you need to evaluate board based upon previous player/opponent.
    return score(board, !current_player_is_x);
  // Otherwise, you need to recurse.
  // This loop will generate all possible boards.
  for all rows {
    for all columns {
      if (board[row][column] == EMPTY_SQUARE) {
        // Assign the square to 'X'or 'O'.
        if (current_player_is_x)
          board[row][column] = X_SQUARE
        else
          board[row][column] = O_SQUARE
        score = minimax(board, !current_player_is_x)
        add score to move-score table
        add move to move-score table
        // Undo the change to the board (return the square to empty) prior to next iteration of for-loops.
        board[row][column] = EMPTY_SQUARE
      }
    }
  }
  // Once you get here, you have iterated over empty squares at this level. All of the scores have been computed
  // in the move-score table for boards at this level.
  // Now you need to return the score depending upon whether you are computing min or max.
  if (current_player_is_x) // if the player is player, we want the max score
      {
    choice <= get the move with the highest score in the move-score table.
    score <= highest score in the move-score table.
  } else  // if the computer is player, we want the min score
      {
    choice <= get the move with the lowest score in the move-score table.
    score <= lowest score in the move-score table.
  }
  return score;
}


// this function will determine the best place to play next
// board: the current tic tac toe board being played on
// player: true if the player is playing, false if the computer is playing
// row: the row which the next move should be played
// column: the column which the next move should be played
//....
// This routine is not recursive but will invoke the recursive minimax function.
// You will call this function from the controlling state machine that you will implement in a later milestone.
// It computes the row and column of the next move based upon:
// the current board,
// the player. true means the computer is X. false means the computer is O.
// When called from the controlling state machine, you will call this function as follows:
// 1. If the computer is playing as X, you will call this function with current_player_is_x = true.
// 2. If the computer is playing as O, you will call this function with current_player_is_x = false.
// minimax_computeNextMove directly passes the current_player_is_x argument into the minimax() (helper) function.
// To assign values to the row and column arguments, you must use the following syntax in the body of the function:
// *row = move_row; *column = move_column; (for example).
void minimax_computeNextMove(minimax_board_t* board, bool current_player_is_x, uint8_t* row, uint8_t* column);

// this function determines if the current board is a win, lose, draw,
// or undetermined.
// returns 10 if player won, -10 if computer won, 0 if a draw, or -1 if the game is still going
// board: the current tic tac toe board being played
// player: true if the player is a player, false if player is the computer
// Determine that the game is over by looking at the score.
bool minimax_isGameOver(minimax_score_t score);

// Returns the score of the board, based upon the player and the board.
// This returns one of 4 values: MINIMAX_X_WINNING_SCORE,
// MINIMAX_O_WINNING_SCORE, MINIMAX_DRAW_SCORE, MINIMAX_NOT_ENDGAME
// Note: the player argument makes it possible to speed up this function.
// Assumptions:
// (1) if current_player_is_x == true, the last thing played was an 'X'.
// (2) if current_player_is_x == false, the last thing played was an 'O'.
// Hint: If you know the game was not over when an 'X' was played,
// you don't need to look for 'O's, and vice-versa.
minimax_score_t minimax_computeBoardScore(minimax_board_t* board, bool player_is_x);

// Init the board to all empty squares.
// this function will set the board to all empty squares
// board: the board being played on
void minimax_initBoard(minimax_board_t* board)
{
    int rows;
    int columns;

    //all rows
    for(rows = 0; rows < MINIMAX_BOARD_ROWS; rows++)
    {
        //all columns
        for(columns = 0; columns < MINIMAX_BOARD_COLUMNS; columns++)
        {
            //delete each board
            board->squares[rows][columns] = MINIMAX_EMPTY_SQUARE;
        }
    }
}
