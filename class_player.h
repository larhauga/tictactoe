#ifndef CLASS_PLAYER
#define CLASS_PLAYER

#include <string>

namespace player{
    class player{
        private:
            int id;
            char sign;
            std::string name;
        public:
            player(int, char);
            player(int, char, std::string);
            int getId();
            char getSign();
            std::string getName();
    };
}

#endif
