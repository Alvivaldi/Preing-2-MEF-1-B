#ifndef AVLA_H
#define AVLA_H
#include "fuites.h"

typedef struct Usine {
    char identifiant[50];
    double volume_max;
    double volume_capt;
    double volume_reel;
    
    struct Usine* gauche;
    struct Usine* droite;
    int eq;
} Usine;

typedef struct AVL_fuites {
    char id[100];           
    AVL_fuites* element;    
    struct AVL_fuites* fg;       
    struct AVL_fuites* fd;  
    int eq;     
} AVL_fuites;


Usine* creerUsine(char* id, double Vmax, double Vcapt, double Vreel);
int max(int a, int b);
int min(int a, int b);
int max3(int a, int b, int c);
int min3(int a, int b, int c);
Usine* rotationGauche(Usine* racine);
Usine* rotationDroite(Usine* racine);
Usine* rotationDoubleDroite(Usine* a) ;
Usine* rotationDoubleGauche(Usine* a);
Usine* equilibrerAVL(Usine* a);
Usine* insertionAVL(Usine* a, Usine* u, int *h) ;
Usine* chercherUsine(Usine* racine, char* id);

void afficherAVL(Usine* racine);

#endif
