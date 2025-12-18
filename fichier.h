#ifndef FICHIER_H
#define FICHIER_H
#include "AVLA.h"



Usine* lireCSV(const char* nom);
void Decoupe(char* ligne,char* c1, char* c2, char* c3, char* c4, char* c5);
int EstLigneUsine(char* c2, char* c3, char* c4);
int EstSourceVersUsine(char* c3, char* c4, char* c5);   



#endif