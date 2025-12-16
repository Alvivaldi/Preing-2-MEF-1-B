#ifndef AVLA_H
#define AVLA_H


typedef struct Usine {
    char identifiant[50];
    double volume_max;
    double volume_capt;
    double volume_reel;
    struct Usine* gauche;
    struct Usine* droite;
    int eq;
} Usine;

Usine* creerUsine(char* id, double Vmax, double Vcapt, double Vreel);
int max(int a, int b);
int min(int a, int b);
int max3(int a, int b, int c);
int min3(int a, int b, int c);
Usine* rotationGauche(Usine* racine);
Usine* rotationDroite(Usine* racine);
Usine* rotationDoubleDroite(Usine* a) ;
Usine* rotationDoubleGauche(Usine* a);
Usine* equilibrerAVL(Usine* a);
Usine* insererAVL(Usine* racine, Usine* u);



#endif