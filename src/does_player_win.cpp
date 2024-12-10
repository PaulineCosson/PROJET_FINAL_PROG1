#include "does_player_win.hpp"

bool does_player_win (unsigned int numeroCase, std::array <char, 9> plateau){

  // switch ((numeroCase)/3) {
  //   case 0 : 
  //       if (plateau[0]==plateau[1] && plateau[1]==plateau[2]){
  //       return true;
  //       }
  //       break;
  //   case 1:
  //       if (plateau[3]==plateau[4] && plateau[4]==plateau[5]){
  //       return true;
  //       }
  //       break;
  //   case 2:
  //       if (plateau[6]==plateau[7] && plateau[7]==plateau[8]){
  //       return true;
  //       }
  //       break;
  // }

  //on test si la colonne où la case vient d'être jouée est gagnante
  // switch ((numeroCase)%3) {
  //   case 0 : 
  //       if (plateau[0]==plateau[3] && plateau[3]==plateau[6]){
  //       return true;
  //       }
  //       break;
  //   case 1:
  //       if (plateau[1]==plateau[4] && plateau[4]==plateau[7]){
  //       return true;
  //       }
  //       break;
  //   case 2:
  //       if (plateau[2]==plateau[5] && plateau[5]==plateau[8]){
  //       return true;
  //       }
  //       break;
  // }

  //on cherche dans quelle ligne est le numéro de case et quelle est le numéro de case au début de cette ligne
  unsigned int startLine = ((numeroCase)/3) * 3;
  //on cherche dans quelle colonne est le numéro de case et quelle est le numéro de case au début de cette colonne
  unsigned int startColumn = (numeroCase)%3;

  //on ne vérifie la victoire qu'avec la ligne et la colonne de la nouvelle case
  if (plateau[startLine]==plateau[startLine+1] && plateau[startLine+1]==plateau[startLine+2]){
    return true; //on test si la ligne où la case vient d'être jouée est gagnante
  }
  else if (plateau[startColumn]==plateau[startColumn+3] && plateau[startColumn+3]==plateau[startColumn+6]){
    return true;   //on test si la colonne où la case vient d'être jouée est gagnante
  }
  // else if (plateau[0]==plateau[4] && plateau[4]==plateau[8]){
  //   return true; //on regarde si les diagonales sont gagnantes
  // }
  // else if (plateau[2]==plateau[4] && plateau[4]==plateau[6]){
  //   return true; //on regarde si les diagonales sont gagnantes
  // }
  else {
    return false;
  }

}