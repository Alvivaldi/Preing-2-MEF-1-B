#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AVLA.h"


void decoupe(char* ligne,char* c1, char* c2, char* c3, char* c4, char* c5) {

    sscanf(ligne, "%[^;];%[^;];%[^;];%[^;];%s",c1, c2, c3, c4, c5);
}


int estLigneUsine(char* c2, char* c3, char* c4) {
    return strstr(c2, "Facility complex") != NULL && strcmp(c3, "-") == 0 && strcmp(c4, "-") != 0;
}



int estSourceVersUsine(char* c3, char* c4, char* c5) {
    return strstr(c3, "Facility complex") != NULL && strcmp(c4, "-") != 0 && strcmp(c5, "-") != 0;
}


Usine* lireCSV(const char* nom) {
    FILE* f = fopen(nom, "r");
    char ligne[256];
    Usine* racine = NULL;
    int h;
   
    while (fgets(ligne, 256, f)) {

        char c1[50], c2[50], c3[50], c4[50], c5[50];
        decoupe(ligne, c1, c2, c3, c4, c5);
      
       




        /* ----- LIGNE USINE ----- */
        if (estLigneUsine(c2,c3, c4)) {

            Usine* u = chercherUsine(racine, c2);
            if (!u) {
                u = creerUsine(c2, atof(c4), 0, 0);
                racine = insertionAVL(racine, u, &h);
            } else {
                u->volume_max = atof(c4);
            }
        }

        /* ----- SOURCE → USINE ----- */
        else if (estSourceVersUsine(c3, c4, c5)) {

            Usine* u = chercherUsine(racine, c3);
            if (!u) {
                u = creerUsine(c3, 0, 0, 0);
                racine = insertionAVL(racine, u, &h);
            }

            double vol = atof(c4);
            double fuite = atof(c5);

            u->volume_capt += vol;
            u->volume_reel += vol * (1.0 - fuite / 100.0);
        }
    }

    fclose(f);
    printf("\n\nAffichage de l'AVL après lecture du fichier CSV :\n\n");
 
    return racine;
}
