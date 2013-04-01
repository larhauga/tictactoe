/* s171201 - Lars Haugan */
#include "class_board.h"
#include "class_space.h"

namespace board{

    board::board(space::t_coord s){
        size = s;
        std::vector<space::space*> row;

        for(int x = 0; x < s; x++){
            for(int y = 0; y < s; y++){
                //b[x][y] = new space::space((space::t_coord) x, (space::t_coord) y); 
                row.push_back(new space::space(x, y));
            }
            b.push_back(row);
            row.clear();
        }

    };
    board::board(space::t_coord sizex, space::t_coord sizey){
        
    };

    std::vector<std::vector<space::space*> > board::getBoard(){
        return this->b;
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
                std::cout << b[x][y]->getChip() << " ";
            }
            std::cout << std::endl;
        }
    }

    
}
