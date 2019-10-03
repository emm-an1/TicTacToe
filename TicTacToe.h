#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe {
  private:
    char _board[3][3];// 3x3 char positions 1-9

  public:
    char player; // player X or O.

    TicTacToe(); //ctor
    void ClearScreen(); // Clear console.
    void drawBoard(); //printing the current board

    // Getters and Setters
    void setBoardElement(char, int, int); //replace an empty position with X or O.
    void getMove(); // ask for a move and throw it into setBoardElement()
    void changePlayer(); // change between player X and O.
    bool checkPositionMarked(int); // Returns 1(true) if the position on the board has already been marked previously by a player, else false.
    bool checkPositionEligible(int); // Returns 1 if position is between 1-9
    bool checkWinCondition(); // Defaults to 0. Returns 1(true) if there is three marks in a row/col/diag
//   int countMarks(char, int); // Returns an integer. How many marks in selected cells. Input: the mark to be searched (eg."X", "O"), the positions to look into

};

#endif // TICTACTOE_H
