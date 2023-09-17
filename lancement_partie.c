#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*----------------------------------------------------------------------------------------------------------------------------------------*/
////////////////////////////////////////////////SOUS-PROGRAMME NOUVELLE PARTIE//////////////////////////////////////////////////////////////
/*----------------------------------------------------------------------------------------------------------------------------------------*/

void nouvelle_partie(char sachet[103],char plateau[16][16])
{
    srand(time(NULL));  //Initialisation de l'algorithme de la fonction srand pour que le sous-programme "pioche_lettre" fonctionne correctement;

    //Déclaration des variables :
    int nb_joueurs=0;
    int i=0, j=0;
    int stop=0;
    int occurrence_lettres=7;



    printf("\nCombien y a t-il de joueurs (4 maximum)?\n");
    nb_joueurs=nombre_joueurs();    //Appel sous-programme "nombre_joueurs"  qui retourne le nombre de joueurs saisit et affectation à la variable "nombre_joueurs";


    t_joueur joueur[nb_joueurs];

    //Demander à chaque joueurs de saisir leur pseudo :
    for(i=0; i<nb_joueurs; i++)
    {
        printf("\nJoueur %d, quel est votre pseudo (15 caracteres maximum)?\n",i+1);
        saisie_pseudo(&joueur[i]);
    }

    //Creer un chevalet pour chaque joueurs en piochant "occurrence_lettres" :
    for(i=0; i<nb_joueurs; i++)
        pioche_lettre(&joueur[i], sachet,&occurrence_lettres);

    //Réperter
    do
    {
        //Créer une boucle qui exécute les instructions pour chacun des joueurs :
        for(i=0; i<nb_joueurs; i++)
        {
            //Afficher le pseudo du joueur qui joue :
            affichage_pseudo(&joueur[i]);
            //Afficher le chevalet du joueur qui joue :
            printf("\nChevalet : ");
            affichage_chevalet(&joueur[i]);
            //Appeler le sous-programme "sous_menu_joueur" pour proposer un menu :
            sous_menu_joueur(&joueur[i],plateau,sachet);
        }

    }
    while(stop==0);     //Tant que stop==0;

}

/*----------------------------------------------------------------------------------------------------------------------------------------*/
////////////////////////////////////////////////SOUS-PROGRAMME NOMBRE JOUEURS///////////////////////////////////////////////////////////////
/*----------------------------------------------------------------------------------------------------------------------------------------*/
//Sous-programme qui retourne le nombre de joueurs saisis :
int nombre_joueurs()
{
    //Déclaration variable :
    int nb_joueurs=0;
    float verification=0.0;

    //Demande à l'utilisateur le nombre de joueurs + blindage saisie d'un entier compris entre 1 et 4.
    do
    {
        do
        {
            scanf("%f",&verification);
            fflush(stdin);
        }
        while((verification>4)||(verification<1));

        nb_joueurs=(int)verification;
    }
    while(nb_joueurs!=verification);

    //Indique que la saisie effectuée est correcte :
    printf("\nSaisie correcte.\n\n");

    return nb_joueurs;
}
/*----------------------------------------------------------------------------------------------------------------------------------------*/
///////////////////////////////////////////////////SOUS-PROGRAMMES PSEUDO///////////////////////////////////////////////////////////////////
/*----------------------------------------------------------------------------------------------------------------------------------------*/
void saisie_pseudo(t_joueur *player)
{
    scanf("%s",player->pseudo);
}
/*----------------------------------------------------------------------------------------------------------------------------------------*/
void affichage_pseudo(t_joueur plaayer)
{

    printf("\n\n\nPseudo : ");
    Color(11,0);
    printf("%s\n", plaayer.pseudo);
    Color(15,0);

}

