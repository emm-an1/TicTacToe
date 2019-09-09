// TicTacToe engine

#include<iostream>

class TicTacToe {
  private:
    char board[3][3];

  public:
    char player;

    TicTacToe();
    void drawBoard();
    void setBoardElement(char, int, int);
    void getMove();
    void changePlayer();
    bool checkPositionMarked(int);
    bool checkWinCondition();
    //  int countMarks(char, int);

};

// ctor
TicTacToe::TicTacToe() :
    board{
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}},
player('X') {
    std::cout << "ctor\n";
};


void TicTacToe::drawBoard() {
    system("CLS");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }
}



void TicTacToe::setBoardElement(char element, int i, int j) {
//    std::cout << "Setting element (" << i << "," << j << ") to " << element <<"\n";
    board[i][j] = element;
}

// Ask for a position on the board. Mark an X or O depending on which player's turn it is.
void TicTacToe::getMove() {
    bool foo=1;
    int x{0}; //the position on the board that will get X or O.
    while(foo==1) { // preventing an already chosen position to be overwritten. foo becomes zero if a free board position is chosen. Also, preventing illigal input
        std::cout << "\n\n\n Player's " << player << " turn!\n";
        while(x<1 | x>9) {
            std::cout << "Choose a position between 1-9: ";
            std::cin >> x;
        };
        if(checkPositionMarked(x)==0) { // if position eligible foo becomes 0 to exit while loop
            foo = 0;
        } else {
            std::cout << "Position already marked. Choose again.\n";
        };
    };
    char mark{'O'};
    if(player=='X') {
        mark ='X';
    };

    setBoardElement(mark, (x-1)/3, (x-1)%3);

}
void TicTacToe::changePlayer() {
    if(player=='X') {
        player ='O';
    } else {
        player ='X';
    };
}

bool TicTacToe::checkPositionMarked(int x) {
    char p{board[(x-1)/3][(x-1)%3]};
    if((p=='X') | (p=='O')) {
        return 1;
    }
    return 0;
}

bool TicTacToe::checkWinCondition() {
    int countX{0};
    int countO{0};
// Check Rows
    for(int i=0; i<3; i++) {
        countX=0;
        countO=0;
        for(int j=0; j<3; j++) {
            if(board[i][j]=='X') {//// Count Xs
                countX++;
            };
            if(board[i][j]=='O') {//// Count Os
                countO++;
            };
        };
        if (countX==3) { ///// win?
            return 1;
        };
        if (countO==3) { ///// win?
            return 1;
        };
    };


// Check Cols
    for(int i=0; i<3; i++) {
        countX=0;
        countO=0;
        for(int j=0; j<3; j++) {
            if(board[j][i]=='X') {//// Count Xs
                countX++;
            };
            if(board[j][i]=='O') {//// Count Os
                countO++;
            };
        };
        if (countX==3) {
            return 1;
        };
        if (countO==3) {
            return 1;
        };
    };
// Check Diagonals
    countX=0;
    countO=0;
    for(int i=0; i<3; i++) {

        if(board[i][i]=='X') {//// Count Xs
            countX++;
        };
        if(board[i][i]=='O') {//// Count Os
            countO++;
        };
    };
    if (countX==3) {
        return 1;
    };
    if (countO==3) {
        return 1;
    };
    return 0;
}
