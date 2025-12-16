#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct Usine {
    char identifiant[50];       
    double volume_max;          
    double volume_capt;         
    double volume_reel;         
    struct Usine* gauche;
    struct Usine* droite;
    int hauteur;
} Usine;