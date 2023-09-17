#ifndef S_PROG_H_INCLUDED
#define S_PROG_H_INCLUDED

//Structure joueur :
typedef struct joueur
{
    char chevalet[8];
    int score_lettre[7];
    int score;
    char pseudo[15];
}t_joueur;

/*----------------------------------------------------------------------------------------------------------------------------------------*/
/////////////////////////////////////////////SOUS-PROGRAMMES dans "lancement_partie.c"//////////////////////////////////////////////////////
/*----------------------------------------------------------------------------------------------------------------------------------------*/
//Sous-programme Lancer nouvelle partie :
void nouvelle_partie();

//Sous-programme nombre de joueurs :
int nombre_joueurs();

//Sous-programmes pseudo :
void saisie_pseudo();
void affichage_pseudo();

//Sous-programmes chevalet :
void pioche_lettre();
void affichage_chevalet();

//Sous-programme plateau :
void affichage_plateau();

//Sous-programme choix joueur :
void sous_menu_joueur();
void notice();

//Sous-programme score joueur :
void affichage_score();

/*----------------------------------------------------------------------------------------------------------------------------------------*/
/////////////////////////////////////////////SOUS-PROGRAMMES dans "placement_mots.c"////////////////////////////////////////////////////////
/*----------------------------------------------------------------------------------------------------------------------------------------*/
void placement_mot();
void verification_placement();
void ecrire_mot(char identifiant, char plateau_jeu[16][16]);

//Sous-programmes de vérification placement mot :
int verificationH();
int verificationV();

//Sous-programmes vérification saisie mot :
int verification_mot();
int dictionnaire();

/*----------------------------------------------------------------------------------------------------------------------------------------*/
/////////////////////////////////////////////SOUS-PROGRAMMES dans "couleurs et dico.c"//////////////////////////////////////////////////////
/*----------------------------------------------------------------------------------------------------------------------------------------*/
//Sous-programmes bonnus :
void changementPoliceConsole();                   //Sous programme pour changer la taille de la police
void Color(int couleurDuTexte,int couleurDeFond); //Sous programme d'affichage de couleurs


#endif
