#define MAX 100

typedef struct arbre{
    Usine usine;
    char identifiant[50];
    struct arbre* fg;
    struct arbre* fd;
    int equilibre;
}AVL;