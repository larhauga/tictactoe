/* s171201 - Lars Haugan */

#include "class_tictactoeGame.h"
#include "class_player.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


namespace tictac{
    int tictactoe::start(){
        std::cout << "Size of the game: "; 
        
        int size = 0;

        std::string s = "";
        std::cin >> s;
        std::stringstream str(s);
        std::stringstream(s) >> size;
        
        theBoard = new board::board(size);


        players.push_back(player::player(0, 'X', "Player"));
        players.push_back(player::player(1, '0', "Computer"));

        tictactoe::playRound();
        delete theBoard;
        return 0;
    }
    void tictactoe::playRound(){
        playersTurn = chooseStartPlayer();
        std::cout << players.at(playersTurn).getName() << " is starting" << std::endl;

        while(playerWin() == 0){
            theBoard->printBoard();

        }

    }
    int tictactoe::chooseStartPlayer(){
        srand(time(NULL));
        return rand() % players.size();
    }
    int tictactoe::playerWin(){
        return 0;
    }
}
