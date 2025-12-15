#define MAX 100

typedef struct usine{
    char id[MAX];
    int capacite_max;       
    int volume_total; 
} Usine;

typedef struct avl{
    Usine usine;
    struct arbre* fg;
    struct arbre* fd;
    int equilibre;
}AVL;
