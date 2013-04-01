/* s171201 - Lars Haugan */

#include "class_tictactoeGame.h"
#include <iostream>

namespace tictac{
    int tictactoe::start(){
        std::cout << "How big will your game be?";
        int size = 0; 
        
        theBoard = new board::board(size);
        tictactoe::playRound();
        delete theBoard;
        return 0;
    }
    void tictactoe::playRound(){
        theBoard->printBoard();
    }
}
