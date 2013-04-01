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
            t_coord xCoord;
            t_coord yCoord;
            t_chip userChip;
            int userId;
        public:
            space(t_coord, t_coord);
            t_coord getxCoord();
            t_coord getyCoord();
            bool setChip(t_chip);
            bool setChip(t_chip, int);
            t_chip getChip();
            bool isUsed();
    };
}

#endif
