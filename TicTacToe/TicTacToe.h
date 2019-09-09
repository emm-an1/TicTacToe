#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe {
  private:
    char board[3][3]; // 3x3 char positions 1-9
    char player; // player X or O.

  public:
    TicTacToe(); //ctor
    void drawBoard(); //printing the current board

    // Getters and Setters
    void setBoardElement(char, int, int); //replace an empty position with X or O.
    void getMove(); // ask for a move and throw it into setBoardElement()
    void changePlayer(); // change between player X and O.
    bool checkPositionMarked(int); // Returns 1(true) if the position on the board has already been marked previously by a player, else false.

};

#endif // TICTACTOE_H
