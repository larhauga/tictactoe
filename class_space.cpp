/* s171201 - Lars Haugan */
#include "class_space.h"

namespace space{
    space::space(t_coord x, t_coord y){
        xCoord = x;
        yCoord = y;
        userChip = '#';
    };

    t_coord space::getxCoord(){
        return xCoord;
    }
    t_coord space::getyCoord(){
        return yCoord;
    }
    void space::setChip(t_chip c){
        userChip = c;
    }
    t_chip space::getChip(){
        return userChip;
    }
};
