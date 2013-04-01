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
    bool space::setChip(t_chip c){
        if(isUsed()){
            userChip = c;
            return true;
        }else{
            return false;
        }
    }
    bool space::setChip(t_chip c, int id){
        if(isUsed()){
            userChip = c;
            userId = id;
            return true;
        }else{
            return false;
        }
    }
    t_chip space::getChip(){
        return userChip;
    }
    bool space::isUsed(){
        if(userChip != 0 || userChip != '#'){
            return true;
        }else{
            return false;
        }
    }
};
