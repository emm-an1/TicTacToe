#include <iostream>
#include "TicTacToe.h"

int main() {

    TicTacToe T2;
    // Draw board
    T2.drawBoard();

// Player 1 plays

    T2.getMove();
    T2.drawBoard();
// Check winning condition

// Player 2 plays
    T2.changePlayer();

    T2.getMove();
    T2.drawBoard();
// Check winning condition

    return 0;
}
