/* s171201 - Lars Haugan */
#include "class_player.h"
#include <string>
namespace player{
    player::player(int i, char s){
        id = i;
        sign = s;
    };
    player::player(int i, char s, std::string n){
        id = i;
        sign = s;
        name = n;
    };
    int player::getId(){
        return id;
    }
    char player::getSign(){
        return sign;
    }
    std::string player::getName(){
        return name;
    }
}
