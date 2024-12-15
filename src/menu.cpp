#include "menu.hpp"
#include "game_board.hpp"


bool menu (){
    std::cout << "Bienvenue dans le jeu du TicTacToe" << std::endl;
    std::cout << "Le but du jeu est d’aligner avant son adversaire 3 symboles identiques." << std::endl;
    std::cout << "Le plateau et les numéros de cases se présentent sous cette forme :" << std::endl;
    
    std::array <char, 9> plateau_exemple {};
    for (int i{0}; i<9; i++){
        plateau_exemple[i]=i+49;
    }
    draw_game_board(plateau_exemple);


    int choix{1};
    while (true)
    {
        std::cout << "Veuillez choisir un mode de jeu :" << "\n" <<
        "1. Deux joueurs" << "\n" <<
        "2. Un joueur contre l'IA"<< std::endl;

        std::cin >> choix;

        if (std::cin.fail())
        {
            std::cin.clear(); // On remet std::cin dans un état fonctionnel.
            std::cin.ignore(255, '\n'); // On vide les caractères mémorisés.
            std::cout << "Erreur valeur non acceptee " << std::endl;
        }    
        else if (choix != 1 && choix != 2)
        {
            std::cin.ignore(255, '\n'); // On vide les caractères mémorisés.
            std::cout << "Erreur réponse non acceptée " << std::endl;
        }
        else
        {
            break;
        }
    } 
    if (choix == 1){
        return 0;
    }
    else {
        return 1;
    }

}