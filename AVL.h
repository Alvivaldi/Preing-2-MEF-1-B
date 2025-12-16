#ifndef AVL_H
#define AVL_H

typedef struct usine{
    char id[100];
    int capacite_max;       
    int volume_total; 
    char identifiant[100];
} Usine;

typedef struct arbre{
    Usine usine;
    struct arbre* fg;
    struct arbre* fd;
    int eq;
}AVL;

#endif