/*----------------------------------------------------------------------------------------------------------------------------------------*/
///////////////////////////////////////////////////SOUS-PROGRAMMES CHEVALET/////////////////////////////////////////////////////////////////
/*----------------------------------------------------------------------------------------------------------------------------------------*/
void pioche_lettre(t_joueur *playy, char pioche[103], int *occurrence_lettres)
{
    //Déclaration variable :
    int valeur=0;
    int i=0, lettre=0;
    char chevalet[8];

    //Créer une boucle qui s'exécutera autant de fois que l'on veut piocher de lettres :
    for(i=0; i<*occurrence_lettres; i++)
    {

        lettre=rand()%(102+1);  //Générer une lettre aléatoire;

        if((pioche[lettre]=='*')||(pioche[lettre]==' '))    //si la lettre est déjà piochée
            i--;                                            //Décrémenter;

        else
        {
            //chevalet[i]=pioche[lettre];
            playy->chevalet[i]=pioche[lettre];  //affecter la lettre pioché au chevalet du joueur;
            pioche[lettre]='*'; //chaque lettres piochées sont remplacées par une étoile;


            //Si la lettre piochée est un a,e,i,l,n,o,r,s,t ou u,
            if((playy->chevalet[i]=='a')||(playy->chevalet[i]=='e')||(playy->chevalet[i]=='i')||(playy->chevalet[i]=='l')||(playy->chevalet[i]=='n')||(playy->chevalet[i]=='o')||(playy->chevalet[i]=='r')||(playy->chevalet[i]=='s')||(playy->chevalet[i]=='t')||(playy->chevalet[i]=='u'))
                playy->score_lettre[i]=1;   //le score de la lettre vaut 1;

            //Même raisonnement pour les autres conditions if :
            if((playy->chevalet[i]=='d')||(playy->chevalet[i]=='g')||(playy->chevalet[i]=='m'))
                playy->score_lettre[i]=2;

            if((playy->chevalet[i]=='b')||(playy->chevalet[i]=='c')||(playy->chevalet[i]=='p'))
                playy->score_lettre[i]=3;

            if((playy->chevalet[i]=='f')||(playy->chevalet[i]=='h')||(playy->chevalet[i]=='v'))
                playy->score_lettre[i]=4;

            if((playy->chevalet[i]=='j')||(playy->chevalet[i]=='q'))
                playy->score_lettre[i]=8;

            if((playy->chevalet[i]=='k')||(playy->chevalet[i]=='w')||(playy->chevalet[i]=='x')||(playy->chevalet[i]=='y')||(playy->chevalet[i]=='z'))
                playy->score_lettre[i]=10;

            if((playy->chevalet[i]=='?'))
                playy->score_lettre[i]=0;
        }
    }


}
/*----------------------------------------------------------------------------------------------------------------------------------------*/
//Sous-programme qui affiche le chevalet du joueur avec les lettres et les points de chaque lettres entre () :
void affichage_chevalet(t_joueur joujoueur)
{
    //Déclaration variable :
    int i=0;

    //Boucle qui affiche autant de lettres qu'il y a dans le chevalet (7lettres) :
    for(i=0; i<7; i++)
    {
        Color(10,0);
        printf("%d",joujoueur.score_lettre[i]); //afficher le score de la lettre du chevalet en vert;
        Color(15,0);
        printf("%c ",joujoueur.chevalet[i]);    //afficher la lettre du chevalet en blanc;
    }
}
/*----------------------------------------------------------------------------------------------------------------------------------------*/
///////////////////////////////////////////////////SOUS-PROGRAMMES Plateau de jeu///////////////////////////////////////////////////////////
/*----------------------------------------------------------------------------------------------------------------------------------------*/
void affichage_plateau(char plateau_jeu[16][16])
{
    //Déclaration variable :
    int i=0, j=0;

    Color(0,15);

    //Afficher le plateau :
    for (i=0; i<16; i++)
    {
        for (j=0; j<16; j++)
        {
            if (j==0)   //Si (j==0) c'est-à-dire si on est sur la première colonne :
            {
                printf("\t%d\t|", plateau_jeu[i][j]);   //Afficher en entier (la valeur décimale des caractères dans cette colonne du tableau);
            }
            if (j>0)
            {
                printf(" %c |", plateau_jeu[i][j]);     //Sinon, afficher les caractères du tableau en format caractere;
            }
        }
        printf("\n");
    }

    Color(15,0);
}

