#pragma once
#include <string> 
#include <iostream>


struct Player
{
    std::string name {"Joueur"};
    char symbol {};
};

Player create_player (char symbolPris);