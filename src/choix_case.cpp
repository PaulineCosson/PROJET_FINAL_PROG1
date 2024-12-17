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

bool does_2_symbols_align (char symbolJ1,int numCase, std::array <char, 9> plateau);
bool is_winning_box ( int numCase, std::array <char, 9> plateau);
bool is_one_IA_symbol ( int numCase, std::array <char, 9> plateau);

unsigned int choix_case_IA (char symbolJ1, std::array <char, 9> plateau){
    std::srand(std::time(nullptr));
    unsigned int numeroCase {};

    int caseGagnante{10};
    int casePerdante{10};
    int caseAvantageuse{10};
    for(int i{0}; i< 9; i++){
        if(plateau[i] == '.'){ 
            //on regarde si il y a deux symboles de l'IA alignés
            if (is_winning_box(i,plateau)){
                caseGagnante = i;
            }
            else if (does_2_symbols_align (symbolJ1,i,plateau)){
            //on regarde si il y a deux symboles du joueur alignés
                casePerdante = i;
            }
            else if (is_one_IA_symbol(i,plateau)){
                caseAvantageuse = i;
            }
        }
    }
    if (caseGagnante != 10){
        return caseGagnante;
    }
    else if (casePerdante != 10){
        return casePerdante;
    }
    else if (caseAvantageuse!=10){
        return caseAvantageuse;
    }
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

bool does_2_symbols_align (char symbolJ1, int numCase, std::array <char, 9> plateau){
    //on cherche dans quelle ligne est le numéro de case et quelle est le numéro de case au début de cette ligne
    int startLine = ((numCase)/3) * 3;
    //on cherche dans quelle colonne est le numéro de case et quelle est le numéro de case au début de cette colonne
    int startColumn = numCase%3;

    int nbr_symbol{0};
    for (int i{startLine}; i<(startLine+3); i++){
        if (plateau[i]==symbolJ1){
            nbr_symbol++;
        }
    }
    if (nbr_symbol==2){
        return true;
    }

    nbr_symbol=0;
    for (int i{startColumn}; i<(startLine+7); i+=3){
        if (plateau[i]==symbolJ1){
            nbr_symbol++;
        }
    }
    if (nbr_symbol==2){
        return true;
    }

    nbr_symbol=0;
    if (numCase == 0 || numCase == 4 || numCase == 8){
        for (int i{0}; i<9; i+=4){
            if (plateau[i]==symbolJ1){
                nbr_symbol++;
            }
        }
        if (nbr_symbol==2){
            return true;
        }
    }

    nbr_symbol=0;
    if (numCase == 2 || numCase == 4 || numCase == 6){
        for (int i{2}; i<7; i+=2){
            if (plateau[i]==symbolJ1){
                nbr_symbol++;
            }
        }
        if (nbr_symbol==2){
            return true;
        }
    }

    return false;
}

bool is_winning_box ( int numCase, std::array <char, 9> plateau){
    //on cherche dans quelle ligne est le numéro de case et quelle est le numéro de case au début de cette ligne
    int startLine = ((numCase)/3) * 3;
    //on cherche dans quelle colonne est le numéro de case et quelle est le numéro de case au début de cette colonne
    int startColumn = numCase%3;

    int nbr_symbol{0};
    for (int i{startLine}; i<(startLine+3); i++){
        if (plateau[i]=='&'){
            nbr_symbol++;
        }
    }
    if (nbr_symbol==2){
        return true;
    }

    nbr_symbol=0;
    for (int i{startColumn}; i<(startColumn+7); i+=3){
        if (plateau[i]=='&'){
            nbr_symbol++;
        }
    }
    if (nbr_symbol==2){
        return true;
    }

    nbr_symbol=0;
    if (numCase == 0 || numCase == 4 || numCase == 8){
        for (int i{0}; i<9; i+=4){
            if (plateau[i]=='&'){
                nbr_symbol++;
            }
        }
        if (nbr_symbol==2){
            return true;
        }
    }

    nbr_symbol=0;
    if (numCase == 2 || numCase == 4 || numCase == 6){
        for (int i{2}; i<7; i+=2){
            if (plateau[i]=='&'){
                nbr_symbol++;
            }
        }
        if (nbr_symbol==2){
            return true;
        }
    }

    return false;
}

bool is_one_IA_symbol ( int numCase, std::array <char, 9> plateau){
    //on cherche dans quelle ligne est le numéro de case et quelle est le numéro de case au début de cette ligne
    int startLine = ((numCase)/3) * 3;
    //on cherche dans quelle colonne est le numéro de case et quelle est le numéro de case au début de cette colonne
    int startColumn = numCase%3;

    int nbr_symbol{0};
    int nbr_empty{0};
    for (int i{startLine}; i<(startLine+3); i++){
        if (plateau[i]=='&'){
            nbr_symbol++;
            nbr_empty++;
        }
    }
    if (nbr_symbol==1 || nbr_empty == 2){
        return true;
    }

    nbr_symbol=0;
    for (int i{startColumn}; i<(startColumn+7); i+=3){
        if (plateau[i]=='&'){
            nbr_symbol++;
            nbr_empty++;
        }
    }
    if (nbr_symbol==1 || nbr_empty == 2){
        return true;
    }

    nbr_symbol=0;
    if (numCase == 0 || numCase == 4 || numCase == 8){
        for (int i{0}; i<9; i+=4){
            if (plateau[i]=='&'){
                nbr_symbol++;
                nbr_empty++;
            }
        }
        if (nbr_symbol==1 || nbr_empty == 2){
            return true;
        }
    }

    nbr_symbol=0;
    if (numCase == 2 || numCase == 4 || numCase == 6){
        for (int i{2}; i<7; i+=2){
            if (plateau[i]=='&'){
                nbr_symbol++;
                nbr_empty++;
            }
        }
        if (nbr_symbol==1 || nbr_empty == 2){
            return true;
        }
    }

    return false;
}