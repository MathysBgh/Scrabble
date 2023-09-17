#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    //déclaration variable :
    int option=0;
    float verification=0.0;
    char sachet[103]= {'a','a','a','a','a','a','a','a','b','b','c','c','d','d','d','e','e','e','e','e','e','e','e','e','e','e','e','e','e','e','f','f','g','g','h','h','i','i','i','i','i','i','i','i','j','k','l','l','l','l','l','m','m','m','n','n','n','n','n','n','o','o','o','o','o','o','p','p','q','r','r','r','r','r','r','s','s','s','s','s','s','t','t','t','t','t','t','u','u','u','u','u','u','v','v','w','x','y','z','?','?'};
    char plateau_scrabble[16][16] =
    {
        {0, 'A', 'B', 'C', 'd', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N','O'},

        {'B'-'A', '§', ' ', ' ', '&', ' ', ' ', ' ', '§', ' ', ' ', ' ', '&', ' ', ' ', '§'},

        {'C'-'A', ' ', '@', ' ', ' ', ' ', '%', ' ', ' ', ' ', '%', ' ', ' ', ' ', '@', ' '},

        {'D'-'A', ' ', ' ', '@', ' ', ' ', ' ', '&', ' ', '&', ' ', ' ', ' ', '@', ' ', ' '},

        {'E'-'A', '&', ' ', ' ', '@', ' ', ' ', ' ', '&', ' ', ' ', ' ', '@', ' ', ' ', '&'},

        {'F'-'A',  ' ', ' ', ' ', ' ', '@', ' ', ' ', ' ', ' ', ' ','@', ' ', ' ', ' ', ' '},

        {'G'-'A', ' ', '%', ' ', ' ', ' ', '%', ' ', ' ', ' ', '%', ' ', ' ', ' ', '%', ' '},

        {'H'-'A', ' ', ' ', '&', ' ', ' ', ' ', '&', ' ', '&', ' ', ' ', ' ', '&', ' ', ' '},

        {'I'-'A', '§', ' ', ' ', '&', ' ', ' ', ' ', '#', ' ', ' ', ' ', '&', ' ', ' ', '§'},

        {'J'-'A', ' ', ' ', '&', ' ', ' ', ' ', '&', ' ', '&', ' ', ' ', ' ', '&', ' ', ' '},

        {'K'-'A',' ', '%', ' ', ' ', ' ', '%', ' ', ' ', ' ', '%', ' ', ' ', ' ', '%', ' '},

        {'L'-'A',' ', ' ', ' ', ' ', '@', ' ',  ' ', ' ', ' ', ' ', '@', ' ', ' ',' ', ' '},

        {'M'-'A','&', ' ', ' ', '@', ' ', ' ', ' ', '&', ' ', ' ', ' ', '@', ' ', ' ', '&'},

        {'N'-'A',' ', ' ', '@', ' ', ' ', ' ', '&', ' ', '&', ' ', ' ', ' ', '@', ' ', ' '},

        {'O'-'A',' ', '@', ' ', ' ', ' ', '%', ' ', ' ', ' ', '%', ' ', ' ', ' ', '@', ' '},

        {'P'-'A','§', ' ', ' ', '&', ' ', ' ', ' ', '§', ' ', ' ', ' ', '&', ' ', ' ', '§'},
    };

    //Afficher choix du menu principal :
    do
    {
        Color(14,0);
        printf("\n\n\tMENU\n\n");
        printf("1. Nouvelle partie\n");
        printf("2. Reprendre une partie\n");
        printf("3. Afficher les scores\n");
        printf("4. Afficher aide\n");
        printf("5. Quitter\n");
        Color(15,0);
        printf("\nQue souhaitez-vous faire ? ");

        //Blinder la saisie pour saisir l'option :
        do
        {
            scanf("%f", &verification);
            option=(int)verification;

        }
        while(verification!=option);


        switch (option)
        {
        case 1:
            nouvelle_partie(sachet,plateau_scrabble);            //appel sous-programme pour lancer une nouvelle partie;
            break;
        case 2:
//      chargementTXT(plateau_scrabble,sachet, nombreJoueurs);    //appel sous-programme pour reprendre une partie sauvegardée;
            break;
        case 3:
//      affichage_score();             //appel sous-programme pour afficher le score des joueurs;
            break;
        case 4:
            notice();       //appel sous-programme pour afficher la notice;
            break;
        case 5:
            printf("A bientot !\n");
            break;
        default:
            printf("Mauvaise saisie.");
            break;
        }

    }
    while(option!=5);

    return 0;
}
