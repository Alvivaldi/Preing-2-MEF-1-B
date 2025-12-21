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
    Chainon* element;    
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
Chainon* creerChainon(char* id, double fuite_pourcentage);
void ajouterFils(Chainon* parent, Chainon* nv_fils);
AVL_fuites* creerAVLfuites(char* id, Chainon* c);
Chainon* chercherAVLfuites(AVL_fuites* racine, char* id2);
AVL_fuites* rotationGaucheFuites(AVL_fuites* racine);
AVL_fuites* rotationDoubleDroiteFuites(AVL_fuites* a);
AVL_fuites* rotationDoubleGaucheFuites(AVL_fuites* a);    
AVL_fuites* equilibrerAVLfuites(AVL_fuites* a);
AVL_fuites* insertionAVLfuites(AVL_fuites* a, char* id, Chainon* c, int *h);
void afficherAVL(Usine* racine);

#endif
