/* s171201 - Lars Haugan */

#include "class_tictactoeGame.h"
#include "class_player.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


namespace tictac{
    int tictactoe::start(){
        
        int size = 0;
        bool valid = false;
        while(valid == false){
            std::cout << "Size of the game: "; 
            std::string s = "";
            std::cin >> s;
            std::stringstream str(s);
            std::stringstream(s) >> size;
            if(size != 0 && size >= 3){
                valid = true;
            }
        }
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

        //while(playerWin() == 0){
            theBoard->printBoardWithHelptext();
            if(players.at(playersTurn).getName() == "Computer"){
                computerPlay(playersTurn);
            }else{
                humanPlay(playersTurn);
            }
            theBoard->printBoardWithHelptext();            
        //}

    }
    int tictactoe::chooseStartPlayer(){
        srand(time(NULL));
        playersTurn = rand() % players.size();
        return playersTurn;
    }
    int tictactoe::findWinner(){
        


        return 0;
    }
    void tictactoe::humanPlay(int id){
        // Input of coordinates
        int x = -1;
        int y = -1;
        bool valid = false;
        std::stringstream ssx;
        std::stringstream ssy;

        std::cout << "Enter coordinates 3 - " << theBoard->getXSize() << std::endl;
        while (!valid){
            // X coordinat
            std::cout << "X: ";
            std::string sx = "";
            std::cin >> sx;
            ssx.str(sx);
            ssx >> x;

            // Y coordinat
            std::cout << "Y: ";
            std::string sy = "";
            std::cin >> sy;
            ssy.str(sy);
            ssy >> y;
            
            if(x > -1 && x < theBoard->getXSize() && y > -1 && y < theBoard->getYSize()){
                if(!theBoard->placeSpace(y,x,players.at(id).getSign(), id)){
                    std::cout << "Already occupied" << std::endl;
                }else{
                    valid = true;
                }
            }else{
                std::cout << "Not valid. Try again." << std::endl;
            }
        }
    
    }
    void tictactoe::computerPlay(int id){
    
    }
}
