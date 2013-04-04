/* s171201 - Lars Haugan */ 
#ifndef CLASS_TICTACTOE
#define CLASS_TICTACTOE

#include "class_board.h"
#include "class_player.h"
#include <vector>

namespace tictac{
    class tictactoe{
        private:
            int playersTurn;                    // Userid of the playing user. 

            void playRound();                   // A single round / board of tictactoe
            int chooseStartPlayer();            // Chooses randomly which player is starting
            int findWinner();                   // Finds the winner of the game.

            void humanPlay(int);                // Gets the action for the human player.
            void computerPlay(int,bool);        // Gets the actions for the computer player. If playing first, bool=true
            
        public:
            board::board* theBoard;             // Pointer to the board class. usage: theBoard->placeSpace();
            std::vector<player::player> players; // Vector of the players. Initially two, but there cold be more players
            int start();                        // The start of the game. Called from main. Loops for new rounds if user approve.

    };
}
#endif
