/* s171201 - Lars Haugan */ 
#ifndef CLASS_TICTACTOE
#define CLASS_TICTACTOE

#include "class_board.h"

namespace tictac{
    class tictactoe{
        private:
            void playRound();
        public:
            int start();
            board::board* theBoard;
            
            
    };
}
#endif
