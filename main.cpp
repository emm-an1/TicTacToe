#include <iostream>
#include "TicTacToe.h"

int main() {

    TicTacToe T2;

// Draw board
    T2.drawBoard();
// Start
    bool gameEnded{0};
    while(gameEnded==0) {
// Player 1 plays
        T2.getMove();
        T2.drawBoard();

// Check winning condition
        if(T2.checkWinCondition()==1) {
            std::cout << T2.player <<" wins\n";
            break;
        };

// Player 2 plays
        T2.changePlayer();
        T2.getMove();
        T2.drawBoard();

// Check winning condition
        if(T2.checkWinCondition()==1) {
            std::cout << T2.player <<" wins\n";
            break;
        };
        T2.changePlayer();
    }
    return 0;
}
