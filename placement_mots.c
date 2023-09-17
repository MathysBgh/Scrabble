#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"


int i;
int j;
int rand(void);
int count;
int randCount;
char mot[45];
char identifiant;

/*----------------------------------------------------------------------------------------------------------------------------------------*/
//Sous-programme pour mettre le mot saisi sur le tableau :
void ecrire_mot(char identifiant, char plateau_jeu[16][16])
{

    for (int k = 0; k < strlen(mot); k++)
    {
        plateau_jeu[i][j] = mot[k];

        if (identifiant == 'H')
        {
            j++;
        }
        else i++;
    }

}
/*----------------------------------------------------------------------------------------------------------------------------------------*/
//Sous-programme pour vérifier si le mot peut être saisi à l'horizontale :
int verificationH(char * mot, int ligne, int colonne, char plateau_jeu[16][16])
{

    int taille = strlen(mot);
    char verif1 = 'F';
    char verif2 = 'T';

    int k;

    if (16 - colonne >= taille && ligne < 16)
    {

        for (k = 0; k < taille; k++)
        {

            if (plateau_jeu[colonne][ligne] == mot[k] || count == 0)
            {
                verif1 = 'T';
            }
            else if (plateau_jeu[colonne][ligne] == ' ')
            {
            }
            else
            {


                verif2 = 'F';

            }
            colonne++;
        }



    }

    if (verif1 == 'T' && verif2 == 'T')
    {


        return 1;
    }

    else
    {
        return 0;
    }




}
/*----------------------------------------------------------------------------------------------------------------------------------------*/
//Sous-programme pour vérifier si le mot peut-être saisi à la verticale :
int verificationV(char * mot, int ligne, int colonne, char plateau_jeu[16][16])
{

    int taille = strlen(mot);
    char verif1 = 'F';
    char verif2 = 'T';
    int k;



    if (16 - ligne >= taille && colonne < 16)
    {


        for (k = 0; k < taille; k++)
        {

            if (plateau_jeu[colonne][ligne] == mot[k] || count == 0)
            {

                verif1 = 'T';

            }

            else if (plateau_jeu[colonne][ligne] == ' ')
            {

            }

            else
            {

                verif2 = 'F';
            }
            ligne++;
        }
    }
    if (verif1 == 'T' && verif2 == 'T')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
/*----------------------------------------------------------------------------------------------------------------------------------------*/
//Sous-programme pour vérifier le placement du mot :
void verification_placement(char plateau_jeu[16][16], int ligne, int colonne)
{
    if (identifiant == 'H')
    {

        if (verificationH(mot, i, j, plateau_jeu))
        {
            ecrire_mot(identifiant, plateau_jeu);
            affichage_plateau(plateau_jeu);

        }
        else
        {
            if (count == 0)
            {
                count = -1;
            }
            else printf ("Le mot ne peut pas etre place horizontalement !");
        }
    }


    else if (identifiant == 'V')
    {

        if (verificationV(mot, i, j, plateau_jeu))
        {

            ecrire_mot(identifiant, plateau_jeu);
            affichage_plateau(plateau_jeu);
        }
        else
        {
            if (count == 0)
            {
                count = -1;
            }
            else printf ("Le mot ne peut pas etre place verticalement !");
        }
    }
    else
    {
        if (count == 0)
        {
            count = -1;
        }
        printf ("Veuillez choisir un identifiant valide");
    }
}
/*---------------------------------------------------------------------------------------------------------------*/
//Sous programme pour saisir le mot qu'on souhaite afficher sur le tableau :
void placement_mot(t_joueur player, char plateau_jeu[16][16])
{
    int nbreligne=16, nbrecolonne=16;
    int z, v;
    affichage_pseudo(player);
    affichage_chevalet(player);
    printf("\n\n\n");
    affichage_plateau(plateau_jeu);

    char end;
    char end2;

    while (1)
    {
        do
        {
            printf ("\nEnter un mot, 'V' ou 'H', et le numero de ligne et de colonne.\n");





            scanf  ("%s", mot);
            scanf ("%c", &end);
            z=dictionnaire(mot);
            v=verification_mot(mot, player);
        }
        while ((z==1)||(v==2));


        scanf ("%c", &identifiant);
        scanf ("%c", &end2);

        if (end2 != '\n' && identifiant != 'R')
        {

            scanf ("%d", &i);
            scanf (" %d", &j);
        }
        if (identifiant == 'R')
        {

            //verificationaleatoire(plateau_jeu, nbrecolonne, nbreligne);
        }
        else
        {
            verification_placement (plateau_jeu, nbreligne, nbrecolonne);
            break;
        }
        printf ("\n");
        count++;
    }

}
/*----------------------------------------------------------------------------------------------------------------------------------------*/
//Sous-programme pour vérifier si le mot saisit correspond aux lettres du chevalet :
int verification_mot(char mot[8],t_joueur playy)
{
    int i=0;
    int k=0;
    int z=0;
    int j=0;
    j=strlen(mot);
    for(i=0; i<=8; i++)
    {

        for(k=0; k<=8; k++)
        {

            if (mot[i]==playy.chevalet[k])
                z++;
            else
                z--;
        }
    }
    if (j=z)

        return 1;
    else
        return 2;

}
/*----------------------------------------------------------------------------------------------------------------------------------------*/
//Sous-programme pour vérifier que les mots saisient sont dans le dictionnaire (et donc valides) :
int dictionnaire(char mot[8])
{
    FILE *fichier=NULL;
    char p;
    char chaine[100]=" ";
    fichier=fopen("dictionnaire.txt","r");

    if(fichier==NULL)
        return 0;

    while (fgets(chaine,100,fichier)!=NULL)
    {
        char *p=strchr(chaine, '\n');

        if (p!=NULL)
        {
            *p=0;
        }
        if((strcmp(mot,chaine)==0)&& (strlen(mot)==strlen(chaine)))
        {
            Color(2,0);
            printf("\nLe mot existe dans le dictionnaire\n");
            Color(15,0);
            return 0;
        }
    }
    return 1;
}
