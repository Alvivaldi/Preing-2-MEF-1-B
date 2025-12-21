#ifndef fuites_h
#define fuites_h

typedef struct Chainon {
    char id[100];
    double fuites;           
    struct Chainon* fils;    
    struct Chainon* suivant; 
} Chainon;

double calculer_pertes(Chainon* c, double vol_entrer);
void fichier_pertes(char* id, float pertes);

