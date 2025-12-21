#include "fuites.h"

double calculer_pertes(Chainon* c, double vol_entrer) {
    if (c == NULL || c->fils == NULL) {
        return 0;
    }
    
    int nb_fils = 0;
    Chainon* tmp = c->fils;
    while (tmp != NULL) {
        nb_fils++;
        tmp = tmp->suivant;
    }

    double total_fuites= 0.0;
    double vol_troncon = vol_entrer / nb_fils;

    tmp = c->fils;
    while (tmp != NULL) {
        double volume_perdu = vol_troncon * (tmp->fuites / 100.0);
        double vol_restant = vol_troncon - volume_perdu;
        total_fuites += volume_perdu+ calculer_pertes(tmp, vol_restant);
        tmp = tmp->suivant;
    }

    return total_fuites;
}

void fichier_pertes(char* id, float pertes){
    FILE* f=fopen("rendements.dat","a");
    if (f==NULL){
        exit(1);
    }
    fprintf(f,"%s;%lf\n",id,pertes);
    fclose(f);
}
