#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichier.h"
#include "AVLA.h"
#include "histogramme.h"
int main() {
    
    Usine* racine = lireCSV("test.csv");
    genererHistogramme(racine, 1);
    genererHistogramme(racine, 2);
    genererHistogramme(racine, 3);


    return 0;
}

