#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AVLA.h"





Usine* creerUsine(char* id, double Vmax, double Vcapt, double Vreel) {
    Usine* u = malloc(sizeof(Usine));
    if (u == NULL) {
    printf("Erreur d'allocation mémoire\n");
    exit(1);
    }
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



Usine* rotationDoubleDroite(Usine* a) {
    if (a == NULL){
        return NULL;
    }
    a->gauche = rotationGauche(a->gauche);
    return rotationDroite(a);
}

Usine* rotationDoubleGauche(Usine* a) {
    if (a == NULL){
        return NULL;
    }
    a->droite = rotationDroite(a->droite);
    return rotationGauche(a);
}



Usine* equilibrerAVL(Usine* a) {
    if (a == NULL){
        return NULL;
    } 
    if (a->eq >= 2) {
        if (a->droite->eq >= 0) {
            return rotationGauche(a); 
        } else {
            return rotationDoubleGauche(a);
        }
    } 
    else if (a->eq <= -2) {
        if (a->gauche->eq <= 0) {
            return rotationDroite(a);
        } else {
            return rotationDoubleDroite(a);
        }
    }
    return a;
}



Usine* insertionAVL(Usine* a, Usine* u, int *h) {
    if (a == NULL) {
        *h = 1;
        return u; 
    }

    if (strcmp(u->identifiant, a->identifiant) > 0) { 
        a->gauche = insertionAVL(a->gauche, u, h);
        *h = -*h; 
    }
    else if (strcmp(u->identifiant, a->identifiant) < 0) {
        a->droite = insertionAVL(a->droite, u, h);
    }
    else { 
        *h = 0;
        return a;
    }

    if (*h != 0) {
        a->eq += *h; 
        a = equilibrerAVL(a);

        if (a->eq == 0)
            *h = 0;
        else
            *h = 1;
    }

    return a;
}




Usine* chercherUsine(Usine* racine, char* id) {
    if (racine == NULL) {
        return NULL;
    }

    int cmp = strcmp(id, racine->identifiant);

    if (cmp == 0) {
        return racine; 
    }
    else if (cmp > 0) {
        return chercherUsine(racine->gauche, id);
    }
    else {
        return chercherUsine(racine->droite, id);
    }
}



int mettreAJourVolumes(Usine* u, double Vmax, double Vcapt, double Vreel) {
    if (u == NULL) {
        return 0;
    }
   
    u->volume_max  = Vmax;
    u->volume_capt += Vcapt;
    u->volume_reel += Vreel;

    return 1;
}