
#include "player.hpp"


Player create_player (){
    Player player;
    std::cout << "Quel est votre surnom : ";
    std::cin >> player.name;

    char symbol1 {'X'};
    char symbol2 {'O'};


    while (true)
    {
    std::cout << "Quel est votre symbole (X) ou (O) : ";
    std::cin >> player.symbol;

    if (std::cin.fail())
    {
        std::cin.clear(); // On remet std::cin dans un état fonctionnel.
        std::cin.ignore(255, '\n'); // On vide les caractères mémorisés.
        std::cout << "Erreur valeur non acceptee " << std::endl;
    }    
    else if (player.symbol != symbol1 && player.symbol != symbol2)
    {
        std::cin.ignore(255, '\n'); // On vide les caractères mémorisés.
        std::cout << "Erreur symbole non accepté " << std::endl;
    }
    else
    {
        break;
    }
    } 
    return player;
}

