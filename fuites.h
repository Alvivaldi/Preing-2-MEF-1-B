#ifndef FUITES_H
#define FUITES_H
#include "AVLA.h"
#define MAX 100

typedef struct Chainon {
    char id[MAX];
    double fuites;           
    struct Chainon* fils;    
    struct Chainon* suivant; 
} Chainon;

double calculer_pertes(Chainon* c, double vol_entrer);
void fichier_pertes(char* id, float pertes);


#endif