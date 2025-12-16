#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AVLA.h"





Usine* creerUsine(char* id, double Vmax, double Vcapt, double Vreel) {
    Usine* u = malloc(sizeof(Usine));
    strcpy(u->identifiant, id);
    u->volume_max = Vmax;
    u->volume_capt = Vcapt;
    u->volume_reel = Vreel;
    u->gauche = NULL;
    u->droite = NULL;
    u->eq = 0;
    return u;
}

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int max3(int a, int b, int c) {
    int m;
    if (a > b) {
        m = a;
    } else {
        m = b;
    }

    if (c > m) {
        m = c;
    }

    return m;
}

int min3(int a, int b, int c) {
    int m;
    if (a < b) {
        m = a;
    } else {
        m = b;
    }

    if (c < m) {
        m = c;
    }

    return m;
}
Usine* rotationGauche(Usine* racine) {
    Usine* pivot = racine->droite;
    int eq_r = racine->eq;
    int eq_p = pivot->eq;

    racine->droite = pivot->gauche;
    pivot->gauche = racine;
    racine->eq = eq_r - max(eq_p, 0) - 1;
    pivot->eq = min3(eq_r - 2, eq_r + eq_p - 2, eq_p - 1);

    return pivot;
}



Usine* rotationDroite(Usine* racine) {
    Usine* pivot = racine->gauche;
    int eq_r = racine->eq;
    int eq_p = pivot->eq;

    racine->gauche = pivot->droite;
    pivot->droite = racine;

    racine->eq = eq_r - min(eq_p, 0) + 1;
    pivot->eq = max3(eq_r + 2, eq_r + eq_p + 2, eq_p + 1);

    return pivot;
}
