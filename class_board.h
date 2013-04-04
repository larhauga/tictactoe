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
            std::vector<std::vector<space::space> > b;                  // Holds the board
            space::t_coord size;                                        // The size of the board
            int moves;                                                  // Total moves made
        public:
            board(space::t_coord);                                      // Constructor with single size
            board(space::t_coord, space::t_coord);                      // Constructor with two sizes. For uneven board
            std::vector<std::vector<space::space> > getBoard();         // Get function for the board. Deprecated
            space::t_coord getXSize();                                  // Gets the size of the x vector. Actually the y vector.
            space::t_coord getYSize();                                  // Gets the size of the y vector. Actually the x vector.
            void printBoard();                                          // Prints the board to command line
            void printBoardWithHelptext();                              // Prints the board with helptext (eg. coordinates)
            bool placeSpace(space::t_coord, space::t_coord, char);      // Places the space. Not in use.
            bool placeSpace(space::t_coord, space::t_coord, char, int); // Places the space with coordinates, the users sign and the userid. Returns true if ok.

            // Winnerchecks
            int checkHorizon();                                         // Checks for possible winner horizontal. Returns userid
            int checkVertical();                                        // Checks for possible winner vertical.   Returns userid
            int checkForwardDiag();                                     // Checks for possible winner diagonal forwards. Returns userid
            int checkBackwardDiag();                                    // Checks for possible winner diagonal backwards. Returns userid

            bool isFull();                                              // Returns true if board is full. False if not.

            // Computerchecks for the next best move.
            space::space* findNextMove(int);                            // Checks for empty space, and could either block or win. Send with userid to check for. ID to block, or id to check for possible wins.
            space::space* findEmptyWinHorizontal(int);                  // Finds a space where it is the last on the horizontal direction
            space::space* findEmptyWinVertical(int);                    // Finds the last space on the vertical direction
            space::space* findEmptyWinForwardDiag(int);                 // Finds the last space on the forwards diagonal direction
            space::space* findEmptyWinBackwardDiag(int);                // Finds the last space on the backwards diagonal direction
    };
}


#endif
