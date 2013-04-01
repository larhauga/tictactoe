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

    int board::spaceLeft(){
        int possible = 0; 
        if(moves < size*size){
            for(int x = 0; x < getXSize(); x++){
                for(int y = 0; y < getYSize(); y++){
                    
                }
            }
        }else{
            return 0;
        }
    }
    
}
