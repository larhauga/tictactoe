/* s171201 - Lars Haugan */
#ifndef CLASS_BOARD
#define CLASS_BOARD

#include "class_space.h"
#include "class_board.h"
#include <vector>
#include <iostream>

namespace board{

    //typedef vector< vector<space::space>> t_board;

    class board{
        private:
            std::vector<std::vector<space::space> > b;
            space::t_coord size;
            int moves;
        public:
            board(space::t_coord);
            board(space::t_coord, space::t_coord);
            std::vector<std::vector<space::space> > getBoard();
            space::t_coord getXSize();
            space::t_coord getYSize();
            void printBoard();
            bool placeSpace(space::t_coord, space::t_coord, char);
            bool placeSpace(space::t_coord, space::t_coord, char, int);
            int spaceLeft();
    };
}


#endif
