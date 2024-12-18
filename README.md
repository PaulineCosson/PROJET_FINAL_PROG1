# ❎ Projet TicTacToe 🅾️
Pour cloturer notre cours de Programmation 1 d'IMAC 1 nous avons dû réaliser un jeu de morpion. Ce jeu comprend deux modes de jeux : un mode deux joueurs et un mode face à l'ordinateur. Dans la suite de ce README je vais détailler mon travail, mon organisation et les difficultés que j'ai rencontré. 

    Des indications pour exécuter votre programme si nécessaire (librairies, système d'exploitation testé).

    Des explications sur l'organisation de votre code (fichiers, structure, fonctions, etc.) et vos choix d'implémentation.
    Si améliorations il y a, une description des fonctionnalités supplémentaires que vous avez réalisées (et comment les utiliser si besoin).

    Un rapide bilan sur les problèmes rencontrés et solutions trouvées.


## 🕹️ Fonctionnalités du jeu 
Dans ma version du jeu nous retrouvons toutes les fonctionnalités demandées dans le cahier des charges, c'est à dire :
- Une structure de joueur
- L'affichage du plateau de jeu
- Deux modes de jeu
- Un menu de démarrage
- Une gestion de la fin de partie

Pour améliorer le jeu j'ai décidé d'ajouter des fonctionnalités à l'IA. Mon IA est ainsi capable de gagner la partie si elle voit qu'elle a 2 symboles alignés. Elle est aussi capable de bloquer les coups de l'adversaire si elle voit que celui-ci a 2 symboles alignés. Aussi, si elle voit qu'elle ne peut pas gagner ou bloquer l'adversaire, elle va aligner son symbol avec un symbol qui existe déjà.
Ces améliorations ne permet pas à l'IA de jouer parfaitement au jeux mais elles lui permettent de plutôt bien jouer. 

## 🗃️ Organisation du code
Mon code est organisé en plusieurs fichiers pour permettre de mieux si retrouver. Le main se trouve dans le fichier *main_projet_final*, c'est là qu'on retrouve tout le programme et les appels de fonctions. Toutes les fonctions sont réparties dans les autres fichiers, voici un résumé des fichiers et de leurs fonctions : 
- Les fichiers *player* regroupent la structure *Player* et le programme *create_player* qui demande à l'utilisateur son surnom et symbol et les mets dans la structure. Dans ce programme, j'utilise une structure Player contenant le surnom du joueur et son symbole. Cette structure est mise dans un tableau de taille 2 pour contenir les 2 profils des joueurs. Pour éviter que les joueurs utilisent le mêmes symbols, j'ai ajouté le symbol de l'adversaire en paramètre de la fonction.
- 



