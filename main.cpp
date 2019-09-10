#include <iostream>
#include "TicTacToe.h"

int main() {

    TicTacToe T2;

// Draw board
    T2.drawBoard();
// Start
    int cround{1}; // Init round counter
    while(cround<10) {

// Player 1 plays
        T2.getMove();
        T2.drawBoard();

// Check winning condition
        if(T2.checkWinCondition()==1) {
            std::cout << T2.player <<" wins\n";
            break;
        };

// Player 2 plays
        if(cround < 9) { // to prevent O's turn on the last round.
            T2.changePlayer();
            T2.getMove();
            T2.drawBoard();

// Check winning condition
            if(T2.checkWinCondition()==1) {
                std::cout << "-----------" << T2.player <<" wins!\n";
                break;
            };
            T2.changePlayer();
            cround++;
        }
    }
    if(T2.checkWinCondition()==0) { //  draw.
        std::cout << "Draw.\n";
    }
    return 0;
}
