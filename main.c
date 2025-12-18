#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichier.h"
#include "AVLA.h"
int main() {
    
    Usine* racine = lireCSV("test.csv");
 
    
    /* Test : parcours AVL et affichage */
    // afficherAVL(racine); // créer une fonction pour parcourir et afficher identifiant + vmax + vcapt + vreal

    return 0;
}

// int main(int argc, char** argv) {
    
//     if (argc < 3) {
//         printf( "Erreur d'argument\n");
//         exit(1);
//     }
    
//     FILE* fichier = fopen(argv[1], "r");
//     if (fichier == NULL) {
//         printf("Erreur avec le fichier\n");
//         exit(2);
//     }

//     FILE* fichier_final = fopen("tmp/resultat.csv", "w");
//     if (fichier_final == NULL){
//         exit(3);
//     }
//     traitementTotal(fichier, fichier_final);
//     fclose(fichier);
//     fclose(fichier_final);
//     return 0;
// }

