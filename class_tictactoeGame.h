/* s171201 - Lars Haugan */ 
#ifndef CLASS_TICTACTOE
#define CLASS_TICTACTOE

#include "class_board.h"
#include "class_player.h"
#include <vector>

namespace tictac{
    class tictactoe{
        private:
            int playersTurn;

            void playRound();
            int chooseStartPlayer();
            int playerWin();
            
        public:
            board::board* theBoard;
            std::vector<player::player> players;
            int start();

    };
}
#endif
