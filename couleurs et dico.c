#include "header.h"
#include <Windows.h>


//Sous-programme d'affichage de couleurs :
void Color(int couleurDuTexte,int couleurDeFond)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
//      AIDE :
/*
        0 : Noir
        1 : Bleu fonc�
        2 : Vert fonc�
        3 : Turquoise
        4 : Rouge fonc�
        5 : Violet
        6 : Vert caca d'oie
        7 : Gris clair
        8 : Gris fonc�
        9 : Bleu fluo
        10 : Vert fluo
        11 : Turquoise
        12 : Rouge fluo
        13 : Violet 2
        14 : Jaune
        15 : Blanc
*/

