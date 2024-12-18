# ❎ Projet TicTacToe 🅾️
Pour clôturer notre cours de Programmation 1 d'IMAC 1 nous avons dû réaliser un jeu de morpion. Ce jeu comprend deux modes de jeux : un mode deux joueurs et un mode face à l'ordinateur. Dans la suite de ce README je vais détailler mon travail, mon organisation et les difficultés que j'ai rencontrées. 

## Système d'exploitation testé
J'ai créer et testé mon code sur windows 11 (23H2) avec le compilateur GCC 14.2.0.

## 🕹️ Fonctionnalités du jeu 
Dans ma version du jeu, nous retrouvons toutes les fonctionnalités demandées dans le cahier des charges, c'est à dire :
- Une structure de joueur
- L'affichage du plateau de jeu
- Deux modes de jeu
- Un menu de démarrage
- Une gestion de la fin de partie

Pour améliorer le jeu, j'ai décidé d'ajouter des fonctionnalités à l'IA. Mon IA est ainsi capable de gagner la partie si elle voit qu'elle a 2 symboles alignés. Elle est aussi capable de bloquer les coups de l'adversaire si elle voit que celui-ci a 2 symboles alignés. Aussi, si elle voit qu'elle ne peut pas gagner ou bloquer l'adversaire, elle va aligner son symbole avec un symbole qui existe déjà.
Ces améliorations ne permettent pas à l'IA de jouer parfaitement au jeu, mais elles lui permettent de plutôt bien jouer. 

## 🗃️ Organisation du code
Mon code est organisé en plusieurs fichiers pour mieux si retrouver. Le main se trouve dans le fichier *main_projet_final*, c'est là qu'on retrouve tout le programme et les appels de fonctions. Toutes les fonctions sont réparties dans les autres fichiers, voici un résumé des fichiers et de leurs fonctions : 
- Les fichiers *player* regroupent la structure *Player* et le programme *create_player* qui demande à l'utilisateur son surnom et symbole et les mets dans la structure. Dans ce programme, j'utilise une structure Player contenant le surnom du joueur et son symbole. Cette structure est mise dans un tableau de taille 2 pour contenir les 2 profils des joueurs. Pour éviter que les joueurs utilisent le même symbole, j'ai ajouté le symbole de l'adversaire en paramètre de la fonction.
- Les fichiers *game_board* permettent de tracer le plateau. La fonction *draw_game_board* permet de tracer le plateau du tableau mis en paramètres.
- Les fichiers *menu* permettent d'afficher le menu du démarrage et de récupérer le mode de jeu auprès du joueur. 
- Les fichiers *choix_case* permettent de gérer le choix des cases par le joueur et par l'IA. Le fichier *choix_case.cpp* regroupe plusieurs fonctions. La première est *choix_case* qui récupère la case du joueur. Elle redemande une case tant que celle-ci n'est pas valide. La seconde fonction est *choix_case_IA* qui fait appel à 3 autres fonctions : *does_2_symbols_align*, *is_winning_box* et *is_one_IA_symbol* qui permettent respectivement de voir si l'IA peut gagner pendant le tour, si elle peut perdre ou quelle case est avantageuse pour elle. Ces 3 fonctions permettent ainsi d'avoir une IA améliorée qui ne choisit une case aléatoire que s'il n'y a pas de case intéressante.
- Enfin, la case *does_player_win* permet de vérifier si le joueur a choisi une case gagnante.

## 🛠️ Difficultés rencontrées 
J'ai eu plusieurs difficultés durant la réalisation de projet. Tout d'abord, je me suis demandé comment faire pour vérifier que le joueur a gagné sans vérifier l'entièreté de cases. Je me suis vite rendu compte qu'à chaque tour il ne faut vérifier que la ligne, la colonne et la ou les diagonales de la case qui vient d'être posée. 

Puis je me suis demandé comment faire dans mon code pour justement ne vérifier que ces lignes et colonnes. Pour cela, on utilise les divisions de int et les modulos pour trouver les cases en début de ligne et de colonnes. Ce qui donne :  
```cpp
unsigned int startLine = ((numeroCase)/3) * 3;
unsigned int startColumn = numeroCase%3;
```
Aussi, pour contourner le fait que les symboles peuvent changer, nous vérifions si 3 cases d'affilées ont la même valeur et si c'est le cas c'est forcément le symbole de celui qui vient de jouer. 

Un autre de mes défis a été d'améliorer l'IA. Comme je l'ai déjà un peu détaillé au-dessus, j'ai fait 3 fonctions qui vérifient si la case mise en paramètre est avantageuse ou pas pour l'IA. Ainsi, le programme fait le tour de toutes les cases et met la priorité sur l'action la plus urgente. 

Un moyen facile d'améliorer l'IA serait de récupérer toutes les cases avantageuses pour l'IA et d'en choisir une au hasard. Ainsi, ses coups seraient moins prévisibles. Ensuite, j'envisage d'implémenter un algorithme de recherche qui envisage les possibilités, et joue le meilleur coup trouvé.

