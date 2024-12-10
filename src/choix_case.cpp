#include "choix_case.hpp"

int choix_case (std::array <char, 9> plateau){
    unsigned int numeroCase {};
    while (true)
    {
        std::cout << "Choix de la case : " ;
        std::cin >> numeroCase;+

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
    return numeroCase;
}