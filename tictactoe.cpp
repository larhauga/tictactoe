/* s171201 - Lars Haugan */

#include "class_board.h"
#include "class_space.h"
#include <iostream>
#include "class_tictactoeGame.h"

    int main(){ 
        tictac::tictactoe* tic = new tictac::tictactoe();
        tic->start();
        delete tic;
        return 0;
    }