/*----------------------------------------------------------------------------------------------------------------------------------------*/
/////////////////////////////////////////////SOUS-PROGRAMMES choix joueur (sous-menu)///////////////////////////////////////////////////////
/*----------------------------------------------------------------------------------------------------------------------------------------*/
void sous_menu_joueur(t_joueur playplay, char plateau[16][16],char pioche[103])
{
    //Déclaration variable :
    int choix=0;
    int i=0;
    int stop=0;
    float verification=0.0;

    //Proposer le menu pour le joueur :
    Color(14,0);
    printf("\n\n\t1. Passer tour\n");
    printf("\t2. Echanger une ou plusieurs lettres du chevalet\n");
    printf("\t3. Placer mot\n");
    printf("\t4. Sauvegarder et quitter\n");
    Color(15,0);

    //Demande à l'utilisateur son choix + blindage saisie d'un entier :
    do
    {
        scanf("%f", &verification);
        choix=(int)verification;

    }
    while(verification!=choix);


    switch (choix)
    {

    case 1: //Si le joueur passe son tour, il sort de la boucle et le joueur suivant joue.
        break;

    case 2: //Le joueur décide de changer une ou plusieurs lettres :
        //  changerLettre(playplay,pioche);
        break;

    case 3: //Le joueur décide de placer son mot :
        placement_mot(playplay,plateau);
        break;
    case 4 :
//        sauvegardeTXT(plateau,&playplay,pioche);

        break;

    default:
        printf("\n\nMauvaise saisie.");
        break;

    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------*/

void notice()
{
    Color(4,0);
    printf("\n            Notice  :\n\n");
    printf("\n    -Demarrage avec 7 lettres tirees aleatoirement.\n");
    printf("\n    -Objectif : trouver un mot.\n");
    printf("\n    -Le premier mot doit passer sur la case # centrale.\n");
    printf("\n    -Le mot suivant place par le prochain joueur doit avoir 1 ou plusieurs lettre en commun, et ainsi de suite.\n\n");
    printf("\n    -Action du joueur :\n\n");
    printf("\n                1) PLACER UN MOT \n");
    printf("\n                2) PASSER SON TOUR \n");
    printf("\n                3) ECHANGER 1 OU PLUSIEURS LETTRES \n");
    printf("\n    -Si le joueur place ces 7 lettres d'un coup : SCRABBLE ! \n");
    printf("\n    -Comment se termine une partie ? lorsqu’un joueur n’a plus de lettre ET qu’il n’y a plus de lettres non plus dans le chevalet.\n\n");
    printf("\n             LES POINTS : \n\n");
    printf("\n Les points d’un mot est l’addition des points des lettres qui composent ce mot, en ajoutant les bonus ci-dessous si le mot passe sur une case bonus. \n");
    printf("\n Points lettre X2 : & \n");
    printf("\n Points lettre X3 : & \n");
    printf("\n Points mot X2 : @ \n");
    printf("\n Points mot X3 : § \n");
    Color(15,0);
}

/*----------------------------------------------------------------------------------------------------------------------------------------*/
/////////////////////////////////////////////SOUS-PROGRAMME score joueur////////////////////////////////////////////////////////////////////
/*----------------------------------------------------------------------------------------------------------------------------------------*/
/*
void afficherScore(int nbJoueurs)
{
    int i=0;
    Joueur playyer[nbJoueurs];

    for(i=0; i<nbJoueurs; i++)
        printf("\n\Le score du joueur %d est de : %d",i+1,playyer[i].score);

}

*/





