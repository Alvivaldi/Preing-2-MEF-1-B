#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AVLA.h"

#define VOL_MAX 1
#define VOL_CAPT 2
#define VOL_TRAIT 3


// void remplir_fichiers(AVL a, FILE* Fmax, FILE* Fcapt, FILE* Freel){
//     if(a == NULL){
//          return;
//     }

//     if(a->usine == NULL){
//         return;
//     }

//     remplir_fichiers(a->fd, Fmax, Fcapt, Freel);

//     fprintf(Fmax,  "%s;%.2f\n", a->id, a->usine->volume_max);
//     fprintf(Fcapt,  "%s;%.2f\n", a->id, a->usine->volume_capte);
//     fprintf(Freel, "%s;%.2f\n", a->id, a->usine->volume_reel);

//     remplir_ficher(AVL a, Fmax, Fcapt, Freel);
// })

void ecrireCSV(Usine* racine, FILE* f, int mode) {
    if (!racine) return;

    // ordre alphabétique inverse
    ecrireCSV(racine->droite, f, mode);

    double valeur = 0.0;

    if (mode == VOL_MAX)
        valeur = racine->volume_max;
    else if (mode == VOL_CAPT)
        valeur = racine->volume_capt;
    else if (mode == VOL_TRAIT)
        valeur = racine->volume_reel;
    // conversion en millions de m³
    // valeur /= 1000000.0;

    fprintf(f, "%s;%.3f\n", racine->identifiant, valeur);

    ecrireCSV(racine->gauche, f, mode);
}

void genererHistogramme(Usine* racine, int mode) {
    FILE* f;
    const char* nom;

    if (mode == VOL_MAX)
        nom = "vol_max.dat";
    else if (mode == VOL_CAPT)
        nom = "vol_captation.dat";
    else
        nom = "vol_traitement.dat";

    f = fopen(nom, "w");
    if (!f) return;

    fprintf(f, "id_usine;volume_Mm3\n");

    ecrireCSV(racine, f, mode);

    fclose(f);
}
