/* s171201 - Lars Haugan */
#ifndef CLASS_PLAYER
#define CLASS_PLAYER

#include <string>

namespace player{
    class player{
        private:
            int id;                             // The users ID
            char sign;                          // The sign of the user (eg. 'X' or '0')
            std::string name;                   // The username
        public:
            player(int, char);                  // Constructor. Sets userID and sign
            player(int, char, std::string);     // Constructor. Sets userID, sign and the username
            int getId();                        // Returns the users ID
            char getSign();                     // Returns the sign of the user
            std::string getName();              // Returns the name of the user
    };
}

#endif
