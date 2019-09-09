// TicTacToe engine

#include<iostream>

class TicTacToe {
  private:
    char board[3][3];
    char player;

  public:

    TicTacToe();
    void drawBoard();
    void setBoardElement(char, int, int);
    void getMove();
    void changePlayer();
    bool checkPositionMarked(int);

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
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }
}



void TicTacToe::setBoardElement(char element, int i, int j) {
    std::cout << "Setting element (" << i << "," << j << ") to " << element <<"\n";
    board[i][j] = element;
}

// Ask for a position on the board. Mark an X or O depending on which player's turn it is.
void TicTacToe::getMove() {
    bool foo=1;
    while(foo==1) { // preventing an already chosen position to be overwritten. foo becomes zero if a free board position is chosen.
        std::cout << "\n Player's " << player << " turn!\n";
        std::cout << "\n Choose a position between 1-9: ";
        int x; //the position on the board that will get X or O.
        std::cin >> x;
        if(checkPositionMarked(x)==0) { // if position eligible foo becomes 0 to exit while loop
            foo = 0;
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
    if(p=='X' | p=='O') {
        return 1;
    }
    return 0;
}
