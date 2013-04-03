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

        try{
            std::string* s = new std::string("y");

            while(*s == "Y" || *s == "y"){
                theBoard = new board::board(size);
                players.push_back(player::player(0, 'X', "Human"));
                players.push_back(player::player(1, 'O', "Computer"));

                tictactoe::playRound();

                std::cout << std::endl << "Play another round? (y/n): ";
                std::cin >> *s;
            }
        }catch(int e){
            return e;
        }

        delete theBoard;
        return 0;
    }
    void tictactoe::playRound(){
        playersTurn = chooseStartPlayer();
        std::cout << players.at(playersTurn).getName() <<" is starting" << std::endl;

        while(findWinner() == -1 && !theBoard->isFull()){
            std::cout << std::endl; 
            theBoard->printBoardWithHelptext();

            if(players.at(playersTurn).getName() == "Computer"){
                computerPlay(playersTurn);
            }else{
                humanPlay(playersTurn);
            }
        }
        int winner = findWinner();
        if(winner == -1 && theBoard->isFull()){
            // No winner, and the board is full
            std::cout <<std::endl << "No moves left. Its a tie." << std::endl;
        }
        else if(winner > -1){
            // We got a winner!
            std::cout << std::endl << players.at(winner).getName() << " won!" << std::endl;
        }

    }
    int tictactoe::chooseStartPlayer(){
        srand(time(NULL));
        playersTurn = rand() % players.size();
        return playersTurn;
    }
    int tictactoe::findWinner(){
        
        int check = theBoard->checkVertical();
        if(check > -1){
            return check;
        }

        check = theBoard->checkHorizon();
        if(check > -1){
            return check;
        }
        

        return -1;
    }
    void tictactoe::humanPlay(int id){
        // Input of coordinates
        int x = -1;
        int y = -1;
        bool valid = false;

        std::cout << "Enter coordinates 0 -> " << (theBoard->getXSize()-1) << std::endl;
        while (!valid){
            std::stringstream ssx;
            std::stringstream ssy;
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
