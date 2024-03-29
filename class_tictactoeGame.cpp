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
        srand(time(NULL)); 
        compvscomp = false;
        compShowBoard = true;

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
            std::cout << "Computer vs. Computer? (y/N) ";
            std::string s = "";
            std::cin >> s;
            if(s == "y" || s == "Y"){
                compvscomp = true;
                
                std::string show = "";
                std::cout << "Show board for every action? (y/n): ";
                std::cin >> show;
                if(show =="y" || show == "Y"){
                    compShowBoard = true;
                }else{
                    compShowBoard = false;
                }
                
            }
        }catch(int e){
            
        }
        try{
            std::string* s = new std::string("y");

                players.push_back(player::player(0, 'X', "Human"));
                players.push_back(player::player(1, 'O', "Computer"));

            while(*s == "Y" || *s == "y"){
                theBoard = new board::board(size);

                tictactoe::playRound();

                std::cout << std::endl << "Play another round? (y/n): ";
                std::cin >> *s;
                delete theBoard;
            }
            delete s;
        }catch(int e){
            return e;
        }

        return 0;
    }
    void tictactoe::playRound(){
        bool firstround = true;
        playersTurn = 0;
        playersTurn = chooseStartPlayer();
        std::cout << players.at(playersTurn).getName() <<" is starting" << std::endl;

        while(findWinner() == -1 && !theBoard->isFull()){
            if(players.at(playersTurn).getName() == "Computer"){
                if(compShowBoard){
                    std::cout << "The computer made a move..." << std::endl;
                }
                computerPlay(playersTurn, firstround);
                playersTurn = 0;
            }else if(playersTurn == 0){
                if(compShowBoard){
                    theBoard->printBoardWithHelptext();
                }
                if(compvscomp){
                    computerPlay(playersTurn, firstround);
                }else{
                    humanPlay(playersTurn);
                }
                playersTurn = 1;
            }
            firstround = false;
        }
        int winner = findWinner();
        if(winner == -1 && theBoard->isFull()){
            // No winner, and the board is full
            std::cout << std::endl;
            theBoard->printBoardWithHelptext();
            std::cout <<std::endl << "No moves left. Its a tie." << std::endl;
        }
        else if(winner > -1){
            // We got a winner!
            theBoard->printBoardWithHelptext();
            std::cout << std::endl << players.at(winner).getName() << " won!" << std::endl;
        }

    }
    int tictactoe::chooseStartPlayer(){
        //srand(time(NULL));
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
        check = theBoard->checkForwardDiag();
        if(check > -1){
            return check;
        }

        check = theBoard->checkBackwardDiag();
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
    void tictactoe::computerPlay(int id, bool firstround){
        // Logic for getting the computer to play.
        int x = 0;
        int y = 0;
        
        if(firstround){
            // Do spesific for first round
            int r = -1;
            r = rand() % 5;
            if(r == 0){
                //Left corner
                x = 0;
                y = 0;
            }else if(r == 1){
                //Right corner
                x = theBoard->getXSize()-1;
                y = 0;
            }else if(r == 2){
                //Left bottom
                x = 0;
                y = theBoard->getYSize()-1;
            }else if(r == 3){
                //Right bottom
                x = theBoard->getXSize()-1;
                y = theBoard->getYSize()-1;
            }else if(r == 4){
                //Center
                x = (theBoard->getXSize()/2);
                y = (theBoard->getYSize()/2);

                // Check for center. (4x4 have no center)
                if(theBoard->getXSize() % 2 == 0){
                    if(rand()%2 == 0){
                        x--;
                        y--;
                    }   
                }
            }
            // Places the sign at the space
            theBoard->placeSpace(y,x,players.at(id).getSign(), id);

        }else{
            
            // If the next move could block or win we take that move. If not. Go all about random!
            // This strategy is not beatable without a fork, but with optimal playing from user, the computer is beatable.
            space::space* possibleBlock = theBoard->findNextMove(0);
            space::space* possibleMove  = theBoard->findNextMove(id);
            if(possibleMove != NULL){ // If computer can win
                possibleMove->setChip(players.at(id).getSign(), id);
            }else if(possibleBlock != NULL){ // If computer cant win, but the user can. We block.
                possibleBlock->setChip(players.at(id).getSign(), id);

            }else{
                // No apparant winning or loosing moves? We go random.
                x = rand() % theBoard->getXSize();
                y = rand() % theBoard->getYSize();

                while(!theBoard->placeSpace(y,x,players.at(id).getSign(), id)){ 
                    //While we go to random space that is not occupied
                    x = rand() % theBoard->getXSize();
                    y = rand() % theBoard->getYSize();
                }
            }
        }


    }
}
