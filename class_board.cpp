/* s171201 - Lars Haugan */
#include "class_board.h"
#include "class_space.h"

namespace board{

    board::board(space::t_coord s){
        size = s;
        moves = 0;
        std::vector<space::space> row;

        for(int x = 0; x < s; x++){
            for(int y = 0; y < s; y++){
                //b[x][y] = new space::space((space::t_coord) x, (space::t_coord) y); 
                row.push_back(space::space(x, y));
            }
            b.push_back(row);
            row.clear();
        }

    };
    board::board(space::t_coord sizex, space::t_coord sizey){
        
    };

    std::vector<std::vector<space::space> > board::getBoard(){
        return b;
    }
    
    space::t_coord board::getXSize(){
        return b.size();
    }
    space::t_coord board::getYSize(){
        return b[0].size();
    }
    void board::printBoard(){
        for(int x = 0; x < getXSize(); x++){
            for(int y = 0; y < getYSize(); y++){
                std::cout << b[x][y].getChip() << " ";
            }
            std::cout << std::endl;
        }
    }
    void board::printBoardWithHelptext(){
        bool x_text_printed = false;
        bool y_text_printed = false;

        for(int x = 0; x < getXSize(); x++){
            x_text_printed = false;

            for( int y = 0; y < getYSize(); y++){
                if(!y_text_printed){
                    std::cout << "  ";
                    for(int i = 0; i < getYSize(); i++){
                        std::cout << i << " ";
                    }
                    y_text_printed = true;
                    std::cout << std::endl;
                }
                if(!x_text_printed){
                    std::cout << x << " ";
                    x_text_printed = true;
                }
                std::cout << b[x][y].getChip() << " ";
            }
            std::cout << std::endl;
        }
    }
    bool board::placeSpace(space::t_coord x , space::t_coord y, char c){
        if(b[x][y].setChip(c)){
            moves += 1;
            return true;
        }else{
            return false;
        }
    }
    bool board::placeSpace(space::t_coord x, space::t_coord y, char c, int id){
        if(b[x][y].setChip(c, id)){
            moves += 1;
            return true;
        }else{
            return false;
        }
    }

    int board::checkHorizon(){
        int userId = -1;
        int count = 0;

        for(int x = 0; x < b.size(); x++){
            if(b[x][0].getUserId() > -1 ){

                userId = b[x][0].getUserId();
                for(int y = 0; y < size; y++){
                    if(userId == b[x][y].getUserId()){
                        count += 1;

                    }
                    if(count == size){
                        return userId;
                    }
                }
            }
            count = 0;
        } 
        return -1;
    }
    int board::checkVertical(){
        int userId = -1;
        int count = 0;

        for(int y = 0; y < getYSize(); y++){
            if(b[0][y].getUserId() > -1){
                userId = b[0][y].getUserId();

                for(int x = 0; x < getXSize(); x++){
                    if(userId == b[x][y].getUserId()){
                        count += 1;
                    }
                    if(count == size){
                        return userId;
                    }
                }

            }
            count = 0;
        }
        return -1;
    }
    int board::checkForwardDiag(){
        int userId = b[0][0].getUserId();
        int count = 0;
        
        int y = 0;
        for(int x = 0; x < getXSize(); x++){
            if(b[x][y].getUserId() == userId){
                count++;
            }
            y++;
        }
        if(count == size){
            return userId;
        }else{
            return -1;
        }
    }
    int board::checkBackwardDiag(){
        int userId = b[0][getXSize()-1].getUserId();
        int count = 0;

        int y = getYSize()-1;
        for(int x = 0; x < getXSize(); x++){
            if(b[x][y].getUserId() == userId){
                count++;
            }
            y--;
        }
        if(count == size){
            return userId;
        }else{
            return -1;
        }
        return -1;
    }

    bool board::isFull(){

        if(moves < size*size){
            for(int x = 0; x < getXSize(); x++){
                for(int y = 0; y < getYSize(); y++){
                    if(!b[x][y].isUsed()){
                        return false;
                    }
                }
            }
            return true;
        }else{
            return true;;
        }
    }

    space::space* board::findNextMove(int thisUser){
        space::space* hor = findEmptyWinHorizontal(thisUser);
        if(hor != NULL){
            return hor;
        }
        space::space* vert = findEmptyWinVertical(thisUser);
        if(vert != NULL){
            return vert;
        }
        space::space* fwdDiag = findEmptyWinForwardDiag(thisUser);
        if(fwdDiag != NULL){
            return fwdDiag;
        }
        space::space* bwdDiag = findEmptyWinBackwardDiag(thisUser);
        if(bwdDiag != NULL){
            return bwdDiag;
        }
        return NULL;
        
    }
    space::space* board::findEmptyWinHorizontal(int id){
        int count = 0;
        int thisusercount = 0;
        int totalcount = 0;

        for(int x = 0; x < size; x++){
            for(int y = 0; y < size; y++){
                totalcount++;
                if(b[x][y].getUserId() == -1){
                    count++;
                }
                if(b[x][y].getUserId() == id){
                    thisusercount++;
                }
            }
            if(totalcount == (count + thisusercount)){ // No other users on this line
                
                if(count < 2){
                    for(int i = 0; i < size; i++){
                        if(b[x][i].getUserId() == -1){
                            return &b[x][i];
                        }
                    }
                }
            }

            count = 0;
            thisusercount = 0;
            totalcount = 0;
        }
        return NULL;
    }
    space::space* board::findEmptyWinVertical(int id){
        int count = 0;
        int thisusercount = 0;
        int totalcount = 0;
        
        for(int y = 0; y < getYSize(); y++){
            for(int x = 0; x < getXSize(); x++){
                totalcount++;

                if(b[x][y].getUserId() == -1){
                    count++;
                }
                if(b[x][y].getUserId() == id){
                    thisusercount++;
                }
            }

            if(totalcount == (count + thisusercount)){

                if(count < 2){
                    for(int i = 0; i < size; i++){
                        if(b[i][y].getUserId() == -1){
                            return &b[i][y];
                        }
                    }
                }
            }
            count = 0;
            thisusercount = 0;
            totalcount = 0;
        }
        return NULL;
    }
    space::space* board::findEmptyWinForwardDiag(int id){
        int count = 0;
        int thisusercount = 0;
        int totalcount = 0;
        
        int y = 0;
        for(int x = 0; x < getXSize(); x++){
            totalcount++;
            if(b[x][y].getUserId() == -1){
                count++;
            }
            if(b[x][y].getUserId() == id){
                thisusercount++;
            }

            y++;
        }
        y = 0;
        if(totalcount == (count + thisusercount)){
            if(count < 2){
                for(int x = 0; x < getXSize(); x++){
                    if(b[x][y].getUserId() == -1){
                        return &b[x][y];
                    }
                    y++;
                }
            }
        }
        return NULL;
    }
    space::space* board::findEmptyWinBackwardDiag(int id){
        return NULL;
    }
    
}
