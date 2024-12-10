#include "choix_case.hpp"

unsigned int choix_case (std::array <char, 9> plateau){
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
        else if (numeroCase == 0 || numeroCase>9) //verifie que le numéro de case existe
        {
            std::cin.ignore(255, '\n'); // On vide les caractères mémorisés.
            std::cout << "Erreur valeur non acceptee " << std::endl;
        }
        else if(plateau[numeroCase-1] != '.'){ //verifie que la case est vide
            std::cin.ignore(255, '\n'); // On vide les caractères mémorisés.
            std::cout << "Case déjà prise " << std::endl;
        }
        else
        {
            break;
        }
                
    }
    return (numeroCase-1);
}

unsigned int choix_case_IA (std::array <char, 9> plateau){
    std::srand(std::time(nullptr));
    unsigned int numeroCase {};
    while (true)
    {
        //l'IA choisie une case au hasard
        numeroCase = std::rand()%8;
        //on verifie que la case est vide
        if(plateau[numeroCase] == '.'){ 
            break;
        }
    }
    return (numeroCase);
}