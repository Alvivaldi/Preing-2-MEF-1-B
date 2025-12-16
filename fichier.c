#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usine.h"

void lireFichier(const char* nomFichier, Usine** racine) {
    FILE* fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier %s\n", nomFichier);
        exit(1);
    }

    char ligne[256];
    

    while (fgets(ligne, 256, fichier)) {
        char id[50];
        double max, src, real;
      
        sscanf(ligne, "%*[^;];%49[^;];%lf;%lf", id, &volume_max, &volume_real);
        Usine* u = creerUsine(id, max, src, real);
        *racine = insererAVL(*racine, u); // insertion dans AVL
    }

    fclose(fichier);
}