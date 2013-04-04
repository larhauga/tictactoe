/* s171201 - Lars Haugan */
#ifndef CLASS_SPACE
#define CLASS_SPACE

namespace space{
    
    //Players chip (eg. X or O)
    typedef char t_chip;

    //Coordinates
    typedef int t_coord;

    //The space is where you can place a chip
    class space{
        private:
            t_coord xCoord;             // The x coordinate
            t_coord yCoord;             // The y coordinate
            t_chip userChip;            // Users chip (eg. 'X' or '0')
            int userId;                 // The users ID
        public:
            space(t_coord, t_coord);    // Construcotr. Called when initializing the board
            t_coord getxCoord();        // Getting the x coordinate from space.
            t_coord getyCoord();        // Getting the y coordinate from space.
            bool setChip(t_chip);       // Sets the chip to the board.
            bool setChip(t_chip, int);  // Sets the chip AND the userID
            t_chip getChip();           // Returns the chip of the board. Std. is '#'
            bool isUsed();              // Returns true if occupied. False if not
            int getUserId();            // Returns the userID of the user whom this space belongs to
    };
}

#endif
