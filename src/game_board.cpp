#include "game_board.hpp"

void draw_game_board (std::array <char, 9> plateau){
    
    for (int i{0}; i<9; i++){
        std::cout << "| " << plateau[i] << " |";
        if ((i+1)%3 == 0){
            std::cout << "\n";
        }
    }
    
}