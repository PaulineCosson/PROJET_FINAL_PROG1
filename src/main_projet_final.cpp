#include <iostream>
#include "player.hpp"
#include "game_board.hpp"
#include "menu.hpp"
#include "choix_case.hpp"
#include "does_player_win.hpp"


int main (){
    //initialise un plateau vide
    std::array <char, 9> plateau {};
    plateau.fill('.');
    //choix du mode de jeu 0 = 2 joueurs / 1 = IA
    bool modeJeu {menu()};

    std::array <Player, 2> player {};
    //on crée le profil du 1er joueur
    player[0] = create_player();

    
    int tour {0};
    bool fin {0};


    if (modeJeu == 0){
        //on crée le profil du 2e joueur
        player[1] = create_player();
        while (fin == false && tour < 9){
            char symbol {};
            draw_game_board(plateau);
            int numJoueur {tour%2};
            std::cout << "Tour de : " << player[numJoueur].name << std::endl;

            // récupère la case du joueur
            unsigned int numeroCase {choix_case(plateau)};
            plateau[numeroCase] = player[numJoueur].symbol;

            // fonction permettant de vérifier si le joueur a gagné
            fin = does_player_win(numeroCase, plateau);
            tour++;
        }
    }
    else{
        //on crée le profil de l'IA
        player[1].name = "IA";
        player[1].symbol = '&';

        while (fin == false && tour < 9){
            char symbol {};
            draw_game_board(plateau);
            int numJoueur {tour%2};
            std::cout << "Tour de : " << player[numJoueur].name << std::endl;

            unsigned int numeroCase {};
            if (numJoueur == 0){
                // récupère la case du joueur
                numeroCase = choix_case(plateau);
            }
            else{
                numeroCase = choix_case_IA(plateau);
            }
            plateau[numeroCase] = player[numJoueur].symbol;

            // fonction permettant de vérifier si le joueur a gagné
            fin = does_player_win(numeroCase, plateau);
            tour++;
        }
    }
    
    draw_game_board(plateau);
    if (fin == true){
        std::cout << player[(tour-1)%2].name << " a gagné la partie" << std::endl ;
    }
    else{
        std::cout << "Personne n'a gagné la partie.." << std::endl ;
    }
}