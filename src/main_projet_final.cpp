#include <iostream>
#include "player.hpp"
#include "game_board.hpp"
#include "menu.hpp"

int main (){
    //initialise un plateau vide
    std::array <char, 9> plateau {};
    plateau.fill('.');
    //choix du mode de jeu 0 = 2 joueurs / 1 = IA
    bool modeJeu {menu()};

    Player player1 {};
    //trouver comment bloquer le choix du symbol
    Player player2 {};

    bool fin {0};
    int tour {1};
    if (modeJeu == 0){
        player1 = create_player();
        player2 = create_player();

        for (int i{0}; i<9; i++){
            char symbol {};
            draw_game_board(plateau);
            std::cout << "Tour de : ";
            if (tour%2 !=0 ){
                std::cout << player1.name << "\n";
                symbol = player1.symbol;
            }
            else {
                std::cout << player2.name << "\n";
                symbol = player2.symbol;
            }

            unsigned int numeroCase {};
            while (true)
            {
                std::cout << "Choix de la case : " ;
                std::cin >> numeroCase;

                if (std::cin.fail())
                {
                    std::cin.clear(); // On remet std::cin dans un état fonctionnel.
                    std::cin.ignore(255, '\n'); // On vide les caractères mémorisés.
                    std::cout << "Erreur valeur non acceptee " << std::endl;
                }    
                else if (numeroCase == 0 || numeroCase>9)
                {
                    std::cin.ignore(255, '\n'); // On vide les caractères mémorisés.
                    std::cout << "Erreur valeur non acceptee " << std::endl;
                }
                else if(plateau[numeroCase-1] != '.'){
                    std::cin.ignore(255, '\n'); // On vide les caractères mémorisés.
                    std::cout << "Case déjà prise " << std::endl;
                }
                else
                {
                    break;
                }
                
            }
            plateau[numeroCase-1] = symbol;
            tour++;
        }

    }
    std::cout << player1.name <<" "<< player1.symbol << std::endl;

    draw_game_board(plateau);
}